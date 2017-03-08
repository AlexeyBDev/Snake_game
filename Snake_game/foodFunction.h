#ifndef FOOD_FUNCTION_H
#define FOOD_FUNCTION_H

#include "pointStruct.h"
#include "snakeStruct.h"
#include "snakeFunction.h"
//---------------------------------------------------------
// псевдоним структуры описывающий еду
typedef struct PointXY foodPosition;

// функции
// перемещение в заданное положение
// определена в snakeFunction.h
extern void moveTo(position);

// генерирует еду с проверкой на непоподание на змею
foodPosition foodGenerator(snakeElement *Snake, int longSnake);		
// возвращает координаты еды

// отрисовка еды в консоли
void consolDrawFood(snakeElement *Snake, int longSnake);
#endif

