#ifndef CHASER_HPP
#define CHASER_HPP

#include "Follower.hpp"

/*                                                           
                                                       BEHAVIOR OF THIS ENEMY
    The Chaser actively chases the Player. If it comes in direct contact with the Player, both the Chaser and the Player get eliminated.
*/

class Chaser: public Follower
{
    public:

        Chaser();
};

#endif