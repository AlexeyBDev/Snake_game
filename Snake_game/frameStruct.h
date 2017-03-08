// Данный файл описывает функции связынне с отрисовкой рамки и выводом сообщений на экран
#ifndef FRAME_STRUCT_H
#define FRAME_STRUCT_H

#include "pointStruct.h"
//=======================================================
// Макросы
// параметры ограничивающей рамки
#define START_POINT_INVITATION_X 0			// точка вывода начального приветствия
#define START_POINT_INVITATION_Y 0
#define START_POINT_FRAME_X 0				// начальная точка рамки (X)
#define START_POINT_FRAME_Y 1				// начальная точка рамки (Y)
#define FRAME_X 60							// размер рамки по x
#define FRAME_Y 20							// размер рамки по y
#define NODE_FRAME '+'						// символ в углах рамки '+'
#define HORIZONT_LINE_FRAME '-'				// символ горизонтальной линии рамки '-'
#define VERTICAL_LINE_FRAME '|'				// символ вертикальной линии рамки '|'
#define EMPTY_SYMBOL_FRAME ' '				// пустой символ рамки ' '
#define NEW_LINE_FRAME '\n'					// символ начало отрисовки новой линии

// псевдоним структуры описывающий положение рамки
typedef struct PointXY framePosition;

// функции
void consolCursoreMove(framePosition);						// функция перемещения курсора по заданным координатам
void consolInvitation(void);								// вывод в консоль приветствия в начале игры
void consolDrawFrame(int width, int height);				// функция отрисовки ограничивающей рамки
void frameInit();											// функция инициализации рамки
void consolPrintStatistic(int speed, int size);					// вывод скорости и размера змеи

#endif