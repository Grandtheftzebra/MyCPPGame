#include <raylib.h>
#include "gameMain.h"

#include <iostream>
#include <ostream>

bool InitGame()
{
    return true;
}

bool UpdateGame()
{
    DrawText("My first text", 400, 0, 20, GREEN);

    return true;
}

void CloseGame()
{
    std::cout << "Closing game" << std::endl;
}
