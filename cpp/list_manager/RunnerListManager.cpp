#include "../../headers/list_manager/RunnerListManager.hpp"

RunnerListManager::RunnerListManager()
{
    this->runnerlist = NULL;
    this->qty = 0;
    this->levelbuffer = 0;
};

void RunnerListManager::addrunner(int y, int x, int dir)
{
    pRunnerList newrunner = new RunnerList;

    (newrunner->runner).init(RUNNER, ENEMY_INIT_HLT, y, x, dir, RUNNER_DMG);

    newrunner->next = this->runnerlist;
    this->runnerlist = newrunner;
};

void RunnerListManager::placeallrunners(int playerlevel)
{
    int random_y, random_x, random_dir;
    bool pos_generated;

    //if(playerlevel % 2 == 0 && playerlevel < 7 && playerlevel != this->levelbuffer) (this->qty)++;
    if(playerlevel == 1) this->qty = 1;
    else if(playerlevel == 2) this->qty = 2;
    else if(playerlevel == 3) this->qty = 3;
    else if(playerlevel == 4) this->qty = 4;
    else if(playerlevel == 5) this->qty = 5;
    else if(playerlevel == 6) this->qty = 6;
    else if(playerlevel >= 7 && playerlevel < 9) this->qty = 1;
    else if(playerlevel >= 9) this->qty = 2;

    this->levelbuffer = playerlevel;

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

        this->addrunner(random_y, random_x, random_dir);
    }
};

pRunnerList RunnerListManager::findrunner(int y, int x)
{
    pRunnerList current = this->runnerlist;

    bool found = false;
    while(!found && current != NULL)
    {
        if( (current->runner).getpos_y() == y && (current->runner).getpos_x() == x )
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

void RunnerListManager::removerunner(pRunnerList todelete)
{
    pRunnerList current = this->runnerlist;
    
    bool removed = false;
    while(!removed)
    {
        if(this->runnerlist == todelete)
        {
            this->runnerlist = (this->runnerlist)->next;
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

void RunnerListManager::displayrunner()
{
    pRunnerList current = this->runnerlist;

    while(current != NULL)
    {
        attron(COLOR_PAIR(CYAN));
        mvaddch((current->runner).getpos_y(), (current->runner).getpos_x(), (current->runner).getaspect());
        attroff(COLOR_PAIR(CYAN));
        
        
        current = current->next;
    }
};

void RunnerListManager::deleteallrunners()
{
    pRunnerList current = this->runnerlist;
    pRunnerList nextnode = NULL;

    while(current != NULL)
    {
        nextnode = current->next;
        delete current;
        current = nextnode;
    }

    this->runnerlist = NULL;
    this->qty = 0;
};

void RunnerListManager::moverunners(int player_x, chtype player_active_pwrup)
{
    pRunnerList current = this->runnerlist;

    while(current != NULL)
    {
        (current->runner).roam();
        current = current->next;
    }
};

void RunnerListManager::handle_projectile_collision(ProjectileListManager &plm, int &points, int &points_buffer)
{
    pRunnerList current_rnr = this->runnerlist;

    while(current_rnr != NULL)
    {
        if(plm.findprojectile((current_rnr->runner).getpos_y(), (current_rnr->runner).getpos_x()) != NULL)
        {
            pProjectileList current_prj = plm.findprojectile((current_rnr->runner).getpos_y(), (current_rnr->runner).getpos_x());
            (current_rnr->runner).takedamage((current_prj->projectile).getdamage());
            plm.removeprojectile(current_prj);
        }
        if(plm.findprojectile((current_rnr->runner).getpos_y(), (current_rnr->runner).getpos_x()+1) != NULL)
        {
            pProjectileList current_prj = plm.findprojectile((current_rnr->runner).getpos_y(), (current_rnr->runner).getpos_x()+1);
            (current_rnr->runner).takedamage((current_prj->projectile).getdamage());
            plm.removeprojectile(current_prj);
        }
        if(plm.findprojectile((current_rnr->runner).getpos_y(), (current_rnr->runner).getpos_x()-1) != NULL)
        {
            pProjectileList current_prj = plm.findprojectile((current_rnr->runner).getpos_y(), (current_rnr->runner).getpos_x()-1);
            (current_rnr->runner).takedamage((current_prj->projectile).getdamage());
            plm.removeprojectile(current_prj);
        }

        if( (current_rnr->runner).gethealth() <= 0 )
        {
            pRunnerList todelete = current_rnr;
            current_rnr = current_rnr->next;
            this->removerunner(todelete);
            points++;
            points_buffer++;
        }
        else current_rnr = current_rnr->next;
    }
};

void RunnerListManager::handle_forcefield(int player_y, int player_x, chtype player_active_pwrup, int &points, int &points_buffer)
{
    pRunnerList current = this->runnerlist;

    while(current != NULL)
    {
        if( player_active_pwrup == FORCEFIELD && (current->runner).getpos_y() == player_y && CollisionDetector::distance( (current->runner).getpos_x(), player_x ) <= FORCEFIELD_RANGE )
        {
            pRunnerList todelete = current;
            current = current->next;
            this->removerunner(todelete);

            points++;
            points_buffer++;
        }
        else current = current->next;
    }
};

int RunnerListManager::getqty()
{
    return this->qty;
};

void RunnerListManager::placefixedqty(int q)
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

        this->addrunner(random_y, random_x, random_dir);
    }
}