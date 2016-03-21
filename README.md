# pathfindingplusplus

A graphic representation of pathfinding algorithms on 2D grids in C++.

## Compilation

    mkdir build
    cd build
    cmake ..
    make

## Usage

    ./pathfindingplusplus MAP ALGO

For instance:

    ./pathfindingplusplus ../maps/empty_room.txt dijkstra
    ./pathfindingplusplus ../maps/empty_room.txt astar
    ./pathfindingplusplus ../maps/obstacle2.txt astar
