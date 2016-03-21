#ifndef ALGO_ALGORITHM_HPP_
# define ALGO_ALGORITHM_HPP_

# include "graphic/Map.hpp"

namespace algo
{

class	Algorithm
{
public:
    Algorithm();
    virtual ~Algorithm();

public:
    inline void		setDisplayMap(graphic::Map* map);
    void		solve(const Map& map, Position* path, bool display);
    virtual void	nextStep() = 0;
    inline bool		isSolved() const;

protected:
    inline void		colorDiscoveredTile(const Position& position);
    inline void		colorVisitedTile(const Position& position);
    inline void		colorPathTile(const Position& position);
    void		fail();
    void		succeed();
    void		reversePath(unsigned int size);

protected:
    virtual void	init() = 0;
    virtual void	onSuccess() = 0;

protected:
    graphic::Map*	m_displayMap;
    algo::Map*		m_map;
    Position*		m_path;
    bool		m_solved;
    bool		m_display;
};

}

# include "Algorithm.ipp"

#endif // !ALGO_ALGORITHM_HPP_
