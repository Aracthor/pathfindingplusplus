namespace graphic
{

void
Application::stop()
{
    m_running = false;
}

template <class APPLICATION>
void
Application::addKeyListener(sf::Keyboard::Key key, void (APPLICATION::*function)())
{
    m_keyListeners[key] = reinterpret_cast<EventFunction>(function);
}


bool
Application::isRunning() const
{
    return m_running;
}

}
