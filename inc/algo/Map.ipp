namespace algo
{

int
Map::getWidth() const
{
    return m_width;
}

int
Map::getHeight() const
{
    return m_height;
}

unsigned char
Map::at(int x, int y) const
{
    return m_data[y * m_width + x];
}

unsigned char
Map::at(const Position& position) const
{
    return this->at(position.x, position.y);
}


void
Map::set(const Position& position, char step)
{
    m_data[position.y * m_width + position.x] = step;
}

}
