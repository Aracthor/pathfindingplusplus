#include "algo/AlgorithmList.hpp"
#include "algo/Dijkstra.hpp"

namespace algo
{

AlgorithmList::AlgorithmList(graphic::Map& map)
{
    m_algorithms["Dijkstra"] = new Dijkstra(map);
}

AlgorithmList::~AlgorithmList()
{
    for (auto algo : m_algorithms)
    {
	delete algo.second;
    }
}

}
