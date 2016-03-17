#include <stdexcept>

#include "algo/PositionQueue.hpp"

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


void
PositionQueue::checkPush() const
{
    if (m_size >= m_maxSize)
    {
	throw std::runtime_error("Inserting position in a full queue.");
    }
}

}
