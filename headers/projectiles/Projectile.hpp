#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP

#include <ncurses.h>
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
        short direction; // tells if the projectile is moving towards right or left
    
    public:

        Projectile();
        Projectile(chtype asp, int dmg, int y, int x, short dir);

        void init(chtype asp, int dmg, int y, int x, short dir);
        
        chtype getaspect();

        int getpos_y();
        int getpos_x();

        int getdamage();
};

#endif