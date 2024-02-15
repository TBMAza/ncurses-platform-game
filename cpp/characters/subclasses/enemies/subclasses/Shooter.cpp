#include "../../../../../headers/characters/subclasses/enemies/subclasses/Shooter.hpp"

Shooter::Shooter()
{
    Character::init(SHOOTER, ENEMY_INIT_HLT, NULLPOS, NULLPOS, NULLDIR, SHOOTER_DMG);
    this->active_projectile = BULLET_RIGHT;
    this->speed = 0;
    this->firespeed = 0;
};

chtype Shooter::getactiveproj()
{
    return this->active_projectile;
};

int Shooter::getfirespeed()
{
    return this->firespeed;
};

void Shooter::incrfirespeed()
{
    (this->firespeed)++;
    if(this->firespeed > 3) this->firespeed = 0;
}

int Shooter::shoot()
{
    if(this->active_projectile == BULLET_RIGHT || this->active_projectile == BULLET_LEFT) return BULLET_DMG;
    else if(this->active_projectile == SUPERBULLET) return SUPERBULLET_DMG;
    else if(this->active_projectile == HYPERBULLET) return HYPERBULLET_DMG;
    else if(this->active_projectile == LASER) return LASER_DMG;
    else return NULLDMG;
};

void Shooter::reach(int player_x)
{
    if((this->speed == 0 || this->jumpstate == JUMPING)) // the condition regarding the jumping state is for optimizing this enemy's jump: the 'speed' variable limits the horizontal travel per frame, thus making the enemy more vulnerable to falling in pits. this condition unlocks enemy's full horizontal travel distance per frame
    {
        int distance = CollisionDetector::distance(this->pos_x, player_x); // horizontal distance between the Shooter and the Player

        // set direction based on player's position
        if(this->pos_x < player_x) this->direction = RIGHT;
        else if(this->pos_x > player_x) this->direction = LEFT;

        /* specific conditions in which the player could go through the edge of floors or floating blocks if he decides to move right or left
           preventing the player to move left or right when these conditions occur in-game, solves the problem */
        bool ghosting_condition_L = (this->pos_y < PLAYER_INIT_POS_Y &&
                                     this->jumpdirection == DOWN &&
                                     CollisionDetector::below(this->pos_y, this->pos_x) != FLOOR &&
                                     CollisionDetector::downleft(this->pos_y, this->pos_x) == FLOOR);
    
        bool ghosting_condition_R = (this->pos_y < PLAYER_INIT_POS_Y &&
                                     this->jumpdirection == DOWN &&
                                     CollisionDetector::below(this->pos_y, this->pos_x) != FLOOR &&
                                     CollisionDetector::downright(this->pos_y, this->pos_x) == FLOOR);
        
        if(distance > SHOOTER_RANGE && this->direction == RIGHT && this->pos_x < MAX_PLAYABLE_X+1 && !ghosting_condition_R)
        {
            Character::mvright();
        }
        else if(distance > SHOOTER_RANGE && this->direction == LEFT && this->pos_x > PLAYER_INIT_POS_X && !ghosting_condition_L)
        {
            Character::mvleft();
        }
    }

    this->speed += 1;
    if(this->speed == 2) this->speed = 0;
};

void Shooter::setactiveproj(chtype proj)
{
    this->active_projectile = proj;
}