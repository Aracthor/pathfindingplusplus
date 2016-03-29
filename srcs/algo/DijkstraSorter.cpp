#include "algo/DijkstraSorter.hpp"

namespace algo
{

DijkstraSorter::DijkstraSorter()
{
}

DijkstraSorter::~DijkstraSorter()
{
}


void
DijkstraSorter::init(const Map* map)
{
    (void)map;
}

void
DijkstraSorter::addPositionInQueue(PositionQueue& queue,
				   const Position& position, const Position& origin)
{
    queue.pushBack(position);
    (void)origin;
}

}
