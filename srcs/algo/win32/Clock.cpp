#include <stdexcept>

namespace algo
{

Clock::time
Clock::getCurrentTime() const
{
    LARGE_INTEGER 	time;
    LARGE_INTEGER	frequency;

    if (!QueryPerformanceCounter(&time) || !QueryPerformanceFrequency(&frequency))
    {
	throw std::runtime_error("Error getting time: Windows sucks.");
    }

    time.QuadPart *= 1000000;
    time.QuadPart /= frequency.QuadPart;

    return static_cast<Clock::time>(time.QuadPart);
}

}
}
