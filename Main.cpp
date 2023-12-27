#include <ncurses.h>
#include <iostream>
#include "constants.hpp"

#include "CollisionDetector.hpp"

#include "headers/map_elements/Map.hpp"

#include "headers/characters/subclasses/enemies/subclasses/Runner.hpp"
#include "headers/characters/subclasses/enemies/subclasses/Charger.hpp"
#include "headers/characters/subclasses/enemies/subclasses/Follower.hpp"
#include "headers/characters/subclasses/enemies/subclasses/Chaser.hpp"
#include "headers/characters/subclasses/enemies/subclasses/Shooter.hpp"

#include "headers/characters/subclasses/player/Player.hpp"

void drawPlayer(int x, int y, chtype asp) {
    mvaddch(y, x, asp);
}

int main() {
    // Initialize ncurses
    initscr();
    raw();
    keypad(stdscr, TRUE);
    curs_set(0);
    noecho();

    Player player;
    bool gennewmap = true;
    bool gameover = false;
    std::vector< std::vector<chtype> > currentmap;

    // Game loop
    while (!gameover) {
        
        clear();

        if(gennewmap)
        {
            Map::genmap();
            currentmap = Map::savemap();
            gennewmap = false;
        }

        Map::buildmap(currentmap);
        
        // Draw player
        drawPlayer(player.getpos_x(), player.getpos_y(), player.getaspect());

        // Check for user input
        int ch = getch();
        switch (ch)
        {
            case KEY_LEFT:
                if(player.getpos_x() > 1)
                {
                    player.mvleft();
                }
            break;
            
            case KEY_RIGHT:
                if(player.getpos_x() < 78)
                {
                    player.mvright();
                }
            break;
            
            case SPACEBAR: // Spacebar for jumping
                if (player.getjumpstate() == NOT_JUMPING && player.getfallstate() == NOT_FALLING)
                {
                    player.setjumpstate(JUMPING);
                }
            break;
            
            case 'q': // Quit the game
                endwin();
                return 0;
        }

        // Apply gravity if jumping
        player.jump();
        player.fall();

        if(player.getpos_x() == getmaxx(stdscr)-2)
        {
            player.setposition(PLAYER_INIT_POS_Y, PLAYER_INIT_POS_X);
            player.setfallstate(NOT_FALLING);
            player.setjumpstate(NOT_JUMPING);
            
            gennewmap = true;
        }

        
        if(player.getpos_y() == PLAYER_INIT_POS_Y &&
           CollisionDetector::retrieve(player.getpos_y()+1, player.getpos_x()) == EMPTY)
           {
                gameover = true;
           }
        // Render
        refresh();
    }

    endwin();

    std::cout << "\nGame over\n\n";
    return 0;
}