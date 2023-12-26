#ifndef COLLISIONDETECTOR_HPP
#define COLLISIONDETECTOR_HPP

#include <ncurses.h>
#include <math.h>
#include "constants.hpp"

class CollisionDetector
{
    public:

        static chtype retrieve(int y, int x);
        static int nextfloor(int y, int x);
        static int distance(int p0, int p1);
};

#endif