#ifndef GRAPHIC_PATHFINDING_PLUS_PLUS_HPP_
# define GRAPHIC_PATHFINDING_PLUS_PLUS_HPP_

# include "graphic/Application.hpp"

# define WINDOW_WIDTH	800
# define WINDOW_HEIGHT	600
# define WINDOW_TITLE	"Pathfinding++"

class	PathfindingPlusPlus : public graphic::Application
{
public:
    PathfindingPlusPlus();
    ~PathfindingPlusPlus();

private:
    void	manageData() override;
    void	manageDisplay(sf::RenderWindow* window) const override;
};

# include "PathfindingPlusPlus.ipp"

#endif // !GRAPHIC_PATHFINDING_PLUS_PLUS_HPP_
