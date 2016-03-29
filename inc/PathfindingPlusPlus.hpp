#ifndef GRAPHIC_PATHFINDING_PLUS_PLUS_HPP_
# define GRAPHIC_PATHFINDING_PLUS_PLUS_HPP_

# include "algo/AlgorithmList.hpp"
# include "algo/Clock.hpp"
# include "algo/MapLoader.hpp"
# include "graphic/Application.hpp"
# include "graphic/Map.hpp"

# define WINDOW_WIDTH	800
# define WINDOW_HEIGHT	800
# define WINDOW_TITLE	"Pathfinding++"

# define ALGO_REFRESH_RATE	50000

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
    algo::AlgorithmList	m_algorithmList;
    algo::Algorithm*	m_algorithm;
    graphic::Map*	m_displayMap;
    algo::Clock		m_clock;
    algo::Clock::time	m_lastTime;
    algo::Position*	m_path;
};

# include "PathfindingPlusPlus.ipp"

#endif // !GRAPHIC_PATHFINDING_PLUS_PLUS_HPP_
