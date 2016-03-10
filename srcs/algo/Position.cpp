#include "algo/Position.hpp"

namespace algo
{

void
Position::set(int x, int y)
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
