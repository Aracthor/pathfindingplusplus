#ifndef ALGO_I_POSITION_SORTER_HPP_
# define ALGO_I_POSITION_SORTER_HPP_

# include "algo/Map.hpp"
# include "algo/PositionQueue.hpp"

namespace algo
{

class	IPositionSorter
{
public:
    virtual ~IPositionSorter() {}

public:
    virtual void	init(const Map* map) = 0;
    virtual void	addPositionInQueue(PositionQueue& queue,
					   const Position& position, const Position& origin) = 0;
    virtual void	setObjective(const Position* position) = 0;
};

}

#endif // !ALGO_I_POSITION_SORTER_HPP_
