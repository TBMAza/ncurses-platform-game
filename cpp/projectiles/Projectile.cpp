#include "../../headers/projectiles/Projectile.hpp"

Projectile::Projectile()
{
    init(NULLPRJ, NULLDMG, NULLPOS, NULLPOS, NULLDIR);
};

void Projectile::init(chtype asp, int dmg, int y, int x, int dir)
{
    
    if(asp == BULLET_RIGHT && dir == LEFT) this->aspect = BULLET_LEFT;
    else this->aspect = asp;
    
    this->damage = dmg;
    this->pos_y = y;
    this->pos_x = x;
    this->direction = dir;
    this->range = PROJRANGE;
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

int Projectile::getdirection()
{
    return this->direction;
};

void Projectile::travel()
{
    if(this->direction == RIGHT) (this->pos_x)++;
    else if(this->direction == LEFT) (this->pos_x)--;
    (this->range)--;
};

int Projectile::getrange()
{
    return this->range;
};

void Projectile::decr_range()
{
    (this->range)--;
};