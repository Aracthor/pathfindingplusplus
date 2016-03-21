#ifndef ALGO_POSITION_QUEUE_HPP_
# define ALGO_POSITION_QUEUE_HPP_

# include "algo/IPositionComparator.hpp"
# include "algo/Position.hpp"

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
    void		insert(const Position& position, const IPositionComparator* comparator);
    Position&		pop();

public:
    inline unsigned int	getSize() const;
    inline unsigned int	getMaxSize() const;

private:
    inline void		checkPush() const;

private:
    Position*		m_ptr;
    Position*		m_data;
    unsigned int	m_size;
    unsigned int	m_maxSize;
};

}

# include "PositionQueue.ipp"

#endif // !ALGO_POSITION_QUEUE_HPP_
