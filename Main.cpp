#include <ncurses.h>
#include "constants.hpp"

#include "headers/map_elements/subclasses/Floor.hpp"
#include "headers/map_elements/subclasses/Cash.hpp"

#include "headers/characters/subclasses/enemies/subclasses/Runner.hpp"
#include "headers/characters/subclasses/enemies/subclasses/Charger.hpp"
#include "headers/characters/subclasses/enemies/subclasses/Follower.hpp"
#include "headers/characters/subclasses/enemies/subclasses/Chaser.hpp"
#include "headers/characters/subclasses/enemies/subclasses/Shooter.hpp"

#include "headers/characters/subclasses/player/Player.hpp"

int main()
{
    initscr();
    raw();
    noecho();
    cbreak();
    curs_set(0);
    
    keypad(stdscr, true);
    box(stdscr, 0, 0);

    for(int i = 1; i < 79; i++)
        {
            mvaddch(22, i, FLOOR);
        }

    Player player;

    while(true)
    {
        refresh();
        
        mvaddch(player.getpos_y(), player.getpos_x(), player.getaspect());
        
        chtype input = getch();
        switch(input)
        {
            case KEY_RIGHT:
                if(player.getpos_x() < 78)
                {
                    mvaddch(player.getpos_y(), player.getpos_x(), EMPTY);
                    player.mvright();
                }
            break;

            case KEY_LEFT:
                if(player.getpos_x() > 1)
                {
                    mvaddch(player.getpos_y(), player.getpos_x(), EMPTY);
                    player.mvleft();
                }
            break;

            default:
        }
    }

    getch();
    endwin();
}