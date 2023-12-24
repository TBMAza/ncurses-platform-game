#include "Chaser.hpp"

Chaser::Chaser(int y, int x, short dir)
{
    Character::init(CHASER, ENEMY_INIT_HLT, y, x, dir, CHASER_DMG);
};