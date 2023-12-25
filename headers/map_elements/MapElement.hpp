#ifndef MAPELEMENT_HPP
#define MAPELEMENT_HPP

#include <ncurses.h>
#include "../../constants.hpp"

/*
    Superclass for all the elements that charachterize the game maps
*/

class MapElement
{
    protected:

        chtype aspect;
        int pos_y, pos_x;
    
    public:

        MapElement();
        MapElement(chtype asp, int y, int x);

        void init(chtype asp, int y, int x);
        
        chtype getaspect();

        int getpos_y();
        int getpos_x();
};

#endif