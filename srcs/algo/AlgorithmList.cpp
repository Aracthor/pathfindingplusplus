#include <algorithm>

#include "algo/AlgorithmList.hpp"
#include "algo/AStar.hpp"
#include "algo/BiDijkstra.hpp"
#include "algo/Dijkstra.hpp"

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
    m_algorithms["dijkstra"] = new Dijkstra;
    m_algorithms["a*"] = new AStar;
    m_algorithms["astar"] = new AStar;
    m_algorithms["bidijkstra"] = new BiDijkstra;
}

AlgorithmList::~AlgorithmList()
{
    for (auto algo : m_algorithms)
    {
	delete algo.second;
    }
}

}
