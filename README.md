A. Asaduz, backend web developer and Computer Science student @ University of Bologna, Italy

### 

### To build

Make sure that `ncurses` library is installed in your system, then follow the steps below:

- Download the repo

- Open terminal

- Change directory to the `cppgame` folder; 
  e.g. : `user@host [/] $: cd path/cppgame`

- Run `make` command

### 

### To run

- Remainind in the `cppgame` directory, run `./Game` command;
  e.g. : `user@host [cppgame] $: ./Game`

### 

### Generalities

<img src="file:readme_imgs/general.png">

The map is made of blank spaces and `=` characters that represent the floor, over which the Player and the enemies can walk, wheter it is the main floor or the floating blocks. If the Player or an enemy reaches the egde of a floating block, he will fall. If they go over the pits in the main floor, they will die.

The Player is represented by `@`, but he can shift shapes based on some active power-ups; for example, when he activates `FORCEFIELD` he looks like this:

<img src="file:///Users/alfahad.asaduz/C++/cppgame/readme_imgs/forcefield.png" title="" alt="" width="97">

when he activates `VANISHER` he looks like this:

<img src="file:///Users/alfahad.asaduz/C++/cppgame/readme_imgs/vanisher.png" title="" alt="" width="97">

When FORCEFIELD is active, any enemy that will approach the player will be killed instantly, without the Player getting contact damage.

When VANISHER is active, enemies won't be able to shoot him, thus wou't follow him nor shoot him.

At the top-left part of the window there is a health bar and inventory stats of the player; at the top-right you have the current level and the points you scored; points are scored killing enemies.

The green `$` symbols are collectable cash that you can use to buy power-ups and restore health in the `market menu`:

![](/Users/alfahad.asaduz/C++/cppgame/readme_imgs/market.png)

The stats remain visible in the market menu in order for the Player to see the inventory state while he is buying new things.

### Other menus

Besides the market, you will find other 3 types of menus

- Pause menu
  ![](/Users/alfahad.asaduz/C++/cppgame/readme_imgs/pause.png)

- Game over menu
  ![](/Users/alfahad.asaduz/C++/cppgame/readme_imgs/gameover.png)

- Main menu
  ![](/Users/alfahad.asaduz/C++/cppgame/readme_imgs/mainmenu.png)

You can access the `pause menu` anytime during the game. From this menu, if you resume, you will get back to your game and find in exactly as you left. If you decide to go to the main menu, the game will be automatically saved and you will be able to return to the exact game `Continue` from the main menu.

The `game over menu` appears whenever you die and it displays the cause of death. If you decide to respawn, you will restart from the same level you died in and loose all the point you accumulated in that level. Your cash will remain intact though.

The `main menu` is the one you encounter when you start the program. Therein you can choose to launch a new game (and this choice will overwrite any previous saved game if there are any), you can load a saved game (`Continue`) or exit the program. You can access the main menu at any moment during the game with the following sequence: press `Q` to enter the pause menu, select `Main menu`. It is highly recommended that whenever you want to close the program you do it through the `Exit` option from the main menu, because this way you ensure that all the heap memory used by the game is deallocated.

### Projectiles

The Player and the `Shooter` are the only characters that can shoot projectiles. There are 4 types of projectiles, one more powerful that the other:

- Bullet
  
  <img src="file:///Users/alfahad.asaduz/C++/cppgame/readme_imgs/bullet.png" title="" alt="" width="230">

- Superbullet
  
  <img src="file:///Users/alfahad.asaduz/C++/cppgame/readme_imgs/superbullet.png" title="" alt="" width="206">

- Hyperbullet
  
  <img src="file:///Users/alfahad.asaduz/C++/cppgame/readme_imgs/hyperbullet.png" title="" alt="" width="237">

- Laser
  
  <img src="file:///Users/alfahad.asaduz/C++/cppgame/readme_imgs/laser.png" title="" alt="" width="252">
  
  Being so powerful, the Laser is available only till level 10 and removed for the player afterwards.

### Enemies

There are five classes of enemies:

- Runner
  
  <img src="file:///Users/alfahad.asaduz/C++/cppgame/readme_imgs/runner.png" title="" alt="" width="240">

- Chaser
  
  <img src="file:///Users/alfahad.asaduz/C++/cppgame/readme_imgs/charger.png" title="" alt="" width="258">

- Follower
  ![](/Users/alfahad.asaduz/C++/cppgame/readme_imgs/follower.png)

- Chaser
  ![](/Users/alfahad.asaduz/C++/cppgame/readme_imgs/chaser.png)

- Shooter
  ![](/Users/alfahad.asaduz/C++/cppgame/readme_imgs/shooter.png)

Runner and Chaser have the same behavior: they are not aware of the Player, the can't jump and they move straight. When they reach the egde of a pit or a floating block, they change direction. If the player hits a Runner, he gets some damage. If he hits the Charger, he gets killed.

Follower and Chasers also have the same behaviour: they both chase the player until they come in contact with him dealing damage. If the Follower hits the player, the player receives some damage. If a Chaser hits him, he gets killed.

The shooter can track the Player and will try to reach him until he is from the player at a distance where the projectiles are in range to reach the player, then he shoots. As the game level increases, the Shooter gets more health and more powerful bullets.

### Objective

The game is virtually infinite: you can go on endlessly up the level ladder and accumulate as many points immaginable through killing the enemies. A level corresponds to a single map: when you reach the right end of a map, you will automatically pass to the next one (which will be randomly generated) and continue your adventure. You can kill enemy in 3 way:  by physical contact (which will damage yourself too), by shooting at them or with the `FORCEFIELD` powerup. At the beginning you are already equipped with standard bullets, which are not very powerful, but you can collect cash from the map and buy the more powerful option. As you climb the level ladder, the enemies will increase in power and number (though non infinitely because this would overpopulate the map and make the game impossible to be played). Do your best to reach the highest level and score the highest points that you can.

### Commands

- `right arrow`: in game -> move right, in menus -> navigate options

- `left arrow`: in game -> move left, in menus -> navigate options

- `enter`: in menus -> select highlighted option

- `spacebar`: jump

- `D`: shoot to right

- `A`: shoot to left

- `1`: activate FORCEFIELD (works if available in inventory)

- `2`: activate VANISHER (works if available in inventory)

- `8`: activate Superbullet (works if unlocked)

- `9`: activate Hyperbullet (works if unlocked)

- `0`: activate Laser (works if unlocked)

- `Q`: pause menu (while in-game)
