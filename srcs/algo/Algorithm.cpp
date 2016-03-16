#include "algo/Algorithm.hpp"

namespace algo
{

Algorithm::Algorithm(graphic::Map& map) :
    m_displayMap(map),
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

    if (!display)
    {
	while (!m_solved)
	{
	    this->nextStep();
	}
    }
}

}
