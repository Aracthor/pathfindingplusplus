#ifndef POSITION_HPP_
# define POSITION_HPP_

# include <ostream> // Debug output

namespace algo
{

class	Position
{
public:
    int	x;
    int	y;

public:
    inline Position();
    inline Position(int x, int y);
    inline ~Position();

public:
    void	set(int x, int y);

public:
    inline bool	operator==(const Position& position) const;
};

}

std::ostream&	operator<<(std::ostream& stream, const algo::Position& position);

# include "Position.ipp"

#endif // !POSITION_HPP_
