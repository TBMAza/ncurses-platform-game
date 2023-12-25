#include "../../../../../headers/characters/subclasses/enemies/subclasses/Shooter.hpp"

Shooter::Shooter(int y, int x, short dir)
{
    Character::init(SHOOTER, ENEMY_INIT_HLT, y, x, dir, SHOOTER_DMG);
};

chtype Shooter::shoot()
{
    return this->active_projectile;
};

void Shooter::jump()
{
    // TODO
};

void Shooter::reach(int player_x)
{
    int distance = abs( (this->pos_x) - player_x ); // distance between the Shooter and the Player
    
    if(distance > SHOOTER_RANGE && this->pos_x < player_x) Character::mvright();
    else if(distance > SHOOTER_RANGE && this->pos_x > player_x) Character::mvleft();
};