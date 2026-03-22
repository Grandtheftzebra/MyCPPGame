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

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(2000, 1000, "My Game");
    SetExitKey(KEY_NULL); // Disables ESC to close the window
    SetTargetFPS(60);

#pragma region Setup
    rlImGuiSetup(true);

    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    io.FontGlobalScale = 2;

    //ImGui::StyleColorsDark();
    ImGui::StyleColorsClassic();
#pragma endregion

    if (!InitGame())
    {
        return 0;
    }

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

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
#pragma region First Window
        ImGui::Begin("My first window");

        ImGui::Text("Hello World");

        if (ImGui::Button("Click me"))
        {
            std::cout << "Button clicked!" << std::endl;
        }

        ImGui::End();
#pragma endregion

#pragma region Second Window

        ImGui::Begin("My second window");

        ImGui::Text("Hello World");
        ImGui::Separator();

        if (ImGui::Button("Button 1"))
        {
            std::cout << "text button 1" << std::endl;
        }
        ImGui::SameLine();
        if (ImGui::Button("Button 2"))
        {
            std::cout << "Button text 2" << std::endl;
        }

        ImGui::NewLine();

        // Static because then the variable keeps its value between frames.
        // Without it, startValue would be recreated every frame and reset back to 2.0f
        static float startValue = 2.0f;
        ImGui::SliderFloat("Value", &startValue, 0.0f, 1.0f);

        ImGui::End();
#pragma endregion

        rlImGuiEnd();
        EndDrawing();
    }

    CloseWindow();
    CloseGame();

    rlImGuiShutdown();

    return 0;
}