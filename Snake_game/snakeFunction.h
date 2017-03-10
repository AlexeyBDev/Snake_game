#ifndef SNAKE_FUNCTION_H
#define SNAKE_FUNCTION_H
// � ������ ����� ����������� ��������� � ������� ������ �� �������

// ����������
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

// �������

// ��������� ����
#define HEAD_SNAKE '@'						// ������ ������ ����
#define BODY_SNAKE 's'						// ������ ���� ���� 'o'
#define SNAKE_SIZE 4						// ��������� ������ ����
#define SNAKE_MAX_SIZE 40					// ������������ ����� ����
#define EMPTY_SPACE ' '						// ������ ������� � ������� ���� ���� (������)
// ���� ���������
#define START_POINT_X FRAME_X / 2			// x ������ �������� ����
#define START_POINT_Y FRAME_Y / 2			// y ������ �������� ����
#define SLEEP 400							// ��� �����
#define DIFF_SPEEDS 1.25					// ����������� ��������� �� ������� � �� ��������

// �����������
#define UP 0x48
#define DOWN 0x50
#define LEFT 0x4b
#define RIGHT 0x4d
//--------------------------------------------------------------

// �������
void moveTo(position);									// ����������� � �������� ���������
int startDirectionSnake(void);							// ��������� ���������� ����������� ���� ������
snakeElement* snakeInit(int leight);							// �������� ����
void stepSnake(snakeElement *Snake, int direction, int longSnake);		// ������� ��������� ���� ����
bool snakeCrash(snakeElement *Snake);									// ������� ����������� ������������ ���� � ������
bool crashWithItSelf(snakeElement *Snake, int longSnake);				// �������� �� ���������������
bool takeFood(snakeElement *Snake, foodPosition food);
// ������ ��� (��������)
void consolDrawSnake(snakeElement* Snake, int longSnake);				// ��������� ���� � �������
void consolClearTail(snakeElement* Snake, int longSnake);				// �������� ������ ����


#endif
