#include "algo/AStar.hpp"

namespace algo
{

AStar::AStar() :
    m_distances(nullptr)
{
}

AStar::~AStar()
{
    if (m_distances)
    {
	delete[] m_distances;
    }
}


int
AStar::compare(const Position& a, const Position& b) const
{
    return (this->pointValue(a) - this->pointValue(b));
}


void
AStar::init()
{
    StepByStep::init();

    if (m_distances)
    {
	delete[] m_distances;
    }
    m_distances = new unsigned int[m_map->getWidth() * m_map->getHeight()];
    this->setDistance(m_map->getBegin(), 0);
}

void
AStar::addPositionInQueue(const Position& position, const Position& origin)
{
    this->setDistance(position, this->pointDistance(origin) + 1);
    m_positionQueue.insert(position, this);
}

int
AStar::pointValue(const Position& position) const
{
    return static_cast<int>(position.distance(m_map->getEnd()) + this->pointDistance(position));
}


unsigned int
AStar::pointDistance(const Position& position) const
{
    return m_distances[position.y * m_map->getWidth() + position.x];
}

void
AStar::setDistance(const Position& position, unsigned int distance)
{
    m_distances[position.y * m_map->getWidth() + position.x] = distance;
}

}
