#ifndef ALGO_CLOCK_HPP_
# define ALGO_CLOCK_HPP_

namespace algo
{

class	Clock
{
public:
    typedef unsigned long	time;

public:
    Clock();
    ~Clock();

public:
    void	update();
    time	reset();

public:
    inline bool	isRunning() const;
    inline time	getElapsedTime() const;

public:
    inline void	setRunning(bool running);

private:
    time	getCurrentTime() const;

private:
    bool	m_running;
    time	m_start;
    time	m_elapsedTime;
};

}

# include "Clock.ipp"

#endif // !ALGO_CLOCK_HPP_
