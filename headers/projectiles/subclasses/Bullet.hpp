#ifndef BULLET_HPP
#define BULLET_HPP

#include "../Projectile.hpp"

class Bullet: private Projectile
{
    public:

        Bullet(int y, int x, short dir);
};

#endif