#ifndef ALGO_STEP_BY_STEP_HPP_
# define ALGO_STEP_BY_STEP_HPP_

# include <map>

# include "algo/Algorithm.hpp"
# include "algo/IPositionSorter.hpp"
# include "algo/PositionQueue.hpp"

namespace algo
{

class	StepByStep : public Algorithm
{
public:
    explicit StepByStep(IPositionSorter* sorter);
    ~StepByStep();

protected:
    virtual void	init() override;
    virtual void	nextStep() override;
    virtual void	onSuccess() override;

private:
    void		tryNextPosition();
    void		tryAdjacentPositions(const Position& position);
    void		tryMovement(const Position& position, char movement, const Position& origin);

private:
    PositionQueue		m_positionQueue;
    std::map<char, Position>	m_movements;
    IPositionSorter*		m_sorter;
};

}

#endif // !ALGO_STEP_BY_STEP_HPP_
