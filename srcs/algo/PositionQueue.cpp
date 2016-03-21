#include <stdexcept>

#include "algo/PositionQueue.hpp"

#include <cstring>

namespace algo
{

PositionQueue::PositionQueue() :
    m_ptr(nullptr),
    m_size(0),
    m_maxSize(0)
{
}

PositionQueue::~PositionQueue()
{
    if (m_ptr)
    {
	delete[] m_ptr;
    }
}


void
PositionQueue::resize(unsigned int maxSize)
{
    if (m_ptr)
    {
	delete[] m_ptr;
    }
    m_ptr = new Position[maxSize];
    m_data = m_ptr;
    m_size = 0;
    m_maxSize = maxSize;
}

void
PositionQueue::pushBack(const Position& position)
{
    this->checkPush();
    m_data[m_size] = position;
    m_size++;
}

void
PositionQueue::insert(const Position& position, const IPositionComparator* comparator)
{
    unsigned int	index;
    unsigned int	i;

    this->checkPush();

    index = 0;
    while (index < m_size && comparator->compare(m_data[index], position) < 0)
    {
	index++;
    }

    i = m_size;
    while (i > index)
    {
    	m_data[i] = m_data[i - 1];
    	i--;
    }
    m_data[index] = position;

    m_size++;
}

Position&
PositionQueue::pop()
{
    if (m_size == 0)
    {
	throw std::runtime_error("Popping position from an empty queue.");
    }
    m_data++;
    m_size--;

    return m_data[-1];
}

}
