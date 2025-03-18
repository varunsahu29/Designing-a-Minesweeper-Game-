cmake_minimum_required(VERSION 3.10)
project(Minesweeper)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source files
set(SOURCES 
    src/Game.cpp 
    src/Board.cpp 
    src/Cell.cpp
    logger/Logger.cpp
)

# Include directories
include_directories(include logger)

# Create the main Minesweeper executable
add_executable(minesweeper main.cpp ${SOURCES})


