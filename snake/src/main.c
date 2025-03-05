#include "raylib.h"

#define SCREEN_WIDTH (512)
#define SCREEN_HEIGHT (512)
#define HUD_HEIGHT (100)
#define GAME_SCREEN (SCREEN_HEIGHT - HUD_HEIGHT)
#define GRID_SIZE (20)
#define COLUMN (int)(SCREEN_HEIGHT / GRID_SIZE)
#define ROW (int)(SCREEN_WIDTH / GRID_SIZE)
#define MAX_SNAKE (COLUMN * ROW)

typedef struct coordinate {
    int x; 
    int y;
} coordinate;

typedef struct {
    coordinate body[MAX_SNAKE]; // snake body
    int length; // snake length
    coordinate direction; // snake direction
} Snake;







int main(void) {
   InitWindow(512, 512, "SNAAAAAKE!");
    
    //snake yuhh
    Snake snake;
    snake.length = 2;
    snake.body[0] = (coordinate){ROW / 2, COLUMN / 2}; // start
    snake.direction = (coordinate){1, 0}; // going right



    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(BLACK);
        
        // draw snake
        for (int i = 0; i < snake.length; i++) {
            DrawRectangle(snake.body[i].x * GRID_SIZE, snake.body[i].y * GRID_SIZE, GRID_SIZE, GRID_SIZE, GREEN);
        }

        EndDrawing();
    }

    
    CloseWindow();
    return 0;
}