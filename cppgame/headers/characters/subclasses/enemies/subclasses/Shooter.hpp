#ifndef SHOOTER_HPP
#define SHOOTER_HPP

#include <ncurses.h>
#include <math.h>
#include "Enemy.hpp"

/*
                                                                                            BEHAVIOR OF THIS ENEMY
    The Shoother is the only class of enemies that can shoot. It can track the Player and will move towards him until it reaches the 'range' value, i.e. the minimum distance from the Player at which
    the Shooter is able to shoot him. The Shooter can use the same classes of projectiles available to the Player; the higher the game level, the more powerful the projectile class employed by the Shooter.
    If the Player and the Shooter come in direct contact, the Player takes some damage and the Shooter gets eliminated.
*/

class Shooter: public Enemy
{
    private:

        chtype active_projectile;
    
    public:

        Shooter(int y, int x, short dir);

        int shoot();
        
        void jump();
        void reach(int player_x); // algorithm to move towards the Player till it reaches its range (min. distance at which it can shoot the Player)
};

#endif