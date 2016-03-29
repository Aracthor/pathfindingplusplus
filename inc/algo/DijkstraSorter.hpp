#ifndef ALGO_DIJKSTRA_SORTER_HPP_
# define ALGO_DIJKSTRA_SORTER_HPP_

# include "algo/IPositionSorter.hpp"

namespace algo
{

class	DijkstraSorter : public IPositionSorter
{
public:
    DijkstraSorter();
    ~DijkstraSorter();

public:
    void	init(const Map* map) override;
    void	addPositionInQueue(PositionQueue& queue,
				   const Position& position, const Position& origin) override;
    inline void	setObjective(const Position* position) override {}
};

}

#endif // !ALGO_DIJKSTRA_SORTER_HPP_
