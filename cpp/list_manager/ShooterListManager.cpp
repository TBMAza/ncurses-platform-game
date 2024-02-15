#include "../../headers/list_manager/ShooterListManager.hpp"

ShooterListManager::ShooterListManager()
{
    this->shooterlist = NULL;
    this->qty = 0;
    this->levelbuffer = 0;
};

void ShooterListManager::addshooter(int y, int x, int playerlevel)
{
    pShooterList newshooter = new ShooterList;

    // increase Shooter's health and contact damage at higher levels
    if(playerlevel < 7) (newshooter->shooter).init(SHOOTER, ENEMY_INIT_HLT, y, x, NULLDIR, SHOOTER_DMG);
    else (newshooter->shooter).init(SHOOTER, SUPER_ENEMY_INIT_HLT, y, x, NULLDIR, SUPER_SHOOTER_DMG);

    // switch to more powerful bullets at higher levels
    if(playerlevel == 4) (newshooter->shooter).setactiveproj(SUPERBULLET);
    else if(playerlevel > 4 && playerlevel < 7) (newshooter->shooter).setactiveproj(HYPERBULLET);
    else if(playerlevel >= 7) (newshooter->shooter).setactiveproj(LASER);

    newshooter->next = this->shooterlist;
    this->shooterlist = newshooter;
};

void ShooterListManager::placeallshooters(int playerlevel)
{
    int random_y, random_x;
    bool pos_generated;

    //if(playerlevel % 3 == 0 && playerlevel < 7 && playerlevel != this->levelbuffer) (this->qty)++;
    if(playerlevel == 3 || playerlevel == 4 || playerlevel == 5) this->qty = 1;
    else if(playerlevel == 6) this->qty = 2;
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

        this->addshooter(random_y, random_x, playerlevel);
    }
};

pShooterList ShooterListManager::findshooter(int y, int x)
{
    pShooterList current = this->shooterlist;

    bool found = false;
    while(!found && current != NULL)
    {
        if( (current->shooter).getpos_y() == y && (current->shooter).getpos_x() == x )
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

void ShooterListManager::removeshooter(pShooterList todelete)
{
    pShooterList current = this->shooterlist;
    
    bool removed = false;
    while(!removed)
    {
        if(this->shooterlist == todelete)
        {
            this->shooterlist = (this->shooterlist)->next;
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

void ShooterListManager::displayshooter()
{
    pShooterList current = this->shooterlist;

    while(current != NULL)
    {
        attron(COLOR_PAIR(3));
        mvaddch((current->shooter).getpos_y(), (current->shooter).getpos_x(), (current->shooter).getaspect());
        attroff(COLOR_PAIR(3));
        
        current = current->next;
    }
};

void ShooterListManager::deleteallshooters()
{
    pShooterList current = this->shooterlist;
    pShooterList nextnode = NULL;

    while(current != NULL)
    {
        nextnode = current->next;
        delete current;
        current = nextnode;
    }

    this->shooterlist = NULL;
    this->qty = 0;
};

void ShooterListManager::moveshooter(int player_x, chtype player_active_pwrup)
{
    pShooterList current = this->shooterlist;

    while(current != NULL)
    {
        if( (current->shooter).getpos_y() == MAX_PLAYABLE_Y - 1 &&
            (current->shooter).getdirection() == RIGHT &&
            CollisionDetector::downright( (current->shooter).getpos_y(), (current->shooter).getpos_x() ) == PIT )
        {
            (current->shooter).setjumpstate(JUMPING);
        }
        if( (current->shooter).getpos_y() == MAX_PLAYABLE_Y - 1 &&
            (current->shooter).getdirection() == LEFT &&
            CollisionDetector::downleft( (current->shooter).getpos_y(), (current->shooter).getpos_x() ) == PIT )
        {
            (current->shooter).setjumpstate(JUMPING);
        } // all of these condition could be put in a single 'if', but we decided to split it for clarity
        
        (current->shooter).jump();
        (current->shooter).fall();

        bool unsafe_to_proceed_R = ( (current->shooter).getdirection() == RIGHT &&
                                     CollisionDetector::above( (current->shooter).getpos_y(), (current->shooter).getpos_x() ) == FLOOR &&
                                     CollisionDetector::downright( (current->shooter).getpos_y(), (current->shooter).getpos_x() ) == PIT );
        bool unsafe_to_proceed_L = ( (current->shooter).getdirection() == LEFT &&
                                     CollisionDetector::above( (current->shooter).getpos_y(), (current->shooter).getpos_x() ) == FLOOR &&
                                     CollisionDetector::downleft( (current->shooter).getpos_y(), (current->shooter).getpos_x() ) == PIT );

        if(!unsafe_to_proceed_R && !unsafe_to_proceed_L && player_active_pwrup != VANISHER)
        {
            (current->shooter).reach(player_x);
        }
        else
        {
            if(player_x > (current->shooter).getpos_x())
            {
                (current->shooter).setdir(RIGHT);
            }
            else if(player_x < (current->shooter).getpos_x())
            {
                (current->shooter).setdir(LEFT);
            }
        }

        if( (current->shooter).getpos_y() > MAX_PLAYABLE_Y )
        {
            pShooterList todelete = current;
            current = current->next;
            this->removeshooter(todelete);
        }
        else current = current->next;
    }
};

void ShooterListManager::let_them_shoot(ProjectileListManager &plm, int player_y, int player_x, int player_active_pwrup)
{
    pShooterList current = this->shooterlist;
    int firespeed = 0, projectile_placement = 0;

    while(current != NULL)
    {
        if(CollisionDetector::distance( (current->shooter).getpos_x(), player_x ) <= SHOOTER_RANGE &&
           (current->shooter).getpos_y() == player_y &&
           (current->shooter).getfirespeed() == 0 &&
           player_active_pwrup != VANISHER )
        {
            if( (current->shooter).getdirection() == RIGHT ) projectile_placement = (current->shooter).getpos_x()+1;
            else if( (current->shooter).getdirection() == LEFT ) projectile_placement = (current->shooter).getpos_x()-1;
            
            plm.addprojectile( (current->shooter).getactiveproj(), (current->shooter).shoot(), (current->shooter).getpos_y(), projectile_placement, (current->shooter).getdirection() );
        }

        (current->shooter).incrfirespeed();
        current = current->next;
    }
};

void ShooterListManager::handle_projectile_collision(ProjectileListManager &plm, int &points, int &points_buffer)
{
    pShooterList current_shr = this->shooterlist;

    while(current_shr != NULL)
    {
        if(plm.findprojectile((current_shr->shooter).getpos_y(), (current_shr->shooter).getpos_x()) != NULL)
        {
            pProjectileList current_prj = plm.findprojectile((current_shr->shooter).getpos_y(), (current_shr->shooter).getpos_x());
            (current_shr->shooter).takedamage((current_prj->projectile).getdamage());
            plm.removeprojectile(current_prj);
        }
        if(plm.findprojectile((current_shr->shooter).getpos_y(), (current_shr->shooter).getpos_x()+1) != NULL)
        {
            pProjectileList current_prj = plm.findprojectile((current_shr->shooter).getpos_y(), (current_shr->shooter).getpos_x()+1);
            (current_shr->shooter).takedamage((current_prj->projectile).getdamage());
            plm.removeprojectile(current_prj);
        }
        if(plm.findprojectile((current_shr->shooter).getpos_y(), (current_shr->shooter).getpos_x()-1) != NULL)
        {
            pProjectileList current_prj = plm.findprojectile((current_shr->shooter).getpos_y(), (current_shr->shooter).getpos_x()-1);
            (current_shr->shooter).takedamage((current_prj->projectile).getdamage());
            plm.removeprojectile(current_prj);
        }

        if( (current_shr->shooter).gethealth() <= 0 )
        {
            pShooterList todelete = current_shr;
            current_shr = current_shr->next;
            this->removeshooter(todelete);
            points++;
            points_buffer++;
        }
        else current_shr = current_shr->next;
    }
};

void ShooterListManager::handle_forcefield(int player_y, int player_x, chtype player_active_pwrup, int &points, int &points_buffer)
{
    pShooterList current = this->shooterlist;

    while(current != NULL)
    {
        if( player_active_pwrup == FORCEFIELD && (current->shooter).getpos_y() == player_y && CollisionDetector::distance( (current->shooter).getpos_x(), player_x ) <= FORCEFIELD_RANGE )
        {
            pShooterList todelete = current;
            current = current->next;
            this->removeshooter(todelete);

            points++;
            points_buffer++;
        }
        else current = current->next;
    }
};

void ShooterListManager::placefixedqty(int q)
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

        this->addshooter(random_y, random_x, random_dir);
    }
};

int ShooterListManager::getqty()
{
    return this->qty;
};