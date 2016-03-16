#ifndef ALGO_ALGORITHM_HPP_
# define ALGO_ALGORITHM_HPP_

# include "graphic/Map.hpp"

namespace algo
{

class	Algorithm
{
public:
    explicit Algorithm(graphic::Map& map);
    virtual ~Algorithm();

public:
    void		solve(const Map& map, Position* path, bool display);

protected:
    inline void		colorVisitedTile(const Position& position);
    inline void		colorDiscoveredTile(const Position& position);
    inline bool		isSolved() const;

private:
    virtual void	nextStep() = 0;

private:
    graphic::Map&	m_displayMap;
    algo::Map*		m_map;
    Position*		m_path;
    bool		m_solved;
};

}

# include "Algorithm.ipp"

#endif // !ALGO_ALGORITHM_HPP_
