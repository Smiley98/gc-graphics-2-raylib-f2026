#include "raylib.h"
#include "raymath.h"
#include "raygui.h"

enum GameState : int
{
    PLAYING,
    WIN,
    LOSS
};

int main()
{
    InitWindow(800, 800, "Graphics-2");
    InitAudioDevice();
    SetTargetFPS(60);

    Vector2 ball = { 400.0f, 400.0f };

    int state = PLAYING;
    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_TAB)) ++state %= 3;
        float tt = GetTime();

        switch (state)
        {
        case PLAYING:
            ball.y = 400.0f + sinf(tt) * 100.0f;
            break;

        case WIN:
            ball.x = 400.0f + sinf(tt) * 400.0f;
            break;

        case LOSS:
            ball.x = 400.0f + sinf(tt) * 100.0f;
            ball.y = 400.0f + cosf(tt) * 100.0f;
            break;
        }

        // *ONLY CALL BeginDrawing(); AND EndDrawing(); **ONCE** PER FRAME!!!*
        BeginDrawing();

            ClearBackground(WHITE);
            switch (state)
            {
            case PLAYING:
                DrawText("Game on!", 350, 400, 20, BLUE);
                break;

            case WIN:
                DrawText("You win :)", 350, 400, 20, GREEN);
                break;

            case LOSS:
                DrawText("You loose :(", 350, 400, 20, RED);
                break;
            }

            DrawCircleV(ball, 25.0f, PURPLE);
        EndDrawing();
    }

    CloseAudioDevice();
    CloseWindow();
    return 0;
}
