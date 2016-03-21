namespace algo
{

Position::Position()
{
}

Position::Position(unsigned int x, unsigned int y) :
    x(x),
    y(y)
{
}

Position::~Position()
{
}


unsigned int
Position::distance(const Position& position) const
{
    return (abs(this->x - position.x) + abs(this->y - position.y));
}


bool
Position::operator==(const Position& position) const
{
    return (this->x == position.x && this->y == position.y);
}

bool
Position::operator!=(const Position& position) const
{
    return (!(*this == position));
}


Position
Position::operator+(const Position& position) const
{
    return Position(this->x + position.x, this->y + position.y);
}

Position
Position::operator-(const Position& position) const
{
    return Position(this->x - position.x, this->y - position.y);
}

}
