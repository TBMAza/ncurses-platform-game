#include "../../../../../headers/characters/subclasses/enemies/subclasses/Charger.hpp"

Charger::Charger(int y, int x)
{
    Character::init(CHARGER, ENEMY_INIT_HLT, y, x, LEFT, CHARGER_DMG);
};