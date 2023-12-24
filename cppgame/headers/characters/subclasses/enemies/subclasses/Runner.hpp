#ifndef RUNNER_HPP
#define RUNNER_HPP

#include <ncurses.h>
#include "Enemy.hpp"

/*                                                                                      
                                                                                            BEHAVIOR OF THIS ENEMY
    The Runner spawns randomly at either edge of the map and runs in only one direction, right or left (it can't jump), careless of the position of the Player. If it hits the Player, it gets eliminated
    while the Player takes some damage.
*/

class Runner: public Enemy
{
    public:

        Runner();
        Runner(int y, int x);
};

#endif