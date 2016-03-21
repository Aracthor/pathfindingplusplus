#include "algo/StepByStep.hpp"

namespace algo
{

StepByStep::StepByStep() :
    m_movements
    ({
	{'U', Position(+0, -1)}, // Up
	{'D', Position(+0, +1)}, // Down
	{'R', Position(+1, +0)}, // Right
	{'L', Position(-1, +0)}  // Left
    })
{
}

StepByStep::~StepByStep()
{
}


void
StepByStep::init()
{
    m_positionQueue.resize(m_map->getWidth() * m_map->getHeight());
    m_positionQueue.pushBack(m_map->getBegin());
    m_map->set(m_map->getBegin(), '0');
}

void
StepByStep::nextStep()
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
StepByStep::onSuccess()
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
StepByStep::tryNextPosition()
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
StepByStep::tryAdjacentPositions(const Position& position)
{
    for (auto movement : m_movements)
    {
	this->tryMovement(position + movement.second, movement.first, position);
    }
}

void
StepByStep::tryMovement(const Position& position, char movement, const Position& origin)
{
    if (m_map->at(position) == '1')
    {
	this->addPositionInQueue(position, origin);
	m_map->set(position, movement);
	if (m_display)
	{
	    this->colorDiscoveredTile(position);
	}
    }
}

}
