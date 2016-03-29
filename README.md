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
    ./pathfindingplusplus ../maps/obstacle2.txt biastar



### Algorithms

For now, the following algorithms can be called (it is not case-sensitive):

- **Dijkstra**: The well known Dijkstra's Algorithm, that explore every tile around the begin in order of distance, until it found the end or doesn't have any more path to explore.
- **A star**: It is an optimization of the Dijkstra's algorithm, giving a priority to path that move close to the end on those that move away.
- **BiDijkstra**: A contraction for *Bi-directional Dijkstra*, it starts two Dijkstra's algorithms: one at the begin and one at the end, that search as usual. The algorithm end when both touch each other or when one of them doesn't have any more path to explore.
- **BiA-star**: The same procedure than *BiDijkstra* but with the *A-star* optimization, with each search algorithm prioritizing movement to another.



## Random mazes testing

In order to directly generate random mazes then solve them, I suggest you to use [this maze generator](https://github.com/Aracthor/madmaze), that can generate mazes at appropriate format for you.  
Clone it, compile it and finally copy the binary in the same directory than pathfindingplusplus. You can then use both on one command line:

    ./madmaze random -x 42 -y 42 -o toto.txt -P 30 -p 1 -w 0 -B B -E E && ./pathfindingplusplus toto.txt astar
