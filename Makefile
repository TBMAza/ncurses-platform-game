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

Game.o: Game.cpp.o
.PHONY : Game.o

# target to build an object file
Game.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/Game.cpp.o
.PHONY : Game.cpp.o

Game.i: Game.cpp.i
.PHONY : Game.i

# target to preprocess a source file
Game.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/Game.cpp.i
.PHONY : Game.cpp.i

Game.s: Game.cpp.s
.PHONY : Game.s

# target to generate assembly for a file
Game.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/Game.cpp.s
.PHONY : Game.cpp.s

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

cpp/cash/Cash.o: cpp/cash/Cash.cpp.o
.PHONY : cpp/cash/Cash.o

# target to build an object file
cpp/cash/Cash.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/cash/Cash.cpp.o
.PHONY : cpp/cash/Cash.cpp.o

cpp/cash/Cash.i: cpp/cash/Cash.cpp.i
.PHONY : cpp/cash/Cash.i

# target to preprocess a source file
cpp/cash/Cash.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/cash/Cash.cpp.i
.PHONY : cpp/cash/Cash.cpp.i

cpp/cash/Cash.s: cpp/cash/Cash.cpp.s
.PHONY : cpp/cash/Cash.s

# target to generate assembly for a file
cpp/cash/Cash.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/cash/Cash.cpp.s
.PHONY : cpp/cash/Cash.cpp.s

cpp/characters/Character.o: cpp/characters/Character.cpp.o
.PHONY : cpp/characters/Character.o

# target to build an object file
cpp/characters/Character.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/characters/Character.cpp.o
.PHONY : cpp/characters/Character.cpp.o

cpp/characters/Character.i: cpp/characters/Character.cpp.i
.PHONY : cpp/characters/Character.i

# target to preprocess a source file
cpp/characters/Character.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/characters/Character.cpp.i
.PHONY : cpp/characters/Character.cpp.i

cpp/characters/Character.s: cpp/characters/Character.cpp.s
.PHONY : cpp/characters/Character.s

# target to generate assembly for a file
cpp/characters/Character.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/characters/Character.cpp.s
.PHONY : cpp/characters/Character.cpp.s

cpp/characters/subclasses/enemies/Enemy.o: cpp/characters/subclasses/enemies/Enemy.cpp.o
.PHONY : cpp/characters/subclasses/enemies/Enemy.o

# target to build an object file
cpp/characters/subclasses/enemies/Enemy.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/characters/subclasses/enemies/Enemy.cpp.o
.PHONY : cpp/characters/subclasses/enemies/Enemy.cpp.o

cpp/characters/subclasses/enemies/Enemy.i: cpp/characters/subclasses/enemies/Enemy.cpp.i
.PHONY : cpp/characters/subclasses/enemies/Enemy.i

# target to preprocess a source file
cpp/characters/subclasses/enemies/Enemy.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/characters/subclasses/enemies/Enemy.cpp.i
.PHONY : cpp/characters/subclasses/enemies/Enemy.cpp.i

cpp/characters/subclasses/enemies/Enemy.s: cpp/characters/subclasses/enemies/Enemy.cpp.s
.PHONY : cpp/characters/subclasses/enemies/Enemy.s

# target to generate assembly for a file
cpp/characters/subclasses/enemies/Enemy.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/characters/subclasses/enemies/Enemy.cpp.s
.PHONY : cpp/characters/subclasses/enemies/Enemy.cpp.s

cpp/characters/subclasses/enemies/subclasses/Charger.o: cpp/characters/subclasses/enemies/subclasses/Charger.cpp.o
.PHONY : cpp/characters/subclasses/enemies/subclasses/Charger.o

# target to build an object file
cpp/characters/subclasses/enemies/subclasses/Charger.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/characters/subclasses/enemies/subclasses/Charger.cpp.o
.PHONY : cpp/characters/subclasses/enemies/subclasses/Charger.cpp.o

cpp/characters/subclasses/enemies/subclasses/Charger.i: cpp/characters/subclasses/enemies/subclasses/Charger.cpp.i
.PHONY : cpp/characters/subclasses/enemies/subclasses/Charger.i

# target to preprocess a source file
cpp/characters/subclasses/enemies/subclasses/Charger.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/characters/subclasses/enemies/subclasses/Charger.cpp.i
.PHONY : cpp/characters/subclasses/enemies/subclasses/Charger.cpp.i

cpp/characters/subclasses/enemies/subclasses/Charger.s: cpp/characters/subclasses/enemies/subclasses/Charger.cpp.s
.PHONY : cpp/characters/subclasses/enemies/subclasses/Charger.s

# target to generate assembly for a file
cpp/characters/subclasses/enemies/subclasses/Charger.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/characters/subclasses/enemies/subclasses/Charger.cpp.s
.PHONY : cpp/characters/subclasses/enemies/subclasses/Charger.cpp.s

cpp/characters/subclasses/enemies/subclasses/Chaser.o: cpp/characters/subclasses/enemies/subclasses/Chaser.cpp.o
.PHONY : cpp/characters/subclasses/enemies/subclasses/Chaser.o

# target to build an object file
cpp/characters/subclasses/enemies/subclasses/Chaser.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/characters/subclasses/enemies/subclasses/Chaser.cpp.o
.PHONY : cpp/characters/subclasses/enemies/subclasses/Chaser.cpp.o

cpp/characters/subclasses/enemies/subclasses/Chaser.i: cpp/characters/subclasses/enemies/subclasses/Chaser.cpp.i
.PHONY : cpp/characters/subclasses/enemies/subclasses/Chaser.i

# target to preprocess a source file
cpp/characters/subclasses/enemies/subclasses/Chaser.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/characters/subclasses/enemies/subclasses/Chaser.cpp.i
.PHONY : cpp/characters/subclasses/enemies/subclasses/Chaser.cpp.i

cpp/characters/subclasses/enemies/subclasses/Chaser.s: cpp/characters/subclasses/enemies/subclasses/Chaser.cpp.s
.PHONY : cpp/characters/subclasses/enemies/subclasses/Chaser.s

# target to generate assembly for a file
cpp/characters/subclasses/enemies/subclasses/Chaser.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/characters/subclasses/enemies/subclasses/Chaser.cpp.s
.PHONY : cpp/characters/subclasses/enemies/subclasses/Chaser.cpp.s

cpp/characters/subclasses/enemies/subclasses/Follower.o: cpp/characters/subclasses/enemies/subclasses/Follower.cpp.o
.PHONY : cpp/characters/subclasses/enemies/subclasses/Follower.o

# target to build an object file
cpp/characters/subclasses/enemies/subclasses/Follower.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/characters/subclasses/enemies/subclasses/Follower.cpp.o
.PHONY : cpp/characters/subclasses/enemies/subclasses/Follower.cpp.o

cpp/characters/subclasses/enemies/subclasses/Follower.i: cpp/characters/subclasses/enemies/subclasses/Follower.cpp.i
.PHONY : cpp/characters/subclasses/enemies/subclasses/Follower.i

# target to preprocess a source file
cpp/characters/subclasses/enemies/subclasses/Follower.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/characters/subclasses/enemies/subclasses/Follower.cpp.i
.PHONY : cpp/characters/subclasses/enemies/subclasses/Follower.cpp.i

cpp/characters/subclasses/enemies/subclasses/Follower.s: cpp/characters/subclasses/enemies/subclasses/Follower.cpp.s
.PHONY : cpp/characters/subclasses/enemies/subclasses/Follower.s

# target to generate assembly for a file
cpp/characters/subclasses/enemies/subclasses/Follower.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/characters/subclasses/enemies/subclasses/Follower.cpp.s
.PHONY : cpp/characters/subclasses/enemies/subclasses/Follower.cpp.s

cpp/characters/subclasses/enemies/subclasses/Runner.o: cpp/characters/subclasses/enemies/subclasses/Runner.cpp.o
.PHONY : cpp/characters/subclasses/enemies/subclasses/Runner.o

# target to build an object file
cpp/characters/subclasses/enemies/subclasses/Runner.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/characters/subclasses/enemies/subclasses/Runner.cpp.o
.PHONY : cpp/characters/subclasses/enemies/subclasses/Runner.cpp.o

cpp/characters/subclasses/enemies/subclasses/Runner.i: cpp/characters/subclasses/enemies/subclasses/Runner.cpp.i
.PHONY : cpp/characters/subclasses/enemies/subclasses/Runner.i

# target to preprocess a source file
cpp/characters/subclasses/enemies/subclasses/Runner.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/characters/subclasses/enemies/subclasses/Runner.cpp.i
.PHONY : cpp/characters/subclasses/enemies/subclasses/Runner.cpp.i

cpp/characters/subclasses/enemies/subclasses/Runner.s: cpp/characters/subclasses/enemies/subclasses/Runner.cpp.s
.PHONY : cpp/characters/subclasses/enemies/subclasses/Runner.s

# target to generate assembly for a file
cpp/characters/subclasses/enemies/subclasses/Runner.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/characters/subclasses/enemies/subclasses/Runner.cpp.s
.PHONY : cpp/characters/subclasses/enemies/subclasses/Runner.cpp.s

cpp/characters/subclasses/enemies/subclasses/Shooter.o: cpp/characters/subclasses/enemies/subclasses/Shooter.cpp.o
.PHONY : cpp/characters/subclasses/enemies/subclasses/Shooter.o

# target to build an object file
cpp/characters/subclasses/enemies/subclasses/Shooter.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/characters/subclasses/enemies/subclasses/Shooter.cpp.o
.PHONY : cpp/characters/subclasses/enemies/subclasses/Shooter.cpp.o

cpp/characters/subclasses/enemies/subclasses/Shooter.i: cpp/characters/subclasses/enemies/subclasses/Shooter.cpp.i
.PHONY : cpp/characters/subclasses/enemies/subclasses/Shooter.i

# target to preprocess a source file
cpp/characters/subclasses/enemies/subclasses/Shooter.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/characters/subclasses/enemies/subclasses/Shooter.cpp.i
.PHONY : cpp/characters/subclasses/enemies/subclasses/Shooter.cpp.i

cpp/characters/subclasses/enemies/subclasses/Shooter.s: cpp/characters/subclasses/enemies/subclasses/Shooter.cpp.s
.PHONY : cpp/characters/subclasses/enemies/subclasses/Shooter.s

# target to generate assembly for a file
cpp/characters/subclasses/enemies/subclasses/Shooter.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/characters/subclasses/enemies/subclasses/Shooter.cpp.s
.PHONY : cpp/characters/subclasses/enemies/subclasses/Shooter.cpp.s

cpp/characters/subclasses/player/Player.o: cpp/characters/subclasses/player/Player.cpp.o
.PHONY : cpp/characters/subclasses/player/Player.o

# target to build an object file
cpp/characters/subclasses/player/Player.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/characters/subclasses/player/Player.cpp.o
.PHONY : cpp/characters/subclasses/player/Player.cpp.o

cpp/characters/subclasses/player/Player.i: cpp/characters/subclasses/player/Player.cpp.i
.PHONY : cpp/characters/subclasses/player/Player.i

# target to preprocess a source file
cpp/characters/subclasses/player/Player.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/characters/subclasses/player/Player.cpp.i
.PHONY : cpp/characters/subclasses/player/Player.cpp.i

cpp/characters/subclasses/player/Player.s: cpp/characters/subclasses/player/Player.cpp.s
.PHONY : cpp/characters/subclasses/player/Player.s

# target to generate assembly for a file
cpp/characters/subclasses/player/Player.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/characters/subclasses/player/Player.cpp.s
.PHONY : cpp/characters/subclasses/player/Player.cpp.s

cpp/collision_detector/CollisionDetector.o: cpp/collision_detector/CollisionDetector.cpp.o
.PHONY : cpp/collision_detector/CollisionDetector.o

# target to build an object file
cpp/collision_detector/CollisionDetector.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/collision_detector/CollisionDetector.cpp.o
.PHONY : cpp/collision_detector/CollisionDetector.cpp.o

cpp/collision_detector/CollisionDetector.i: cpp/collision_detector/CollisionDetector.cpp.i
.PHONY : cpp/collision_detector/CollisionDetector.i

# target to preprocess a source file
cpp/collision_detector/CollisionDetector.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/collision_detector/CollisionDetector.cpp.i
.PHONY : cpp/collision_detector/CollisionDetector.cpp.i

cpp/collision_detector/CollisionDetector.s: cpp/collision_detector/CollisionDetector.cpp.s
.PHONY : cpp/collision_detector/CollisionDetector.s

# target to generate assembly for a file
cpp/collision_detector/CollisionDetector.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/collision_detector/CollisionDetector.cpp.s
.PHONY : cpp/collision_detector/CollisionDetector.cpp.s

cpp/filereader/FileReader.o: cpp/filereader/FileReader.cpp.o
.PHONY : cpp/filereader/FileReader.o

# target to build an object file
cpp/filereader/FileReader.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/filereader/FileReader.cpp.o
.PHONY : cpp/filereader/FileReader.cpp.o

cpp/filereader/FileReader.i: cpp/filereader/FileReader.cpp.i
.PHONY : cpp/filereader/FileReader.i

# target to preprocess a source file
cpp/filereader/FileReader.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/filereader/FileReader.cpp.i
.PHONY : cpp/filereader/FileReader.cpp.i

cpp/filereader/FileReader.s: cpp/filereader/FileReader.cpp.s
.PHONY : cpp/filereader/FileReader.s

# target to generate assembly for a file
cpp/filereader/FileReader.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/filereader/FileReader.cpp.s
.PHONY : cpp/filereader/FileReader.cpp.s

cpp/list_manager/CashListManager.o: cpp/list_manager/CashListManager.cpp.o
.PHONY : cpp/list_manager/CashListManager.o

# target to build an object file
cpp/list_manager/CashListManager.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/list_manager/CashListManager.cpp.o
.PHONY : cpp/list_manager/CashListManager.cpp.o

cpp/list_manager/CashListManager.i: cpp/list_manager/CashListManager.cpp.i
.PHONY : cpp/list_manager/CashListManager.i

# target to preprocess a source file
cpp/list_manager/CashListManager.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/list_manager/CashListManager.cpp.i
.PHONY : cpp/list_manager/CashListManager.cpp.i

cpp/list_manager/CashListManager.s: cpp/list_manager/CashListManager.cpp.s
.PHONY : cpp/list_manager/CashListManager.s

# target to generate assembly for a file
cpp/list_manager/CashListManager.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/list_manager/CashListManager.cpp.s
.PHONY : cpp/list_manager/CashListManager.cpp.s

cpp/list_manager/ChargerListManager.o: cpp/list_manager/ChargerListManager.cpp.o
.PHONY : cpp/list_manager/ChargerListManager.o

# target to build an object file
cpp/list_manager/ChargerListManager.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/list_manager/ChargerListManager.cpp.o
.PHONY : cpp/list_manager/ChargerListManager.cpp.o

cpp/list_manager/ChargerListManager.i: cpp/list_manager/ChargerListManager.cpp.i
.PHONY : cpp/list_manager/ChargerListManager.i

# target to preprocess a source file
cpp/list_manager/ChargerListManager.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/list_manager/ChargerListManager.cpp.i
.PHONY : cpp/list_manager/ChargerListManager.cpp.i

cpp/list_manager/ChargerListManager.s: cpp/list_manager/ChargerListManager.cpp.s
.PHONY : cpp/list_manager/ChargerListManager.s

# target to generate assembly for a file
cpp/list_manager/ChargerListManager.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/list_manager/ChargerListManager.cpp.s
.PHONY : cpp/list_manager/ChargerListManager.cpp.s

cpp/list_manager/ChaserListManager.o: cpp/list_manager/ChaserListManager.cpp.o
.PHONY : cpp/list_manager/ChaserListManager.o

# target to build an object file
cpp/list_manager/ChaserListManager.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/list_manager/ChaserListManager.cpp.o
.PHONY : cpp/list_manager/ChaserListManager.cpp.o

cpp/list_manager/ChaserListManager.i: cpp/list_manager/ChaserListManager.cpp.i
.PHONY : cpp/list_manager/ChaserListManager.i

# target to preprocess a source file
cpp/list_manager/ChaserListManager.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/list_manager/ChaserListManager.cpp.i
.PHONY : cpp/list_manager/ChaserListManager.cpp.i

cpp/list_manager/ChaserListManager.s: cpp/list_manager/ChaserListManager.cpp.s
.PHONY : cpp/list_manager/ChaserListManager.s

# target to generate assembly for a file
cpp/list_manager/ChaserListManager.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/list_manager/ChaserListManager.cpp.s
.PHONY : cpp/list_manager/ChaserListManager.cpp.s

cpp/list_manager/FollowerListManager.o: cpp/list_manager/FollowerListManager.cpp.o
.PHONY : cpp/list_manager/FollowerListManager.o

# target to build an object file
cpp/list_manager/FollowerListManager.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/list_manager/FollowerListManager.cpp.o
.PHONY : cpp/list_manager/FollowerListManager.cpp.o

cpp/list_manager/FollowerListManager.i: cpp/list_manager/FollowerListManager.cpp.i
.PHONY : cpp/list_manager/FollowerListManager.i

# target to preprocess a source file
cpp/list_manager/FollowerListManager.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/list_manager/FollowerListManager.cpp.i
.PHONY : cpp/list_manager/FollowerListManager.cpp.i

cpp/list_manager/FollowerListManager.s: cpp/list_manager/FollowerListManager.cpp.s
.PHONY : cpp/list_manager/FollowerListManager.s

# target to generate assembly for a file
cpp/list_manager/FollowerListManager.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/list_manager/FollowerListManager.cpp.s
.PHONY : cpp/list_manager/FollowerListManager.cpp.s

cpp/list_manager/ProjectileListManager.o: cpp/list_manager/ProjectileListManager.cpp.o
.PHONY : cpp/list_manager/ProjectileListManager.o

# target to build an object file
cpp/list_manager/ProjectileListManager.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/list_manager/ProjectileListManager.cpp.o
.PHONY : cpp/list_manager/ProjectileListManager.cpp.o

cpp/list_manager/ProjectileListManager.i: cpp/list_manager/ProjectileListManager.cpp.i
.PHONY : cpp/list_manager/ProjectileListManager.i

# target to preprocess a source file
cpp/list_manager/ProjectileListManager.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/list_manager/ProjectileListManager.cpp.i
.PHONY : cpp/list_manager/ProjectileListManager.cpp.i

cpp/list_manager/ProjectileListManager.s: cpp/list_manager/ProjectileListManager.cpp.s
.PHONY : cpp/list_manager/ProjectileListManager.s

# target to generate assembly for a file
cpp/list_manager/ProjectileListManager.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/list_manager/ProjectileListManager.cpp.s
.PHONY : cpp/list_manager/ProjectileListManager.cpp.s

cpp/list_manager/RunnerListManager.o: cpp/list_manager/RunnerListManager.cpp.o
.PHONY : cpp/list_manager/RunnerListManager.o

# target to build an object file
cpp/list_manager/RunnerListManager.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/list_manager/RunnerListManager.cpp.o
.PHONY : cpp/list_manager/RunnerListManager.cpp.o

cpp/list_manager/RunnerListManager.i: cpp/list_manager/RunnerListManager.cpp.i
.PHONY : cpp/list_manager/RunnerListManager.i

# target to preprocess a source file
cpp/list_manager/RunnerListManager.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/list_manager/RunnerListManager.cpp.i
.PHONY : cpp/list_manager/RunnerListManager.cpp.i

cpp/list_manager/RunnerListManager.s: cpp/list_manager/RunnerListManager.cpp.s
.PHONY : cpp/list_manager/RunnerListManager.s

# target to generate assembly for a file
cpp/list_manager/RunnerListManager.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/list_manager/RunnerListManager.cpp.s
.PHONY : cpp/list_manager/RunnerListManager.cpp.s

cpp/list_manager/ShooterListManager.o: cpp/list_manager/ShooterListManager.cpp.o
.PHONY : cpp/list_manager/ShooterListManager.o

# target to build an object file
cpp/list_manager/ShooterListManager.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/list_manager/ShooterListManager.cpp.o
.PHONY : cpp/list_manager/ShooterListManager.cpp.o

cpp/list_manager/ShooterListManager.i: cpp/list_manager/ShooterListManager.cpp.i
.PHONY : cpp/list_manager/ShooterListManager.i

# target to preprocess a source file
cpp/list_manager/ShooterListManager.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/list_manager/ShooterListManager.cpp.i
.PHONY : cpp/list_manager/ShooterListManager.cpp.i

cpp/list_manager/ShooterListManager.s: cpp/list_manager/ShooterListManager.cpp.s
.PHONY : cpp/list_manager/ShooterListManager.s

# target to generate assembly for a file
cpp/list_manager/ShooterListManager.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/list_manager/ShooterListManager.cpp.s
.PHONY : cpp/list_manager/ShooterListManager.cpp.s

cpp/map/Map.o: cpp/map/Map.cpp.o
.PHONY : cpp/map/Map.o

# target to build an object file
cpp/map/Map.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/map/Map.cpp.o
.PHONY : cpp/map/Map.cpp.o

cpp/map/Map.i: cpp/map/Map.cpp.i
.PHONY : cpp/map/Map.i

# target to preprocess a source file
cpp/map/Map.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/map/Map.cpp.i
.PHONY : cpp/map/Map.cpp.i

cpp/map/Map.s: cpp/map/Map.cpp.s
.PHONY : cpp/map/Map.s

# target to generate assembly for a file
cpp/map/Map.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/map/Map.cpp.s
.PHONY : cpp/map/Map.cpp.s

cpp/projectiles/Projectile.o: cpp/projectiles/Projectile.cpp.o
.PHONY : cpp/projectiles/Projectile.o

# target to build an object file
cpp/projectiles/Projectile.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/projectiles/Projectile.cpp.o
.PHONY : cpp/projectiles/Projectile.cpp.o

cpp/projectiles/Projectile.i: cpp/projectiles/Projectile.cpp.i
.PHONY : cpp/projectiles/Projectile.i

# target to preprocess a source file
cpp/projectiles/Projectile.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/projectiles/Projectile.cpp.i
.PHONY : cpp/projectiles/Projectile.cpp.i

cpp/projectiles/Projectile.s: cpp/projectiles/Projectile.cpp.s
.PHONY : cpp/projectiles/Projectile.s

# target to generate assembly for a file
cpp/projectiles/Projectile.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/projectiles/Projectile.cpp.s
.PHONY : cpp/projectiles/Projectile.cpp.s

cpp/projectiles/subclasses/Bullet.o: cpp/projectiles/subclasses/Bullet.cpp.o
.PHONY : cpp/projectiles/subclasses/Bullet.o

# target to build an object file
cpp/projectiles/subclasses/Bullet.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/projectiles/subclasses/Bullet.cpp.o
.PHONY : cpp/projectiles/subclasses/Bullet.cpp.o

cpp/projectiles/subclasses/Bullet.i: cpp/projectiles/subclasses/Bullet.cpp.i
.PHONY : cpp/projectiles/subclasses/Bullet.i

# target to preprocess a source file
cpp/projectiles/subclasses/Bullet.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/projectiles/subclasses/Bullet.cpp.i
.PHONY : cpp/projectiles/subclasses/Bullet.cpp.i

cpp/projectiles/subclasses/Bullet.s: cpp/projectiles/subclasses/Bullet.cpp.s
.PHONY : cpp/projectiles/subclasses/Bullet.s

# target to generate assembly for a file
cpp/projectiles/subclasses/Bullet.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/projectiles/subclasses/Bullet.cpp.s
.PHONY : cpp/projectiles/subclasses/Bullet.cpp.s

cpp/projectiles/subclasses/Hyperbullet.o: cpp/projectiles/subclasses/Hyperbullet.cpp.o
.PHONY : cpp/projectiles/subclasses/Hyperbullet.o

# target to build an object file
cpp/projectiles/subclasses/Hyperbullet.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/projectiles/subclasses/Hyperbullet.cpp.o
.PHONY : cpp/projectiles/subclasses/Hyperbullet.cpp.o

cpp/projectiles/subclasses/Hyperbullet.i: cpp/projectiles/subclasses/Hyperbullet.cpp.i
.PHONY : cpp/projectiles/subclasses/Hyperbullet.i

# target to preprocess a source file
cpp/projectiles/subclasses/Hyperbullet.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/projectiles/subclasses/Hyperbullet.cpp.i
.PHONY : cpp/projectiles/subclasses/Hyperbullet.cpp.i

cpp/projectiles/subclasses/Hyperbullet.s: cpp/projectiles/subclasses/Hyperbullet.cpp.s
.PHONY : cpp/projectiles/subclasses/Hyperbullet.s

# target to generate assembly for a file
cpp/projectiles/subclasses/Hyperbullet.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/projectiles/subclasses/Hyperbullet.cpp.s
.PHONY : cpp/projectiles/subclasses/Hyperbullet.cpp.s

cpp/projectiles/subclasses/Laser.o: cpp/projectiles/subclasses/Laser.cpp.o
.PHONY : cpp/projectiles/subclasses/Laser.o

# target to build an object file
cpp/projectiles/subclasses/Laser.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/projectiles/subclasses/Laser.cpp.o
.PHONY : cpp/projectiles/subclasses/Laser.cpp.o

cpp/projectiles/subclasses/Laser.i: cpp/projectiles/subclasses/Laser.cpp.i
.PHONY : cpp/projectiles/subclasses/Laser.i

# target to preprocess a source file
cpp/projectiles/subclasses/Laser.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/projectiles/subclasses/Laser.cpp.i
.PHONY : cpp/projectiles/subclasses/Laser.cpp.i

cpp/projectiles/subclasses/Laser.s: cpp/projectiles/subclasses/Laser.cpp.s
.PHONY : cpp/projectiles/subclasses/Laser.s

# target to generate assembly for a file
cpp/projectiles/subclasses/Laser.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/projectiles/subclasses/Laser.cpp.s
.PHONY : cpp/projectiles/subclasses/Laser.cpp.s

cpp/projectiles/subclasses/Superbullet.o: cpp/projectiles/subclasses/Superbullet.cpp.o
.PHONY : cpp/projectiles/subclasses/Superbullet.o

# target to build an object file
cpp/projectiles/subclasses/Superbullet.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/projectiles/subclasses/Superbullet.cpp.o
.PHONY : cpp/projectiles/subclasses/Superbullet.cpp.o

cpp/projectiles/subclasses/Superbullet.i: cpp/projectiles/subclasses/Superbullet.cpp.i
.PHONY : cpp/projectiles/subclasses/Superbullet.i

# target to preprocess a source file
cpp/projectiles/subclasses/Superbullet.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/projectiles/subclasses/Superbullet.cpp.i
.PHONY : cpp/projectiles/subclasses/Superbullet.cpp.i

cpp/projectiles/subclasses/Superbullet.s: cpp/projectiles/subclasses/Superbullet.cpp.s
.PHONY : cpp/projectiles/subclasses/Superbullet.s

# target to generate assembly for a file
cpp/projectiles/subclasses/Superbullet.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/projectiles/subclasses/Superbullet.cpp.s
.PHONY : cpp/projectiles/subclasses/Superbullet.cpp.s

cpp/random_generator/RandomGenerator.o: cpp/random_generator/RandomGenerator.cpp.o
.PHONY : cpp/random_generator/RandomGenerator.o

# target to build an object file
cpp/random_generator/RandomGenerator.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/random_generator/RandomGenerator.cpp.o
.PHONY : cpp/random_generator/RandomGenerator.cpp.o

cpp/random_generator/RandomGenerator.i: cpp/random_generator/RandomGenerator.cpp.i
.PHONY : cpp/random_generator/RandomGenerator.i

# target to preprocess a source file
cpp/random_generator/RandomGenerator.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/random_generator/RandomGenerator.cpp.i
.PHONY : cpp/random_generator/RandomGenerator.cpp.i

cpp/random_generator/RandomGenerator.s: cpp/random_generator/RandomGenerator.cpp.s
.PHONY : cpp/random_generator/RandomGenerator.s

# target to generate assembly for a file
cpp/random_generator/RandomGenerator.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Game.dir/build.make CMakeFiles/Game.dir/cpp/random_generator/RandomGenerator.cpp.s
.PHONY : cpp/random_generator/RandomGenerator.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... Game"
	@echo "... Game.o"
	@echo "... Game.i"
	@echo "... Game.s"
	@echo "... Main.o"
	@echo "... Main.i"
	@echo "... Main.s"
	@echo "... cpp/cash/Cash.o"
	@echo "... cpp/cash/Cash.i"
	@echo "... cpp/cash/Cash.s"
	@echo "... cpp/characters/Character.o"
	@echo "... cpp/characters/Character.i"
	@echo "... cpp/characters/Character.s"
	@echo "... cpp/characters/subclasses/enemies/Enemy.o"
	@echo "... cpp/characters/subclasses/enemies/Enemy.i"
	@echo "... cpp/characters/subclasses/enemies/Enemy.s"
	@echo "... cpp/characters/subclasses/enemies/subclasses/Charger.o"
	@echo "... cpp/characters/subclasses/enemies/subclasses/Charger.i"
	@echo "... cpp/characters/subclasses/enemies/subclasses/Charger.s"
	@echo "... cpp/characters/subclasses/enemies/subclasses/Chaser.o"
	@echo "... cpp/characters/subclasses/enemies/subclasses/Chaser.i"
	@echo "... cpp/characters/subclasses/enemies/subclasses/Chaser.s"
	@echo "... cpp/characters/subclasses/enemies/subclasses/Follower.o"
	@echo "... cpp/characters/subclasses/enemies/subclasses/Follower.i"
	@echo "... cpp/characters/subclasses/enemies/subclasses/Follower.s"
	@echo "... cpp/characters/subclasses/enemies/subclasses/Runner.o"
	@echo "... cpp/characters/subclasses/enemies/subclasses/Runner.i"
	@echo "... cpp/characters/subclasses/enemies/subclasses/Runner.s"
	@echo "... cpp/characters/subclasses/enemies/subclasses/Shooter.o"
	@echo "... cpp/characters/subclasses/enemies/subclasses/Shooter.i"
	@echo "... cpp/characters/subclasses/enemies/subclasses/Shooter.s"
	@echo "... cpp/characters/subclasses/player/Player.o"
	@echo "... cpp/characters/subclasses/player/Player.i"
	@echo "... cpp/characters/subclasses/player/Player.s"
	@echo "... cpp/collision_detector/CollisionDetector.o"
	@echo "... cpp/collision_detector/CollisionDetector.i"
	@echo "... cpp/collision_detector/CollisionDetector.s"
	@echo "... cpp/filereader/FileReader.o"
	@echo "... cpp/filereader/FileReader.i"
	@echo "... cpp/filereader/FileReader.s"
	@echo "... cpp/list_manager/CashListManager.o"
	@echo "... cpp/list_manager/CashListManager.i"
	@echo "... cpp/list_manager/CashListManager.s"
	@echo "... cpp/list_manager/ChargerListManager.o"
	@echo "... cpp/list_manager/ChargerListManager.i"
	@echo "... cpp/list_manager/ChargerListManager.s"
	@echo "... cpp/list_manager/ChaserListManager.o"
	@echo "... cpp/list_manager/ChaserListManager.i"
	@echo "... cpp/list_manager/ChaserListManager.s"
	@echo "... cpp/list_manager/FollowerListManager.o"
	@echo "... cpp/list_manager/FollowerListManager.i"
	@echo "... cpp/list_manager/FollowerListManager.s"
	@echo "... cpp/list_manager/ProjectileListManager.o"
	@echo "... cpp/list_manager/ProjectileListManager.i"
	@echo "... cpp/list_manager/ProjectileListManager.s"
	@echo "... cpp/list_manager/RunnerListManager.o"
	@echo "... cpp/list_manager/RunnerListManager.i"
	@echo "... cpp/list_manager/RunnerListManager.s"
	@echo "... cpp/list_manager/ShooterListManager.o"
	@echo "... cpp/list_manager/ShooterListManager.i"
	@echo "... cpp/list_manager/ShooterListManager.s"
	@echo "... cpp/map/Map.o"
	@echo "... cpp/map/Map.i"
	@echo "... cpp/map/Map.s"
	@echo "... cpp/projectiles/Projectile.o"
	@echo "... cpp/projectiles/Projectile.i"
	@echo "... cpp/projectiles/Projectile.s"
	@echo "... cpp/projectiles/subclasses/Bullet.o"
	@echo "... cpp/projectiles/subclasses/Bullet.i"
	@echo "... cpp/projectiles/subclasses/Bullet.s"
	@echo "... cpp/projectiles/subclasses/Hyperbullet.o"
	@echo "... cpp/projectiles/subclasses/Hyperbullet.i"
	@echo "... cpp/projectiles/subclasses/Hyperbullet.s"
	@echo "... cpp/projectiles/subclasses/Laser.o"
	@echo "... cpp/projectiles/subclasses/Laser.i"
	@echo "... cpp/projectiles/subclasses/Laser.s"
	@echo "... cpp/projectiles/subclasses/Superbullet.o"
	@echo "... cpp/projectiles/subclasses/Superbullet.i"
	@echo "... cpp/projectiles/subclasses/Superbullet.s"
	@echo "... cpp/random_generator/RandomGenerator.o"
	@echo "... cpp/random_generator/RandomGenerator.i"
	@echo "... cpp/random_generator/RandomGenerator.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

