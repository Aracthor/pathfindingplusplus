#ifndef ALGO_ALGORITHM_LIST_HPP_
# define ALGO_ALGORITHM_LIST_HPP_

# include <map>
# include <string>

# include "algo/Algorithm.hpp"

namespace algo
{

class	AlgorithmList
{
public:
    AlgorithmList();
    ~AlgorithmList();

public:
    inline Algorithm*	chooseAlgorithm(const std::string& name);

private:
    std::map<std::string, Algorithm*>	m_algorithms;
};

}

# include "AlgorithmList.ipp"

#endif // !ALGO_ALGORITHM_LIST_HPP_
