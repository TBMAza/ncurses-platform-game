#ifndef FOLLOWER_HPP
#define FOLLOWER_HPP

#include <ncurses.h>
#include "Enemy.hpp"

/*                                                           
                                                            BEHAVIOR OF THIS ENEMY
    The Follower actively chases the player. If it comes in direct contact with the player, it gets eliminated, while the player takes some damage.
*/

class Follower: public Enemy
{
    public:

        Follower();
        Follower(int y, int x, short dir);

        void chase(int player_x); // algorithm to chase the player given his position through y, x coordinates
        void jump();
};

#endif