#include <ncurses.h>

int main()
{
    initscr();
    raw();
    noecho();
    curs_set(0);
    keypad(stdscr, true);

    box(stdscr, 0, 0);

    getch();
    endwin();
}