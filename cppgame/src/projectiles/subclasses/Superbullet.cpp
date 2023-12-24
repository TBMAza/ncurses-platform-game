#include "Superbullet.hpp"

Superbullet::Superbullet(int y, int x, short dir)
{
    Projectile::init(SUPERBULLET, SUPERBULLET_DMG, y, x, dir);
};