#ifndef SNAKE_FUNCTION_H
#define SNAKE_FUNCTION_H
// � ������ ����� ����������� ��������� � ������� ������ �� �������

// ����������
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <time.h>
#include <stdbool.h>
#include <windows.h>
#include "snakeStruct.h"
//--------------------------------------------------------------

// �������
// ��������� �������������� �����
#define START_POINT_FRAME_X 0				// ��������� ����� ����� (X)
#define START_POINT_FRAME_Y 1				// ��������� ����� ����� (Y)
#define FRAME_X 60							// ������ ����� �� x
#define FRAME_Y 20							// ������ ����� �� y
#define NODE_FRAME '+'						// ������ � ����� ����� '+'
#define HORIZONT_LINE_FRAME '-'				// ������ �������������� ����� ����� '-'
#define VERTICAL_LINE_FRAME '|'				// ������ ������������ ����� ����� '|'
#define EMPTY_SYMBOL_FRAME ' '				// ������ ������ ����� ' '
#define NEW_LINE_FRAME '\n'					// ������ ������ ��������� ����� �����
// ��������� ����
#define HEAD_SNAKE '@'						// ������ ������ ����
#define BODY_SNAKE 'o'						// ������ ���� ���� 'o'
#define SNAKE_SIZE 4						// ��������� ������ ����
#define SNAKE_MAX_SIZE 40					// ������������ ����� ����
#define EMPTY_SPACE ' '						// ������ ������� � ������� ���� ���� (������)
// ���� ���������
#define START_POINT_X FRAME_X / 2			// x ������ �������� ����
#define START_POINT_Y FRAME_Y / 2			// y ������ �������� ����
#define SLEEP 400							// ��� �����
#define DIFF_SPEEDS 1.25					// ����������� ��������� �� ������� � �� ��������
#define FOOD '*'							// ������ ���
// �����������
#define UP 0x48
#define DOWN 0x50
#define LEFT 0x4b
#define RIGHT 0x4d
//--------------------------------------------------------------

// �������
void drawFrame(int, int);					// ������� ��������� �������������� �����
void gotoxy(snakeElement);						// ������� ����������� ������� �� �������� �����������
int startDirection(void);					// ������� ��������� ���������� �����������
void newSnake(snakeElement *, int leight, int direction);		// ������� ��������� ��������� ���� ����
snakeElement stepSnake(int direction, snakeElement head);		// ������� ��������� ���� ����
bool snakeCrash(snakeElement position);							// ������� ����������� ������������ ���� � ������
foodPosition foodGenerator(snakeElement *Snake, int longSnake);					// ��������� ���
bool crashWithItSelf(snakeElement *Snake, int longSnake);

#endif
