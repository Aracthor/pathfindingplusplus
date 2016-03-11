#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "graphic/Application.hpp"

namespace graphic
{

Application::Application(const std::string& title, unsigned int width, unsigned int height, unsigned int bpp)
{
    sf::VideoMode	videoMode(width, height, bpp);

    m_window = new sf::RenderWindow(videoMode, title);
    m_window->setFramerateLimit(WINDOW_FRAMERATE_LIMIT);
    this->addKeyListener(sf::Keyboard::Escape, &Application::stop);
}


Application::~Application()
{
    delete m_window;
}


void
Application::start()
{
    m_running = true;
    while (m_running)
    {
	this->manageEvents();
	this->manageData();
	m_window->clear();
	this->manageDisplay(m_window);
	m_window->display();
    }
}


void
Application::manageEvents()
{
    sf::Event	event;

    // Close events
    while (m_window->pollEvent(event))
    {
	if (event.type == sf::Event::Closed)
	{
	    this->stop();
	}
    }

    // Key events
    for (auto listener : m_keyListeners)
    {
	if (sf::Keyboard::isKeyPressed(listener.first))
	{
	    (this->*listener.second)();
	}
    }
}

}
