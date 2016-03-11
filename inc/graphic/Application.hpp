#ifndef GRAPHIC_APPLICATION_HPP_
# define GRAPHIC_APPLICATION_HPP_

# include <map>
# include <string>

# include <SFML/Graphics/RenderWindow.hpp>
# include <SFML/Window/Keyboard.hpp>

# define DEFAULT_BPP		32
# define WINDOW_FRAMERATE_LIMIT	60

namespace graphic
{

class	Application
{
public:
    Application(const std::string& title, unsigned int width, unsigned int height, unsigned int bpp = DEFAULT_BPP);
    virtual ~Application();

public:
    void	start();
    inline void	stop();
    template <class APPLICATION> // APPLCATION must inherit from current class
    inline void	addKeyListener(sf::Keyboard::Key key, void (APPLICATION::*function)());

public:
    inline bool	isRunning() const;

protected:
    sf::RenderWindow*				m_window;
    bool					m_running;

private:
    typedef void (Application::*EventFunction)();

private:
    std::map<sf::Keyboard::Key, EventFunction>	m_keyListeners;

private:
    void		manageEvents();
    virtual void	manageData() = 0;
    virtual void	manageDisplay(sf::RenderWindow* window) const = 0;
};

}

# include "Application.ipp"

#endif // !GRAPHIC_APPLICATION_HPP_
