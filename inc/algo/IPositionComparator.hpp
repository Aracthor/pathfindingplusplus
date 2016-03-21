#ifndef ALGO_I_POSITION_COMPARATOR_HPP_
# define ALGO_I_POSITION_COMPARATOR_HPP_

# include "algo/Position.hpp"

namespace algo
{

class	IPositionComparator
{
public:
    virtual ~IPositionComparator() {}

public:
    virtual int	compare(const Position& a, const Position& b) const = 0;
};

}

#endif // !ALGO_I_POSITION_COMPARATOR_HPP_
