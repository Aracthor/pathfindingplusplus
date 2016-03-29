#ifndef ALGO_BI_DIRECTIONAL_HPP_
# define ALGO_BI_DIRECTIONAL_HPP_

# include <map>

# include "algo/Algorithm.hpp"
# include "algo/IPositionSorter.hpp"
# include "algo/PositionQueue.hpp"

namespace algo
{

class	BiDirectional : public Algorithm
{
public:
    explicit BiDirectional(IPositionSorter* sorter);
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
    PositionQueue		m_positionQueue[2];
    Position			m_intersections[2];
    unsigned int		m_searcherTurn;
    std::map<char, Position>	m_movements;
    IPositionSorter*		m_sorter;
};

}

#endif // !ALGO_BI_DIRECTIONAL_HPP_
