#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include "../../constants.hpp"

/*
    Superclass for all shootable objects
*/

class Projectile
{
    protected:

        chtype aspect;
        int damage; // damage dealt to a character if the projectile hits it
        int pos_y, pos_x;
        int direction; // tells if the projectile is moving towards right or left
        int range;
    
    public:

        Projectile();

        void init(chtype asp, int dmg, int y, int x, int dir);
        
        chtype getaspect();
        int getpos_y();
        int getpos_x();
        int getdirection();
        int getrange();
        int getdamage();

        void decr_range();

        void travel();
};

#endif