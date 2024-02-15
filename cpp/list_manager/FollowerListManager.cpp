#include "../../headers/list_manager/FollowerListManager.hpp"

FollowerListManager::FollowerListManager()
{
    this->followerlist = NULL;
    this->qty = 0;
    this->levelbuffer = 0;
};

void FollowerListManager::addfollower(int y, int x)
{
    pFollowerList newfollower = new FollowerList;

    (newfollower->follower).init(FOLLOWER, ENEMY_INIT_HLT, y, x, NULLDIR, FOLLOWER_DMG);

    newfollower->next = this->followerlist;
    this->followerlist = newfollower;
};

void FollowerListManager::placeallfollowers(int playerlevel)
{
    int random_y, random_x;
    bool pos_generated;

    //if(playerlevel % 2 == 0 && playerlevel < 7 && playerlevel != this->levelbuffer) (this->qty)++;
    if(playerlevel == 2 || playerlevel == 3) this->qty = 1;
    else if(playerlevel == 4 || playerlevel == 5) this->qty = 2;
    else if(playerlevel == 6) this->qty = 3;
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

        this->addfollower(random_y, random_x);
    }
};

pFollowerList FollowerListManager::findfollower(int y, int x)
{
    pFollowerList current = this->followerlist;

    bool found = false;
    while(!found && current != NULL)
    {
        if( (current->follower).getpos_y() == y && (current->follower).getpos_x() == x )
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

void FollowerListManager::removefollower(pFollowerList todelete)
{
    pFollowerList current = this->followerlist;
    
    bool removed = false;
    while(!removed)
    {
        if(this->followerlist == todelete)
        {
            this->followerlist = (this->followerlist)->next;
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

void FollowerListManager::displayfollower()
{
    pFollowerList current = this->followerlist;

    while(current != NULL)
    {
        attron(COLOR_PAIR(ORANGE));
        mvaddch((current->follower).getpos_y(), (current->follower).getpos_x(), (current->follower).getaspect());
        attroff(COLOR_PAIR(ORANGE));
        
        current = current->next;
    }
};

void FollowerListManager::deleteallfollowers()
{
    pFollowerList current = this->followerlist;
    pFollowerList nextnode = NULL;

    while(current != NULL)
    {
        nextnode = current->next;
        delete current;
        current = nextnode;
    }

    this->followerlist = NULL;
    this->qty = 0;
};

void FollowerListManager::movefollowers(int player_x, int player_active_pwrup)
{
    pFollowerList current = this->followerlist;

    while(current != NULL)
    {
        if( (current->follower).getpos_y() == MAX_PLAYABLE_Y - 1 &&
            (current->follower).getdirection() == RIGHT &&
            CollisionDetector::downright( (current->follower).getpos_y(), (current->follower).getpos_x() ) == PIT )
        {
            (current->follower).setjumpstate(JUMPING);
        }
        if( (current->follower).getpos_y() == MAX_PLAYABLE_Y - 1 &&
            (current->follower).getdirection() == LEFT &&
            CollisionDetector::downleft( (current->follower).getpos_y(), (current->follower).getpos_x() ) == PIT )
        {
            (current->follower).setjumpstate(JUMPING);
        } // all of these condition could be put in a single 'if', but we decided to split it for clarity
        
        (current->follower).jump();
        (current->follower).fall();

        bool unsafe_to_proceed_R = ( (current->follower).getdirection() == RIGHT &&
                                     CollisionDetector::above( (current->follower).getpos_y(), (current->follower).getpos_x() ) == FLOOR &&
                                     CollisionDetector::downright( (current->follower).getpos_y(), (current->follower).getpos_x() ) == PIT );
        bool unsafe_to_proceed_L = ( (current->follower).getdirection() == LEFT &&
                                     CollisionDetector::above( (current->follower).getpos_y(), (current->follower).getpos_x() ) == FLOOR &&
                                     CollisionDetector::downleft( (current->follower).getpos_y(), (current->follower).getpos_x() ) == PIT );

        if(!unsafe_to_proceed_R && !unsafe_to_proceed_L && player_active_pwrup != VANISHER)
        {
            (current->follower).chase(player_x);
        }
        else
        {
            if(player_x > (current->follower).getpos_x())
            {
                (current->follower).setdir(RIGHT);
            }
            else if(player_x < (current->follower).getpos_x())
            {
                (current->follower).setdir(LEFT);
            }
        }

        if( (current->follower).getpos_y() > MAX_PLAYABLE_Y )
        {
            pFollowerList todelete = current;
            current = current->next;
            this->removefollower(todelete);
        }
        else current = current->next;
    }
};

void FollowerListManager::handle_projectile_collision(ProjectileListManager &plm, int &points, int &points_buffer)
{
    pFollowerList current_flr = this->followerlist;

    while(current_flr != NULL)
    {
        if(plm.findprojectile((current_flr->follower).getpos_y(), (current_flr->follower).getpos_x()) != NULL)
        {
            pProjectileList current_prj = plm.findprojectile((current_flr->follower).getpos_y(), (current_flr->follower).getpos_x());
            (current_flr->follower).takedamage((current_prj->projectile).getdamage());
            plm.removeprojectile(current_prj);
        }
        if(plm.findprojectile((current_flr->follower).getpos_y(), (current_flr->follower).getpos_x()+1) != NULL)
        {
            pProjectileList current_prj = plm.findprojectile((current_flr->follower).getpos_y(), (current_flr->follower).getpos_x()+1);
            (current_flr->follower).takedamage((current_prj->projectile).getdamage());
            plm.removeprojectile(current_prj);
        }
        if(plm.findprojectile((current_flr->follower).getpos_y(), (current_flr->follower).getpos_x()-1) != NULL)
        {
            pProjectileList current_prj = plm.findprojectile((current_flr->follower).getpos_y(), (current_flr->follower).getpos_x()-1);
            (current_flr->follower).takedamage((current_prj->projectile).getdamage());
            plm.removeprojectile(current_prj);
        }

        if( (current_flr->follower).gethealth() <= 0 )
        {
            pFollowerList todelete = current_flr;
            current_flr = current_flr->next;
            this->removefollower(todelete);
            points++;
            points_buffer++;
        }
        else current_flr = current_flr->next;
    }
};

void FollowerListManager::handle_forcefield(int player_y, int player_x, chtype player_active_pwrup, int &points, int &points_buffer)
{
    pFollowerList current = this->followerlist;

    while(current != NULL)
    {
        if( player_active_pwrup == FORCEFIELD && (current->follower).getpos_y() == player_y && CollisionDetector::distance( (current->follower).getpos_x(), player_x ) <= FORCEFIELD_RANGE )
        {
            pFollowerList todelete = current;
            current = current->next;
            this->removefollower(todelete);

            points++;
            points_buffer++;
        }
        else current = current->next;
    }
};

void FollowerListManager::placefixedqty(int q)
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

        this->addfollower(random_y, random_x);
    }
}

int FollowerListManager::getqty()
{
    return this->qty;
};