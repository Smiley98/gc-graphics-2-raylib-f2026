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

    int state = PLAYING;
    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_TAB)) ++state %= 3;

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

        EndDrawing();
    }

    CloseAudioDevice();
    CloseWindow();
    return 0;
}
