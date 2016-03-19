#include <SFML/Graphics/RenderTarget.hpp>

#include "graphic/Map.hpp"

namespace graphic
{

Map::Map(const algo::Map& map) :
    m_width(map.getWidth()),
    m_height(map.getHeight()),
    m_shapes(new sf::RectangleShape[m_width * m_height])
{
    this->initRectangles(map);
    this->initCircles(map);
}

Map::~Map()
{
    delete[] m_shapes;
}


void
Map::initRectangles(const algo::Map& map)
{
    unsigned int	x, y;
    sf::RectangleShape	model;

    model.setSize(sf::Vector2f(TILE_SIZE, TILE_SIZE));
    model.setOutlineThickness(TILE_OUTLINE_THICKNESS);
    model.setOutlineColor(TILE_OUTLINE_COLOR);

    for (x = 0; x < m_width; x++)
    {
	for (y = 0; y < m_height; y++)
	{
	    sf::RectangleShape&	shape = m_shapes[y * m_width + x];
	    shape = model;
	    shape.setFillColor(map.at(x, y) == '0' ? WALL_COLOR : PATH_COLOR);
	    shape.setPosition(x * TILE_SIZE + TILE_OUTLINE_THICKNESS, y * TILE_SIZE + TILE_OUTLINE_THICKNESS);
	}
    }
}


void
Map::initCircles(const algo::Map& map)
{
    sf::CircleShape	model;

    model.setRadius(POINT_RADIUS);
    model.setOutlineThickness(POINT_OUTLINE_THICKNESS);
    model.setOutlineColor(POINT_OUTLINE_COLOR);

    m_begin = model;
    m_begin.setFillColor(BEGIN_FILL_COLOR);
    m_begin.move(map.getBegin().x * TILE_SIZE + POINT_SHIFT, map.getBegin().y * TILE_SIZE + POINT_SHIFT);

    m_end = model;
    m_end.setFillColor(END_FILL_COLOR);
    m_end.move(map.getEnd().x * TILE_SIZE + POINT_SHIFT, map.getEnd().y * TILE_SIZE + POINT_SHIFT);
}


void
Map::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    unsigned int	i;

    for (i = 0; i < m_width * m_height; i++)
    {
	target.draw(m_shapes[i], states);
    }

    target.draw(m_begin, states);
    target.draw(m_end, states);
}

}
