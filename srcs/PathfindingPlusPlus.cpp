#include "PathfindingPlusPlus.hpp"

PathfindingPlusPlus::PathfindingPlusPlus(int argc, char** argv) :
    graphic::Application(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT),
    m_map(nullptr),
    m_algorithmList(*m_displayMap)
{
    if (argc != 3)
    {
	throw std::runtime_error(std::string("Usage: ") + argv[0] + " FILE ALGO");
    }
    m_map = m_mapLoader.loadFromFile(argv[1]);
    m_algorithm = m_algorithmList.chooseAlgorithm(argv[2]);

    if (m_map)
    {
	m_displayMap = new graphic::Map(*m_map);

	sf::View	view(sf::Vector2f(m_displayMap->getWidth() / 2, m_displayMap->getHeight() / 2),
			     sf::Vector2f(m_displayMap->getWidth(), m_displayMap->getHeight()));
	m_window->setView(view);
    }
}

PathfindingPlusPlus::~PathfindingPlusPlus()
{
    if (m_map)
    {
	delete m_displayMap;
	delete m_algorithm;
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
