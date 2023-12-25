#ifndef BULLET_HPP
#define BULLET_HPP

#include <ncurses.h>
#include "../Projectile.hpp"

class Bullet: private Projectile
{
    public:

        Bullet(int y, int x, short dir);
};

#endif