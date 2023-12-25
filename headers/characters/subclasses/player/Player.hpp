#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <ncurses.h>
#include "../../Character.hpp"

class Player: public Character
{
    private:

        int cash;
        chtype active_powerup; // power-up currently used by the Player
        chtype active_projectile; // projectile class currently used by the Player
        int forcefield_qty, invisibility_qty; // quantity of forcefield and invisibility power-ups available in Player's inventory
    
    public:

        Player();

        void init();

        int getcash(); // returns the amount of cash currently owned by the player
        chtype getactivepowerup();
        chtype getactiveproj();
        int getffqty(); // returns the amount of forcefield power-ups owned by the Player

        void setaspect(chtype asp);
        void incrcash(); // increments the amount of cash by 1 when the Player collects it in the map
        void setpowerup(chtype pwrup); // sets the active power-up
        void setproj(chtype proj); // sets the active projectile, i.e. the projectile class that the player can currently use
        void incrforcefield(); // increments the amount of forcefield power-ups in the Player's inventory
        void incrinv(); // increments the amount of invisibility power-ups in the Player's inventory
        
        void jump();
        chtype shoot(); // returns the active projectile; the damage that a character takes if hit by this shot will be calculated based on the projectile class, as all the classes of projectiles are mapped to their respective damage values in the constants.hpp file
};

#endif