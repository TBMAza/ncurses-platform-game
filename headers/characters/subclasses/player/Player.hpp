#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <math.h>
#include "../../Character.hpp"
#include "../../../collision_detector/CollisionDetector.hpp"

class Player: public Character
{
    private:

        int cash;
        
        chtype active_powerup; // power-up currently used by the Player
        chtype active_projectile; // projectile class currently used by the Player
        
        int jumpstate; // member that keeps track if the player is currently jumping or not
        int jumpforce;
        int jumpdirection;

        int fallstate; // member that keeps track if the player is currently falling or not
    
    public:

        Player();

        void init();

        chtype getactivepowerup();
        chtype getactiveproj();
        int getjumpstate();
        int getjumpdir();
        int getfallstate();

        void setaspect(chtype asp);
        void setpowerup(chtype pwrup); // sets the active power-up
        void setproj(chtype proj); // sets the active projectile, i.e. the projectile class that the player can currently use
        void setjumpstate(int js);
        void setfallstate(int fs);
        void sethealth(int hlt);
        void restore_health();
        
        void incrhealth();
        
        void resetjumpstate();
        
        void jump();
        void fall();
        int shoot(); // returns the active projectile; the damage that a character takes if hit by this shot will be calculated based on the projectile class, as all the classes of projectiles are mapped to their respective damage values in the constants.hpp file
};

#endif