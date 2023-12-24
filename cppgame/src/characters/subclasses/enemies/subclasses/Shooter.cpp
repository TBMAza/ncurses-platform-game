#include "Shooter.hpp"

Shooter::Shooter(int y, int x, short dir)
{
    Character::init(SHOOTER, ENEMY_INIT_HLT, y, x, dir, SHOOTER_DMG);
};

int Shooter::shoot()
{
    if(this->active_projectile == BULLET_RIGHT || this->active_projectile == BULLET_LEFT) return BULLET_DMG;
    else if(this->active_projectile == SUPERBULLET) return SUPERBULLET_DMG;
    else if(this->active_projectile == HYPERBULLET) return HYPERBULLET_DMG;
    else if(this->active_projectile == LASER) return LASER_DMG;
    else return NULLDMG;
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
