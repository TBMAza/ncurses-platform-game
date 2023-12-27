#include "CollisionDetector.hpp"

chtype CollisionDetector::retrieve(int y, int x)
{
    move(y, x);
    chtype element = inch();
    return element;
};

int CollisionDetector::distance(int p0, int p1)
{
    return abs(p0 - p1);
}