cmake_minimum_required(VERSION 3.0)
project(Game)

# Find the ncurses library
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

# Add executable and link ncurses library
add_executable(Game Main.cpp CollisionDetector.cpp RandomGenerator.cpp cpp/map_elements/Map.cpp cpp/projectiles/Projectile.cpp cpp/projectiles/subclasses/Bullet.cpp cpp/projectiles/subclasses/Superbullet.cpp cpp/projectiles/subclasses/Hyperbullet.cpp cpp/projectiles/subclasses/Laser.cpp cpp/characters/Character.cpp cpp/characters/subclasses/enemies/Enemy.cpp cpp/characters/subclasses/enemies/subclasses/Runner.cpp cpp/characters/subclasses/enemies/subclasses/Charger.cpp cpp/characters/subclasses/enemies/subclasses/Follower.cpp cpp/characters/subclasses/enemies/subclasses/Chaser.cpp cpp/characters/subclasses/enemies/subclasses/Shooter.cpp cpp/characters/subclasses/player/Player.cpp)
target_link_libraries(Game ${CURSES_LIBRARIES})
