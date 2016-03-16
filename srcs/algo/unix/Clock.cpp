#include <stdexcept>

#include <sys/time.h>

namespace algo
{

Clock::time
Clock::getCurrentTime() const
{
    struct timeval	tv;

    if (gettimeofday(&tv, nullptr) != 0)
    {
	throw std::runtime_error("Error with gettimeofday.");
    }

    return (tv.tv_usec + tv.tv_sec * 1000000);
}

}
