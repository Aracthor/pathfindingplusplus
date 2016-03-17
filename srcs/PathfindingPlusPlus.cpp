#include "PathfindingPlusPlus.hpp"

PathfindingPlusPlus::PathfindingPlusPlus(int argc, char** argv) :
    graphic::Application(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT),
    m_map(nullptr)
{
    algo::Clock	clock;

    if (argc != 3)
    {
	throw std::runtime_error(std::string("Usage: ") + argv[0] + " FILE ALGO");
    }
    m_map = m_mapLoader.loadFromFile(argv[1]);

    m_displayMap = new graphic::Map(*m_map);

    sf::View	view(sf::Vector2f(m_displayMap->getWidth() / 2, m_displayMap->getHeight() / 2),
		     sf::Vector2f(m_displayMap->getWidth(), m_displayMap->getHeight()));
    m_window->setView(view);

    m_algorithm = m_algorithmList.chooseAlgorithm(argv[2]);
    m_algorithm->setDisplayMap(m_displayMap);
    if (!m_algorithm)
    {
	throw std::runtime_error(std::string("Unknown algorithm \"") + argv[2] + "\".");
    }
    m_path = new algo::Position[m_map->getWidth() * m_map->getHeight()];

    clock.reset();
    m_algorithm->solve(*m_map, m_path, false);
    clock.update();
    m_lastTime = clock.getElapsedTime();
}

PathfindingPlusPlus::~PathfindingPlusPlus()
{
    if (m_map)
    {
	delete[] m_path;
	delete m_displayMap;
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
    window->draw(*m_displayMap);
}
