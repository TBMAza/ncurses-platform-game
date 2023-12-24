#include "Hyperbullet.hpp"

Hyperbullet::Hyperbullet(int y, int x, short dir)
{
    Projectile::init(HYPERBULLET, HYPERBULLET_DMG, y, x, dir);
};