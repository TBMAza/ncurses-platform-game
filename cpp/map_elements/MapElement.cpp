#include "../../headers/map_elements/MapElement.hpp"

MapElement::MapElement()
{
    init(NULLMAP, NULLPOS, NULLPOS);
};

MapElement::MapElement(chtype asp, int y, int x)
{
    init(asp, y, x);
};

void MapElement::init(chtype asp, int y, int x)
{
    this->aspect = asp;
    this->pos_y = y;
    this->pos_x = x;
};

chtype MapElement::getaspect()
{
    return this->aspect;
};

int MapElement::getpos_y()
{
    return this->pos_y;
};

int MapElement::getpos_x()
{
    return this->pos_x;
};