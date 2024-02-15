#include "../../../../../headers/characters/subclasses/enemies/subclasses/Runner.hpp"

Runner::Runner()
{
    Character::init(RUNNER, ENEMY_INIT_HLT, NULLPOS, NULLPOS, NULLDIR, RUNNER_DMG);
};

void Runner::changedir()
{
    if(this->direction == RIGHT) this->direction = LEFT;
    else if(this->direction == LEFT) this->direction = RIGHT;
};

void Runner::roam()
{
    if(CollisionDetector::downright(this->pos_y, this->pos_x) != FLOOR || CollisionDetector::downleft(this->pos_y, this->pos_x) != FLOOR ||
       this->pos_x < PLAYER_INIT_POS_X || this->pos_x > MAX_PLAYABLE_X-1)
    {
        this->changedir();
    }
    if(this->direction == RIGHT) Character::mvright();
    if(this->direction == LEFT) Character::mvleft();
}