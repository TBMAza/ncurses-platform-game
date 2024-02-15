#ifndef FOLLOWER_HPP
#define FOLLOWER_HPP

#include "../Enemy.hpp"
#include "../../../../collision_detector/CollisionDetector.hpp"

/*                                                           
                                                            BEHAVIOR OF THIS ENEMY
    The Follower actively chases the player. If it comes in direct contact with the player, it gets eliminated, while the player takes some damage.
*/

class Follower: public Enemy
{
    protected:

        int jumpstate;
        int jumpforce;
        int jumpdirection;
        int fallstate;
        int speed;
    
    public:

        Follower();

        void setdir(int dir);
        
        void setjumpstate(int js);
        void resetjumpstate();
        void setfallstate(int fs);

        void chase(int player_x); // algorithm to chase the player given his position through y, x coordinates
        void jump();
        void fall();
};

#endif