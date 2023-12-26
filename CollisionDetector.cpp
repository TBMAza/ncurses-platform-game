#include "CollisionDetector.hpp"

chtype CollisionDetector::retrieve(int y, int x)
{
    move(y, x);
    chtype element = inch();
    return element;
};

int CollisionDetector::nextfloor(int y, int x)
{
    int max_y = getmaxy(stdscr);

    for(int i = y; i < max_y; i++)
    {
        if(CollisionDetector::retrieve(i, x) == FLOOR) return i+1;
    }

    return -1;
};

int CollisionDetector::distance(int p0, int p1)
{
    return abs(p0 - p1);
}