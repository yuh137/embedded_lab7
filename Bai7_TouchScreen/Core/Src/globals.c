#include "globals.h"

int draw_Status = INIT;
int game_status = INIT;
int snake_lenght = 5;

int snake_x_coord = 50;
int snake_y_coord = 50;

int fruit_x_coord = 0;
int fruit_y_coord = 0;

int is_fruit_eaten = 0;
int score = 0;

int snake_direction = UP;

int counter_game = 0;

uint8_t isButtonClear(){
	if(!touch_IsTouched()) return 0;
	return touch_GetX() > 60 && touch_GetX() < 180 && touch_GetY() > 10 && touch_GetY() < 60;
}

uint8_t isDirectionInput() {
    if(!touch_IsTouched()) return 0;
    if (touch_GetX() > 50 && touch_GetX() < 90 && touch_GetY() > 250 && touch_GetY() < 290) {
        return LEFT;
    }

    if (touch_GetX() > 100 && touch_GetX() < 140 && touch_GetY() > 230 && touch_GetY() < 270) {
        return UP;
    }

    if (touch_GetX() > 100 && touch_GetX() < 140 && touch_GetY() > 280 && touch_GetY() < 320) {
        return DOWN;
    }

    if (touch_GetX() > 150 && touch_GetX() < 190 && touch_GetY() > 250 && touch_GetY() < 290) {
        return RIGHT;
    }
}

uint8_t restartGame() {
    if (touch_IsTouched()) return 0;
    return touch_GetX() > 60 && touch_GetX() < 180 && touch_GetY() > 180 && touch_GetY() < 230;
}

void generateFruit() {
    // rand()
    fruit_x_coord = (rand() % (230 - 15 + 1)) + 15; 
    fruit_y_coord = (rand() % (210 - 15 + 1)) + 15;

    lcd_DrawCircle(fruit_x_coord, fruit_y_coord, RED, 6, 1);

    is_fruit_eaten = 0;
}

void touchProcess(){
	switch (draw_Status) {
		case INIT:
                // display blue button
			lcd_Fill(60, 10, 180, 60, GBLUE);
			lcd_ShowStr(90, 20, "CLEAR", RED, BLACK, 24, 1);
			draw_Status = DRAW;
			break;
		case DRAW:
			if(isButtonClear()){
				draw_Status = CLEAR;
                    // clear board
				lcd_Fill(0, 60, 240, 320, BLACK);
                    // display green button
				lcd_Fill(60, 10, 180, 60, GREEN);
				lcd_ShowStr(90, 20, "CLEAR", RED, BLACK, 24, 1);
			}
			break;
		case CLEAR:
			if(!touch_IsTouched()) draw_Status = INIT;
			break;
		default:
			break;
	}
}

void drawGameBoard() {
    // lcd_Fill(0, 0, 240, 220, BLACK);
    lcd_DrawRectangle(10, 10, 230, 220, RED);

    lcd_ShowIntNum(snake_x_coord, snake_y_coord, 0, 1, GREEN, BLACK, 24);
}

void drawControlPad() {
    char str[10];
    lcd_Fill(0, 220, 240, 320, BLACK);

    lcd_Fill(50, 250, 90, 290, CYAN);
    strcpy(str, "L");
    lcd_ShowStr(64, 260, str, RED, CYAN, 24, 0);

    lcd_Fill(100, 230, 140, 270, CYAN);
    strcpy(str, "U");
    lcd_ShowStr(114, 240, str, RED, CYAN, 24, 0);

    lcd_Fill(100, 280, 140, 320, CYAN);
    strcpy(str, "D");
    lcd_ShowStr(114, 290, str, RED, CYAN, 24, 0);

    lcd_Fill(150, 250, 190, 290, CYAN);
    strcpy(str, "R");
    lcd_ShowStr(164, 260, str, RED, CYAN, 24, 0);
}

void printGameOver() {
    char str[10];

    lcd_Fill(0, 0, 240, 320, RED);
    strcpy(str, "GAME OVER");
    lcd_StrCenter(0, 100, str, YELLOW, RED, 24, 0);

    lcd_Fill(60, 180, 180, 230, GBLUE);
    strcpy(str, "RESTART");
    lcd_ShowStr(80, 190, str, RED, BLACK, 24, 1);
}

void snake_movement() {
    counter_game = (counter_game + 1) % 1;

    if (counter_game == 0) {
        switch (snake_direction) {
        case UP:
            snake_y_coord--;
            break;
        case DOWN:
            snake_y_coord++;
            break;
        case LEFT:
            snake_x_coord--;
            break;
        case RIGHT:
            snake_x_coord++;
            break;
        default:
            break;
        }  

        lcd_ShowIntNum(170, 300, score, 3, YELLOW, BLACK, 24);
        // lcd_ShowIntNum(150, 10, snake_x_coord, 3, GREEN, BLACK, 24);
        // lcd_ShowIntNum(200, 10, snake_y_coord, 3, GREEN, BLACK, 24);
    }
}