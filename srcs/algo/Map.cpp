#include <iostream> // For debug print

#include "algo/Map.hpp"

namespace algo
{

Map::Map(const char* data, unsigned int width, unsigned int height, const Position& begin, const Position& end) :
    m_width(width),
    m_height(height),
    m_begin(begin),
    m_end(end)
{
    unsigned int	size = m_width * m_height;
    unsigned int	i;

    m_data = new char[size];
    for (i = 0; i < size; i++)
    {
	m_data[i] = data[i];
    }
}

Map::Map(const Map& map) :
    m_width(map.getWidth()),
    m_height(map.getHeight())
{
    unsigned int	i = 0;
    unsigned int	x;
    unsigned int	y;

    m_data = new char[m_width * m_height];
    for (y = 0; y < m_height; y++)
    {
	for (x = 0; x < m_width; x++)
	{
	    m_data[i] = map.at(x, y);
	    i++;
	}
    }
}

Map::~Map()
{
    delete[] m_data;
}


void
Map::print(const int* path, unsigned int pathSize) const
{
    unsigned int	x, y;
    unsigned int	i;
    char		tile;
    bool		isInPath;

    for (y = 0; y < m_height; y++)
    {
	for (x = 0; x < m_width; x++)
	{
	    tile = this->at(x, y);
	    if (tile == 0 || tile == 1)
	    {
		tile += '0';
	    }
	    isInPath = false;
	    if (path != NULL)
	    {
		for (i = 0; i < pathSize; i++)
		{
		    if (path[i] == y * m_width + x)
		    {
			isInPath = true;
			break;
		    }
		}
	    }

	    if (isInPath)
	    {
		std::cout << "\033[01m";
	    }
	    std::cout << tile << ' ';
	    if (isInPath)
	    {
		std::cout << "\033[0m";
	    }
	}
	std::cout << std::endl;
    }
    std::cout << std::endl;
}

}
