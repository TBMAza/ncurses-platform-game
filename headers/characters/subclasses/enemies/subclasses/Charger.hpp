#ifndef CHARGER_HPP
#define CHARGER_HPP

#include "Runner.hpp"

/*                                                                                      
                                                                                        BEHAVIOR OF THIS ENEMY
    The Charger spawns randomly at either edge of the map and runs in only one direction, right or left (it can't jump), careless of the position of the player. If it hits the player, both the Charger
    and the player get eliminated.
*/

class Charger: public Runner
{
    public:

        Charger();
};

#endif