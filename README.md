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



## Random mazes testing

In order to directly generate random mazes then solve them, I suggest you to use [this maze generator](https://github.com/Aracthor/madmaze), that can generate mazes at appropriate format for you.  
Clone it, compile it and finally copy the binary in the same directory than pathfindingplusplus. You can then use both on one command line:

    ./madmaze random -x 42 -y 42 -o toto.txt -P 30 -p 1 -w 0 -B B -E E && ./pathfindingplusplus toto.txt astar
