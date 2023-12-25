#ifndef CASH_HPP
#define CASH_HPP

#include <ncurses.h>
#include "../MapElement.hpp"

class Cash: private MapElement
{
    public:

        Cash(int y, int x);
};

#endif