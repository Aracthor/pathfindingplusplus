#ifndef MAP_HPP_
# define MAP_HPP_

# include "algo/Position.hpp"

namespace algo
{

class	Map
{
public:
    Map(const char* data, unsigned int width, unsigned int height, const Position& begin, const Position& end);
    Map(const Map& map);
    ~Map();

public:
    inline unsigned int	getWidth() const;
    inline unsigned int	getHeight() const;
    inline char		at(unsigned int x, unsigned int y) const;
    inline char		at(const Position& position) const;
    void		print(const int* path = NULL, unsigned int pathSize = 0) const;

public:
    inline void	        set(const Position& position, char step);

private:
    char*		m_data;
    const unsigned int	m_width;
    const unsigned int	m_height;
    Position		m_begin;
    Position		m_end;
};

}

# include "Map.ipp"

#endif // !MAP_HPP_
