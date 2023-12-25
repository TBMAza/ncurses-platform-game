#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <ncurses.h>
#include "../../constants.hpp"

/*
    Superclass for all playing characters
*/

class Character
{
    protected:
    
        chtype aspect;
        int health;
        int pos_y, pos_x;
        short direction; // tells if the character is moving towards right or left
        int damage_at_contact; // damage inflicted to opponents when they come in contact
    
    public:

        Character();
        Character(chtype asp, int hlt, int y, int x, short dir, int dac);

        void init(chtype asp, int hlt, int y, int x, short dir, int dac);

        chtype getaspect();

        int getpos_y();
        int getpos_x();
        int gethealth();
        short getdirection();
        int getdac(); // return the value of the damage at contact dealt by the Character
        
        void mvright();
        void mvleft();
        
        void takedamage(int damage);
};

#endif