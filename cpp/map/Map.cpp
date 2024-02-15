#include "../../headers/map/Map.hpp"
void Map::genmap()
{
    box(stdscr, 0, 0);
    
    Map::buildfloor();
    Map::buildfloatingblocks();
    
    Map::placepits();
};

void Map::buildmap(chtype** map)
{
    for (int y = 0; y < MAX_PLAYABLE_Y; y++)
    {
        for (int x = 0; x < MAX_PLAYABLE_X; x++)
        {
            mvaddch(y + 1, x + 1, map[y][x]);
        }
    }

    box(stdscr, 0, 0);
}

chtype** Map::savemap()
{
    chtype** map = new chtype*[MAX_PLAYABLE_Y];
    for (int i = 0; i < MAX_PLAYABLE_Y; i++)
    {
        map[i] = new chtype[MAX_PLAYABLE_X];
        for (int j = 0; j < MAX_PLAYABLE_X; j++)
        {
            if (CollisionDetector::retrieve(i + 1, j + 1) == PIT || CollisionDetector::retrieve(i + 1, j + 1) == FLOOR)
                map[i][j] = CollisionDetector::retrieve(i + 1, j + 1);
        }
    }

    return map;
}

void Map::buildfloor()
{
    for(int x = 1; x < MAX_X-1; x++)
    {
        attron(COLOR_PAIR(BROWN));
        mvaddch(FLOOR_Y, x, FLOOR); // the y value, corresponding to the floor, remains fixed and the cursor slides along the x and places the floor blocks one by one
        attroff(COLOR_PAIR(5));
    }
};

void Map::placefloatingblock(int startingpoint, int level)
{
    for(int i = startingpoint; i < (startingpoint + FLOATING_BLOCK_LENGTH); i++)
    {
        attron(COLOR_PAIR(BROWN));
        mvaddch(level, i, FLOOR);
        attroff(COLOR_PAIR(BROWN));
    }
};

void Map::fb_config_1()
{
    Map::placefloatingblock(PLAYER_INIT_POS_X + 20, FLOATING_BLOCK_LVL1);
    Map::placefloatingblock(PLAYER_INIT_POS_X + 30, FLOATING_BLOCK_LVL2);
    Map::placefloatingblock(PLAYER_INIT_POS_X + 40, FLOATING_BLOCK_LVL3);
    Map::placefloatingblock(PLAYER_INIT_POS_X + 50, FLOATING_BLOCK_LVL2);
    Map::placefloatingblock(PLAYER_INIT_POS_X + 60, FLOATING_BLOCK_LVL1);
};

void Map::fb_config_2()
{
    Map::placefloatingblock(PLAYER_INIT_POS_X + 4, FLOATING_BLOCK_LVL3);
    Map::placefloatingblock(PLAYER_INIT_POS_X + 14, FLOATING_BLOCK_LVL2);
    Map::placefloatingblock(PLAYER_INIT_POS_X + 24, FLOATING_BLOCK_LVL1);
    Map::placefloatingblock(PLAYER_INIT_POS_X + 34, FLOATING_BLOCK_LVL2);
    Map::placefloatingblock(PLAYER_INIT_POS_X + 44, FLOATING_BLOCK_LVL3);
};

void Map::fb_config_3()
{
    Map::placefloatingblock(PLAYER_INIT_POS_X + 16, FLOATING_BLOCK_LVL1);
    Map::placefloatingblock(PLAYER_INIT_POS_X + 26, FLOATING_BLOCK_LVL2);
    Map::placefloatingblock(PLAYER_INIT_POS_X + 36, FLOATING_BLOCK_LVL3);
    Map::placefloatingblock(PLAYER_INIT_POS_X + 46, FLOATING_BLOCK_LVL1);
    Map::placefloatingblock(PLAYER_INIT_POS_X + 56, FLOATING_BLOCK_LVL2);
    Map::placefloatingblock(PLAYER_INIT_POS_X + 66, FLOATING_BLOCK_LVL3);
};

void Map::fb_config_4()
{
    Map::placefloatingblock(PLAYER_INIT_POS_X + 4, FLOATING_BLOCK_LVL3);
    Map::placefloatingblock(PLAYER_INIT_POS_X + 14, FLOATING_BLOCK_LVL2);
    Map::placefloatingblock(PLAYER_INIT_POS_X + 24, FLOATING_BLOCK_LVL1);
    Map::placefloatingblock(PLAYER_INIT_POS_X + 34, FLOATING_BLOCK_LVL3);
    Map::placefloatingblock(PLAYER_INIT_POS_X + 44, FLOATING_BLOCK_LVL2);
    Map::placefloatingblock(PLAYER_INIT_POS_X + 54, FLOATING_BLOCK_LVL1);
};

void Map::fb_config_5()
{
    Map::placefloatingblock(PLAYER_INIT_POS_X + 4, FLOATING_BLOCK_LVL1);
    Map::placefloatingblock(PLAYER_INIT_POS_X + 14, FLOATING_BLOCK_LVL2);
    Map::placefloatingblock(PLAYER_INIT_POS_X + 24, FLOATING_BLOCK_LVL3);
    Map::placefloatingblock(PLAYER_INIT_POS_X + 34, FLOATING_BLOCK_LVL2);
    Map::placefloatingblock(PLAYER_INIT_POS_X + 44, FLOATING_BLOCK_LVL1);
    Map::placefloatingblock(PLAYER_INIT_POS_X + 54, FLOATING_BLOCK_LVL2);
    Map::placefloatingblock(PLAYER_INIT_POS_X + 64, FLOATING_BLOCK_LVL3);
};

void Map::fb_config_6()
{
    Map::placefloatingblock(PLAYER_INIT_POS_X + 4, FLOATING_BLOCK_LVL3);
    Map::placefloatingblock(PLAYER_INIT_POS_X + 14, FLOATING_BLOCK_LVL2);
    Map::placefloatingblock(PLAYER_INIT_POS_X + 24, FLOATING_BLOCK_LVL1);
    Map::placefloatingblock(PLAYER_INIT_POS_X + 34, FLOATING_BLOCK_LVL2);
    Map::placefloatingblock(PLAYER_INIT_POS_X + 44, FLOATING_BLOCK_LVL3);
    Map::placefloatingblock(PLAYER_INIT_POS_X + 54, FLOATING_BLOCK_LVL2);
    Map::placefloatingblock(PLAYER_INIT_POS_X + 64, FLOATING_BLOCK_LVL1);
};

void Map::buildfloatingblocks()
{
    static int buffer = 0;
    
    int selection = RandomGenerator::generate(1, 6);
    
    if(selection == buffer && selection != 6) selection++; // if a configuration was already used in the previous level, this guarantees that the current one will be different
    else if(selection == buffer && selection == 6) selection--; // we chose to increase (or decrease if we are at the upper bound) by one instead of regenerating randomly because of game freezing issues we encounterend when used random generation too frequently, especially in loop

    buffer = selection;
    
    switch(selection) // the configuration to be displayed is chosen randomly
    {
        case 1:
            Map::fb_config_1();
        break;

        case 2:
            Map::fb_config_2();
        break;

        case 3:
            Map::fb_config_3();
        break;

        case 4:
            Map::fb_config_4();
        break;

        case 5:
            Map::fb_config_5();
        break;

        case 6:
            Map::fb_config_6();
        break;

        default:
        break;
    };
};

void Map::placepits()
{
    int maxpits = MAX_X * 0.1; // only 10% of the floor will consist of pits where the Player might fall

    int i;
    for(i = 0; i < maxpits; i++)
    {
        int pitposition = RandomGenerator::generate(PLAYER_INIT_POS_X+1, MAX_PLAYABLE_X-1);
        mvaddch(FLOOR_Y, pitposition, PIT); // the pits are places at the same height of the floor; this method slides along the x values of the floor and randomly replaces a floor block with an empty block, except for the leftmost floor block, where the player spawns
    }
};

void Map::freemap(chtype** arr)
{
    for (int i = 0; i < MAX_PLAYABLE_Y; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
};