#include "algo/Position.hpp"

namespace algo
{

void
Position::set(unsigned int x, unsigned int y)
{
    this->x = x;
    this->y = y;
}


Position&
Position::operator+=(const Position& position)
{
    this->x += position.x;
    this->y += position.y;
    return *this;
}

Position&
Position::operator-=(const Position& position)
{
    this->x -= position.x;
    this->y -= position.y;
    return *this;
}

}

std::ostream&
operator<<(std::ostream& stream, const algo::Position& position)
{
    return (stream << position.x << ", " << position.y);
}
