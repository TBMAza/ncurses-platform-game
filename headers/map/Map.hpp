#ifndef MAP_HPP
#define MAP_HPP

#include <ncurses.h>
#include <vector>
#include "../../constants.hpp"
#include "../../RandomGenerator.hpp"
#include "../../CollisionDetector.hpp"

class Map
{
    public:

        Map();

        static void genmap();
        static void buildmap(std::vector< std::vector<chtype> > map);
        static std::vector< std::vector<chtype> > savemap();
        
        static void buildfloor();
        static void buildfloatingblocks();
        
        static void placepits();
};

#endif