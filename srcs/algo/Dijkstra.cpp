#include "algo/Dijkstra.hpp"
#include <iostream>

namespace algo
{

Dijkstra::Dijkstra() :
    m_movements
    ({
	{'U', Position(+0, -1)}, // Up
	{'D', Position(+0, +1)}, // Down
	{'R', Position(+1, +0)}, // Right
	{'L', Position(-1, +0)}  // Left
    })
{
}

Dijkstra::~Dijkstra()
{
}


void
Dijkstra::init()
{
    m_positionQueue.resize(m_map->getWidth() * m_map->getHeight());
    m_positionQueue.pushBack(m_map->getBegin());
    m_map->set(m_map->getBegin(), '0');
}

void
Dijkstra::nextStep()
{
    if (m_positionQueue.getSize() == 0)
    {
	this->fail();
    }
    else
    {
	this->tryNextPosition();
    }
}

void
Dijkstra::onSuccess()
{
    Position		position = m_map->getEnd();
    unsigned int	i = 0;

    while (position != m_map->getBegin())
    {
	m_path[i] = position;
	position -= m_movements[m_map->at(position)];
	i++;
    }
    this->reversePath(i);
}


void
Dijkstra::tryNextPosition()
{
    const Position&	position = m_positionQueue.pop();

    if (position == m_map->getEnd())
    {
	this->succeed();
    }
    else
    {
	if (m_display)
	{
	    this->colorVisitedTile(position);
	}
	this->tryAdjacentPositions(position);
    }
}

void
Dijkstra::tryAdjacentPositions(const Position& position)
{
    for (auto movement : m_movements)
    {
	this->tryMovement(position + movement.second, movement.first);
    }
}

void
Dijkstra::tryMovement(const Position& position, char movement)
{
    if (m_map->at(position) == '1')
    {
	m_positionQueue.pushBack(position);
	m_map->set(position, movement);
	if (m_display)
	{
	    this->colorDiscoveredTile(position);
	}
    }
}

}
