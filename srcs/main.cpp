#include <exception>
#include <iostream>

#include "PathfindingPlusPlus.hpp"

int	main()
{
    int	return_value;

    try
    {
	PathfindingPlusPlus	application;
	application.start();
    	return_value = 0;
    }
    catch (const std::exception& exception)
    {
    	std::cerr << exception.what() << std::endl;
    	return_value = 1;
    }
    
    return return_value;
}
