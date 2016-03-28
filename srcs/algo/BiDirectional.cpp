#include "algo/BiDirectional.hpp"

namespace algo
{

BiDirectional::BiDirectional(IPositionSorter* sorter) :
    m_movements
    ({
	{'U', Position(+0, -1)}, // Up
	{'D', Position(+0, +1)}, // Down
	{'R', Position(+1, +0)}, // Right
	{'L', Position(-1, +0)}  // Left
    }),
    m_sorter(sorter)
{
}

BiDirectional::~BiDirectional()
{
}


void
BiDirectional::init()
{
    m_positionQueue[0].resize(m_map->getWidth() * m_map->getHeight() / 2);
    m_positionQueue[0].pushBack(m_map->getBegin());
    m_positionQueue[1].resize(m_map->getWidth() * m_map->getHeight() / 2);
    m_positionQueue[1].pushBack(m_map->getEnd());
    m_map->set(m_map->getBegin(), '0');
    m_map->set(m_map->getEnd(), '0');

    m_searcherTurn = 0;

    m_sorter->init(m_map);
}

void
BiDirectional::nextStep()
{
    if (m_positionQueue[m_searcherTurn].getSize() == 0)
    {
	this->fail();
    }
    else
    {
	m_sorter->setObjective(m_searcherTurn == 0 ? &m_map->getEnd() : &m_map->getBegin());
	this->tryNextPosition();
    }

    m_searcherTurn = !m_searcherTurn;
}

void
BiDirectional::onSuccess()
{
    unsigned int	size;

    size = this->retracePath(m_searcherTurn, 0);
    this->reversePath(size);
    size = this->retracePath(!m_searcherTurn, size);
    m_path[size] = m_map->getEnd();
}


void
BiDirectional::tryNextPosition()
{
    const Position&	position = m_positionQueue[m_searcherTurn].pop();

    if (m_display)
    {
	this->colorVisitedTile(position);
    }
    this->tryAdjacentPositions(position);
}

void
BiDirectional::tryAdjacentPositions(const Position& position)
{
    char	movementChar;

    for (auto movement : m_movements)
    {
	movementChar = movement.first;
	if (m_searcherTurn == 1)
	{
	    movementChar += 0x20;
	}
	this->tryMovement(position + movement.second, movementChar, position);
    }
}

void
BiDirectional::tryMovement(const Position& position, char movement, const Position& origin)
{
    if (m_map->at(position) != '0')
    {
	if (this->isSearcherObjective(position, origin) && !m_solved)
	{
	    this->succeed();
	}
	else if (m_map->at(position) == '1')
	{
	    m_sorter->addPositionInQueue(m_positionQueue[m_searcherTurn], position, origin);
	    m_map->set(position, movement);
	    if (m_display)
	    {
		this->colorDiscoveredTile(position);
	    }
	}
    }
}

bool
BiDirectional::isSearcherObjective(const Position& position, const Position& origin)
{
    char	c = m_map->at(position) - (m_searcherTurn == 0 ? 0x20 : 0);

    if (c >= 'A' && c <= 'Z')
    {
	m_intersections[m_searcherTurn] = position;
	m_intersections[!m_searcherTurn] = origin;
	return true;
    }
    return false;
}

unsigned int
BiDirectional::retracePath(unsigned int searcher, unsigned int pathIndex)
{
    Position		position = m_intersections[searcher];
    const Position&	objective = (searcher == 1) ? m_map->getBegin() : m_map->getEnd();
    unsigned int	i = 0;
    unsigned int	difference = (searcher == 1) ? 0 : 0x20;

    while (position != objective)
    {
	m_path[pathIndex] = position;
	position -= m_movements[m_map->at(position) - difference];
	pathIndex++;
    }

    return pathIndex;
}

}
