namespace graphic
{

unsigned int
Map::getWidth() const
{
    return m_width * TILE_SIZE + TILE_OUTLINE_THICKNESS * 2;
}

unsigned int
Map::getHeight() const
{
    return m_height * TILE_SIZE + TILE_OUTLINE_THICKNESS * 2;
}

}
