#include "RandomGenerator.hpp"

int RandomGenerator::generate(int lbound, int ubound)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<>distrib(lbound, ubound);

    return distrib(gen);
};