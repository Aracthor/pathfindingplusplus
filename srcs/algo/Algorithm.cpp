#include "algo/Algorithm.hpp"
#include <iostream> // DEBUG

namespace algo
{

Algorithm::Algorithm() :
    m_map(nullptr)
{
}

Algorithm::~Algorithm()
{
    if (m_map)
    {
	delete m_map;
    }
}


void
Algorithm::solve(const Map& map, Position* path, bool display)
{
    if (m_map)
    {
	delete m_map;
    }
    m_map = new Map(map);
    m_path = path;
    m_solved = false;
    m_display = display;

    this->init();

    if (!display)
    {
	while (!m_solved)
	{
	    this->nextStep();
	}
    }
}


void
Algorithm::fail()
{
    m_solved = true;
    m_path[0] = m_map->getBegin();
}

void
Algorithm::succeed()
{
    m_solved = true;
    this->onSuccess();
    m_display = true;
    if (m_display)
    {
	Position	position = m_path[0];
	unsigned int	i = 0;

	while (position != m_map->getEnd())
	{
	    this->colorPathTile(position);
	    i++;
	    position = m_path[i];
	}
    }
}

void
Algorithm::reversePath(unsigned int size)
{
    unsigned int	i;

    for (i = 0; i < size / 2; i++)
    {
	std::swap(m_path[i], m_path[size - 1 - i]);
    }
}

}
