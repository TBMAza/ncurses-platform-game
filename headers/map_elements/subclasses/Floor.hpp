#ifndef FLOOR_HPP
#define FLOOR_HPP

#include <ncurses.h>
#include "../MapElement.hpp"

class Floor: private MapElement
{
    public:

        Floor(int y, int x);
};

#endif