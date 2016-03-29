#include "algo/AStarSorter.hpp"

namespace algo
{

AStarSorter::AStarSorter() :
    m_distances(nullptr)
{
}

AStarSorter::~AStarSorter()
{
    if (m_distances)
    {
	delete[] m_distances;
    }
}

void
AStarSorter::init(const Map* map)
{
    m_map = map;
    if (m_distances)
    {
	delete[] m_distances;
    }
    m_distances = new unsigned int[map->getWidth() * map->getHeight()];
    m_objective = &m_map->getEnd();
    this->setDistance(map->getBegin(), 0);
}

void
AStarSorter::addPositionInQueue(PositionQueue& queue,
				const Position& position, const Position& origin)
{
    this->setDistance(position, this->pointDistance(origin) + 1);
    queue.insert(position, this);
}

int
AStarSorter::compare(const Position& a, const Position& b) const
{
    return (this->pointValue(a) - this->pointValue(b));
}


int
AStarSorter::pointValue(const Position& position) const
{
    return static_cast<int>(position.distance(*m_objective) + this->pointDistance(position));
}

unsigned int
AStarSorter::pointDistance(const Position& position) const
{
    return m_distances[position.y * m_map->getWidth() + position.x];
}

void
AStarSorter::setDistance(const Position& position, unsigned int distance)
{
    m_distances[position.y * m_map->getWidth() + position.x] = distance;
}

}
