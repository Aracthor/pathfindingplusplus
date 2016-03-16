#ifndef GRAPHIC_MAP_HPP_
# define GRAPHIC_MAP_HPP_

# include <SFML/Graphics/RectangleShape.hpp>

# include "algo/Map.hpp"

# define TILE_SIZE		0x20
# define WALL_COLOR		sf::Color(0x80, 0x80, 0x80)
# define PATH_COLOR		sf::Color::Black
# define TILE_OUTLINE_THICKNESS	4.0f
# define TILE_OUTLINE_COLOR	sf::Color::White

# define DISCOVERED_TILE_COLOR	sf::Color::Green
# define VISITED_TILE_COLOR	sf::Color::Yellow
# define PATH_TILE_COLOR	sf::Color::Red

namespace graphic
{

class	Map : public sf::Drawable
{
public:
    Map(const algo::Map& map);
    ~Map();

public:
    void		draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const override;

public:
    inline unsigned int	getWidth() const;
    inline unsigned int	getHeight() const;
    inline void		setTileColor(unsigned int x, unsigned int y, const sf::Color& color);

private:
    unsigned int	m_width;
    unsigned int	m_height;
    sf::RectangleShape*	m_shapes;
};

}

# include "Map.ipp"

#endif // !GRAPHIC_MAP_HPP_
