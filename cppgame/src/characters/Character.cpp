#include "Character.hpp"

Character::Character()
{
    init(NULLCHR, NULLHLT, NULLPOS, NULLPOS, NULLDIR, NULLDMG);
};

Character::Character(chtype asp, int hlt, int y, int x, short dir, int dac)
{
    init(asp, hlt, y, x, dir, dac);
};

void Character::init(chtype asp, int hlt, int y, int x, short dir, int dac)
{
    this->aspect = asp;
    this->health = hlt;
    this->pos_y = y;
    this->pos_x = x;
    this->direction = dir;
    this->damage_at_contact = dac;
};

chtype Character::getaspect()
{
    return this->aspect;
};

int Character::getpos_y()
{
    return this->pos_y;
};

int Character::getpos_x()
{
    return this->pos_x;
};

int Character::gethealth()
{
    return this->health;
};

short Character::getdirection()
{
    return this->direction;
};

int Character::getdac()
{
    return damage_at_contact;
};

void Character::mvright()
{
    (this->pos_x)++;
};

void Character::mvleft()
{
    (this->pos_x)--;
};

void Character::takedamage(int damage)
{
    (this->health) -= damage;
};