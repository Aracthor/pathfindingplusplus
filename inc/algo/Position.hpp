#ifndef POSITION_HPP_
# define POSITION_HPP_

# include <ostream> // Debug output

namespace algo
{

class	Position
{
public:
    unsigned int	x;
    unsigned int	y;

public:
    inline Position();
    inline Position(unsigned int x, unsigned int y);
    inline ~Position();

public:
    void	set(unsigned int x, unsigned int y);

public:
    inline bool	operator==(const Position& position) const;
    inline bool	operator!=(const Position& position) const;

public:
    Position&		operator+=(const Position& position);
    Position&		operator-=(const Position& position);
    inline Position	operator+(const Position& position) const;
    inline Position	operator-(const Position& position) const;
};

}

std::ostream&	operator<<(std::ostream& stream, const algo::Position& position);

# include "Position.ipp"

#endif // !POSITION_HPP_
