#include "Projectile.hpp"

Projectile::Projectile()
{
    init(NULLPRJ, NULLDMG, NULLPOS, NULLPOS, NULLDIR);
};

Projectile::Projectile(chtype asp, int dmg, int y, int x, short dir)
{
    init(asp, dmg, y, x, dir);
};

void Projectile::init(chtype asp, int dmg, int y, int x, short dir)
{
    this->aspect = asp;
    this->damage = dmg;
    this->pos_y = y;
    this->pos_x = x;
    this->direction = dir;
};

chtype Projectile::getaspect()
{
    return this->aspect;
};

int Projectile::getpos_y()
{
    return this->pos_y;
};

int Projectile::getpos_x()
{
    return this->pos_x;
};

int Projectile::getdamage()
{
    return this->damage;
};