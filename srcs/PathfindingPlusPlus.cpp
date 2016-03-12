#include "PathfindingPlusPlus.hpp"

PathfindingPlusPlus::PathfindingPlusPlus(int argc, char** argv) :
    graphic::Application(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT),
    m_map(nullptr)
{
    if (argc != 3)
    {
	throw std::runtime_error(std::string("Usage: ") + argv[0] + " FILE ALGO");
    }
    m_mapLoader.loadFromFile(argv[1]);
}

PathfindingPlusPlus::~PathfindingPlusPlus()
{
    if (m_map)
    {
	delete m_map;
    }
}


void
PathfindingPlusPlus::manageData()
{
}

void
PathfindingPlusPlus::manageDisplay(sf::RenderWindow* window) const
{
    (void)window;
}
