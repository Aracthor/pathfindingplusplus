#include <exception>
#include <iostream>

#include "PathfindingPlusPlus.hpp"

int	main(int argc, char** argv)
{
    int	return_value;

    try
    {
	PathfindingPlusPlus	application(argc, argv);
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
