#include "Runner.hpp"

Runner::Runner()
{
    Character::init(NULLCHR, NULLHLT, NULLPOS, NULLPOS, NULLDIR, NULLDMG);
};

Runner::Runner(int y, int x)
{
    Character::init(RUNNER, ENEMY_INIT_HLT, y, x, LEFT, RUNNER_DMG);
}