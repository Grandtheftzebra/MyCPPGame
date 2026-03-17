#include <iostream>

int main()
{
    std::cout << "Hello CMake World" << std::endl;

    if (!PRODUCTION_BUILD)
    {
        std::cout << "This is a debug build" << std::endl;
    }

    return 0;
}