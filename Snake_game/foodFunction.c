#include <Windows.h>
#include <time.h>
#include "foodFunction.h"
#include "frameStruct.h"

// генератор еды
foodPosition foodGenerator(snakeElement *Snake, int longSnake)
{
	foodPosition food;
	DWORD nStartValue = time(NULL);
	srand(nStartValue);
	int food_x, food_y;
	food.x = START_POINT_FRAME_X + rand() % (FRAME_X - 2) + 1;				// генерация положения еды в рамке
	food.y = START_POINT_FRAME_Y + rand() % (FRAME_Y - 2) + 1;				// -2 - уменьшение диапазона чтобы не попало на рамки
																			// +1 - смещение относительно начало
																			// проверка на совпадение положения еды с положением самой змеи
																			// если попало на змею, генерируем заново
	for (int i = 0; i < longSnake; i++) {
		if (food.x == Snake[i].x && food.y == Snake[i].y)
		{
			food = foodGenerator(Snake, longSnake);							// если совпало, то вызываем повторно
			//moveTo(food);
			//putchar(FOOD); // отрисовка еды
			return food;
		}
	}
	//moveTo(food);
	//putchar(FOOD);											// отрисовка еды
	return food;
}

// функция отрисовки еды в консоли
void consolDrawFood(snakeElement *Snake, int longSnake)
{
	foodPosition food = foodGenerator(Snake, longSnake);
	moveTo(food);
	putchar(FOOD);											// отрисовка еды
}
