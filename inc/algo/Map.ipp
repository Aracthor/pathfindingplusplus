namespace algo
{

unsigned int
Map::getWidth() const
{
    return m_width;
}

unsigned int
Map::getHeight() const
{
    return m_height;
}

char
Map::at(unsigned int x, unsigned int y) const
{
    return m_data[y * m_width + x];
}

char
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
