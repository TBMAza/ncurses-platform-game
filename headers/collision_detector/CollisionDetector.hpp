#ifndef COLLISIONDETECTOR_HPP
#define COLLISIONDETECTOR_HPP

#include <math.h>
#include "../../constants.hpp"

class CollisionDetector
{
    public:

        static chtype retrieve(int y, int x); // returns the type of block placed in the y, x coordinates taken in input
        
        static chtype above(int y, int x); // returns the type of block places above the coordinates given in input; example use case: CollisionDetector::above(y, x); y, x being the current coordinates of the player, the method will return what type of block is one space above the player
        static chtype below(int y, int x); // works same as the previous method, but the check is done below the given coordinates
        static chtype toright(int y, int x); // works same as the previous methods, but the check is done below the given coordinates
        static chtype toleft(int y, int x); // works same as the previous methods, but the check is done below the given coordinates
        static chtype downright(int y, int x);
        static chtype downleft(int y, int x);

        static bool totalcollision(int y0, int x0, int y1, int x1);
        static bool isempty(int y, int x);
        
        static int distance(int p0, int p1);
};

#endif