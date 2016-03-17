#ifndef ALGO_POSITION_QUEUE_HPP_
# define ALGO_POSITION_QUEUE_HPP_

# include "Position.hpp"

namespace algo
{

class	PositionQueue
{
public:
    PositionQueue();
    ~PositionQueue();

public:
    void		resize(unsigned int maxSize);
    void		pushBack(const Position& position);
    Position&		pop();

public:
    inline unsigned int	getSize() const;
    inline unsigned int	getMaxSize() const;

private:
    void		checkPush() const;

private:
    Position*		m_ptr;
    Position*		m_data;
    unsigned int	m_size;
    unsigned int	m_maxSize;
};

}

# include "PositionQueue.ipp"

#endif // !ALGO_POSITION_QUEUE_HPP_
