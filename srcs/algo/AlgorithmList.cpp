#include <algorithm>

#include "algo/AlgorithmList.hpp"
#include "algo/AStarSorter.hpp"
#include "algo/BiDirectional.hpp"
#include "algo/DijkstraSorter.hpp"
#include "algo/StepByStep.hpp"

namespace algo
{

bool
AlgorithmList::caseLess::operator()(const std::string& a, const std::string& b) const
{
    std::string	newA(a);
    std::string	newB(b);

    std::transform(a.begin(), a.end(), newA.begin(), ::tolower);
    std::transform(b.begin(), b.end(), newB.begin(), ::tolower);
    return (newA < newB);
}


AlgorithmList::AlgorithmList()
{
    m_algorithms["dijkstra"] = new StepByStep(new DijkstraSorter);
    m_algorithms["a*"] = new StepByStep(new AStarSorter);
    m_algorithms["astar"] = new StepByStep(new AStarSorter);
    m_algorithms["bidijkstra"] = new BiDirectional(new DijkstraSorter);
    m_algorithms["bia*"] = new BiDirectional(new AStarSorter);
    m_algorithms["biastar"] = new BiDirectional(new AStarSorter);
}

AlgorithmList::~AlgorithmList()
{
    for (auto algo : m_algorithms)
    {
	delete algo.second;
    }
}

}
