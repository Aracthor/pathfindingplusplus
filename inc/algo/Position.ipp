namespace algo
{

Position::Position()
{
}

Position::Position(int x, int y) :
    x(x),
    y(y)
{
}

Position::~Position()
{
}


bool
Position::operator==(const Position& position) const
{
    return (this->x == position.x && this->y == position.y);
}

}
