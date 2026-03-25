#include <iostream>
#include <raylib.h>

#include <imgui.h>
#include <rlImGui.h>
#include <gameMain.h>

int main()
{

#if PRODUCTION_BUILD == 1
    // Prevents raylib to print debug messages to the console.
    SetTraceLogLevel(LOG_NONE);
#endif


#pragma region Setup
    // Raylib
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(2000, 1000, "My Game");
    SetExitKey(KEY_NULL); // Disables ESC to close the window
    SetTargetFPS(240);

    rlImGuiSetup(true);

    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    io.FontGlobalScale = 2;

    //ImGui::StyleColorsDark();
    ImGui::StyleColorsClassic();
#pragma endregion

    if (!InitGame())
    {
        std::cout << "Game failed to initialize" << std::endl;

        return 0;
    }

    // Main Game Loop. Within Raylib the SetTargetFPS is limiting frame rate
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        std::cout << "FPS: " << GetFPS() << std::endl;

#pragma region ImGui
        rlImGuiBegin();

        ImGui::PushStyleColor(ImGuiCol_WindowBg, {});
        ImGui::PushStyleColor(ImGuiCol_DockingEmptyBg, {});
        ImGui::DockSpaceOverViewport(ImGui::GetMainViewport()->ID);
        ImGui::PopStyleColor(2);

#pragma endregion

        if (!UpdateGame())
        {
            CloseWindow();

            std::cout << "Game failed to update" << std::endl;

            return 0;
        }

        rlImGuiEnd();
        EndDrawing();
    }

    CloseWindow();
    CloseGame();

    rlImGuiShutdown();

    return 0;
}