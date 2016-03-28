#ifndef ALGO_BI_DIJKSTRA_HPP_
# define ALGO_BI_DIJKSTRA_HPP_

# include "algo/BiDirectional.hpp"

namespace algo
{

class	BiDijkstra : public BiDirectional
{
public:
    BiDijkstra();
    ~BiDijkstra();

private:
    void	addPositionInQueue(PositionQueue& queue, const Position& position, const Position& origin) override;
};

}

#endif // !ALGO_BI_DIJKSTRA_HPP_
