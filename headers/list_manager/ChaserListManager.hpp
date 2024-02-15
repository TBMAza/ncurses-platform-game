#ifndef CHASERLISTMANAGER_HPP
#define CHASERLISTMANAGER_HPP

#include "../characters/subclasses/enemies/subclasses/Chaser.hpp"
#include "../collision_detector/CollisionDetector.hpp"
#include "../random_generator/RandomGenerator.hpp"
#include "ProjectileListManager.hpp"
#include "../filereader/FileReader.hpp"

struct ChaserList
{
    Chaser chaser;
    ChaserList *next;
};
typedef ChaserList* pChaserList;

class ChaserListManager
{
    private:

        pChaserList chaserlist;
        int qty;
    
    public:

        ChaserListManager();
        
        void addchaser(int y, int x);
        void placeallchasers(int playerlevel);
        pChaserList findchaser(int y, int x);
        void removechaser(pChaserList todelete);
        void displaychaser();
        void deleteallchasers();
        void movechasers(int player_x, int player_active_pwrup);
        void handle_projectile_collision(ProjectileListManager &plm, int &points, int &points_buffer);
        void handle_forcefield(int player_y, int player_x, chtype player_active_pwrup, int &points, int &points_buffer);
        void placefixedqty(int q);

        int getqty();
};

#endif