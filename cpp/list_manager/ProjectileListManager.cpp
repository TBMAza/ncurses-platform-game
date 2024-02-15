#include "../../headers/list_manager/ProjectileListManager.hpp"

ProjectileListManager::ProjectileListManager()
{
    this->projectilelist = NULL;
};

void ProjectileListManager::addprojectile(chtype asp, int dmg, int y, int x, int dir)
{
    pProjectileList newprojectile = new ProjectileList;
    (newprojectile->projectile).init(asp, dmg, y, x, dir);

    newprojectile->next = this->projectilelist;
    this->projectilelist = newprojectile;
};

pProjectileList ProjectileListManager::findprojectile(int y, int x)
{
    pProjectileList current = this->projectilelist;

    bool found = false;
    while(!found && current != NULL)
    {
        if( (current->projectile).getpos_y() == y && (current->projectile).getpos_x() == x )
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

void ProjectileListManager::removeprojectile(pProjectileList todelete)
{
    pProjectileList current = this->projectilelist;
    
    bool removed = false;
    while(!removed)
    {
        if(this->projectilelist == todelete)
        {
            this->projectilelist = (this->projectilelist)->next;
            delete todelete;
            todelete = NULL;
            removed = true;
        }
        else if(current->next == todelete)
        {
            current->next = todelete->next;
            delete todelete;
            todelete = NULL;
            removed = true;
        }
        else
        {
            current = current->next;
        }
        
    }
};

void ProjectileListManager::displayprojectile()
{
    pProjectileList current = this->projectilelist;

    while(current != NULL)
    {
        if( (current->projectile).getaspect() == LASER ) attron(COLOR_PAIR(4));
        else attron(COLOR_PAIR(6));

        mvaddch((current->projectile).getpos_y(), (current->projectile).getpos_x(), (current->projectile).getaspect());
        
        if( (current->projectile).getaspect() == LASER ) attroff(COLOR_PAIR(4));
        else attroff(COLOR_PAIR(6));
        
        current = current->next;
    }
};

void ProjectileListManager::deleteallprojectiles()
{
    pProjectileList current = this->projectilelist;
    pProjectileList nextnode = NULL;

    while(current != NULL)
    {
        nextnode = current->next;
        delete current;
        current = nextnode;
    }

    this->projectilelist = NULL;
};

void ProjectileListManager::moveprojectile()
{
    pProjectileList current = this->projectilelist;
    bool range_surpassed_R, range_surpassed_L; // conditions to verify if the bullets have traveled the maximum range allowed for them and to remove them upon reaching such limit

    while(current != NULL)
    {
        range_surpassed_R = ( (current->projectile).getdirection() == RIGHT &&
                                CollisionDetector::toright( (current->projectile).getpos_y(), (current->projectile).getpos_x() ) == FLOOR );
        range_surpassed_L = ( (current->projectile).getdirection() == LEFT &&
                                CollisionDetector::toleft( (current->projectile).getpos_y(), (current->projectile).getpos_x() ) == FLOOR );
        
        (current->projectile).travel();
        if( (current->projectile).getpos_x() < PLAYER_INIT_POS_X || (current->projectile).getpos_x() > MAX_PLAYABLE_X || (current->projectile).getrange() < 0 ||
            range_surpassed_R || range_surpassed_L)
        {
            this->removeprojectile(current);
        }
        current = current->next;
    }
};