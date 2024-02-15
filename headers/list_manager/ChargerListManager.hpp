#ifndef CHARGERLISTMANAGER_HPP
#define CHARGERLISTMANAGER_HPP

#include "../characters/subclasses/enemies/subclasses/Charger.hpp"
#include "../collision_detector/CollisionDetector.hpp"
#include "../random_generator/RandomGenerator.hpp"
#include "ProjectileListManager.hpp"
#include "../filereader/FileReader.hpp"

struct ChargerList
{
    Charger charger;
    ChargerList *next;
};
typedef ChargerList* pChargerList;

class ChargerListManager
{
    private:

        pChargerList chargerlist;
        int qty;
    
    public:

        ChargerListManager();

        void addcharger(int y, int x, int dir);
        void placeallchargers(int playerlevel);
        pChargerList findcharger(int y, int x);
        void removecharger(pChargerList todelete);
        void displaycharger();
        void deleteallchargers();
        void movechargers();
        void handle_projectile_collision(ProjectileListManager &plm, int &points, int &points_buffer);
        void handle_forcefield(int player_y, int player_x, chtype player_active_pwrup, int &points, int &points_buffer);
        void placefixedqty(int q);

        int getqty();
};

#endif