#ifndef FOLLOWERLISTMANAGER_HPP
#define FOLLOWERLISTMANAGER_HPP

#include "../characters/subclasses/enemies/subclasses/Follower.hpp"
#include "../collision_detector/CollisionDetector.hpp"
#include "../random_generator/RandomGenerator.hpp"
#include "ProjectileListManager.hpp"
#include "../filereader/FileReader.hpp"

struct FollowerList
{
    Follower follower;
    FollowerList *next;
};
typedef FollowerList* pFollowerList;

class FollowerListManager
{
    private:

        pFollowerList followerlist;
        int qty;
        int levelbuffer;
    
    public:

        FollowerListManager();
        
        void addfollower(int y, int x);
        void placeallfollowers(int playerlevel);
        pFollowerList findfollower(int y, int x);
        void removefollower(pFollowerList todelete);
        void displayfollower();
        void deleteallfollowers();
        void movefollowers(int player_x, int player_active_pwrup);
        void handle_projectile_collision(ProjectileListManager &plm, int &points, int &points_buffer);
        void handle_forcefield(int player_y, int player_x, chtype player_active_pwrup, int &points, int &points_buffer);
        void placefixedqty(int q);

        int getqty();
};

#endif