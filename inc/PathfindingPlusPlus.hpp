#ifndef GRAPHIC_PATHFINDING_PLUS_PLUS_HPP_
# define GRAPHIC_PATHFINDING_PLUS_PLUS_HPP_

# include "algo/MapLoader.hpp"
# include "graphic/Application.hpp"
# include "graphic/Map.hpp"

# define WINDOW_WIDTH	800
# define WINDOW_HEIGHT	600
# define WINDOW_TITLE	"Pathfinding++"

class	PathfindingPlusPlus : public graphic::Application
{
public:
    PathfindingPlusPlus(int argc, char** argv);
    ~PathfindingPlusPlus();

private:
    void		manageData() override;
    void		manageDisplay(sf::RenderWindow* window) const override;

private:
    algo::MapLoader	m_mapLoader;
    algo::Map*		m_map;
    graphic::Map*	m_displayMap;
};

# include "PathfindingPlusPlus.ipp"

#endif // !GRAPHIC_PATHFINDING_PLUS_PLUS_HPP_
