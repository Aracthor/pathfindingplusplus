namespace algo
{

Algorithm*
AlgorithmList::chooseAlgorithm(const std::string& name)
{
    return m_algorithms[name];
}

}
