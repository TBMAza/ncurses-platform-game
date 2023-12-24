#ifndef SUPERBULLET_HPP
#define SUPERBULLET_HPP

#include <ncurses.h>
#include "Projectile.hpp"

class Superbullet: private Projectile
{
    public:

        Superbullet(int y, int x, short dir);
};

#endif