#include <Windows.h>
#include <time.h>
#include "foodFunction.h"
#include "frameStruct.h"

// ��������� ���
foodPosition foodGenerator(snakeElement *Snake, int longSnake)
{
	foodPosition food;
	DWORD nStartValue = time(NULL);
	srand(nStartValue);
	int food_x, food_y;
	food.x = START_POINT_FRAME_X + rand() % (FRAME_X - 2) + 1;				// ��������� ��������� ��� � �����
	food.y = START_POINT_FRAME_Y + rand() % (FRAME_Y - 2) + 1;				// -2 - ���������� ��������� ����� �� ������ �� �����
																			// +1 - �������� ������������ ������
																			// �������� �� ���������� ��������� ��� � ���������� ����� ����
																			// ���� ������ �� ����, ���������� ������
	for (int i = 0; i < longSnake; i++) {
		if (food.x == Snake[i].x && food.y == Snake[i].y)
		{
			food = foodGenerator(Snake, longSnake);							// ���� �������, �� �������� ��������
			//moveTo(food);
			//putchar(FOOD); // ��������� ���
			return food;
		}
	}
	//moveTo(food);
	//putchar(FOOD);											// ��������� ���
	return food;
}

// ������� ��������� ��� � �������
void consolDrawFood(snakeElement *Snake, int longSnake)
{
	foodPosition food = foodGenerator(Snake, longSnake);
	moveTo(food);
	putchar(FOOD);											// ��������� ���
}
