#ifndef ALGO_BI_DIRECTIONAL_HPP_
# define ALGO_BI_DIRECTIONAL_HPP_

# include <map>

# include "algo/Algorithm.hpp"
# include "algo/PositionQueue.hpp"

namespace algo
{

class	BiDirectional : public Algorithm
{
public:
    BiDirectional();
    ~BiDirectional();

protected:
    virtual void	init() override;
    virtual void	nextStep() override;
    virtual void	onSuccess() override;

private:
    void		tryNextPosition();
    void		tryAdjacentPositions(const Position& position);
    void		tryMovement(const Position& position, char movement, const Position& origin);
    bool		isSearcherObjective(const Position& position, const Position& origin);
    unsigned int	retracePath(unsigned int searcher, unsigned int pathIndex);

private:
    virtual void	addPositionInQueue(PositionQueue& queue, const Position& position, const Position& origin) = 0;

protected:
    PositionQueue		m_positionQueue[2];
    Position			m_intersections[2];
    unsigned int		m_searcherTurn;

private:
    std::map<char, Position>	m_movements;
};

}

#endif // !ALGO_BI_DIRECTIONAL_HPP_
