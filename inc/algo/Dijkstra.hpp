#ifndef ALGO_DIJKSTRA_HPP_
# define ALGO_DIJKSTRA_HPP_

# include <map>

# include "algo/Algorithm.hpp"
# include "algo/PositionQueue.hpp"

namespace algo
{

class	Dijkstra : public Algorithm
{
public:
    Dijkstra();
    ~Dijkstra();

private:
    void	init() override;
    void	nextStep() override;
    void	onSuccess() override;

private:
    void	tryNextPosition();
    void	tryAdjacentPositions(const Position& position);
    void	tryMovement(const Position& position, char movement);

private:
    PositionQueue		m_positionQueue;
    std::map<char, Position>	m_movements;
};

}

#endif // !ALGO_DIJKSTRA_HPP_
