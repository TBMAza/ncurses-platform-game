#include "../../headers/map_elements/Map.hpp"

Map::Map()
{
    //
};

void Map::genmap()
{
    box(stdscr, 0, 0);
    
    Map::buildfloor();
    Map::buildfloatingblocks();
    
    Map::placepits();
};

void Map::buildmap(std::vector< std::vector<chtype> > map)
{
    int maxmapy = getmaxy(stdscr)-2;
    int maxmapx = getmaxx(stdscr)-2;
    
    for(int y = 0; y < maxmapy; y++)
    {
        for(int x = 0; x < maxmapx; x++)
        {
            mvaddch(y+1, x+1, map[y][x]);
        }
    }

    box(stdscr, 0, 0);
};

std::vector< std::vector<chtype> > Map::savemap()
{
    int maxmapy = getmaxy(stdscr)-2;
    int maxmapx = getmaxx(stdscr)-2;

    std::vector< std::vector<chtype> > map(maxmapy, std::vector<chtype>(maxmapx, 0));

    for(int i = 0; i < maxmapy; i++)
    {
        for(int j = 0; j < maxmapx; j++)
        {
            map[i][j] = CollisionDetector::retrieve(i+1, j+1);
        }
    }

    return map;
}

void Map::buildfloor()
{
    for(int x = 1; x < getmaxx(stdscr)-1; x++)
    {
        int floorposition = getmaxy(stdscr)-2; // the floor on the map is places 2 rows above the max window size: the first row is for the window border, thus the floor goes right above that, on the second row
        
        mvaddch(floorposition, x, FLOOR); // the y value, corresponding to the floor, remains fixed and the cursor slides along the x and places the floor blocks one by one
    }
};

void Map::buildfloatingblocks()
{
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
};

void Map::placepits()
{
    int maxpits = getmaxx(stdscr) * 0.1; // only 10% of the floor will consist of pits where the Player might fall

    for(int i = 0; i < maxpits; i++)
    {
        int floorposition = getmaxy(stdscr)-2;
        int pitposition = RandomGenerator::generate(2, getmaxx(stdscr));

        mvaddch(floorposition, pitposition, EMPTY); // the pits are places at the same height of the floor; this method slides along the x values of the floor and randomly replaces a floor block with an empty block, except for the leftmost floor block, where the player spawns
    }
};