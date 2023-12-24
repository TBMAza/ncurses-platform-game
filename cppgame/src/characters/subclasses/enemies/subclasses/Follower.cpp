#include "Follower.hpp"

Follower::Follower()
{
    Character::init(NULLCHR, NULLHLT, NULLPOS, NULLPOS, NULLDIR, NULLDMG);
};

Follower::Follower(int y, int x, short dir)
{
    Character::init(FOLLOWER, ENEMY_INIT_HLT, y, x, dir, FOLLOWER_DMG);
};

void Follower::chase(int player_x)
{
    if(this->pos_x < player_x) Character::mvright();
    else if(this->pos_x > player_x) Character::mvleft();
};

void Follower::jump()
{
    // TODO
};
