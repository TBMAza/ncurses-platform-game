# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.28.0/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.28.0/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/alfahad.asaduz/C++/cppgame

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/alfahad.asaduz/C++/cppgame

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running CMake cache editor..."
	/opt/homebrew/Cellar/cmake/3.28.0/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --cyan "Running CMake to regenerate build system..."
	/opt/homebrew/Cellar/cmake/3.28.0/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/alfahad.asaduz/C++/cppgame/CMakeFiles /Users/alfahad.asaduz/C++/cppgame//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/alfahad.asaduz/C++/cppgame/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named Game

# Build rule for target.
Game: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 Game
.PHONY : Game

# fast build rule for target.
Game/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/build
.PHONY : Game/fast

Main.o: Main.cpp.o
.PHONY : Main.o

# target to build an object file
Main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/Main.cpp.o
.PHONY : Main.cpp.o

Main.i: Main.cpp.i
.PHONY : Main.i

# target to preprocess a source file
Main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/Main.cpp.i
.PHONY : Main.cpp.i

Main.s: Main.cpp.s
.PHONY : Main.s

# target to generate assembly for a file
Main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/Main.cpp.s
.PHONY : Main.cpp.s

src/characters/Character.o: src/characters/Character.cpp.o
.PHONY : src/characters/Character.o

# target to build an object file
src/characters/Character.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/src/characters/Character.cpp.o
.PHONY : src/characters/Character.cpp.o

src/characters/Character.i: src/characters/Character.cpp.i
.PHONY : src/characters/Character.i

# target to preprocess a source file
src/characters/Character.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/src/characters/Character.cpp.i
.PHONY : src/characters/Character.cpp.i

src/characters/Character.s: src/characters/Character.cpp.s
.PHONY : src/characters/Character.s

# target to generate assembly for a file
src/characters/Character.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/src/characters/Character.cpp.s
.PHONY : src/characters/Character.cpp.s

src/characters/subclasses/enemies/Enemy.o: src/characters/subclasses/enemies/Enemy.cpp.o
.PHONY : src/characters/subclasses/enemies/Enemy.o

# target to build an object file
src/characters/subclasses/enemies/Enemy.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/src/characters/subclasses/enemies/Enemy.cpp.o
.PHONY : src/characters/subclasses/enemies/Enemy.cpp.o

src/characters/subclasses/enemies/Enemy.i: src/characters/subclasses/enemies/Enemy.cpp.i
.PHONY : src/characters/subclasses/enemies/Enemy.i

# target to preprocess a source file
src/characters/subclasses/enemies/Enemy.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/src/characters/subclasses/enemies/Enemy.cpp.i
.PHONY : src/characters/subclasses/enemies/Enemy.cpp.i

src/characters/subclasses/enemies/Enemy.s: src/characters/subclasses/enemies/Enemy.cpp.s
.PHONY : src/characters/subclasses/enemies/Enemy.s

# target to generate assembly for a file
src/characters/subclasses/enemies/Enemy.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/src/characters/subclasses/enemies/Enemy.cpp.s
.PHONY : src/characters/subclasses/enemies/Enemy.cpp.s

src/characters/subclasses/enemies/subclasses/Charger.o: src/characters/subclasses/enemies/subclasses/Charger.cpp.o
.PHONY : src/characters/subclasses/enemies/subclasses/Charger.o

# target to build an object file
src/characters/subclasses/enemies/subclasses/Charger.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/src/characters/subclasses/enemies/subclasses/Charger.cpp.o
.PHONY : src/characters/subclasses/enemies/subclasses/Charger.cpp.o

src/characters/subclasses/enemies/subclasses/Charger.i: src/characters/subclasses/enemies/subclasses/Charger.cpp.i
.PHONY : src/characters/subclasses/enemies/subclasses/Charger.i

# target to preprocess a source file
src/characters/subclasses/enemies/subclasses/Charger.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/src/characters/subclasses/enemies/subclasses/Charger.cpp.i
.PHONY : src/characters/subclasses/enemies/subclasses/Charger.cpp.i

src/characters/subclasses/enemies/subclasses/Charger.s: src/characters/subclasses/enemies/subclasses/Charger.cpp.s
.PHONY : src/characters/subclasses/enemies/subclasses/Charger.s

# target to generate assembly for a file
src/characters/subclasses/enemies/subclasses/Charger.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/src/characters/subclasses/enemies/subclasses/Charger.cpp.s
.PHONY : src/characters/subclasses/enemies/subclasses/Charger.cpp.s

src/characters/subclasses/enemies/subclasses/Chaser.o: src/characters/subclasses/enemies/subclasses/Chaser.cpp.o
.PHONY : src/characters/subclasses/enemies/subclasses/Chaser.o

# target to build an object file
src/characters/subclasses/enemies/subclasses/Chaser.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/src/characters/subclasses/enemies/subclasses/Chaser.cpp.o
.PHONY : src/characters/subclasses/enemies/subclasses/Chaser.cpp.o

src/characters/subclasses/enemies/subclasses/Chaser.i: src/characters/subclasses/enemies/subclasses/Chaser.cpp.i
.PHONY : src/characters/subclasses/enemies/subclasses/Chaser.i

# target to preprocess a source file
src/characters/subclasses/enemies/subclasses/Chaser.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/src/characters/subclasses/enemies/subclasses/Chaser.cpp.i
.PHONY : src/characters/subclasses/enemies/subclasses/Chaser.cpp.i

src/characters/subclasses/enemies/subclasses/Chaser.s: src/characters/subclasses/enemies/subclasses/Chaser.cpp.s
.PHONY : src/characters/subclasses/enemies/subclasses/Chaser.s

# target to generate assembly for a file
src/characters/subclasses/enemies/subclasses/Chaser.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/src/characters/subclasses/enemies/subclasses/Chaser.cpp.s
.PHONY : src/characters/subclasses/enemies/subclasses/Chaser.cpp.s

src/characters/subclasses/enemies/subclasses/Follower.o: src/characters/subclasses/enemies/subclasses/Follower.cpp.o
.PHONY : src/characters/subclasses/enemies/subclasses/Follower.o

# target to build an object file
src/characters/subclasses/enemies/subclasses/Follower.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/src/characters/subclasses/enemies/subclasses/Follower.cpp.o
.PHONY : src/characters/subclasses/enemies/subclasses/Follower.cpp.o

src/characters/subclasses/enemies/subclasses/Follower.i: src/characters/subclasses/enemies/subclasses/Follower.cpp.i
.PHONY : src/characters/subclasses/enemies/subclasses/Follower.i

# target to preprocess a source file
src/characters/subclasses/enemies/subclasses/Follower.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/src/characters/subclasses/enemies/subclasses/Follower.cpp.i
.PHONY : src/characters/subclasses/enemies/subclasses/Follower.cpp.i

src/characters/subclasses/enemies/subclasses/Follower.s: src/characters/subclasses/enemies/subclasses/Follower.cpp.s
.PHONY : src/characters/subclasses/enemies/subclasses/Follower.s

# target to generate assembly for a file
src/characters/subclasses/enemies/subclasses/Follower.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/src/characters/subclasses/enemies/subclasses/Follower.cpp.s
.PHONY : src/characters/subclasses/enemies/subclasses/Follower.cpp.s

src/characters/subclasses/enemies/subclasses/Runner.o: src/characters/subclasses/enemies/subclasses/Runner.cpp.o
.PHONY : src/characters/subclasses/enemies/subclasses/Runner.o

# target to build an object file
src/characters/subclasses/enemies/subclasses/Runner.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/src/characters/subclasses/enemies/subclasses/Runner.cpp.o
.PHONY : src/characters/subclasses/enemies/subclasses/Runner.cpp.o

src/characters/subclasses/enemies/subclasses/Runner.i: src/characters/subclasses/enemies/subclasses/Runner.cpp.i
.PHONY : src/characters/subclasses/enemies/subclasses/Runner.i

# target to preprocess a source file
src/characters/subclasses/enemies/subclasses/Runner.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/src/characters/subclasses/enemies/subclasses/Runner.cpp.i
.PHONY : src/characters/subclasses/enemies/subclasses/Runner.cpp.i

src/characters/subclasses/enemies/subclasses/Runner.s: src/characters/subclasses/enemies/subclasses/Runner.cpp.s
.PHONY : src/characters/subclasses/enemies/subclasses/Runner.s

# target to generate assembly for a file
src/characters/subclasses/enemies/subclasses/Runner.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/src/characters/subclasses/enemies/subclasses/Runner.cpp.s
.PHONY : src/characters/subclasses/enemies/subclasses/Runner.cpp.s

src/characters/subclasses/enemies/subclasses/Shooter.o: src/characters/subclasses/enemies/subclasses/Shooter.cpp.o
.PHONY : src/characters/subclasses/enemies/subclasses/Shooter.o

# target to build an object file
src/characters/subclasses/enemies/subclasses/Shooter.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/src/characters/subclasses/enemies/subclasses/Shooter.cpp.o
.PHONY : src/characters/subclasses/enemies/subclasses/Shooter.cpp.o

src/characters/subclasses/enemies/subclasses/Shooter.i: src/characters/subclasses/enemies/subclasses/Shooter.cpp.i
.PHONY : src/characters/subclasses/enemies/subclasses/Shooter.i

# target to preprocess a source file
src/characters/subclasses/enemies/subclasses/Shooter.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/src/characters/subclasses/enemies/subclasses/Shooter.cpp.i
.PHONY : src/characters/subclasses/enemies/subclasses/Shooter.cpp.i

src/characters/subclasses/enemies/subclasses/Shooter.s: src/characters/subclasses/enemies/subclasses/Shooter.cpp.s
.PHONY : src/characters/subclasses/enemies/subclasses/Shooter.s

# target to generate assembly for a file
src/characters/subclasses/enemies/subclasses/Shooter.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/src/characters/subclasses/enemies/subclasses/Shooter.cpp.s
.PHONY : src/characters/subclasses/enemies/subclasses/Shooter.cpp.s

src/characters/subclasses/player/Player.o: src/characters/subclasses/player/Player.cpp.o
.PHONY : src/characters/subclasses/player/Player.o

# target to build an object file
src/characters/subclasses/player/Player.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/src/characters/subclasses/player/Player.cpp.o
.PHONY : src/characters/subclasses/player/Player.cpp.o

src/characters/subclasses/player/Player.i: src/characters/subclasses/player/Player.cpp.i
.PHONY : src/characters/subclasses/player/Player.i

# target to preprocess a source file
src/characters/subclasses/player/Player.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/src/characters/subclasses/player/Player.cpp.i
.PHONY : src/characters/subclasses/player/Player.cpp.i

src/characters/subclasses/player/Player.s: src/characters/subclasses/player/Player.cpp.s
.PHONY : src/characters/subclasses/player/Player.s

# target to generate assembly for a file
src/characters/subclasses/player/Player.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/src/characters/subclasses/player/Player.cpp.s
.PHONY : src/characters/subclasses/player/Player.cpp.s

src/map_elements/MapElement.o: src/map_elements/MapElement.cpp.o
.PHONY : src/map_elements/MapElement.o

# target to build an object file
src/map_elements/MapElement.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/src/map_elements/MapElement.cpp.o
.PHONY : src/map_elements/MapElement.cpp.o

src/map_elements/MapElement.i: src/map_elements/MapElement.cpp.i
.PHONY : src/map_elements/MapElement.i

# target to preprocess a source file
src/map_elements/MapElement.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/src/map_elements/MapElement.cpp.i
.PHONY : src/map_elements/MapElement.cpp.i

src/map_elements/MapElement.s: src/map_elements/MapElement.cpp.s
.PHONY : src/map_elements/MapElement.s

# target to generate assembly for a file
src/map_elements/MapElement.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/src/map_elements/MapElement.cpp.s
.PHONY : src/map_elements/MapElement.cpp.s

src/map_elements/subclasses/Cash.o: src/map_elements/subclasses/Cash.cpp.o
.PHONY : src/map_elements/subclasses/Cash.o

# target to build an object file
src/map_elements/subclasses/Cash.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/src/map_elements/subclasses/Cash.cpp.o
.PHONY : src/map_elements/subclasses/Cash.cpp.o

src/map_elements/subclasses/Cash.i: src/map_elements/subclasses/Cash.cpp.i
.PHONY : src/map_elements/subclasses/Cash.i

# target to preprocess a source file
src/map_elements/subclasses/Cash.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/src/map_elements/subclasses/Cash.cpp.i
.PHONY : src/map_elements/subclasses/Cash.cpp.i

src/map_elements/subclasses/Cash.s: src/map_elements/subclasses/Cash.cpp.s
.PHONY : src/map_elements/subclasses/Cash.s

# target to generate assembly for a file
src/map_elements/subclasses/Cash.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/src/map_elements/subclasses/Cash.cpp.s
.PHONY : src/map_elements/subclasses/Cash.cpp.s

src/map_elements/subclasses/Floor.o: src/map_elements/subclasses/Floor.cpp.o
.PHONY : src/map_elements/subclasses/Floor.o

# target to build an object file
src/map_elements/subclasses/Floor.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/src/map_elements/subclasses/Floor.cpp.o
.PHONY : src/map_elements/subclasses/Floor.cpp.o

src/map_elements/subclasses/Floor.i: src/map_elements/subclasses/Floor.cpp.i
.PHONY : src/map_elements/subclasses/Floor.i

# target to preprocess a source file
src/map_elements/subclasses/Floor.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/src/map_elements/subclasses/Floor.cpp.i
.PHONY : src/map_elements/subclasses/Floor.cpp.i

src/map_elements/subclasses/Floor.s: src/map_elements/subclasses/Floor.cpp.s
.PHONY : src/map_elements/subclasses/Floor.s

# target to generate assembly for a file
src/map_elements/subclasses/Floor.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/src/map_elements/subclasses/Floor.cpp.s
.PHONY : src/map_elements/subclasses/Floor.cpp.s

src/projectiles/Projectile.o: src/projectiles/Projectile.cpp.o
.PHONY : src/projectiles/Projectile.o

# target to build an object file
src/projectiles/Projectile.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/src/projectiles/Projectile.cpp.o
.PHONY : src/projectiles/Projectile.cpp.o

src/projectiles/Projectile.i: src/projectiles/Projectile.cpp.i
.PHONY : src/projectiles/Projectile.i

# target to preprocess a source file
src/projectiles/Projectile.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/src/projectiles/Projectile.cpp.i
.PHONY : src/projectiles/Projectile.cpp.i

src/projectiles/Projectile.s: src/projectiles/Projectile.cpp.s
.PHONY : src/projectiles/Projectile.s

# target to generate assembly for a file
src/projectiles/Projectile.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/src/projectiles/Projectile.cpp.s
.PHONY : src/projectiles/Projectile.cpp.s

src/projectiles/subclasses/Bullet.o: src/projectiles/subclasses/Bullet.cpp.o
.PHONY : src/projectiles/subclasses/Bullet.o

# target to build an object file
src/projectiles/subclasses/Bullet.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/src/projectiles/subclasses/Bullet.cpp.o
.PHONY : src/projectiles/subclasses/Bullet.cpp.o

src/projectiles/subclasses/Bullet.i: src/projectiles/subclasses/Bullet.cpp.i
.PHONY : src/projectiles/subclasses/Bullet.i

# target to preprocess a source file
src/projectiles/subclasses/Bullet.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/src/projectiles/subclasses/Bullet.cpp.i
.PHONY : src/projectiles/subclasses/Bullet.cpp.i

src/projectiles/subclasses/Bullet.s: src/projectiles/subclasses/Bullet.cpp.s
.PHONY : src/projectiles/subclasses/Bullet.s

# target to generate assembly for a file
src/projectiles/subclasses/Bullet.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/src/projectiles/subclasses/Bullet.cpp.s
.PHONY : src/projectiles/subclasses/Bullet.cpp.s

src/projectiles/subclasses/Hyperbullet.o: src/projectiles/subclasses/Hyperbullet.cpp.o
.PHONY : src/projectiles/subclasses/Hyperbullet.o

# target to build an object file
src/projectiles/subclasses/Hyperbullet.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/src/projectiles/subclasses/Hyperbullet.cpp.o
.PHONY : src/projectiles/subclasses/Hyperbullet.cpp.o

src/projectiles/subclasses/Hyperbullet.i: src/projectiles/subclasses/Hyperbullet.cpp.i
.PHONY : src/projectiles/subclasses/Hyperbullet.i

# target to preprocess a source file
src/projectiles/subclasses/Hyperbullet.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/src/projectiles/subclasses/Hyperbullet.cpp.i
.PHONY : src/projectiles/subclasses/Hyperbullet.cpp.i

src/projectiles/subclasses/Hyperbullet.s: src/projectiles/subclasses/Hyperbullet.cpp.s
.PHONY : src/projectiles/subclasses/Hyperbullet.s

# target to generate assembly for a file
src/projectiles/subclasses/Hyperbullet.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/src/projectiles/subclasses/Hyperbullet.cpp.s
.PHONY : src/projectiles/subclasses/Hyperbullet.cpp.s

src/projectiles/subclasses/Laser.o: src/projectiles/subclasses/Laser.cpp.o
.PHONY : src/projectiles/subclasses/Laser.o

# target to build an object file
src/projectiles/subclasses/Laser.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/src/projectiles/subclasses/Laser.cpp.o
.PHONY : src/projectiles/subclasses/Laser.cpp.o

src/projectiles/subclasses/Laser.i: src/projectiles/subclasses/Laser.cpp.i
.PHONY : src/projectiles/subclasses/Laser.i

# target to preprocess a source file
src/projectiles/subclasses/Laser.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/src/projectiles/subclasses/Laser.cpp.i
.PHONY : src/projectiles/subclasses/Laser.cpp.i

src/projectiles/subclasses/Laser.s: src/projectiles/subclasses/Laser.cpp.s
.PHONY : src/projectiles/subclasses/Laser.s

# target to generate assembly for a file
src/projectiles/subclasses/Laser.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/src/projectiles/subclasses/Laser.cpp.s
.PHONY : src/projectiles/subclasses/Laser.cpp.s

src/projectiles/subclasses/Superbullet.o: src/projectiles/subclasses/Superbullet.cpp.o
.PHONY : src/projectiles/subclasses/Superbullet.o

# target to build an object file
src/projectiles/subclasses/Superbullet.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/src/projectiles/subclasses/Superbullet.cpp.o
.PHONY : src/projectiles/subclasses/Superbullet.cpp.o

src/projectiles/subclasses/Superbullet.i: src/projectiles/subclasses/Superbullet.cpp.i
.PHONY : src/projectiles/subclasses/Superbullet.i

# target to preprocess a source file
src/projectiles/subclasses/Superbullet.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/src/projectiles/subclasses/Superbullet.cpp.i
.PHONY : src/projectiles/subclasses/Superbullet.cpp.i

src/projectiles/subclasses/Superbullet.s: src/projectiles/subclasses/Superbullet.cpp.s
.PHONY : src/projectiles/subclasses/Superbullet.s

# target to generate assembly for a file
src/projectiles/subclasses/Superbullet.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/src/projectiles/subclasses/Superbullet.cpp.s
.PHONY : src/projectiles/subclasses/Superbullet.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... Game"
	@echo "... Main.o"
	@echo "... Main.i"
	@echo "... Main.s"
	@echo "... src/characters/Character.o"
	@echo "... src/characters/Character.i"
	@echo "... src/characters/Character.s"
	@echo "... src/characters/subclasses/enemies/Enemy.o"
	@echo "... src/characters/subclasses/enemies/Enemy.i"
	@echo "... src/characters/subclasses/enemies/Enemy.s"
	@echo "... src/characters/subclasses/enemies/subclasses/Charger.o"
	@echo "... src/characters/subclasses/enemies/subclasses/Charger.i"
	@echo "... src/characters/subclasses/enemies/subclasses/Charger.s"
	@echo "... src/characters/subclasses/enemies/subclasses/Chaser.o"
	@echo "... src/characters/subclasses/enemies/subclasses/Chaser.i"
	@echo "... src/characters/subclasses/enemies/subclasses/Chaser.s"
	@echo "... src/characters/subclasses/enemies/subclasses/Follower.o"
	@echo "... src/characters/subclasses/enemies/subclasses/Follower.i"
	@echo "... src/characters/subclasses/enemies/subclasses/Follower.s"
	@echo "... src/characters/subclasses/enemies/subclasses/Runner.o"
	@echo "... src/characters/subclasses/enemies/subclasses/Runner.i"
	@echo "... src/characters/subclasses/enemies/subclasses/Runner.s"
	@echo "... src/characters/subclasses/enemies/subclasses/Shooter.o"
	@echo "... src/characters/subclasses/enemies/subclasses/Shooter.i"
	@echo "... src/characters/subclasses/enemies/subclasses/Shooter.s"
	@echo "... src/characters/subclasses/player/Player.o"
	@echo "... src/characters/subclasses/player/Player.i"
	@echo "... src/characters/subclasses/player/Player.s"
	@echo "... src/map_elements/MapElement.o"
	@echo "... src/map_elements/MapElement.i"
	@echo "... src/map_elements/MapElement.s"
	@echo "... src/map_elements/subclasses/Cash.o"
	@echo "... src/map_elements/subclasses/Cash.i"
	@echo "... src/map_elements/subclasses/Cash.s"
	@echo "... src/map_elements/subclasses/Floor.o"
	@echo "... src/map_elements/subclasses/Floor.i"
	@echo "... src/map_elements/subclasses/Floor.s"
	@echo "... src/projectiles/Projectile.o"
	@echo "... src/projectiles/Projectile.i"
	@echo "... src/projectiles/Projectile.s"
	@echo "... src/projectiles/subclasses/Bullet.o"
	@echo "... src/projectiles/subclasses/Bullet.i"
	@echo "... src/projectiles/subclasses/Bullet.s"
	@echo "... src/projectiles/subclasses/Hyperbullet.o"
	@echo "... src/projectiles/subclasses/Hyperbullet.i"
	@echo "... src/projectiles/subclasses/Hyperbullet.s"
	@echo "... src/projectiles/subclasses/Laser.o"
	@echo "... src/projectiles/subclasses/Laser.i"
	@echo "... src/projectiles/subclasses/Laser.s"
	@echo "... src/projectiles/subclasses/Superbullet.o"
	@echo "... src/projectiles/subclasses/Superbullet.i"
	@echo "... src/projectiles/subclasses/Superbullet.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
