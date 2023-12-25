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

void Player::jump()
{
    // TODO
};

chtype Player::shoot()
{
    return this->active_projectile;
};