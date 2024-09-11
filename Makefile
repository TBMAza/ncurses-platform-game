# Compiler
CXX = g++

# Directories
SRC_DIR = cpp
OBJ_DIR = obj
INCLUDE_DIR = headers

# Source files
SRCS = Main.cpp \
       Game.cpp \
       $(SRC_DIR)/cash/Cash.cpp \
       $(SRC_DIR)/characters/Character.cpp \
       $(SRC_DIR)/characters/subclasses/enemies/Enemy.cpp \
       $(SRC_DIR)/characters/subclasses/enemies/subclasses/Charger.cpp \
       $(SRC_DIR)/characters/subclasses/enemies/subclasses/Chaser.cpp \
       $(SRC_DIR)/characters/subclasses/enemies/subclasses/Follower.cpp \
       $(SRC_DIR)/characters/subclasses/enemies/subclasses/Runner.cpp \
       $(SRC_DIR)/characters/subclasses/enemies/subclasses/Shooter.cpp \
       $(SRC_DIR)/characters/subclasses/player/Player.cpp \
       $(SRC_DIR)/collision_detector/CollisionDetector.cpp \
       $(SRC_DIR)/filereader/FileReader.cpp \
       $(SRC_DIR)/list_manager/CashListManager.cpp \
       $(SRC_DIR)/list_manager/ChargerListManager.cpp \
       $(SRC_DIR)/list_manager/ChaserListManager.cpp \
       $(SRC_DIR)/list_manager/FollowerListManager.cpp \
       $(SRC_DIR)/list_manager/ProjectileListManager.cpp \
       $(SRC_DIR)/list_manager/RunnerListManager.cpp \
       $(SRC_DIR)/list_manager/ShooterListManager.cpp \
       $(SRC_DIR)/map/Map.cpp \
       $(SRC_DIR)/projectiles/Projectile.cpp \
       $(SRC_DIR)/projectiles/subclasses/Bullet.cpp \
       $(SRC_DIR)/projectiles/subclasses/Hyperbullet.cpp \
       $(SRC_DIR)/projectiles/subclasses/Laser.cpp \
       $(SRC_DIR)/projectiles/subclasses/Superbullet.cpp \
       $(SRC_DIR)/random_generator/RandomGenerator.cpp

# Object files
OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)

# Include directories
INCLUDES = -I $(INCLUDE_DIR)

# Executable name
EXEC = Game

# Default rule
all: $(EXEC)

# Link executable
$(EXEC): $(OBJS)
	$(CXX) $(INCLUDES) $^ -o $@ -lncurses

# Compile source files to object files
$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(INCLUDES) -c $< -o $@

# Clean rule
clean:
	rm -rf $(OBJ_DIR) $(EXEC)

.PHONY: all clean
