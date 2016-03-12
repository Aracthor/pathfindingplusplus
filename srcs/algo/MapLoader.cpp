#include <fstream>
#include <stdexcept>

#include "algo/MapLoader.hpp"

namespace algo
{

MapLoader::MapLoader()
{
}

MapLoader::~MapLoader()
{
}


Map*
MapLoader::loadFromFile(const std::string& fileName)
{
    std::ifstream	file(fileName);

    if (file.is_open())
    {
	return this->loadFromStream(file);
    }
    else
    {
	throw std::runtime_error("Cannot open file " + fileName + '.');
    }
}

Map*
MapLoader::loadFromStream(std::istream& stream)
{
    std::string		line;

    this->resetData();

    while (std::getline(stream, line))
    {
	this->loadLine(line);
    }

    if (m_begin.x == m_width)
    {
	throw std::runtime_error("Error loading map: missing begin.");
    }
    if (m_end.x == m_width)
    {
	throw std::runtime_error("Error loading map: missing end.");
    }

    return new Map(m_data.data(), m_width, m_height, m_begin, m_end);
}


void
MapLoader::resetData()
{
    m_width = 0;
    m_height = 0;
    m_data.clear();
}

void
MapLoader::loadLine(const std::string& line)
{
    unsigned int	x;

    m_height++;
    if (m_width == 0)
    {
	m_width = line.length();
	// Set absurd values to represent "undefied" data.
	m_begin.x = m_width;
	m_end.x = m_width;
    }
    else if (m_width != line.length())
    {
        throw std::runtime_error("Error loading map: wrong line size line " + std::to_string(m_height));
    }

    x = 0;
    for (char c : line)
    {
	if (c == 'B')
	{
	    this->setPosition(m_begin, x, m_height);
	    m_data.push_back('1');
	}
	else if (c == 'E')
	{
	    this->setPosition(m_end, x, m_height);
	    m_data.push_back('1');
	}
	else if (c == '0' || c == '1')
	{
	    m_data.push_back(c);
	}
	else
	{
	    throw std::runtime_error("Error loading map: unrecognized character:" + std::to_string(m_height) + ':' + std::to_string(x));
	}
	x++;
    }
}

void
MapLoader::setPosition(Position& position, unsigned int x, unsigned int y)
{
    if (position.x != m_width)
    {
	throw std::runtime_error("Position setted twice:" + std::to_string(y) + ':' + std::to_string(x));
    }
    position.set(x, y);
}

}
