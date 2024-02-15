#include "../../headers/random_generator/RandomGenerator.hpp"

int RandomGenerator::generate(int lbound, int ubound)
{
    return rand() % (ubound - lbound + 1) + lbound;
};