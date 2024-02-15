#include "../../../../headers/characters/subclasses/player/Player.hpp"

Player::Player()
{
    Character::init(PLAYER_DEFAULT_FORM, PLAYER_INIT_HLT, PLAYER_INIT_POS_Y, PLAYER_INIT_POS_X, PLAYER_INIT_DIR, PLAYER_DMG);
    this->init();
};

void Player::init()
{
    this->cash = PLAYER_INIT_CASH;

    this->active_projectile = BULLET_RIGHT;
    
    this->active_powerup = PLAYER_DEFAULT_FORM;
    
    this->jumpstate = NOT_JUMPING;
    this->fallstate = NOT_FALLING;
    this->jumpforce = MAX_JUMPFORCE;
    this->jumpdirection = UP;
};

chtype Player::getactivepowerup()
{
    return active_powerup;
};

chtype Player::getactiveproj()
{
    return active_projectile;
};

int Player::getjumpstate()
{
    return this->jumpstate;
}

int Player::getjumpdir()
{
    return this->jumpdirection;
};

int Player::getfallstate()
{
    return this->fallstate;
};

void Player::incrhealth()
{
    (this->health)++;
}

void Player::setaspect(chtype asp)
{
    this->aspect = asp;
};

void Player::setpowerup(chtype pwrup)
{
    this->active_powerup = pwrup;
};

void Player::setproj(chtype proj)
{
    this->active_projectile = proj;
};

void Player::setjumpstate(int js)
{
    this->jumpstate = js;
};

void Player::resetjumpstate()
{
    this->jumpstate = NOT_JUMPING;
    this->jumpforce = MAX_JUMPFORCE;
    this->jumpdirection = UP;
};

void Player::setfallstate(int fs)
{
    this->fallstate = fs;
};

void Player::jump()
{
    if(CollisionDetector::above(this->pos_y, this->pos_x) == FLOOR) this->resetjumpstate();

    if(this->jumpstate == JUMPING && this->fallstate == NOT_FALLING)
    {
        if(this->jumpforce < 0) this->jumpdirection = DOWN;
        this->pos_y -= GRAVITY * this->jumpdirection;
        this->jumpforce -= GRAVITY;
        
        if(CollisionDetector::below(this->pos_y, this->pos_x) == FLOOR)
        {
            this->resetjumpstate(); // jump stops if player lands on a floor block or if the jump would make him go through a floating block
        }
    }
};

void Player::fall()
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

int Player::shoot()
{
    if(this->active_projectile == BULLET_RIGHT || this->active_projectile == BULLET_LEFT) return BULLET_DMG;
    else if(this->active_projectile == SUPERBULLET) return SUPERBULLET_DMG;
    else if(this->active_projectile == HYPERBULLET) return HYPERBULLET_DMG;
    else if(this->active_projectile == LASER) return LASER_DMG;
    else return NULLDMG;
};

void Player::restore_health()
{
    this->sethealth(PLAYER_INIT_HLT);
};

void Player::sethealth(int hlt)
{
    this->health = hlt;
};