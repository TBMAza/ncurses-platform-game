#ifndef GAME_HPP
#define GAME_HPP

#include <ncurses.h>
#include <iostream>
#include <unistd.h>
#include <string>
#include <cstdlib>

#include "constants.hpp"

#include "headers/collision_detector/CollisionDetector.hpp"
#include "headers/map/Map.hpp"
#include "headers/cash/Cash.hpp"

#include "headers/list_manager/CashListManager.hpp"
#include "headers/list_manager/ProjectileListManager.hpp"
#include "headers/list_manager/RunnerListManager.hpp"
#include "headers/list_manager/ChargerListManager.hpp"
#include "headers/list_manager/FollowerListManager.hpp"
#include "headers/list_manager/ChaserListManager.hpp"
#include "headers/list_manager/ShooterListManager.hpp"

#include "headers/characters/subclasses/enemies/subclasses/Runner.hpp"
#include "headers/characters/subclasses/enemies/subclasses/Charger.hpp"
#include "headers/characters/subclasses/enemies/subclasses/Follower.hpp"
#include "headers/characters/subclasses/enemies/subclasses/Chaser.hpp"
#include "headers/characters/subclasses/enemies/subclasses/Shooter.hpp"
#include "headers/filereader/FileReader.hpp"

#include "headers/characters/subclasses/player/Player.hpp"

struct PlayerStats
{
    int level,
        points,
        cash,
        forcefield_qty,
        vanisher_qty;
    bool superbullet_unlocked,
         hyperbullet_unlocked,
         laser_unlocked;
};

struct EnemyListManager
{
    RunnerListManager runners;
    ChargerListManager chargers;
    FollowerListManager followers;
    ChaserListManager chasers;
    ShooterListManager shooters;
};

class Game
{
    private:

        Player player;
        PlayerStats player_stats;
        
        CashListManager cash_list_manager;
        ProjectileListManager projectile_list_manager;
        EnemyListManager enemy_list_manager;

        bool gen_newmap;
        chtype **currentmap;
        
        bool inmainmenu;
        bool inmarket;
        bool in_pausemenu;
        bool in_gameover_menu;
        bool gameover;
        bool restored;
        bool entered;

        std::string gameover_message;
        std::string messagebox;
        int messagebox_timer;
        int points_buffer;
    
    public:

        Game();

        void main_menu();
        void pause_menu();
        void gameover_menu(); // TODO
        void market();
        
        void start();
        void clear_dynamic_memory(); // deletes all the in-game elements present in the map managed by linked lists, i.e. cash, projectiles, enemies
        //void loadstate();
        
        void newmap();
        
        void render_player();
        void resetplayer();
        void render_dynamic_healthbar();
        void render_stats();
        
        void render_enemies();
        
        void render();

        void handle_input();
        void handle_enemy_behavior();
        void handle_collisions();
        void handle_market_selection(int sel);
        void handle_gameover();
        void handle_mainmenu_selection(int sel);
        void handle_pausemenu_selection(int sel);
        void handle_gameovermenu_selection(int sel);
        
        void gameover_sendmessage();
        void send_to_messagebox(std::string message);
        void display_messagebox();

        void apply_gravity_on_player();

        void levelup();

        void save();
        void load_saved_game();

        void resetstats();

};

#endif