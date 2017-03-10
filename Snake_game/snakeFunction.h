#ifndef SNAKE_FUNCTION_H
#define SNAKE_FUNCTION_H
// в данной файле описываются константы и функции работы со змейкой

// библиотеки
//#include <stdio.h>
//#include <stdlib.h>
//#include <conio.h>
//#include <locale.h>
//#include <time.h>
#include <stdbool.h>
//#include <windows.h>

#include "foodFunction.h"
#include "snakeStruct.h"

//--------------------------------------------------------------

// Макросы

// параметры змеи
#define HEAD_SNAKE '@'						// символ головы змеи
#define BODY_SNAKE 's'						// символ тела змеи 'o'
#define SNAKE_SIZE 4						// начальная длинна змеи
#define SNAKE_MAX_SIZE 40					// максимальный рамер змеи
#define EMPTY_SPACE ' '						// пустая позиция с которой ушла змея (пробел)
// иные параметры
#define START_POINT_X FRAME_X / 2			// x начала движения змеи
#define START_POINT_Y FRAME_Y / 2			// y начала двизения змеи
#define SLEEP 400							// шаг паузы
#define DIFF_SPEEDS 1.25					// соотношение скоростей по строкам и по столбцам

// направления
#define UP 0x48
#define DOWN 0x50
#define LEFT 0x4b
#define RIGHT 0x4d
//--------------------------------------------------------------

// функции
void moveTo(position);									// перемещение в заданное положение
int startDirectionSnake(void);							// генерация начального направления хода змейки
snakeElement* snakeInit(int leight);							// создание змеи
void stepSnake(snakeElement *Snake, int direction, int longSnake);		// функция генерации шага змеи
bool snakeCrash(snakeElement *Snake);									// функция определения столкновения змеи с рамкой
bool crashWithItSelf(snakeElement *Snake, int longSnake);				// проверка на самопересечение
bool takeFood(snakeElement *Snake, foodPosition food);
// съесть еду (проверка)
void consolDrawSnake(snakeElement* Snake, int longSnake);				// отрисовка змеи в консоли
void consolClearTail(snakeElement* Snake, int longSnake);				// стирание хвоста змеи


#endif
