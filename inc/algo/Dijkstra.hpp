#ifndef ALGO_DIJKSTRA_HPP_
# define ALGO_DIJKSTRA_HPP_

# include "algo/StepByStep.hpp"

namespace algo
{

class	Dijkstra : public StepByStep
{
public:
    Dijkstra();
    ~Dijkstra();

private:
    void	addPositionInQueue(const Position& position, const Position& origin) override;
};

}

#endif // !ALGO_DIJKSTRA_HPP_
