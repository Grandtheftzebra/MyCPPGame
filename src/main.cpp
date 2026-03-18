#include <iostream>
#include <raylib.h>

int main()
{

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(800, 450, "My Game");

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("My first text", 400, 0, 20, GREEN);

        //DrawRectangle(100, 100, 200, 200, {50,200,200, 255});
        DrawRectangle(100, 100, 200, 200, {200,0,200, 100});

        EndDrawing();
    }

    CloseWindow();

    return 0;
}