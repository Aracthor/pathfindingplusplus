namespace algo
{

void
Algorithm::setDisplayMap(graphic::Map* map)
{
    m_displayMap = map;
}


void
Algorithm::colorVisitedTile(const Position& position)
{
    m_displayMap->setTileColor(position.x, position.y, VISITED_TILE_COLOR);
}

void
Algorithm::colorDiscoveredTile(const Position& position)
{
    m_displayMap->setTileColor(position.x, position.y, DISCOVERED_TILE_COLOR);
}

void
Algorithm::colorPathTile(const Position& position)
{
    m_displayMap->setTileColor(position.x, position.y, PATH_TILE_COLOR);
}

bool
Algorithm::isSolved() const
{
    return (m_solved);
}

}
