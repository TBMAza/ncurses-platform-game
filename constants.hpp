#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <ncurses.h>

/*                   <KEYS>
   Declaring keys that don't come with keypad() */

const chtype SPACEBAR = ' ';

/*                   <\KEYS>                    */

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

/*                               <DIRECTION>
   Used by players and bullets to keep trace if they're moving right or left */

const short RIGHT = 0;
const short LEFT = 1;

/*                              <\DIRECTION>                                 */

/*                         <JUMP>
   Constants required to implement jump for characters */

const int GRAVITY = 1;

const short NOT_FALLING = 0;
const short FALLING = 1;

const short NOT_JUMPING = 0;
const short JUMPING = 1;

const int INIT_JMPFRC = 0; // initial jump force (i.e. when player is on the ground and hasn't pressed 'jump' key (spacebar))
const int MAX_JUMPFORCE = 2;

/*                         <\JUMP>                     */

/*                   <PLAYER>
   Default/initial paraameters for the Player */

const int PLAYER_INIT_HLT = 32; // initial and also maximum health of the Player
const int PLAYER_DMG = 16; // amount of damage the Player deals to enemies when they come in direct contact

const int PLAYER_INIT_CASH = 0; // Player starts the game with no cash
const int PLAYER_INIT_PWUPS_QTY = 0; // initial quantity of power-ups in player's inventory; he starts with none

const int PLAYER_INIT_POS_Y = 21; // y coordinate of the Player's position at spawn
const int PLAYER_INIT_POS_X = 1; // x coordinate of the Player's position at spawn
const int PLAYER_INIT_DIR = RIGHT; // the initial direction where the player is pointed to

const chtype PLAYER_DEFAULT_FORM = '@'; // default aspect of the Player
const chtype FORCEFIELD = '&'; // Player's aspect when the forcefield power-up is active
const chtype INVSIBLE = '%'; // Player's aspect when the invisibility power-up is active

/*                   <\PLAYER>                */

/*                             <ENEMIES>
   Default/initial parameters for the different classes of enemies */

const int ENEMY_INIT_HLT = 16; // initial health of an enemy; all enemies share this same initial value

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

const int SHOOTER_RANGE = 32; // minimum x axis distance required for the Shooter to be able to "see" and therefore shoot the Player

/*                             <\ENEMIES>           */

/*                                         <PROJECTILES>
   Aspects of each class of projectiles and their power (i.e. the amount of damage they deal) */

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

/*                <MAP ELEMENTS>
   Aspects of elements found in the game maps */

const chtype EMPTY = ' ';
const chtype FLOOR = '=';
const chtype CASH = '$';

/*               <\MAP ELEMENTS>              */

#endif