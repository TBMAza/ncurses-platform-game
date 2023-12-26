#include <ncurses.h>
#include <iostream>
#include "constants.hpp"

#include "CollisionDetector.hpp"

#include "headers/map_elements/subclasses/Floor.hpp"
#include "headers/map_elements/subclasses/Cash.hpp"

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

    // Game loop
    while (true) {
        clear();
        box(stdscr, 0, 0);
        
        for(int i = 1; i < getmaxx(stdscr)-1; i++)
        {
            mvaddch(22, i, FLOOR);
        }
        for(int i = 10; i < 20; i++)
        {
            mvaddch(20, i, FLOOR);
        }
        for(int i = 22; i < 30; i++)
        {
            mvaddch(18, i, FLOOR);
        }
        for(int i = 32; i < 40; i++)
        {
            mvaddch(16, i, FLOOR);
        }

        // Draw player
        drawPlayer(player.getpos_x(), player.getpos_y(), player.getaspect());

        // Check for user input
        int ch = getch();
        switch (ch)
        {
            case KEY_LEFT:
                if(player.getpos_x() > 1) player.mvleft();
            break;
            
            case KEY_RIGHT:
                if(player.getpos_x() < 78) player.mvright();
            break;
            
            case SPACEBAR: // Spacebar for jumping
                if (player.getjumpstate() == NOT_JUMPING && player.getfallstate() == NOT_FALLING) {
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

        // Render
        refresh();
    }

    endwin();
    return 0;
}
