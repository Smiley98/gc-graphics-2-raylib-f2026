#include "raylib.h"
#include "raymath.h"
#include "raygui.h"

int main()
{
    InitWindow(800, 800, "Graphics-2");
    InitAudioDevice();
    SetTargetFPS(60);

    Vector2 pos1 = { 0.0f, GetScreenHeight() * 0.5f };
    Vector2 pos2 = { GetScreenWidth() * 0.5f, GetScreenHeight() * 0.5f };

    while (!WindowShouldClose())
    {
        float total_time = GetTime();
        float frame_time = GetFrameTime();

        pos1.x += 250.0f * frame_time;
        if (pos1.x + 20.0f >= GetScreenWidth())
            pos1.x = 0.0f;

        pos1.y = sinf(total_time * 8.0f) * 100.0f + GetScreenHeight() * 0.5f;

        // Rotate at 100 degrees per second in a radius of 100, then translate by half the screen
        Matrix translation_1 = MatrixTranslate(100.0f, 0.0f, 0.0f);
        Matrix rotation = MatrixRotateZ(total_time * 100.0f * DEG2RAD);
        Matrix translation_2 = MatrixTranslate(GetScreenWidth() * 0.5f, GetScreenHeight() * 0.5f, 0.0f);

        Vector2 pos_2_rotated = Vector2UnitX * translation_1 * rotation * translation_2;
        DrawCircleV(pos_2_rotated, 20.0f, PURPLE);

        DrawLineV(pos1, pos_2_rotated, LIME);
        DrawLineEx({ GetScreenWidth() * 0.5f, GetScreenHeight() * 0.5f }, GetMousePosition(), 4.0f, ORANGE);

        BeginDrawing();
        ClearBackground(WHITE);
        DrawFPS(10, 10);
        DrawText("Hello raylib", 660, 10, 20, DARKBLUE);
        DrawCircleV(pos1, 20.0f, BLUE);
        DrawCircleV(GetMousePosition(), 20.0f, RED);

        EndDrawing();
    }

    CloseAudioDevice();
    CloseWindow();
    return 0;
}
