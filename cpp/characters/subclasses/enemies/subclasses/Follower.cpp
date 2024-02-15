#include "../../../../../headers/characters/subclasses/enemies/subclasses/Follower.hpp"

Follower::Follower()
{
    Character::init(FOLLOWER, ENEMY_INIT_HLT, NULLPOS, NULLPOS, NULLDIR, FOLLOWER_DMG);
    this->jumpstate = NOT_JUMPING;
    this->jumpforce = MAX_JUMPFORCE;
    this->jumpdirection = UP;
    this->fallstate = NOT_FALLING;
    this->speed = 0;
};

void Follower::chase(int player_x)
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
        
        if(distance > 0 && this->direction == RIGHT && this->pos_x < MAX_PLAYABLE_X+1 && !ghosting_condition_R)
        {

            Character::mvright();
        }
        else if(distance > 0 && this->direction == LEFT && this->pos_x > PLAYER_INIT_POS_X && !ghosting_condition_L)
        {
            Character::mvleft();
        }
    }

    this->speed += 1;
    if(this->speed == 2) this->speed = 0;
};

void Follower::setdir(int dir)
{
    this->direction = dir;
}

void Follower::setjumpstate(int js)
{
    this->jumpstate = js;
};

void Follower::resetjumpstate()
{
    this->jumpstate = NOT_JUMPING;
    this->jumpforce = MAX_JUMPFORCE;
    this->jumpdirection = UP;
};

void Follower::setfallstate(int fs)
{
    this->fallstate = fs;
};

void Follower::jump()
{
    if(CollisionDetector::above(this->pos_y, this->pos_x) == FLOOR) this->resetjumpstate();

    if(this->jumpstate == JUMPING)
    {
        if(this->jumpforce < 0) this->jumpdirection = DOWN;
        this->pos_y -= GRAVITY * this->jumpdirection;
        this->jumpforce -= GRAVITY;
        
        if(CollisionDetector::below(this->pos_y, this->pos_x) == FLOOR)
        {
            this->resetjumpstate(); // jump stops if character lands on a floor block or if the jump would make him go through a floating block
        }
    }
};

void Follower::fall()
{
    if(CollisionDetector::below(this->pos_y, this->pos_x) != FLOOR && this->jumpstate == NOT_JUMPING)
    {
        this->fallstate = FALLING;
        this->pos_y += GRAVITY;
    }
    if(CollisionDetector::below(this->pos_y, this->pos_x) == FLOOR)
    {
        this->fallstate = NOT_FALLING;
    }
};