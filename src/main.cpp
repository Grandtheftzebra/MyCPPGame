#include <iostream>
#include <raylib.h>

#include <imgui.h>
#include <rlImGui.h>

int main()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(2000, 1000, "My Game");

#pragma region Setup
    rlImGuiSetup(true);

    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    io.FontGlobalScale = 2;
#pragma endregion

    while (!WindowShouldClose())
    {
#pragma region raylib
        BeginDrawing();
        ClearBackground(RAYWHITE);
#pragma endregion


#pragma region ImGui
        rlImGuiBegin();

        ImGui::PushStyleColor(ImGuiCol_WindowBg, {});
        ImGui::PushStyleColor(ImGuiCol_DockingEmptyBg, {});
        ImGui::DockSpaceOverViewport(ImGui::GetMainViewport()->ID);
        ImGui::PopStyleColor(2);

        DrawText("My first text", 400, 0, 20, GREEN);
        DrawRectangle(100, 100, 200, 200, {50,200,200, 255});
        DrawRectangle(100, 100, 200, 200, {200,0,200, 100});
#pragma endregion

        ImGui::Text("Test");


        rlImGuiEnd();
        EndDrawing();
    }

    rlImGuiShutdown();
    CloseWindow();

    return 0;
}