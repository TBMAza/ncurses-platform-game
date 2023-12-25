cmake_minimum_required(VERSION 3.0)
project(Game)

# Find the ncurses library
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

# Add executable and link ncurses library
add_executable(Game Main.cpp src/map_elements/MapElement.cpp src/map_elements/subclasses/Floor.cpp src/map_elements/subclasses/Cash.cpp src/projectiles/Projectile.cpp src/projectiles/subclasses/Bullet.cpp src/projectiles/subclasses/Superbullet.cpp src/projectiles/subclasses/Hyperbullet.cpp src/projectiles/subclasses/Laser.cpp src/characters/Character.cpp src/characters/subclasses/enemies/Enemy.cpp src/characters/subclasses/enemies/subclasses/Runner.cpp src/characters/subclasses/enemies/subclasses/Charger.cpp src/characters/subclasses/enemies/subclasses/Follower.cpp src/characters/subclasses/enemies/subclasses/Chaser.cpp src/characters/subclasses/enemies/subclasses/Shooter.cpp src/characters/subclasses/player/Player.cpp)
target_link_libraries(Game ${CURSES_LIBRARIES})
