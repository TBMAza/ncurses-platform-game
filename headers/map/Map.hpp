#ifndef MAP_HPP
#define MAP_HPP

#include "../../constants.hpp"
#include "../random_generator/RandomGenerator.hpp"
#include "../collision_detector/CollisionDetector.hpp"

class Map
{
    public:

        static void genmap();
        static void buildmap(chtype **map);
        static chtype** savemap();
        
        static void buildfloor();
        
        static void placefloatingblock(int startingpoint, int level);
        
        // default semi-hardcoded configurations for floating blocks; generating them completely randomly made the game freeze, probably due to excessive memory usage
        static void fb_config_1();
        static void fb_config_2();
        static void fb_config_3();
        static void fb_config_4();
        static void fb_config_5();
        static void fb_config_6();

        static void buildfloatingblocks();
        
        static void placepits();

        static void freemap(chtype** arr);
};

#endif