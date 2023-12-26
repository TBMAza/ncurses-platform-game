#include "../../../../headers/characters/subclasses/player/Player.hpp"

Player::Player()
{
    Character::init(PLAYER_DEFAULT_FORM, PLAYER_INIT_HLT, PLAYER_INIT_POS_Y, PLAYER_INIT_POS_X, PLAYER_INIT_DIR, PLAYER_DMG);
    this->init();
};

void Player::init()
{
    this->cash = PLAYER_INIT_CASH;
    this->active_powerup = PLAYER_DEFAULT_FORM;
    this->active_projectile = BULLET_RIGHT;
    this->forcefield_qty = PLAYER_INIT_PWUPS_QTY;
    this->invisibility_qty = PLAYER_INIT_PWUPS_QTY;
    this->jumpstate = NOT_JUMPING;
    this->fallstate = NOT_FALLING;
};

int Player::getcash()
{
    return this->cash;
};

chtype Player::getactivepowerup()
{
    return active_powerup;
};

chtype Player::getactiveproj()
{
    return active_projectile;
};

int Player::getffqty()
{
    return forcefield_qty;
};

short Player::getjumpstate()
{
    return this->jumpstate;
}

short Player::getfallstate()
{
    return this->fallstate;
};

void Player::setaspect(chtype asp)
{
    this->aspect = asp;
};

void Player::incrcash()
{
    (this->cash)++;
};

void Player::setpowerup(chtype pwrup)
{
    this->active_powerup = pwrup;
};

void Player::setproj(chtype proj)
{
    this->active_projectile = proj;
};

void Player::incrforcefield()
{
    (this->forcefield_qty)++;
};

void Player::incrinv()
{
    (this->invisibility_qty)++;
};

void Player::setjumpstate(short js)
{
    this->jumpstate = js;
};

void Player::jump()
{
    if (this->jumpstate == JUMPING)
    {
        static int jumpforce = MAX_JUMPFORCE;
        static int sign = 1;
        
        if(jumpforce < 0) sign = -1;
        this->pos_y -= GRAVITY * sign;
        jumpforce -= GRAVITY;
        
        if (CollisionDetector::retrieve((this->pos_y)+1, this->pos_x) == FLOOR)
        {
            this->jumpstate = NOT_JUMPING;
            jumpforce = MAX_JUMPFORCE;
            sign = 1;
        }
    }
};

void Player::fall()
{
    if(CollisionDetector::retrieve((this->pos_y)+1, this->pos_x) != FLOOR && this->jumpstate == NOT_JUMPING)
    {
        this->fallstate = FALLING;
        this->pos_y += GRAVITY;
    }
    if(this->pos_y >= PLAYER_INIT_POS_Y)
    {
        this->pos_y = PLAYER_INIT_POS_Y;
        this->fallstate = NOT_FALLING;
    }
};

chtype Player::shoot()
{
    return this->active_projectile;
};
