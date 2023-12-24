#include "Bullet.hpp"

Bullet::Bullet(int y, int x, short dir)
{
    chtype asp;
    
    if(dir == RIGHT) asp = BULLET_RIGHT;
    else if(dir == LEFT) asp = BULLET_LEFT;
    else asp = NULLPRJ;

    Projectile::init(asp, BULLET_DMG, y, x, dir);
}