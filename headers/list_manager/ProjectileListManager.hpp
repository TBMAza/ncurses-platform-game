#ifndef PROJECTILELISTMANAGER_HPP
#define PROJECTILELISTMANAGER_HPP

#include "../projectiles/Projectile.hpp"
#include "../filereader/FileReader.hpp"
#include "../collision_detector/CollisionDetector.hpp"

struct ProjectileList
{
    Projectile projectile;
    ProjectileList *next;
};
typedef ProjectileList* pProjectileList;

class ProjectileListManager
{
    private:

        pProjectileList projectilelist;
    
    public:

        ProjectileListManager();

        void addprojectile(chtype asp, int dmg, int y, int x, int dir);
        pProjectileList findprojectile(int y, int x);
        void removeprojectile(pProjectileList todelete);
        void displayprojectile();
        void deleteallprojectiles();
        void moveprojectile();
};

#endif