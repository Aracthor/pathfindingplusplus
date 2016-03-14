#include <SFML/Graphics/RenderTarget.hpp>

#include "graphic/Map.hpp"

namespace graphic
{

Map::Map(const algo::Map& map) :
    m_width(map.getWidth()),
    m_height(map.getHeight()),
    m_shapes(new sf::RectangleShape[m_width * m_height])
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

Map::~Map()
{
    delete[] m_shapes;
}


void
Map::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    unsigned int	i;

    for (i = 0; i < m_width * m_height; i++)
    {
	target.draw(m_shapes[i], states);
    }
}

}
