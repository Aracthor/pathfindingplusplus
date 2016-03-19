#include "algo/Clock.hpp"

namespace algo
{

Clock::Clock() :
    m_running(true)
{
    this->reset();
}

Clock::~Clock()
{
}


void
Clock::update()
{
    if (m_running)
    {
	time	now = this->getCurrentTime();

	m_elapsedTime = now - m_start;
    }
}

Clock::time
Clock::reset()
{
    Clock::time	now = this->getCurrentTime();
    Clock::time	elapsed = now - m_start;

    m_start = now;
    m_elapsedTime = 0;

    return (elapsed);
}

void
Clock::substractTime(time substraction)
{
    if (substraction > m_elapsedTime)
    {
	m_elapsedTime = 0;
    }
    else
    {
	m_start += substraction;
    }
}

}

#if defined(__unix__) || defined(__unix) || defined(unix)
# include "unix/Clock.cpp"
#elif defined(_WIN32)
# include "win32/Clock.cpp"
#else
# error "No clock availlable for your system."
#endif
