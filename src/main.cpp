#include <iostream>
#include <raylib.h>

#include <imgui.h>
#include <rlImGui.h>

int main()
{

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(800, 450, "My Game");

    rlImGuiSetup(true);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        rlImGuiBegin();

        DrawText("My first text", 400, 0, 20, GREEN);

        DrawRectangle(100, 100, 200, 200, {50,200,200, 255});
        DrawRectangle(100, 100, 200, 200, {200,0,200, 100});

        ImGui::Begin("My first window");

        ImGui::Text("Hello World");
        ImGui::Button("Click me");

        ImGui::End();

        rlImGuiEnd();
        EndDrawing();
    }

    rlImGuiShutdown();
    CloseWindow();

    return 0;
}