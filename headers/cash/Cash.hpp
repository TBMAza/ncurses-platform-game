#ifndef CASH_HPP
#define CASH_HPP

#include "../../constants.hpp"
#include "../random_generator/RandomGenerator.hpp"

class Cash
{
    private:

        chtype aspect;
        int pos_y;
        int pos_x;
    
    public:

        Cash();
        
        void setposition(int y, int x);
        
        chtype getaspect();
        int getpos_y();
        int getpos_x();
};

#endif