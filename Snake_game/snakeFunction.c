#include <windows.h>
#include <time.h>
#include <stdio.h>
#include "snakeFunction.h"
#include "snakeStruct.h"
#include "frameStruct.h"
#include "foodFunction.h"

//snakeElement startPointFrame = { START_POINT_FRAME_X,// ����� ������ ��������� �����
//START_POINT_FRAME_Y };
//snakeElement pointForEndMessage = { 0,			// ����� ������ ����������� ������� �� ��������� ���������
//START_POINT_FRAME_Y + FRAME_Y + 2 };
//snakeElement pointForEndStatistic = { 0,		// ����� ������ ���������� �� ����� ������ ���������
//START_POINT_FRAME_Y + FRAME_Y + 1 };

//-----------------------------------------------------------------
// ���������� �������

// ��������� ����������� ������� � �������� ���������
void moveTo(position point)
{
	COORD currentPos = { point.x, point.y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), currentPos);
}

// ��������� ���������� ����������� ���� ������
int startDirectionSnake(void)
{
	DWORD nStartValue = time(NULL);
	srand(nStartValue);
	int direction;
	direction = rand() % 4;						// ��������� ���������� �����������

	switch (direction) {
	case 0: return LEFT;
	case 1: return RIGHT;
	case 2: return UP;
	case 3: return DOWN;
	default: return UP;
	}
}

// �������� ������
snakeElement* snakeInit(int leight)
{
	static snakeElement Snake[SNAKE_MAX_SIZE]; // �������� ����
	int direction = startDirectionSnake();

	Snake[0].x = START_POINT_X;
	Snake[0].y = START_POINT_Y;

	switch (direction) {
	case LEFT:
		for (int i = 1; i < SNAKE_SIZE; ++i)
		{
			Snake[i].x = START_POINT_X + i;
			Snake[i].y = START_POINT_Y;
		} break;
	case RIGHT:
		for (int i = 1; i < SNAKE_SIZE; ++i)
		{
			Snake[i].x = START_POINT_X - i;
			Snake[i].y = START_POINT_Y;
		} break;
	case UP:
		for (int i = 1; i < SNAKE_SIZE; ++i)
		{
			Snake[i].x = START_POINT_X;
			Snake[i].y = START_POINT_Y + i;
		} break;
	case DOWN:
		for (int i = 1; i < SNAKE_SIZE; ++i)
		{
			Snake[i].x = START_POINT_X;
			Snake[i].y = START_POINT_Y - i;
		} break;
	default:
		for (int i = 1; i < SNAKE_SIZE; ++i)					// UP
		{
			Snake[i].x = START_POINT_X;
			Snake[i].y = START_POINT_Y + i;
		} break;
	} // switch
	return Snake;
} // snakeInit

// ����������� ������
void stepSnake(snakeElement *Snake, int direction, int longSnake)		// ������� ��������� ���� ����
{
	snakeElement newHead = Snake[0];
	//snakeElement step;
	switch (direction) {
	case LEFT:	newHead.x = -1 + newHead.x;					// ���� (��� ��� 75)
				newHead.y = 0 + newHead.y;
		break;
	case RIGHT: newHead.x = 1 + newHead.x;					// ����� (��� ��� - 77)
				newHead.y = 0 + newHead.y;
		break;
	case UP:	newHead.x = 0 + newHead.x;					// ���� (��� ��� - 72)
				newHead.y = -1 + newHead.y;
		break;
	case DOWN:	newHead.x = 0 + newHead.x;					// ��� (��� ��� - 80)
				newHead.y = 1 + newHead.y;
		break;
	default:	newHead.x = 0 + newHead.x;
				newHead.y = 0 + newHead.y;
		break;
	}
	for (int i = longSnake - 1; i > 0; i--)						// ����������� ���� ���� � ����� ���������
	{
		Snake[i] = Snake[i - 1];
	}
	Snake[0] = newHead;
}

// ������� ����������� ������������ ���� � ������
bool snakeCrash(snakeElement *Snake)						
{
	if (Snake[0].x <= START_POINT_FRAME_X || Snake[0].x >= START_POINT_FRAME_X + FRAME_X ||
		Snake[0].y <= START_POINT_FRAME_Y || Snake[0].y >= START_POINT_FRAME_Y + FRAME_Y) 
		return true; // �����������
	else 
		return false; // ���
}

// �������� ���� �� ������������ � ����� �����
bool crashWithItSelf(snakeElement *Snake, int longSnake) {		
	for (int i = 1; i < longSnake; i++)
	{
		if (Snake[0].x == Snake[i].x && Snake[0].y == Snake[i].y)
			return true;
	}
	return false;
}

// �������� �� ����������� � ����
bool takeFood(snakeElement *Snake, foodPosition food)
{
	if (food.x == Snake[0].x && food.y == Snake[0].y) return true;
	else return false;
}

// ��������� ���� � �������
void consolDrawSnake(snakeElement* Snake, int longSnake)
{
	moveTo(Snake[0]);							// ����������� ������� � ������ ������ ����
	putchar(HEAD_SNAKE);						// ��������� ������ ����
	for (int i = 1; i < longSnake; i++)
	{
		moveTo(Snake[i]);
		putchar(BODY_SNAKE);
		//moveTo(Snake[i]);
	}
	moveTo(Snake[0]);							// ���� ������� � ������
}

// �������� ������ ����
void consolClearTail(snakeElement* Snake, int longSnake)
{
	moveTo(Snake[longSnake - 1]);
	putchar(EMPTY_SPACE);
	moveTo(Snake[0]);
}
