#include "../../headers/collision_detector/CollisionDetector.hpp"

chtype CollisionDetector::retrieve(int y, int x)
{
    move(y, x);
    chtype element = inch();
    return element;
};

chtype CollisionDetector::above(int y, int x)
{
    return CollisionDetector::retrieve(y-1, x);
};

chtype CollisionDetector::below(int y, int x)
{
    return CollisionDetector::retrieve(y+1, x);
};

chtype CollisionDetector::toright(int y, int x)
{
    return CollisionDetector::retrieve(y, x+1);
};

chtype CollisionDetector::toleft(int y, int x)
{
    return CollisionDetector::retrieve(y, x-1);
};

chtype CollisionDetector::downright(int y, int x)
{
    return CollisionDetector::retrieve(y+1, x+1);
};

chtype CollisionDetector::downleft(int y, int x)
{
    return CollisionDetector::retrieve(y+1, x-1);
};

bool CollisionDetector::totalcollision(int y0, int x0, int y1, int x1)
{
    if(y0 == y1 && x0 == x1) return true;
    return false;
};

bool CollisionDetector::isempty(int y, int x)
{
    if(CollisionDetector::retrieve(y, x) == ' ') return true;
    return false;
};

int CollisionDetector::distance(int p0, int p1)
{
    return abs(p0 - p1);
}