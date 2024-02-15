#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <ncurses.h>
#include <string>

/*                       <NULL VALUES>
   Values assigned to attributes when not initialized properly */

const chtype NULLCHR = ' '; // NULL value for playing characters
const chtype NULLPRJ = ' '; // NULL value for projectiles
const short NULLDIR = -1; // NULL value for direction; go to line 44 of this file for more details
const chtype NULLMAP = ' '; // NULL value for for map element; although it's identical to the EMPTY map element, we choose to declare a separate NULL element to differentiate the context of use
const int NULLHLT = -1; // NULL value for a character's health
const int NULLPOS = -1; // NULL value for an object's position
const int NULLDMG = 0; // NULL value for damage inflicted/taken by a character

/*                       <\NULL VALUES>                        */

/*                   <CUSTOM COLORS>                  */

#define COLOR_BROWN 8
#define COLOR_GREY 9
#define COLOR_ORANGE 10
#define COLOR_PURPLE 11
#define COLOR_BORDEAUX 12

/*                                                    */

/*                   <KEYS>
   Declaring keys that don't come with keypad() */

const chtype SPACEBAR = ' ';
const chtype ENTER = '\n';

/*                   <\KEYS>                    */

/*    COLORS      */

const int YELLOW = 1;
const int GREEN = 2;
const int MAGENTA = 3;
const int RED = 4;
const int BROWN = 5;
const int GREY = 6;
const int ORANGE = 7;
const int CYAN = 8;
const int BLUE = 9;

/*    COLORS      */

/*                                                            <MESSAGES> 
   during the game, there can occur cases in which certain messages have to pe prompted to the user to let him know important states
   of game execution. Message displaying is handled by methods contained in the Game class. Messages can be of three types:
   positive messages, negative messages and neutral messages. Below, we declare all the possible messages and three constants that will
   primarily used as arguments for the methods that handle message displaying, based on which the displayed messages will be
   correctly color-coded. */

const int NEUTRAL = 0;
const int POSITIVE = 1;
const int NEGATIVE = -1;

// market messages
const std::string NOT_ENOUGH_CASH = "NOT ENOUGH CASH!";
const std::string MAX_HEALTH_REACHED = "MAXIMUM HEALTH REACHED!";
const std::string SB_UNLOCKED = "SUPERBULLET UNLOCKED!";
const std::string HB_UNLOCKED = "HYPERBULLET UNLOCKED!";
const std::string L_UNLOCKED = "LASER UNLOCKED!";
const std::string SB_OWNED = "SUPERBULLET ALREADY UNLOCKED.";
const std::string HB_OWNED = "HYPERBULLET ALREADY UNLOCKED.";
const std::string L_OWNED = "LASER ALREADY UNLOCKED.";
const std::string NOT_AVAILABLE = "POWER-UP NO LONGER AVAILABLE AT THIS LEVEL.";

// main menu messages
const std::string NO_SAVEDGAME = "NO SAVED GAME AVAILABLE!.";

/*                                                           <\MESSAGES>                                                     */

/*                    <MAP ELEMENTS>
   Aspects and sizes of elements found in the game maps */

const int MAX_Y = 24; // total height of the game screen
const int MAX_X = 80; // total width dimension of the game screen

const int MAX_PLAYABLE_Y = MAX_Y - 2; // total height of the game screen excluding the border, whereby no game events shall occur
const int MAX_PLAYABLE_X = MAX_X -2; // total width dimension of the game screen excluding the border, whereby no game events shall occur

const chtype PIT = ' ';
const chtype FLOOR = 1341;

const int FLOOR_Y = MAX_Y-2; // height at which the floor is rendered

const int FLOATING_BLOCK_LENGTH = 8;
const int FLOATING_BLOCK_LVL1 = FLOOR_Y - 2; // height at which the first of the three layers of floating blocks is rendered
const int FLOATING_BLOCK_LVL2 = FLOATING_BLOCK_LVL1 - 2; // height of second layer of floating blocks
const int FLOATING_BLOCK_LVL3 = FLOATING_BLOCK_LVL2 - 2; // height of third layer of floating blocks
const int MAXBLOCKS = 4;

/*                    <\MAP ELEMENTS>                   */

/*    <CASH>
   Data about cash aspect and generation */
const chtype CASH = '$';
/*   <\CASH>   */

/*                               <DIRECTION>
   Used by players and bullets to keep trace if they're moving right or left */

const int RIGHT = 0;
const int LEFT = 1;
const int UP = 1;
const int DOWN = -1;

/*                              <\DIRECTION>                                 */

/*                         <JUMP>
   Constants required to implement jump for characters */

const int GRAVITY = 1;

const int NOT_FALLING = 0;
const int FALLING = 1;

const int NOT_JUMPING = 0;
const int JUMPING = 1;
const int INIT_JMPFRC = 0; // initial jump force (i.e. when player is on the ground and hasn't pressed 'jump' key (spacebar))
const int MAX_JUMPFORCE = 2;

/*                         <\JUMP>                     */

/*                   <PLAYER>
   Default/initial paraameters for the Player */

const int PLAYER_INIT_HLT = 32; // initial and also maximum health of the Player
const int PLAYER_DMG = 16; // amount of damage the Player deals to enemies when they come in direct contact

const int PLAYER_INIT_CASH = 0; // Player starts the game with no cash
const int PLAYER_INIT_PWUPS_QTY = 0; // initial quantity of power-ups in player's inventory; he starts with none

const int PLAYER_INIT_POS_Y = MAX_Y-3; // y coordinate of the Player's position at spawn
const int PLAYER_INIT_POS_X = 1; // x coordinate of the Player's position at spawn
const int PLAYER_INIT_DIR = RIGHT; // the initial direction where the player is pointed to

const chtype PLAYER_DEFAULT_FORM = '@'; // default aspect of the Player
const chtype FORCEFIELD = '&'; // Player's aspect when the forcefield power-up is active
const int FORCEFIELD_RANGE = 4;
const chtype VANISHER = '%'; // Player's aspect when the invisibility power-up is active

/*                   <\PLAYER>                */

/*                             <ENEMIES>
   Default/initial parameters for the different classes of enemies */

const int ENEMY_INIT_HLT = 16; // initial health of an enemy; all enemies share this same initial value
const int SUPER_ENEMY_INIT_HLT = 32;

// aspect of each class of enemies
const chtype RUNNER = 'R';
const chtype CHARGER = 'C';
const chtype FOLLOWER = 'F';
const chtype CHASER = 'H';
const chtype SHOOTER = 'S';

// amount of damage that each class of enemies deal when they come in direct contact with the Player
/* if the value is equivalent to PLAYER_INIT_HLT (i.e. the Players maximum health) it means that class of enemies can instantly kill
   the player at contact */
const int RUNNER_DMG = 2;
const int CHARGER_DMG = PLAYER_INIT_HLT;
const int FOLLOWER_DMG = 4;
const int CHASER_DMG = PLAYER_INIT_HLT;
const int SHOOTER_DMG = 8;
const int SUPER_SHOOTER_DMG = PLAYER_INIT_HLT;

const int SHOOTER_RANGE = 16; // minimum x axis distance required for the Shooter to be able to "see" and therefore shoot the Player

/*                             <\ENEMIES>           */

/*                                         <PROJECTILES>
   Aspects of each class of projectiles and their power (i.e. the amount of damage they deal) */

const int PROJRANGE = 16;

const chtype BULLET_RIGHT = '>';
const chtype BULLET_LEFT = '<';
const chtype SUPERBULLET = 'o';
const chtype HYPERBULLET = 'O';
const chtype LASER = '~';

const int BULLET_DMG = 1;
const int SUPERBULLET_DMG = 2;
const int HYPERBULLET_DMG = 4;
const int LASER_DMG = 8;

/*                                         <\PROJECTILES>                                     */

/*    <COST OF ITEMS>   */

const int HEALTH_COST = 1;
const int SUPERBULLET_COST = 2;
const int HYPERBULLET_COST = 8;
const int LASER_COST = 16;
const int FORCEFIELD_COST = 8;
const int VANISHER_COST = 16;

/*    <\COST OF ITEMS>  */

#endif