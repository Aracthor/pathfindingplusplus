#include "algo/AlgorithmList.hpp"
#include "algo/Dijkstra.hpp"

namespace algo
{

AlgorithmList::AlgorithmList()
{
    m_algorithms["Dijkstra"] = new Dijkstra;
}

AlgorithmList::~AlgorithmList()
{
    for (auto algo : m_algorithms)
    {
	delete algo.second;
    }
}

}
