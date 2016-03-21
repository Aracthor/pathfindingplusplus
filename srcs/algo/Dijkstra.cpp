#include "algo/Dijkstra.hpp"

namespace algo
{

Dijkstra::Dijkstra()
{
}

Dijkstra::~Dijkstra()
{
}


void
Dijkstra::addPositionInQueue(const Position& position, const Position& origin)
{
    m_positionQueue.pushBack(position);
    (void)origin;
}

}
