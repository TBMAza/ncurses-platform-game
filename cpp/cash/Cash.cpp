#include "../../headers/cash/Cash.hpp"

Cash::Cash()
{
    this->aspect = CASH;
    this->pos_y = NULLPOS;
    this->pos_x = NULLPOS;
};

void Cash::setposition(int y, int x)
{
    this->pos_y = y;
    this->pos_x = x;
};

chtype Cash::getaspect()
{
    return this->aspect;
};

int Cash::getpos_y()
{
    return this->pos_y;
};

int Cash::getpos_x()
{
    return this->pos_x;
};