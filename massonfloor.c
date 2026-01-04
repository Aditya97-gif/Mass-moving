#include <stdio.h>
#include "raylib.h"

#define WIDTH 800
#define HEIGHT 600

int main(void)
{
    InitWindow(WIDTH, HEIGHT, "Masson Floor - Demo");
    SetTargetFPS(60);

    const int floorHeight = 8;
    const int floorY = HEIGHT/2 - floorHeight/2; 
    float massSize = 40.0f;
    float massX = -massSize;
    float massY = floorY - massSize; 
    float massSpeed = 200.0f; 
    while (!WindowShouldClose())
    {
        float dt = GetFrameTime();
        massX += massSpeed * dt;
        if (massX - massSize > WIDTH) massX = -massSize; 

        BeginDrawing();
        ClearBackground(BLACK);

        DrawRectangle(0, floorY, WIDTH, floorHeight, GRAY);
        DrawRectangle((int)massX, (int)massY, (int)massSize, (int)massSize, GREEN);

        DrawFPS(10, 10);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}