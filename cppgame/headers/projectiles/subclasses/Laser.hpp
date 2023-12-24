#ifndef LASER_HPP
#define LASER_HPP

#include <ncurses.h>
#include "Projectile.hpp"

class Laser: private Projectile
{
    public:

        Laser(int y, int x, short dir);
};

#endif