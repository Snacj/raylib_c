#include "raylib.h"

int main(void)
{
    // Initialization
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 450;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Raylib");

    Vector2 ball_position = { -100.0f, -100.0f };
    Color ball_color = DARKBLUE;
    int isCursorHidden = 0;

    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose()) {
        // update
        if (IsKeyPressed(KEY_H)) {
            HideCursor();
            isCursorHidden = 1;
        } else {
            ShowCursor();
            isCursorHidden = 0;
        }

        ball_position = GetMousePosition();


        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) ball_color = MAROON;
        else if (IsMouseButtonPressed(MOUSE_BUTTON_MIDDLE)) ball_color = LIME;
        else if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) ball_color = DARKBLUE;
        else if (IsMouseButtonPressed(MOUSE_BUTTON_SIDE)) ball_color = PURPLE;
        else if (IsMouseButtonPressed(MOUSE_BUTTON_EXTRA)) ball_color = YELLOW;
        else if (IsMouseButtonPressed(MOUSE_BUTTON_FORWARD)) ball_color = ORANGE;
        else if (IsMouseButtonPressed(MOUSE_BUTTON_BACK)) ball_color = BEIGE;

        // Draw
        BeginDrawing();
            ClearBackground(RAYWHITE);

            DrawCircleV(ball_position, 40, ball_color);

            DrawText("move ball with mouse and click mouse to change color", 10, 10, 20, DARKGRAY);
            DrawText("Press 'H' to toggle cursor visibility", 10, 30, 20, RED);

            if (isCursorHidden == 1) DrawText("CURSOR HIDDEN", 20, 60, 20, RED);
            else DrawText("CURSOR VISIBLE", 20 , 60, 20, LIME);

        EndDrawing();
    }

    // De-Initialization
    CloseWindow();
    return 0;
}
