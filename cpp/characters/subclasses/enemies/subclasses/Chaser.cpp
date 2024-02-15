#include "../../../../../headers/characters/subclasses/enemies/subclasses/Chaser.hpp"

Chaser::Chaser()
{
    Character::init(FOLLOWER, SUPER_ENEMY_INIT_HLT, NULLPOS, NULLPOS, NULLDIR, CHASER_DMG);
    this->jumpstate = NOT_JUMPING;
    this->jumpforce = MAX_JUMPFORCE;
    this->jumpdirection = UP;
    this->fallstate = NOT_FALLING;
    this->speed = 0;
};