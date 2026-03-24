#include <raylib.h>
#include "gameMain.h"
#include <iostream>
#include <ostream>

struct GameData
{
    float PosX = 100;
    float PosY = 100;
}gameData;

bool InitGame()
{
    return true;
}

bool UpdateGame()
{
    if (IsKeyDown(KEY_D)) {gameData.PosX += 1;}
    if (IsKeyDown(KEY_A)) {gameData.PosX -= 1;}
    // Movement inverted for W and S
    if (IsKeyDown(KEY_W)) {gameData.PosY -= 1;}
    if (IsKeyDown(KEY_S)) {gameData.PosY += 1;}

    DrawRectangle(gameData.PosX, gameData.PosY, 50, 50, RED);
    return true;
}

void CloseGame()
{
    std::cout << "Closing game" << std::endl;
}
