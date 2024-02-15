#ifndef SUPERBULLET_HPP
#define SUPERBULLET_HPP

#include "../Projectile.hpp"

class Superbullet: private Projectile
{
    public:

        Superbullet(int y, int x, short dir);
};

#endif