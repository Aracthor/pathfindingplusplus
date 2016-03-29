#ifndef ALGO_ASTAR_SORTER_HPP_
# define ALGO_ASTAR_SORTER_HPP_

# include "algo/IPositionComparator.hpp"
# include "algo/IPositionSorter.hpp"

namespace algo
{

class	AStarSorter : public IPositionSorter,
		      public IPositionComparator
{
public:
    AStarSorter();
    ~AStarSorter();

public:
    void	init(const Map* map) override;
    void	addPositionInQueue(PositionQueue& queue,
				   const Position& position, const Position& origin) override;
    int		compare(const Position& a, const Position& b) const override;

public:
    inline void	setObjective(const Position* position) override;

private:
    int			pointValue(const Position& position) const;
    unsigned int	pointDistance(const Position& position) const;
    void		setDistance(const Position& position, unsigned int distance);

private:
    const Map*		m_map;
    unsigned int*	m_distances;
    const Position*	m_objective;
};

}

# include "AStarSorter.ipp"

#endif // !ALGO_ASTAR_SORTER_HPP_
