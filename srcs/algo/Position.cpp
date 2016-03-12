#include "algo/Position.hpp"

namespace algo
{

void
Position::set(unsigned int x, unsigned int y)
{
    this->x = x;
    this->y = y;
}

}

std::ostream&
operator<<(std::ostream& stream, const algo::Position& position)
{
    return (stream << position.x << ", " << position.y);
}
