#include <raylib.h>
#include "gameMain.h"
#include <asserts.h>

#include <iostream>
#include <ostream>

struct GameData
{
    float PosX = 100;
    float PosY = 100;
    float MoveSpeed = 200;
}gameData;

bool InitGame()
{
    return true;
}

constexpr float MaxDeltaTime = 1.f / 5.f;
bool UpdateGame()
{
    float deltaTime = GetFrameTime();
    if (deltaTime > MaxDeltaTime) {deltaTime = MaxDeltaTime;}

    permaAssertCommentDevelopement(deltaTime > 10.f, "test");

    if (IsKeyDown(KEY_D)) {gameData.PosX += gameData.MoveSpeed * deltaTime;}
    if (IsKeyDown(KEY_A)) {gameData.PosX -= gameData.MoveSpeed * deltaTime;}
    // Movement inverted for W and S
    if (IsKeyDown(KEY_W)) {gameData.PosY -= gameData.MoveSpeed * deltaTime;}
    if (IsKeyDown(KEY_S)) {gameData.PosY += gameData.MoveSpeed * deltaTime;}

    DrawRectangle(gameData.PosX, gameData.PosY, 50, 50, RED);

    return true;
}

void CloseGame()
{
    std::cout << "Closing game" << std::endl;
}
