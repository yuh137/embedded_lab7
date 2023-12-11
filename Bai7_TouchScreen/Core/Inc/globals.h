#ifndef _GLOBALS_H_
#define _GLOBALS_H_
#ifdef __cplusplus
 extern "C" {
#endif

#include "lcd.h"
#include "picture.h"
#include "ds3231.h"
#include "sensor.h"
#include "buzzer.h"
#include "touch.h"

#define INIT 0
#define DRAW 1
#define CLEAR 2

#define GAME_START 1
#define GAME_OVER 2

#define LEFT 1
#define UP 2
#define RIGHT 3
#define DOWN 4

extern int draw_Status;
extern int game_status;

extern int snake_length;
extern int snake_x_coord;
extern int snake_y_coord;

extern int snake_direction;

extern int fruit_x_coord;
extern int fruit_y_coord;

extern int is_fruit_eaten;
extern int score;

extern int counter_game;

void touchProcess();
uint8_t isButtonClear();
void drawControlPad(void);
void drawGameBoard(void);
void snake_movement(void);
uint8_t isDirectionInput(void);
uint8_t restartGame(void);
void printGameOver(void);
void generateFruit(void);

#ifdef __cplusplus
}
#endif
#endif /*_GLOBALS_H_*/