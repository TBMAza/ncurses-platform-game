#include "../../headers/list_manager/ChargerListManager.hpp"

ChargerListManager::ChargerListManager()
{
    this->chargerlist = NULL;
    this->qty = 0;
};

void ChargerListManager::addcharger(int y, int x, int dir)
{
    pChargerList newcharger = new ChargerList;

    (newcharger->charger).init(CHARGER, ENEMY_INIT_HLT, y, x, dir, CHARGER_DMG);

    newcharger->next = this->chargerlist;
    this->chargerlist = newcharger;
};

void ChargerListManager::placeallchargers(int playerlevel)
{
    int random_y, random_x, random_dir;
    bool pos_generated;

    if(playerlevel > 6 && playerlevel < 9) this->qty = 1;
    else if(playerlevel >= 9) this->qty = 2;

    for(int i = 0; i < this->qty; i++)
    {
        pos_generated = false;
        while(!pos_generated)
        {
            random_y = RandomGenerator::generate(FLOATING_BLOCK_LVL3-1, PLAYER_INIT_POS_Y);
            random_x = RandomGenerator::generate(MAX_PLAYABLE_X/2, MAX_PLAYABLE_X);

            if(CollisionDetector::isempty(random_y, random_x) && CollisionDetector::below(random_y, random_x) == FLOOR &&
               CollisionDetector::downright(random_y, random_x) == FLOOR && CollisionDetector::downleft(random_y, random_x) == FLOOR)
            {
                pos_generated = true;
            }
        }

        random_dir = RandomGenerator::generate(RIGHT, LEFT);

        this->addcharger(random_y, random_x, random_dir);
    }
};

pChargerList ChargerListManager::findcharger(int y, int x)
{
    pChargerList current = this->chargerlist;

    bool found = false;
    while(!found && current != NULL)
    {
        if( (current->charger).getpos_y() == y && (current->charger).getpos_x() == x )
        {
            found = true;
        }
        else
        {
            current = current->next;
        }
    }

    return current;
};

void ChargerListManager::removecharger(pChargerList todelete)
{
    pChargerList current = this->chargerlist;
    
    bool removed = false;
    while(!removed)
    {
        if(this->chargerlist == todelete)
        {
            this->chargerlist = (this->chargerlist)->next;
            delete todelete;
            todelete = NULL;
            removed = true;
            (this->qty)--;
        }
        else if(current->next == todelete)
        {
            current->next = todelete->next;
            delete todelete;
            todelete = NULL;
            removed = true;
            (this->qty)--;
        }
        else
        {
            current = current->next;
        }
        
    }
};

void ChargerListManager::displaycharger()
{
    pChargerList current = this->chargerlist;

    while(current != NULL)
    {
        attron(COLOR_PAIR(BLUE));
        mvaddch((current->charger).getpos_y(), (current->charger).getpos_x(), (current->charger).getaspect());
        attroff(COLOR_PAIR(BLUE));
        
        
        current = current->next;
    }
};

void ChargerListManager::deleteallchargers()
{
    pChargerList current = this->chargerlist;
    pChargerList nextnode = NULL;

    while(current != NULL)
    {
        nextnode = current->next;
        delete current;
        current = nextnode;
    }

    this->chargerlist = NULL;
    this->qty = 0;
};

void ChargerListManager::movechargers()
{
    pChargerList current = this->chargerlist;

    while(current != NULL)
    {
        (current->charger).roam();
        current = current->next;
    }
};

void ChargerListManager::handle_projectile_collision(ProjectileListManager &plm, int &points, int &points_buffer)
{
    pChargerList current_chg = this->chargerlist;

    while(current_chg != NULL)
    {
        if(plm.findprojectile((current_chg->charger).getpos_y(), (current_chg->charger).getpos_x()) != NULL)
        {
            pProjectileList current_prj = plm.findprojectile((current_chg->charger).getpos_y(), (current_chg->charger).getpos_x());
            (current_chg->charger).takedamage((current_prj->projectile).getdamage());
            plm.removeprojectile(current_prj);
        }
        if(plm.findprojectile((current_chg->charger).getpos_y(), (current_chg->charger).getpos_x()+1) != NULL)
        {
            pProjectileList current_prj = plm.findprojectile((current_chg->charger).getpos_y(), (current_chg->charger).getpos_x()+1);
            (current_chg->charger).takedamage((current_prj->projectile).getdamage());
            plm.removeprojectile(current_prj);
        }
        if(plm.findprojectile((current_chg->charger).getpos_y(), (current_chg->charger).getpos_x()-1) != NULL)
        {
            pProjectileList current_prj = plm.findprojectile((current_chg->charger).getpos_y(), (current_chg->charger).getpos_x()-1);
            (current_chg->charger).takedamage((current_prj->projectile).getdamage());
            plm.removeprojectile(current_prj);
        }

        if( (current_chg->charger).gethealth() <= 0 )
        {
            pChargerList todelete = current_chg;
            current_chg = current_chg->next;
            this->removecharger(todelete);
            points++;
            points_buffer++;
        }
        else current_chg = current_chg->next;
    }
};

void ChargerListManager::handle_forcefield(int player_y, int player_x, chtype player_active_pwrup, int &points, int &points_buffer)
{
    pChargerList current = this->chargerlist;

    while(current != NULL)
    {
        if( player_active_pwrup == FORCEFIELD && (current->charger).getpos_y() == player_y && CollisionDetector::distance( (current->charger).getpos_x(), player_x ) <= FORCEFIELD_RANGE )
        {
            pChargerList todelete = current;
            current = current->next;
            this->removecharger(todelete);

            points++;
            points_buffer++;
        }
        else current = current->next;
    }
};

int ChargerListManager::getqty()
{
    return this->qty;
};

void ChargerListManager::placefixedqty(int q)
{
    int random_y, random_x, random_dir;
    bool pos_generated;
    this->qty = q;
    
    for(int i = 0; i < q; i++)
    {
        pos_generated = false;
        while(!pos_generated)
        {
            random_y = RandomGenerator::generate(FLOATING_BLOCK_LVL3-1, PLAYER_INIT_POS_Y);
            random_x = RandomGenerator::generate(MAX_PLAYABLE_X/2, MAX_PLAYABLE_X);

            if(CollisionDetector::isempty(random_y, random_x) && CollisionDetector::below(random_y, random_x) == FLOOR &&
               CollisionDetector::downright(random_y, random_x) == FLOOR && CollisionDetector::downleft(random_y, random_x) == FLOOR)
            {
                pos_generated = true;
            }
        }

        random_dir = RandomGenerator::generate(RIGHT, LEFT);

        this->addcharger(random_y, random_x, random_dir);
    }
}