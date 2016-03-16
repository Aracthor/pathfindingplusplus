namespace algo
{

void
Algorithm::colorVisitedTile(const Position& position)
{
    m_displayMap.setTileColor(position.x, position.y, VISITED_TILE_COLOR);
}

void
Algorithm::colorDiscoveredTile(const Position& position)
{
    m_displayMap.setTileColor(position.x, position.y, DISCOVERED_TILE_COLOR);
}

bool
Algorithm::isSolved() const
{
    return (m_solved);
}

}
