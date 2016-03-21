#ifndef ALGO_STEP_BY_STEP_HPP_
# define ALGO_STEP_BY_STEP_HPP_

# include <map>

# include "algo/Algorithm.hpp"
# include "algo/PositionQueue.hpp"

namespace algo
{

class	StepByStep : public Algorithm
{
public:
    StepByStep();
    ~StepByStep();

protected:
    virtual void	init() override;
    virtual void	nextStep() override;
    virtual void	onSuccess() override;

private:
    void	tryNextPosition();
    void	tryAdjacentPositions(const Position& position);
    void	tryMovement(const Position& position, char movement, const Position& origin);

private:
    virtual void	addPositionInQueue(const Position& position, const Position& origin) = 0;

protected:
    PositionQueue		m_positionQueue;

private:
    std::map<char, Position>	m_movements;
};

}

#endif // !ALGO_STEP_BY_STEP_HPP_
