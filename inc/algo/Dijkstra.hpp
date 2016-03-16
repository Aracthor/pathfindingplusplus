#ifndef ALGO_DIJKSTRA_HPP_
# define ALGO_DIJKSTRA_HPP_

# include "algo/Algorithm.hpp"

namespace algo
{

class	Dijkstra : public Algorithm
{
public:
    explicit Dijkstra(graphic::Map& map);
    ~Dijkstra();

public:
    void	nextStep() override;
};

}

#endif // !ALGO_DIJKSTRA_HPP_
