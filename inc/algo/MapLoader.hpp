#ifndef ALGO_MAP_LOADER_HPP_
# define ALGO_MAP_LOADER_HPP_

# include <istream>
# include <string>
# include <vector>

# include "algo/Map.hpp"

namespace algo
{

class	MapLoader
{
public:
    MapLoader();
    ~MapLoader();

public:
    Map*	loadFromFile(const std::string& fileName);
    Map*	loadFromStream(std::istream& stream);

private:
    unsigned int	m_width;
    unsigned int	m_height;
    Position		m_begin;
    Position		m_end;
    std::vector<char>	m_data;

private:
    void	resetData();
    void	loadLine(const std::string& line);
    void	setPosition(Position& position, unsigned int x, unsigned int y);
};

}

#endif // !ALGO_MAP_LOADER_HPP_
