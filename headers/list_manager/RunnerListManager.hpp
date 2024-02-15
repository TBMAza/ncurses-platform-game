#ifndef RUNNERLISTMANAGER_HPP
#define RUNNERLISTMANAGER_HPP

#include "../characters/subclasses/enemies/subclasses/Runner.hpp"
#include "../collision_detector/CollisionDetector.hpp"
#include "../random_generator/RandomGenerator.hpp"
#include "ProjectileListManager.hpp"
#include "../filereader/FileReader.hpp"

struct RunnerList
{
    Runner runner;
    RunnerList *next;
};
typedef RunnerList* pRunnerList;

class RunnerListManager
{
    private:

        pRunnerList runnerlist;
        int qty;
        int levelbuffer;
    
    public:

        RunnerListManager();

        void addrunner(int y, int x, int dir);
        void placeallrunners(int playerlevel);
        pRunnerList findrunner(int y, int x);
        void removerunner(pRunnerList todelete);
        void displayrunner();
        void deleteallrunners();
        void moverunners(int player_x, chtype player_active_pwrup);
        void handle_projectile_collision(ProjectileListManager &plm, int &points, int &points_buffer);
        void handle_forcefield(int player_y, int player_x, chtype player_active_pwrup, int &points, int &points_buffer);
        void placefixedqty(int q);

        int getqty();
};

#endif