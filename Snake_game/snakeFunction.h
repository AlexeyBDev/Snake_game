#ifndef SNAKE_FUNCTION_H
#define SNAKE_FUNCTION_H
// в данной файле описываются константы и функции работы со змейкой

// библиотеки
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <time.h>
#include <stdbool.h>
#include <windows.h>
#include "snakeStruct.h"
//--------------------------------------------------------------

// Макросы
// параметры ограничивающей рамки
#define START_POINT_FRAME_X 0				// начальная точка рамки (X)
#define START_POINT_FRAME_Y 1				// начальная точка рамки (Y)
#define FRAME_X 60							// размер рамки по x
#define FRAME_Y 20							// размер рамки по y
#define NODE_FRAME '+'						// символ в углах рамки '+'
#define HORIZONT_LINE_FRAME '-'				// символ горизонтальной линии рамки '-'
#define VERTICAL_LINE_FRAME '|'				// символ вертикальной линии рамки '|'
#define EMPTY_SYMBOL_FRAME ' '				// пустой символ рамки ' '
#define NEW_LINE_FRAME '\n'					// символ начало отрисовки новой линии
// параметры змеи
#define HEAD_SNAKE '@'						// символ головы змеи
#define BODY_SNAKE 'o'						// символ тела змеи 'o'
#define SNAKE_SIZE 4						// начальная длинна змеи
#define SNAKE_MAX_SIZE 40					// максимальный рамер змеи
#define EMPTY_SPACE ' '						// пустая позиция с которой ушла змея (пробел)
// иные параметры
#define START_POINT_X FRAME_X / 2			// x начала движения змеи
#define START_POINT_Y FRAME_Y / 2			// y начала двизения змеи
#define SLEEP 400							// шаг паузы
#define DIFF_SPEEDS 1.25					// соотношение скоростей по строкам и по столбцам
#define FOOD '*'							// символ еды
// направления
#define UP 0x48
#define DOWN 0x50
#define LEFT 0x4b
#define RIGHT 0x4d
//--------------------------------------------------------------

// функции
void drawFrame(int, int);					// функция отрисовки ограничивающей рамки
void gotoxy(snakeElement);						// функция перемещения курсора по заданным координатам
int startDirection(void);					// функция генерации начального направления
void newSnake(snakeElement *, int leight, int direction);		// функция начальной генерации тела змеи
snakeElement stepSnake(int direction, snakeElement head);		// функция генерации шага змеи
bool snakeCrash(snakeElement position);							// функция определения столкновения змеи с рамкой
foodPosition foodGenerator(snakeElement *Snake, int longSnake);					// генератор еды
bool crashWithItSelf(snakeElement *Snake, int longSnake);

#endif
