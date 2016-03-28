#include "algo/BiDijkstra.hpp"

namespace algo
{

BiDijkstra::BiDijkstra()
{
}

BiDijkstra::~BiDijkstra()
{
}


void
BiDijkstra::addPositionInQueue(PositionQueue& queue, const Position& position, const Position& origin)
{
    queue.pushBack(position);
    (void)origin;
}

}
