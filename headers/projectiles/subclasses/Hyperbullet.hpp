#ifndef HYPERBULLET_HPP
#define HYPERBULLET_HPP

#include "../Projectile.hpp"

class Hyperbullet: private Projectile
{
    public:

        Hyperbullet(int y, int x, short dir);
};

#endif