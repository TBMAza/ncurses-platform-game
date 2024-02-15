#include "Game.hpp"

Game::Game()
{
    (this->player_stats).level = 1;
    (this->player_stats).points = 0;
    (this->player_stats).cash = 0;
    (this->player_stats).forcefield_qty = 0;
    (this->player_stats).vanisher_qty = 0;
    (this->player_stats).superbullet_unlocked = false;
    (this->player_stats).hyperbullet_unlocked = false;
    (this->player_stats).laser_unlocked = false;
    
    this->gen_newmap = false;
    this->inmarket = false;
    this->gameover = true;
    this->inmainmenu = true;
    this->in_pausemenu = false;
    this->in_gameover_menu = false;
    this->entered = false;

    this->points_buffer = 0;

    initscr();
    raw();
    keypad(stdscr, TRUE);
    curs_set(0);
    noecho();
    nodelay(stdscr, true);
    cbreak();

    start_color();

    init_color(COLOR_BROWN, 500, 300, 0);
    init_color(COLOR_GREY, 400, 400, 400);
    init_color(COLOR_ORANGE, 1000, 500, 0);

    init_pair(YELLOW, COLOR_YELLOW, COLOR_BLACK);
    init_pair(GREEN, COLOR_GREEN, COLOR_BLACK);
    init_pair(MAGENTA, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(RED, COLOR_RED, COLOR_BLACK);
    init_pair(BROWN, COLOR_BROWN, COLOR_BLACK);
    init_pair(GREY, COLOR_GREY, COLOR_BLACK);
    init_pair(ORANGE, COLOR_ORANGE, COLOR_BLACK);
    init_pair(CYAN, COLOR_CYAN, COLOR_BLACK);
    init_pair(BLUE, COLOR_BLUE, COLOR_BLACK);
};

void Game::start()
{
    srand(time(NULL));
    this->main_menu();
    while(!(this->gameover))
    {
        usleep(138000);
        clear();
        this->main_menu();
        this->newmap();
        this->render();
        this->handle_input();
        this->apply_gravity_on_player();
        this->handle_enemy_behavior();
        (this->projectile_list_manager).moveprojectile();
        this->handle_collisions();
        this->levelup();
        this->handle_gameover();
        this->gameover_menu();
    }

    if(this->entered) clear_dynamic_memory();
        
    endwin();
    
    this->gameover_sendmessage();
};

void Game::render()
{
    Map::buildmap(this->currentmap);
        
    (this->cash_list_manager).displaycash();
    (this->projectile_list_manager).displayprojectile();
    
    ((this->enemy_list_manager).runners).displayrunner();
    ((this->enemy_list_manager).chargers).displaycharger();
    ((this->enemy_list_manager).followers).displayfollower();
    ((this->enemy_list_manager).shooters).displayshooter();
    ((this->enemy_list_manager).chasers).displaychaser();
    
    this->render_player();
    this->render_dynamic_healthbar();
    this->render_stats();
};

void Game::render_player()
{
    attron(COLOR_PAIR(YELLOW));
    
    mvaddch((this->player).getpos_y(), (this->player).getpos_x(), (this->player).getaspect());
    
    attroff(COLOR_PAIR(YELLOW));
};

void Game::render_dynamic_healthbar()
{
    attron(A_BOLD);

    for(int i = 0; i < (this->player).gethealth(); i++)
    {
        if((this->player).gethealth() < PLAYER_INIT_HLT*0.25) attron(COLOR_PAIR(RED));
        else if((this->player).gethealth() < PLAYER_INIT_HLT*0.50) attron(COLOR_PAIR(ORANGE));
        else if((this->player).gethealth() < PLAYER_INIT_HLT*0.75) attron(COLOR_PAIR(YELLOW));
        else attron(COLOR_PAIR(GREEN));

        mvprintw(1, i+1, "/");

        if((this->player).gethealth() < PLAYER_INIT_HLT*0.25) attroff(COLOR_PAIR(RED));
        else if((this->player).gethealth() < PLAYER_INIT_HLT*0.50) attroff(COLOR_PAIR(ORANGE));
        else if((this->player).gethealth() < PLAYER_INIT_HLT*0.75) attroff(COLOR_PAIR(YELLOW));
        else attroff(COLOR_PAIR(GREEN));
    }

    attroff(A_BOLD);
};

void Game::render_stats()
{
    attron(A_BOLD);
    attron(A_ITALIC);
    
    mvprintw(2, 1, "%d$", (this->player_stats).cash);
    mvprintw(3, 1, "FORCEFIELDS: %d", (this->player_stats).forcefield_qty);
    mvprintw(4, 1, "VANISHERS: %d", (this->player_stats).vanisher_qty);
    mvprintw(5, 1, "ACTIVE PROJECTILE: %c", (this->player).getactiveproj());
        
    mvprintw(1, 64, "LEVEL: %d", (this->player_stats).level);
    mvprintw(2, 64, "POINTS: %d", (this->player_stats).points);

    attroff(A_BOLD);
    attroff(A_ITALIC);
};

void Game::handle_input()
{
    /* specific conditions in which the player could go through the edge of floors or floating blocks if he decides to move right or left
       preventing the player to move left or right when these conditions occur in-game, solves the problem */
    bool ghosting_condition_L = ((this->player).getpos_y() < PLAYER_INIT_POS_Y &&
                                 (this->player).getjumpdir() == DOWN &&
                                 CollisionDetector::below((this->player).getpos_y(), (this->player).getpos_x()) != FLOOR &&
                                 CollisionDetector::downleft((this->player).getpos_y(), (this->player).getpos_x()) == FLOOR);
    
    bool ghosting_condition_R = ((this->player).getpos_y() < PLAYER_INIT_POS_Y &&
                                 (this->player).getjumpdir() == DOWN &&
                                 CollisionDetector::below((this->player).getpos_y(), (this->player).getpos_x()) != FLOOR &&
                                 CollisionDetector::downright((this->player).getpos_y(), (this->player).getpos_x()) == FLOOR);
    
    // handle user input
    int ch = getch();
    switch (ch)
    {
        case KEY_LEFT:
            if((this->player).getpos_x() > PLAYER_INIT_POS_X && !ghosting_condition_L)
            {
                (this->player).mvleft();
            }
        break;
            
        case KEY_RIGHT:
            if((this->player).getpos_x() < MAX_PLAYABLE_X+1 && !ghosting_condition_R)
            {
                (this->player).mvright();
            }
        break;
            
        case SPACEBAR:
            if ((this->player).getjumpstate() == NOT_JUMPING && (this->player).getfallstate() == NOT_FALLING)
            {
                (this->player).setjumpstate(JUMPING);
            }
        break;

        case '1':
            if((this->player).getactivepowerup() == PLAYER_DEFAULT_FORM && (this->player_stats).forcefield_qty > 0)
            {
                (this->player).setpowerup(FORCEFIELD);
                (this->player).setaspect(FORCEFIELD);
                (this->player_stats).forcefield_qty--;
            }
        break;

        case '2':
            if((this->player).getactivepowerup() == PLAYER_DEFAULT_FORM && (this->player_stats).vanisher_qty > 0)
            {
                (this->player).setpowerup(VANISHER);
                (this->player).setaspect(VANISHER);
                (this->player_stats).vanisher_qty--;
            }
        break;

        case '7':
            (this->player).setproj(BULLET_RIGHT);
        break;

        case '8':
            if((this->player_stats).superbullet_unlocked) (this->player).setproj(SUPERBULLET);
        break;

        case '9':
            if((this->player_stats).hyperbullet_unlocked) (this->player).setproj(HYPERBULLET);
        break;

        case '0':
            if((this->player_stats).laser_unlocked) (this->player).setproj(LASER);
        break;

        case 'd':
            (this->projectile_list_manager).addprojectile((this->player).getactiveproj(), (this->player).shoot(), (this->player).getpos_y(), (this->player).getpos_x()+1, RIGHT);
        break;
            
        case 'a':
            (this->projectile_list_manager).addprojectile((this->player).getactiveproj(), (this->player).shoot(), (this->player).getpos_y(), (this->player).getpos_x()-1, LEFT);
        break;

        case 'm':
            this->inmarket = true;
            this->market();
        break;

        case 'q': // Quit the game
            this->in_pausemenu = true;
            this->pause_menu();
    }
};

void Game::apply_gravity_on_player()
{
    (this->player).jump();
    (this->player).fall();
};

void Game::levelup()
{
    if((this->player).getpos_x() == MAX_PLAYABLE_X+1)
    {
        (this->player).setposition(PLAYER_INIT_POS_Y, PLAYER_INIT_POS_X);
        (this->player).setfallstate(NOT_FALLING);
        (this->player).resetjumpstate();
        (this->player).setpowerup(PLAYER_DEFAULT_FORM);
        (this->player).setaspect(PLAYER_DEFAULT_FORM);
            
        this->clear_dynamic_memory();
            
        (this->player_stats).level++;
        this->points_buffer = 0;
            
        this->gen_newmap = true;

        if((this->player_stats).level >= 10)
        {
            if((this->player).getactiveproj() == LASER)
            {
                (this->player).setproj(BULLET_RIGHT);
                (this->player_stats).laser_unlocked = false;
                (this->player_stats).vanisher_qty = 0;
            }
        }
    }
};

void Game::handle_enemy_behavior()
{
    ((this->enemy_list_manager).runners).moverunners((this->player).getpos_x(), (this->player).getactivepowerup());
    ((this->enemy_list_manager).chargers).movechargers();
    
    ((this->enemy_list_manager).followers).movefollowers((this->player).getpos_x(), (this->player).getactivepowerup());
    ((this->enemy_list_manager).chasers).movechasers((this->player).getpos_x(), (this->player).getactivepowerup());
    
    ((this->enemy_list_manager).shooters).moveshooter((this->player).getpos_x(), (this->player).getactivepowerup()); // iterates through all the shooters in the linked list and makes each of them move based on current game conditions (obstacles, player distance)
    ((this->enemy_list_manager).shooters).let_them_shoot(this->projectile_list_manager, (this->player).getpos_y(), (this->player).getpos_x(), (this->player).getactivepowerup()); // iterates through all the shooters in the linked list and makes them shoot, if the conditions to do so for each shooter are met
};

void Game::handle_collisions()
{
    // player-projectile collision detection block
    if((this->projectile_list_manager).findprojectile((this->player).getpos_y(), (this->player).getpos_x()) != NULL)
    {
        pProjectileList current = (this->projectile_list_manager).findprojectile((this->player).getpos_y(), (this->player).getpos_x());
        (this->player).takedamage((current->projectile).getdamage());
        (this->projectile_list_manager).removeprojectile(current);

        if((this->player).gethealth() <= 0) this->gameover_message = "player was killed by Shooter.";
    }
    if((this->projectile_list_manager).findprojectile((this->player).getpos_y(), (this->player).getpos_x()+1) != NULL)
    {
        pProjectileList current = (this->projectile_list_manager).findprojectile((this->player).getpos_y(), (this->player).getpos_x()+1);
        (this->player).takedamage((current->projectile).getdamage());
        (this->projectile_list_manager).removeprojectile(current);

        if((this->player).gethealth() <= 0) this->gameover_message = "player was killed by Shooter.";
    }
    if((this->projectile_list_manager).findprojectile((this->player).getpos_y(), (this->player).getpos_x()-1) != NULL)
    {
        pProjectileList current = (this->projectile_list_manager).findprojectile((this->player).getpos_y(), (this->player).getpos_x()-1);
        (this->player).takedamage((current->projectile).getdamage());
        (this->projectile_list_manager).removeprojectile(current);

        if((this->player).gethealth() <= 0) this->gameover_message = "player was killed by Shooter.";
    }
    // endblock (player-projectile)

    // player-cash collision block
    if((this->cash_list_manager).findcash((this->player).getpos_y(), (this->player).getpos_x()) != NULL)
    {
        (this->cash_list_manager).removecash((this->player).getpos_y(), (this->player).getpos_x());
        (this->player_stats).cash++;
    }
    // endblock (player-cash)

    // player-runner collision detection block
    ((this->enemy_list_manager).runners).handle_forcefield((this->player).getpos_y(), (this->player).getpos_x(), (this->player).getactivepowerup(), (this->player_stats).points, this->points_buffer);
    
    if(((this->enemy_list_manager).runners).findrunner((this->player).getpos_y(), (this->player).getpos_x()) != NULL)
    {
        pRunnerList current = ((this->enemy_list_manager).runners).findrunner((this->player).getpos_y(), (this->player).getpos_x());
        (this->player).takedamage( (current->runner).getdac() );

        if((this->player).gethealth() > 0)
        {
            (current->runner).takedamage(player.getdac());
            if( (current->runner).gethealth() <= 0 ) ((this->enemy_list_manager).runners).removerunner(current);
            (this->player_stats).points++;
            (this->points_buffer)++;
        }
        else this->gameover_message = "player was killed by Runner.";
    }
    if(((this->enemy_list_manager).runners).findrunner((this->player).getpos_y(), (this->player).getpos_x()+1) != NULL)
    {
        pRunnerList current = ((this->enemy_list_manager).runners).findrunner((this->player).getpos_y(), (this->player).getpos_x()+1);
        (this->player).takedamage( (current->runner).getdac() );

        if((this->player).gethealth() > 0)
        {
            (current->runner).takedamage(player.getdac());
            if( (current->runner).gethealth() <= 0 ) ((this->enemy_list_manager).runners).removerunner(current);
            (this->player_stats).points++;
            (this->points_buffer)++;
        }
        else this->gameover_message = "player was killed by Runner.";
    }
    if(((this->enemy_list_manager).runners).findrunner((this->player).getpos_y(), (this->player).getpos_x()-1) != NULL)
    {
        pRunnerList current = ((this->enemy_list_manager).runners).findrunner((this->player).getpos_y(), (this->player).getpos_x()-1);
        (this->player).takedamage( (current->runner).getdac() );

        if((this->player).gethealth() > 0)
        {
            (current->runner).takedamage(player.getdac());
            if( (current->runner).gethealth() <= 0 ) ((this->enemy_list_manager).runners).removerunner(current);
            (this->player_stats).points++;
            (this->points_buffer)++;
        }
        else this->gameover_message = "player was killed by Runner.";
    }
    // endblock (player-runner)

    // player-charger collision detection block
    ((this->enemy_list_manager).chargers).handle_forcefield((this->player).getpos_y(), (this->player).getpos_x(), (this->player).getactivepowerup(), (this->player_stats).points, this->points_buffer);

    if(((this->enemy_list_manager).chargers).findcharger((this->player).getpos_y(), (this->player).getpos_x()) != NULL)
    {
        pChargerList current = ((this->enemy_list_manager).chargers).findcharger((this->player).getpos_y(), (this->player).getpos_x());
        (this->player).takedamage( (current->charger).getdac() );

        if((this->player).gethealth() > 0)
        {
            (current->charger).takedamage(player.getdac());
            if( (current->charger).gethealth() <= 0 ) ((this->enemy_list_manager).chargers).removecharger(current);
            (this->player_stats).points++;
            this->points_buffer++;
        }
        else this->gameover_message = "player was killed by Charger.";
    }
    if(((this->enemy_list_manager).chargers).findcharger((this->player).getpos_y(), (this->player).getpos_x()+1) != NULL)
    {
        pChargerList current = ((this->enemy_list_manager).chargers).findcharger((this->player).getpos_y(), (this->player).getpos_x()+1);
        (this->player).takedamage( (current->charger).getdac() );

        if((this->player).gethealth() > 0)
        {
            (current->charger).takedamage(player.getdac());
            if( (current->charger).gethealth() <= 0 ) ((this->enemy_list_manager).chargers).removecharger(current);
            (this->player_stats).points++;
            this->points_buffer++;
        }
        else this->gameover_message = "player was killed by Charger.";
    }
    if(((this->enemy_list_manager).chargers).findcharger((this->player).getpos_y(), (this->player).getpos_x()-1) != NULL)
    {
        pChargerList current = ((this->enemy_list_manager).chargers).findcharger((this->player).getpos_y(), (this->player).getpos_x()-1);
        (this->player).takedamage( (current->charger).getdac() );

        if((this->player).gethealth() > 0)
        {
            (current->charger).takedamage(player.getdac());
            if( (current->charger).gethealth() <= 0 ) ((this->enemy_list_manager).chargers).removecharger(current);
            (this->player_stats).points++;
            this->points_buffer++;
        }
        else this->gameover_message = "player was killed by Charger.";
    }
    // endblock (player-charger)

    // player-follower collision detection block
    ((this->enemy_list_manager).followers).handle_forcefield((this->player).getpos_y(), (this->player).getpos_x(), (this->player).getactivepowerup(), (this->player_stats).points, this->points_buffer);

    if(((this->enemy_list_manager).followers).findfollower((this->player).getpos_y(), (this->player).getpos_x()) != NULL)
    {
        pFollowerList current = ((this->enemy_list_manager).followers).findfollower((this->player).getpos_y(), (this->player).getpos_x());
        (this->player).takedamage( (current->follower).getdac() );

        if((this->player).gethealth() > 0)
        {
            (current->follower).takedamage(player.getdac());
            if( (current->follower).gethealth() <= 0 ) ((this->enemy_list_manager).followers).removefollower(current);
            (this->player_stats).points++;
            (this->points_buffer)++;
        }
        else this->gameover_message = "player was killed by Follower.";
    }
    if(((this->enemy_list_manager).followers).findfollower((this->player).getpos_y(), (this->player).getpos_x()+1) != NULL)
    {
        pFollowerList current = ((this->enemy_list_manager).followers).findfollower((this->player).getpos_y(), (this->player).getpos_x()+1);
        (this->player).takedamage( (current->follower).getdac() );

        if((this->player).gethealth() > 0)
        {
            (current->follower).takedamage(player.getdac());
            if( (current->follower).gethealth() <= 0 ) ((this->enemy_list_manager).followers).removefollower(current);
            (this->player_stats).points++;
            (this->points_buffer)++;
        }
        else this->gameover_message = "player was killed by Follower.";
    }
    if(((this->enemy_list_manager).followers).findfollower((this->player).getpos_y(), (this->player).getpos_x()-1) != NULL)
    {
        pFollowerList current = ((this->enemy_list_manager).followers).findfollower((this->player).getpos_y(), (this->player).getpos_x()-1);
        (this->player).takedamage( (current->follower).getdac() );

        if((this->player).gethealth() > 0)
        {
            (current->follower).takedamage(player.getdac());
            if( (current->follower).gethealth() <= 0 ) ((this->enemy_list_manager).followers).removefollower(current);
            (this->player_stats).points++;
            (this->points_buffer)++;
        }
        else this->gameover_message = "player was killed by Follower.";
    }
    // endblock (player-follower)

    // player-chaser collision detection block
    ((this->enemy_list_manager).chasers).handle_forcefield((this->player).getpos_y(), (this->player).getpos_x(), (this->player).getactivepowerup(), (this->player_stats).points, this->points_buffer);

    if(((this->enemy_list_manager).chasers).findchaser((this->player).getpos_y(), (this->player).getpos_x()) != NULL)
    {
        pChaserList current = ((this->enemy_list_manager).chasers).findchaser((this->player).getpos_y(), (this->player).getpos_x());
        (this->player).takedamage( (current->chaser).getdac() );

        if((this->player).gethealth() > 0)
        {
            (current->chaser).takedamage(player.getdac());
            if( (current->chaser).gethealth() <= 0 ) ((this->enemy_list_manager).chasers).removechaser(current);
            (this->player_stats).points++;
            (this->points_buffer)++;
        }
        else this->gameover_message = "player was killed by Chaser.";
    }
    if(((this->enemy_list_manager).chasers).findchaser((this->player).getpos_y(), (this->player).getpos_x()+1) != NULL)
    {
        pChaserList current = ((this->enemy_list_manager).chasers).findchaser((this->player).getpos_y(), (this->player).getpos_x()+1);
        (this->player).takedamage( (current->chaser).getdac() );

        if((this->player).gethealth() > 0)
        {
            (current->chaser).takedamage(player.getdac());
            if( (current->chaser).gethealth() <= 0 ) ((this->enemy_list_manager).chasers).removechaser(current);
            (this->player_stats).points++;
            (this->points_buffer)++;
        }
        else this->gameover_message = "player was killed by Chaser.";
    }
    if(((this->enemy_list_manager).chasers).findchaser((this->player).getpos_y(), (this->player).getpos_x()-1) != NULL)
    {
        pChaserList current = ((this->enemy_list_manager).chasers).findchaser((this->player).getpos_y(), (this->player).getpos_x()-1);
        (this->player).takedamage( (current->chaser).getdac() );

        if((this->player).gethealth() > 0)
        {
            (current->chaser).takedamage(player.getdac());
            if( (current->chaser).gethealth() <= 0 ) ((this->enemy_list_manager).chasers).removechaser(current);
            (this->player_stats).points++;
            (this->points_buffer)++;
        }
        else this->gameover_message = "player was killed by Chaser.";
    }
    // endblock (player-chaser)
    
    // player-shooter collision detection block
    ((this->enemy_list_manager).shooters).handle_forcefield((this->player).getpos_y(), (this->player).getpos_x(), (this->player).getactivepowerup(), (this->player_stats).points, this->points_buffer);

    if(((this->enemy_list_manager).shooters).findshooter((this->player).getpos_y(), (this->player).getpos_x()) != NULL)
    {
        pShooterList current = ((this->enemy_list_manager).shooters).findshooter((this->player).getpos_y(), (this->player).getpos_x());
        (this->player).takedamage( (current->shooter).getdac() );

        if((this->player).gethealth() > 0)
        {
            (current->shooter).takedamage(player.getdac());
            if( (current->shooter).gethealth() <= 0 ) ((this->enemy_list_manager).shooters).removeshooter(current);
            (this->player_stats).points++;
            (this->points_buffer)++;
        }
        else this->gameover_message = "player was killed by Shooter.";
    }
    if(((this->enemy_list_manager).shooters).findshooter((this->player).getpos_y(), (this->player).getpos_x()+1) != NULL)
    {
        pShooterList current = ((this->enemy_list_manager).shooters).findshooter((this->player).getpos_y(), (this->player).getpos_x()+1);
        (this->player).takedamage( (current->shooter).getdac() );

        if((this->player).gethealth() > 0)
        {
            (current->shooter).takedamage(player.getdac());
            if( (current->shooter).gethealth() <= 0 ) ((this->enemy_list_manager).shooters).removeshooter(current);
            (this->player_stats).points++;
            (this->points_buffer)++;
        }
        else this->gameover_message = "player was killed by Shooter.";
    }
    if(((this->enemy_list_manager).shooters).findshooter((this->player).getpos_y(), (this->player).getpos_x()-1) != NULL)
    {
        pShooterList current = ((this->enemy_list_manager).shooters).findshooter((this->player).getpos_y(), (this->player).getpos_x()-1);
        (this->player).takedamage( (current->shooter).getdac() );

        if((this->player).gethealth() > 0)
        {
            (current->shooter).takedamage(player.getdac());
            if( (current->shooter).gethealth() <= 0 ) ((this->enemy_list_manager).shooters).removeshooter(current);
            (this->player_stats).points++;
            (this->points_buffer)++;
        }
        else this->gameover_message = "player was killed by Shooter.";
    }
    // endblock (player-shooter)

    // runner-projectile collision detection block
    ((this->enemy_list_manager).runners).handle_projectile_collision((this->projectile_list_manager), (this->player_stats).points, this->points_buffer);
    // endblock (runner-projectile)

    // charger-projectile collision detection block
    ((this->enemy_list_manager).chargers).handle_projectile_collision((this->projectile_list_manager), (this->player_stats).points, this->points_buffer);
    // endblock (charger-projectile)

    // follower-projectile collision detection block
    ((this->enemy_list_manager).followers).handle_projectile_collision((this->projectile_list_manager), (this->player_stats).points, this->points_buffer);
    // endblock (follower-projectile)

    // chaser-projectile collision detection block
    ((this->enemy_list_manager).chasers).handle_projectile_collision((this->projectile_list_manager), (this->player_stats).points, this->points_buffer);
    // endblock (chaser-projectile)
    
    // shooter-projectile collision detection block
    ((this->enemy_list_manager).shooters).handle_projectile_collision((this->projectile_list_manager), (this->player_stats).points, this->points_buffer);
    // endblock (shooter-projectile)
};

void Game::handle_gameover()
{
    if(player.getpos_y() > MAX_PLAYABLE_Y)
    {
        this->in_gameover_menu = true;
        this->gameover_message = "player fell in pit.";
        (this->player_stats).points -= this->points_buffer;
        this->points_buffer = 0;
    }
    else if(player.gethealth() <= 0)
    {
        this->in_gameover_menu = true;
        (this->player_stats).points -= points_buffer;
        this->points_buffer = 0;
    }
};

void Game::clear_dynamic_memory()
{
    (this->cash_list_manager).deleteallcash();
    (this->projectile_list_manager).deleteallprojectiles();
    ((this->enemy_list_manager).runners).deleteallrunners();
    ((this->enemy_list_manager).chargers).deleteallchargers();
    ((this->enemy_list_manager).followers).deleteallfollowers();
    ((this->enemy_list_manager).chasers).deleteallchasers();
    ((this->enemy_list_manager).shooters).deleteallshooters();
    Map::freemap(this->currentmap);
};

void Game::newmap()
{
    if(this->gen_newmap)
    {
        Map::genmap();
        currentmap = Map::savemap();

        (this->cash_list_manager).placeallcash();
        ((this->enemy_list_manager).runners).placeallrunners((this->player_stats).level);
        ((this->enemy_list_manager).chargers).placeallchargers((this->player_stats).level);
        ((this->enemy_list_manager).followers).placeallfollowers((this->player_stats).level);
        ((this->enemy_list_manager).chasers).placeallchasers((this->player_stats).level);
        ((this->enemy_list_manager).shooters).placeallshooters((this->player_stats).level);

        this->gen_newmap = false;
    }
};

void Game::gameover_sendmessage()
{
    std::cout << "\nGame over: " << this->gameover_message << "\n\n";
}

void Game::market()
{
    usleep(1000);
    clear();
    std::string options[7] = {"Restore health (1$)", "Unlock Superbullet (2$)", "Unlock Hyperbullet (8$)", "Unlock Laser (16$)", "Buy Forcefield (8$)", "Buy Vanisher (16$)", "Back to game"};
    int selection, highlight = 0;
    
    while(this->inmarket)
    {
        clear();
        
        box(stdscr, ' ', ' ');
        render_dynamic_healthbar();
        render_stats();

        attron(A_BOLD);
        attron(A_ITALIC);
        attron(COLOR_PAIR(ORANGE));
        mvprintw(8, 1, "M  A  R  K  E  T");
        attroff(A_BOLD);
        attroff(A_ITALIC);
        attroff(COLOR_PAIR(ORANGE));
        
        
        attron(COLOR_PAIR(ORANGE));
        for(int i = 0; i < 7; i++)
        {
            if(i == highlight) attron(A_REVERSE);
            mvprintw(i+10, 1, options[i].c_str());
            if(i == highlight) attroff(A_REVERSE);
        }
        attroff(COLOR_PAIR(ORANGE));

        selection = getch();
        switch(selection)
        {
            case KEY_UP:
                highlight--;
                if(highlight < 0) highlight = 6;
            break;

            case KEY_DOWN:
                highlight++;
                if(highlight > 6) highlight = 0;
            break;

            case ENTER:
                this->handle_market_selection(highlight);
            break;
        }

        this->display_messagebox();
        refresh();
    }
    this->render();
};

void Game::handle_market_selection(int sel)
{
    switch(sel)
    {
        case 0:
            if((this->player_stats).cash >= HEALTH_COST && (this->player).gethealth() < PLAYER_INIT_HLT)
            {
                (this->player).incrhealth();
                (this->player_stats).cash -= HEALTH_COST;
            }
            else if((this->player).gethealth() >= PLAYER_INIT_HLT) this->send_to_messagebox(MAX_HEALTH_REACHED);
            else this->send_to_messagebox(NOT_ENOUGH_CASH);
        break;

        case 1:
            if((this->player_stats).cash >= SUPERBULLET_COST && !(this->player_stats).superbullet_unlocked)
            {
                (this->player_stats).superbullet_unlocked = true;
                (this->player_stats).cash -= SUPERBULLET_COST;
                this->send_to_messagebox(SB_UNLOCKED);
            }
            else if((this->player_stats).superbullet_unlocked) this->send_to_messagebox(SB_OWNED);
            else this->send_to_messagebox(NOT_ENOUGH_CASH);
        break;

        case 2:
            if((this->player_stats).cash >= HYPERBULLET_COST && !(this->player_stats).hyperbullet_unlocked)
            {
                (this->player_stats).hyperbullet_unlocked = true;
                (this->player_stats).cash -= HYPERBULLET_COST;
                this->send_to_messagebox(HB_UNLOCKED);
            }
            else if((this->player_stats).hyperbullet_unlocked) this->send_to_messagebox(HB_OWNED);
            else this->send_to_messagebox(NOT_ENOUGH_CASH);
        break;

        case 3:
            if((this->player_stats).cash >= LASER_COST && !(this->player_stats).laser_unlocked && (this->player_stats).level < 10)
            {
                (this->player_stats).laser_unlocked = true;
                (this->player_stats).cash -= LASER_COST;
                this->send_to_messagebox(L_UNLOCKED);
            }
            else if((this->player_stats).laser_unlocked) this->send_to_messagebox(L_OWNED);
            else if((this->player_stats).cash < LASER_COST) this->send_to_messagebox(NOT_ENOUGH_CASH);
            else if((this->player_stats).level >= 10) this->send_to_messagebox(NOT_AVAILABLE);
        break;

        case 4:
            if((this->player_stats).cash >= FORCEFIELD_COST)
            {
                (this->player_stats).forcefield_qty++;
                (this->player_stats).cash -= FORCEFIELD_COST;
            }
            else this->send_to_messagebox(NOT_ENOUGH_CASH);
        break;

        case 5:
            if((this->player_stats).cash >= VANISHER_COST && (this->player_stats).level < 10)
            {
                (this->player_stats).vanisher_qty++;
                (this->player_stats).cash -= VANISHER_COST;
            }
            else if((this->player_stats).cash < VANISHER_COST) this->send_to_messagebox(NOT_ENOUGH_CASH);
            else if((this->player_stats).level >= 10) this->send_to_messagebox(NOT_AVAILABLE);
        break;

        case 6:
            this->inmarket = false;
        break;
    }
};

void Game::display_messagebox()
{
    bool unlocked = (this->messagebox == SB_UNLOCKED ||
                     this->messagebox == HB_UNLOCKED ||
                     this->messagebox == L_UNLOCKED);
    bool unlock_reattempt = (this->messagebox == SB_OWNED ||
                             this->messagebox == HB_OWNED ||
                             this->messagebox == L_OWNED);
    
    if (this->messagebox_timer < 40000)
    {
        if(this->messagebox == NOT_ENOUGH_CASH || this->messagebox == NO_SAVEDGAME || this->messagebox == NOT_AVAILABLE) attron(COLOR_PAIR(RED));
        else if(unlocked) attron(COLOR_PAIR(GREEN));
        else if(unlock_reattempt || this->messagebox == MAX_HEALTH_REACHED) attron(COLOR_PAIR(YELLOW));

        attron(A_BLINK);
        attron(A_ITALIC);
        attron(A_BOLD);
        //mvprintw(MAX_PLAYABLE_Y, 1, (this->messagebox).c_str());
        mvprintw(MAX_PLAYABLE_Y, 1, (this->messagebox).c_str());
        
        if(this->messagebox == NOT_ENOUGH_CASH || this->messagebox == NO_SAVEDGAME || this->messagebox == NOT_AVAILABLE) attroff(COLOR_PAIR(RED));
        else if(unlocked) attroff(COLOR_PAIR(GREEN));
        else if(unlock_reattempt || this->messagebox == MAX_HEALTH_REACHED) attroff(COLOR_PAIR(YELLOW));

        attroff(A_BLINK);
        attroff(A_ITALIC);
        attroff(A_BOLD);

        messagebox_timer++;
    }
    else mvprintw(10, 40, "");
};

void Game::send_to_messagebox(std::string message)
{
    this->messagebox = message;
    this->messagebox_timer = 0;
};

void Game::main_menu()
{
    usleep(1000);
    clear();
    std::string options[3] = {"New game", "Continue", "Exit"};
    int selection, highlight = 0;
    
    while(this->inmainmenu)
    {
        clear();
        
        box(stdscr, ' ', ' ');

        attron(A_BOLD);
        attron(A_ITALIC);
        mvprintw(8, 1, "MAIN MENU");
        attroff(A_BOLD);
        attroff(A_ITALIC);
        
        
        for(int i = 0; i < 3; i++)
        {
            if(i == highlight) attron(A_REVERSE);
            mvprintw(i+10, 1, options[i].c_str());
            if(i == highlight) attroff(A_REVERSE);
        }

        selection = getch();
        switch(selection)
        {
            case KEY_UP:
                highlight--;
                if(highlight < 0) highlight = 2;
            break;

            case KEY_DOWN:
                highlight++;
                if(highlight > 2) highlight = 0;
            break;

            case ENTER:
                this->handle_mainmenu_selection(highlight);
            break;
        }

        this->display_messagebox();
        refresh();
    }
    clear();
};

void Game::handle_mainmenu_selection(int sel)
{
    switch(sel)
    {
        case 0:
            if(!(this->entered))
            {
                this->resetplayer();
                this->resetstats();
                this->gen_newmap = true;
                this->entered = true;
                this->gameover = false;
            }
            else
            {
                this->clear_dynamic_memory();
                this->resetplayer();
                this->resetstats();
                this->gen_newmap = true;
                this->gameover = false;
            }

            this->inmainmenu = false;
        break;

        case 1:
            
            if(FileReader::loadval("savedata/saved.txt") && !(this->entered))
            {
                this->gen_newmap = false;
                this->entered = true;
                this->load_saved_game();
                this->gameover = false;

                this->inmainmenu = false;
            }
            else if(this->entered)
            {
                this->inmainmenu = false;
            }
            else
            {
                this->send_to_messagebox(NO_SAVEDGAME);
            }
        break;

        case 2:
            this->gameover = true;
            this->gameover_message = "exited";
            this->inmainmenu = false;
            this->in_gameover_menu = false;
            if(this->entered) this->save();
            resetplayer();
        break;
    }
};

void Game::pause_menu()
{
    usleep(1000);
    clear();
    std::string options[2] = {"Resume", "Main menu"};
    int selection, highlight = 0;
    
    while(this->in_pausemenu)
    {
        clear();
        
        box(stdscr, ' ', ' ');

        attron(A_BOLD);
        attron(A_ITALIC);
        mvprintw(8, 1, "PAUSED");
        attroff(A_BOLD);
        attroff(A_ITALIC);
        
        
        for(int i = 0; i < 2; i++)
        {
            if(i == highlight) attron(A_REVERSE);
            mvprintw(i+10, 1, options[i].c_str());
            if(i == highlight) attroff(A_REVERSE);
        }

        selection = getch();
        switch(selection)
        {
            case KEY_UP:
                highlight--;
                if(highlight < 0) highlight = 1;
            break;

            case KEY_DOWN:
                highlight++;
                if(highlight > 1) highlight = 0;
            break;

            case ENTER:
                this->handle_pausemenu_selection(highlight);
            break;
        }

        this->display_messagebox();
        refresh();
    }
    render();
};

void Game::handle_pausemenu_selection(int sel)
{
    switch(sel)
    {
        case 0:
            this->in_pausemenu = false;
        break;

        case 1:
            this->inmainmenu = true;
            this->in_pausemenu = false;
        break;
    }
};

void Game::gameover_menu()
{
    usleep(1000);
    clear();
    std::string options[2] = {"Respawn", "Main menu"};
    int selection, highlight = 0;
    
    while(this->in_gameover_menu)
    {
        clear();
        
        box(stdscr, ' ', ' ');

        attron(A_BOLD);
        attron(A_ITALIC);
        attron(COLOR_PAIR(RED));
        mvprintw(8, 1, "G  A  M  E    O  V  E  R");
        mvprintw(9, 1, (this->gameover_message).c_str());
        attroff(A_BOLD);
        attroff(A_ITALIC);
        attroff(COLOR_PAIR(RED));
        
        
        for(int i = 0; i < 2; i++)
        {
            if(i == highlight) attron(A_REVERSE);
            mvprintw(i+11, 1, options[i].c_str());
            if(i == highlight) attroff(A_REVERSE);
        }

        selection = getch();
        switch(selection)
        {
            case KEY_UP:
                highlight--;
                if(highlight < 0) highlight = 1;
            break;

            case KEY_DOWN:
                highlight++;
                if(highlight > 1) highlight = 0;
            break;

            case ENTER:
                this->handle_gameovermenu_selection(highlight);
            break;
        }

        refresh();
    }
    clear();
};

void Game::handle_gameovermenu_selection(int sel)
{
    switch(sel)
    {
        case 0:
            this->clear_dynamic_memory();
            this->resetplayer();
            this->gen_newmap = true;
            this->in_gameover_menu = false;
        break;

        case 1:
            this->inmainmenu = true;
            this->in_gameover_menu = false;
        break;
    }
};

void Game::resetplayer()
{
    (this->player).restore_health();
    (this->player).setposition(PLAYER_INIT_POS_Y, PLAYER_INIT_POS_X);
    (this->player).setfallstate(NOT_FALLING);
    (this->player).resetjumpstate();
    (this->player).setpowerup(PLAYER_DEFAULT_FORM);
    (this->player).setaspect(PLAYER_DEFAULT_FORM);
};

void Game::save()
{
    // save player's health
    FileReader::storeval((this->player).gethealth(), "savedata/playerstats/health.txt");
    
    // save player's score
    FileReader::storeval((this->player_stats).level, "savedata/playerstats/score/level.txt");
    FileReader::storeval((this->player_stats).points, "savedata/playerstats/score/points.txt");
    FileReader::storeval(this->points_buffer, "savedata/playerstats/score/pointsbuffer.txt");

    // save player's unlocked and active projectiles
    FileReader::storeval((this->player_stats).superbullet_unlocked, "savedata/playerstats/projectiles/super_unlocked.txt");
    FileReader::storeval((this->player_stats).hyperbullet_unlocked, "savedata/playerstats/projectiles/hyper_unlocked.txt");
    FileReader::storeval((this->player_stats).laser_unlocked, "savedata/playerstats/projectiles/laser_unlocked.txt");

    // save player's inventory
    FileReader::storeval((this->player_stats).cash, "savedata/playerstats/inventory/cash.txt");
    FileReader::storeval((this->player_stats).forcefield_qty, "savedata/playerstats/inventory/forcefields.txt");
    FileReader::storeval((this->player_stats).vanisher_qty, "savedata/playerstats/inventory/vanishers.txt");

    // save player's position
    FileReader::storeval((this->player).getpos_y(), "savedata/playerstats/position/y.txt");
    FileReader::storeval((this->player).getpos_x(), "savedata/playerstats/position/x.txt");

    // save in-map elements (enemies, cash)
    FileReader::storeval((this->cash_list_manager).getqty() , "savedata/mapstats/cash_inmap.txt");
    FileReader::storeval(((this->enemy_list_manager).runners).getqty(), "savedata/enemystats/runners.txt");
    FileReader::storeval(((this->enemy_list_manager).chargers).getqty(), "savedata/enemystats/chargers.txt");
    FileReader::storeval(((this->enemy_list_manager).followers).getqty(), "savedata/enemystats/followers.txt");
    FileReader::storeval(((this->enemy_list_manager).chasers).getqty(), "savedata/enemystats/chasers.txt");
    FileReader::storeval(((this->enemy_list_manager).shooters).getqty(), "savedata/enemystats/shooters.txt");

    // save map
    int max_pl_y = MAX_PLAYABLE_Y, max_pl_x = MAX_PLAYABLE_X;
    FileReader::storearray(this->currentmap, max_pl_y, max_pl_x, "savedata/mapstats/map.txt");

    // toggle saved flag
    FileReader::storeval(1, "savedata/saved.txt");
};

void Game::load_saved_game()
{
    // load saved map
    int max_pl_y = MAX_PLAYABLE_Y, max_pl_x = MAX_PLAYABLE_X;
    this->currentmap = FileReader::loadarray("savedata/mapstats/map.txt", max_pl_y, max_pl_x);
    Map::buildmap(this->currentmap);
    
    // load player's saved stats
    (this->player).sethealth(FileReader::loadval("savedata/playerstats/health.txt"));
    (this->player_stats).level = FileReader::loadval("savedata/playerstats/score/level.txt");
    (this->player_stats).points = FileReader::loadval("savedata/playerstats/score/points.txt");
    this->points_buffer = FileReader::loadval("savedata/playerstats/score/pointsbuffer.txt");
        
    // load player's unlocked projectiles
    (this->player_stats).superbullet_unlocked = FileReader::loadval("savedata/playerstats/projectiles/super_unlocked.txt");
    (this->player_stats).hyperbullet_unlocked = FileReader::loadval("savedata/playerstats/projectiles/hyper_unlocked.txt");
    (this->player_stats).laser_unlocked = FileReader::loadval("savedata/playerstats/projectiles/laser_unlocked.txt");

    // load player's saved inventory
    (this->player_stats).cash = FileReader::loadval("savedata/playerstats/inventory/cash.txt");
    (this->player_stats).forcefield_qty = FileReader::loadval("savedata/playerstats/inventory/forcefields.txt");
    (this->player_stats).vanisher_qty = FileReader::loadval("savedata/playerstats/inventory/vanishers.txt");

    // load player's saved position
    (this->player).setposition(FileReader::loadval("savedata/playerstats/position/y.txt"), FileReader::loadval("savedata/playerstats/position/x.txt"));

    // load saved map dynamic elements (collectable cash, enemies)
    (this->cash_list_manager).placefixedqty(FileReader::loadval("savedata/mapstats/cash_inmap.txt"));
    ((this->enemy_list_manager).runners).placefixedqty(FileReader::loadval("savedata/enemystats/runners.txt"));
    ((this->enemy_list_manager).chargers).placefixedqty(FileReader::loadval("savedata/enemystats/chargers.txt"));
    ((this->enemy_list_manager).followers).placefixedqty(FileReader::loadval("savedata/enemystats/followers.txt"));
    ((this->enemy_list_manager).chasers).placefixedqty(FileReader::loadval("savedata/enemystats/chasers.txt"));
    ((this->enemy_list_manager.shooters).placefixedqty(FileReader::loadval("savedata/enemystats/shooters.txt")));
}

void Game::resetstats()
{
    (this->player_stats).cash = 0;
    (this->player_stats).forcefield_qty = 0;
    (this->player_stats).hyperbullet_unlocked = false;
    (this->player_stats).laser_unlocked = false;
    (this->player_stats).level = 1;
    (this->player_stats).points = 0;
    this->points_buffer = 0;
    (this->player_stats).superbullet_unlocked = false;
    (this->player_stats).vanisher_qty = 0;
};