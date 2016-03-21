#ifndef ALGO_ALGORITHM_LIST_HPP_
# define ALGO_ALGORITHM_LIST_HPP_

# include <map>
# include <string>

# include "algo/Algorithm.hpp"

namespace algo
{

class	AlgorithmList
{
private:
    class	caseLess : public std::binary_function<std::string, std::string, bool>
    {
    public:
	bool	operator()(const std::string& a, const std::string& b) const;
    };

private:
    typedef std::map<std::string, Algorithm*, caseLess>	algoMap;


public:
    AlgorithmList();
    ~AlgorithmList();

public:
    inline Algorithm*	chooseAlgorithm(const std::string& name);

private:
    algoMap		m_algorithms;
};

}

# include "AlgorithmList.ipp"

#endif // !ALGO_ALGORITHM_LIST_HPP_
