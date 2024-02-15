#include "../../headers/list_manager/ChaserListManager.hpp"

ChaserListManager::ChaserListManager()
{
    this->chaserlist = NULL;
    this->qty = 0;
};

void ChaserListManager::addchaser(int y, int x)
{
    pChaserList newchaser = new ChaserList;

    (newchaser->chaser).init(CHASER, ENEMY_INIT_HLT, y, x, NULLDIR, CHASER_DMG);

    newchaser->next = this->chaserlist;
    this->chaserlist = newchaser;
};

void ChaserListManager::placeallchasers(int playerlevel)
{
    int random_y, random_x;
    bool pos_generated;

    if(playerlevel == 8) this->qty = 1;
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

        this->addchaser(random_y, random_x);
    }
};

pChaserList ChaserListManager::findchaser(int y, int x)
{
    pChaserList current = this->chaserlist;

    bool found = false;
    while(!found && current != NULL)
    {
        if( (current->chaser).getpos_y() == y && (current->chaser).getpos_x() == x )
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

void ChaserListManager::removechaser(pChaserList todelete)
{
    pChaserList current = this->chaserlist;
    
    bool removed = false;
    while(!removed)
    {
        if(this->chaserlist == todelete)
        {
            this->chaserlist = (this->chaserlist)->next;
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

void ChaserListManager::displaychaser()
{
    pChaserList current = this->chaserlist;

    while(current != NULL)
    {
        attron(COLOR_PAIR(RED));
        mvaddch((current->chaser).getpos_y(), (current->chaser).getpos_x(), (current->chaser).getaspect());
        attroff(COLOR_PAIR(RED));
        
        current = current->next;
    }
};

void ChaserListManager::deleteallchasers()
{
    pChaserList current = this->chaserlist;
    pChaserList nextnode = NULL;

    while(current != NULL)
    {
        nextnode = current->next;
        delete current;
        current = nextnode;
    }

    this->chaserlist = NULL;
    this->qty = 0;
};

void ChaserListManager::movechasers(int player_x, int player_active_pwrup)
{
    pChaserList current = this->chaserlist;

    while(current != NULL)
    {
        if( (current->chaser).getpos_y() == MAX_PLAYABLE_Y - 1 &&
            (current->chaser).getdirection() == RIGHT &&
            CollisionDetector::downright( (current->chaser).getpos_y(), (current->chaser).getpos_x() ) == PIT )
        {
            (current->chaser).setjumpstate(JUMPING);
        }
        if( (current->chaser).getpos_y() == MAX_PLAYABLE_Y - 1 &&
            (current->chaser).getdirection() == LEFT &&
            CollisionDetector::downleft( (current->chaser).getpos_y(), (current->chaser).getpos_x() ) == PIT )
        {
            (current->chaser).setjumpstate(JUMPING);
        } // all of these condition could be put in a single 'if', but we decided to split it for clarity
        
        (current->chaser).jump();
        (current->chaser).fall();

        bool unsafe_to_proceed_R = ( (current->chaser).getdirection() == RIGHT &&
                                     CollisionDetector::above( (current->chaser).getpos_y(), (current->chaser).getpos_x() ) == FLOOR &&
                                     CollisionDetector::downright( (current->chaser).getpos_y(), (current->chaser).getpos_x() ) == PIT );
        bool unsafe_to_proceed_L = ( (current->chaser).getdirection() == LEFT &&
                                     CollisionDetector::above( (current->chaser).getpos_y(), (current->chaser).getpos_x() ) == FLOOR &&
                                     CollisionDetector::downleft( (current->chaser).getpos_y(), (current->chaser).getpos_x() ) == PIT );

        if(!unsafe_to_proceed_R && !unsafe_to_proceed_L && player_active_pwrup != VANISHER)
        {
            (current->chaser).chase(player_x);
        }
        else
        {
            if(player_x > (current->chaser).getpos_x())
            {
                (current->chaser).setdir(RIGHT);
            }
            else if(player_x < (current->chaser).getpos_x())
            {
                (current->chaser).setdir(LEFT);
            }
        }

        if( (current->chaser).getpos_y() > MAX_PLAYABLE_Y )
        {
            pChaserList todelete = current;
            current = current->next;
            this->removechaser(todelete);
        }
        else current = current->next;
    }
};

void ChaserListManager::handle_projectile_collision(ProjectileListManager &plm, int &points, int &points_buffer)
{
    pChaserList current_csr = this->chaserlist;

    while(current_csr != NULL)
    {
        if(plm.findprojectile((current_csr->chaser).getpos_y(), (current_csr->chaser).getpos_x()) != NULL)
        {
            pProjectileList current_prj = plm.findprojectile((current_csr->chaser).getpos_y(), (current_csr->chaser).getpos_x());
            (current_csr->chaser).takedamage((current_prj->projectile).getdamage());
            plm.removeprojectile(current_prj);
        }
        if(plm.findprojectile((current_csr->chaser).getpos_y(), (current_csr->chaser).getpos_x()+1) != NULL)
        {
            pProjectileList current_prj = plm.findprojectile((current_csr->chaser).getpos_y(), (current_csr->chaser).getpos_x()+1);
            (current_csr->chaser).takedamage((current_prj->projectile).getdamage());
            plm.removeprojectile(current_prj);
        }
        if(plm.findprojectile((current_csr->chaser).getpos_y(), (current_csr->chaser).getpos_x()-1) != NULL)
        {
            pProjectileList current_prj = plm.findprojectile((current_csr->chaser).getpos_y(), (current_csr->chaser).getpos_x()-1);
            (current_csr->chaser).takedamage((current_prj->projectile).getdamage());
            plm.removeprojectile(current_prj);
        }

        if( (current_csr->chaser).gethealth() <= 0 )
        {
            pChaserList todelete = current_csr;
            current_csr = current_csr->next;
            this->removechaser(todelete);
            points++;
            points_buffer++;
        }
        else current_csr = current_csr->next;
    }
};

void ChaserListManager::handle_forcefield(int player_y, int player_x, chtype player_active_pwrup, int &points, int &points_buffer)
{
    pChaserList current = this->chaserlist;

    while(current != NULL)
    {
        if( player_active_pwrup == FORCEFIELD && (current->chaser).getpos_y() == player_y && CollisionDetector::distance( (current->chaser).getpos_x(), player_x ) <= FORCEFIELD_RANGE )
        {
            pChaserList todelete = current;
            current = current->next;
            this->removechaser(todelete);

            points++;
            points_buffer++;
        }
        else current = current->next;
    }
};

void ChaserListManager::placefixedqty(int q)
{
    int random_y, random_x;
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

        this->addchaser(random_y, random_x);
    }
};

int ChaserListManager::getqty()
{
    return this->qty;
};