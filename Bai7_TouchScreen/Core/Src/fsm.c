#include "fsm.h"

void fsm() {
    switch (game_status) {
    case INIT:
        drawGameBoard();
        drawControlPad();
        generateFruit();
        game_status = GAME_START;
        break;
    case GAME_START:
        snake_movement();
        drawGameBoard();
        if (snake_x_coord + 6 >= fruit_x_coord - 10 && snake_x_coord + 6 <= fruit_x_coord + 10 && snake_y_coord + 12  >= fruit_y_coord - 10 && snake_y_coord + 12 <= fruit_y_coord + 10) {
            is_fruit_eaten = 1;
            score += 10;
            lcd_DrawCircle(fruit_x_coord, fruit_y_coord, BLACK, 10, 1);
            generateFruit(); 
        }
        if (snake_x_coord >= 216 || snake_x_coord <= 10 || snake_y_coord >= 196 || snake_y_coord <= 10) {
            game_status = GAME_OVER;
        }
        break;
    case GAME_OVER:
        printGameOver();
        if (restartGame()) {
            snake_x_coord = 100;
            snake_y_coord = 100;
            score = 0;
            lcd_Clear(BLACK);
            game_status = INIT;
        }
        break;
    default:
        break;
    }
}