#include <cassert>

namespace algo
{

void
PositionQueue::checkPush() const
{
    assert(m_size < m_maxSize);
}


unsigned int
PositionQueue::getSize() const
{
    return m_size;
}

unsigned int
PositionQueue::getMaxSize() const
{
    return m_maxSize;
}

}
