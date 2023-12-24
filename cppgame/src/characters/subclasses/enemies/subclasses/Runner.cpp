#include "Runner.hpp"

Runner::Runner()
{
    Character::init(NULLCHR, NULLHLT, NULLPOS, NULLPOS, NULLDIR, NULLDMG);
};

Runner::Runner(int y, int x)
{
    Character::init(RUNNER, ENEMY_INIT_HLT, y, x, LEFT, RUNNER_DMG);
};

void Runner::changedir()
{
    if(this->direction == RIGHT) this->direction = LEFT;
    else if(this->direction == LEFT) this->direction = RIGHT;
};
