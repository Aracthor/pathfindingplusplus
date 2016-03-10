#ifndef MAP_HPP_
# define MAP_HPP_

# include "algo/Position.hpp"

namespace algo
{

class	Map
{
public:
    Map(const unsigned char* data, int width, int height);
    Map(const Map& map);
    ~Map();

public:
    inline int			getWidth() const;
    inline int			getHeight() const;
    inline unsigned char	at(int x, int y) const;
    inline unsigned char	at(const Position& position) const;
    void			print(const int* path = NULL, int pathSize = 0) const;

public:
    inline void			set(const Position& position, char step);

private:
    unsigned char*		m_data;
    const int			m_width;
    const int			m_height;
};

}

# include "Map.ipp"

#endif // !MAP_HPP_
