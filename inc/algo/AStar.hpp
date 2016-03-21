#ifndef ALGO_A_STAR_HPP_
# define ALGO_A_STAR_HPP_

# include "algo/IPositionComparator.hpp"
# include "algo/StepByStep.hpp"

namespace algo
{

class	AStar : public StepByStep,
		public IPositionComparator
{
public:
    AStar();
    ~AStar();

public:
    int			compare(const Position& a, const Position& b) const override;

private:
    void		init() override;
    void		addPositionInQueue(const Position& position, const Position& origin) override;
    int			pointValue(const Position& position) const;

private:
    unsigned int	pointDistance(const Position& position) const;
    void		setDistance(const Position& position, unsigned int distance);

private:
    unsigned int*	m_distances;
};

}

#endif // !ALGO_A_STAR_HPP_
