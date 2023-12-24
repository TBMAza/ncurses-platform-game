cmake_minimum_required(VERSION 3.0)
project(Game)

# Find the ncurses library
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

# Add executable and link ncurses library
add_executable(Game Main.cpp)
target_link_libraries(Game ${CURSES_LIBRARIES})
