#ifndef SHOOTERLISTMANAGER_HPP
#define SHOOTERLISTMANAGER_HPP

#include "../characters/subclasses/enemies/subclasses/Shooter.hpp"
#include "../collision_detector/CollisionDetector.hpp"
#include "../random_generator/RandomGenerator.hpp"
#include "ProjectileListManager.hpp"
#include "../characters/subclasses/player/Player.hpp"
#include "../filereader/FileReader.hpp"

struct ShooterList
{
    Shooter shooter;
    ShooterList *next;
};
typedef ShooterList* pShooterList;

class ShooterListManager
{
    private:

        pShooterList shooterlist;
        int qty;
        int levelbuffer;
    
    public:

        ShooterListManager();
        
        void addshooter(int y, int x, int playerlevel);
        void placeallshooters(int playerlevel);
        pShooterList findshooter(int y, int x);
        void removeshooter(pShooterList todelete);
        void displayshooter();
        void deleteallshooters();
        void moveshooter(int player_x, chtype player_active_pwrup);
        void let_them_shoot(ProjectileListManager &plm, int player_y, int player_x, int player_active_pwrup);
        void handle_projectile_collision(ProjectileListManager &plm, int &points, int &points_buffer);
        void handle_forcefield(int player_y, int player_x, chtype player_active_pwrup, int &points, int &points_buffer);
        void placefixedqty(int q);

        int getqty();
};

#endif