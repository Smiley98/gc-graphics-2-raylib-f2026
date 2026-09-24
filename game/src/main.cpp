#include "raylib.h"
#include "raymath.h"
#include "raygui.h"

int main()
{
    InitWindow(800, 800, "Graphics-2");
    InitAudioDevice();
    SetTargetFPS(60);

    float pos_x = 0.0f;
    float pos_y = 400.0f;
    float speed = 250.0f;

    while (!WindowShouldClose())
    {
        float total_time = GetTime();
        float frame_time = GetFrameTime();

        pos_x += speed * frame_time;
        if (pos_x + 20.0f >= GetScreenWidth())
            pos_x = 0.0f;

        pos_y = sinf(total_time * 8.0f) * 100.0f + GetScreenHeight() * 0.5f;

        BeginDrawing();
        ClearBackground(WHITE);

        DrawCircle(pos_x, pos_y, 20.0f, BLUE);
        DrawCircleV(GetMousePosition(), 20.0f, RED);

        EndDrawing();
    }

    CloseAudioDevice();
    CloseWindow();
    return 0;
}
