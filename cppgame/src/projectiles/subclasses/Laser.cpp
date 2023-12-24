#include "Laser.hpp"

Laser::Laser(int y, int x, short dir)
{
    Projectile::init(LASER, LASER_DMG, y, x, dir);
};