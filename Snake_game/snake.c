/* ��������� ������������ ���� "������"
 * ��������� ����� ��������� ������� �� ����� "���������������� �� ����� C (��)" (����������). 
 * �������������� ����� ����������.
 * ������ 0.91
 * 080317 - �������� ���� ��������� �� �����, ����������� ����; 
*/
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <windows.h>
#include "snakeStruct.h"
#include "snakeFunction.h"
#include "frameStruct.h"
#include "foodFunction.h"

//#define OPEN_GL_SNAKE_MODE					// ������ ������� � OpenGL
//extern snakeElement startPointFrame;


						// �������� ���� �� ������������ � ����� �����

int main()
{
	system("color 1E");						// ��������� ������ ���� � ������� ������
	setlocale(LC_CTYPE, "rus");

	frameInit();							// ����������� ������ ���� � ��������� �����

	int key, prevKey;			// ������� ������� ����������� � ����������
	key = startDirectionSnake();

	int speed = SLEEP;						// ��������� �������� ����

	int longSnake = SNAKE_SIZE;						// longSnake - ������� ������ ����
	snakeElement* Snake = snakeInit(longSnake);		// ������ ���� ����
	consolDrawSnake(Snake, longSnake);				// ��������� ����

	foodPosition food;
	food = consolDrawFood(Snake, longSnake);							// ��������� ��� ��� ����

	consolPrintStatistic(SLEEP / speed, longSnake);					// ����� ����������
			
	// �������� ���� ���������
	while (true) 
	{
		// ������������ ���� � ������
		if (snakeCrash(Snake)) {					
			consolPrintMsg("������!!!\n");
			break;
		}
		// �������� �� ������������ ���� � ����� �����
		if (crashWithItSelf(Snake, longSnake)) {	
			consolPrintMsg("� ����������.....!!!\n");
			break;
		}
		

		if (takeFood(Snake, food)) {				// ���� ��������� ������ ������� � ���������� ���
			longSnake++;												// ���������� ���� �� ���� ������
			food = consolDrawFood(Snake, longSnake - 1);					// ��������� ����� ��� ��� ����
			speed = SLEEP / (longSnake / SNAKE_SIZE);					// ���������� �������� ��� ����� ����
			consolPrintStatistic(SLEEP / speed, longSnake);				// ����� ����������
		}
		// �������� food
		// printf("%d %d\n", food.x, food.y);

		//gotoxy(Snake[0]);												// ����������� ������� � ������ ������ ����
		//putchar(HEAD_SNAKE);											// ��������� ������ ����
		//for (int i = 1; i < longSnake; i++)
		//{
		//	gotoxy(Snake[i]);
		//	putchar(BODY_SNAKE);
		//	gotoxy(Snake[i]);
		//}
		if (kbhit() != false)
		{
			prevKey = key;
			key = getch();								// �������� ������� ������
			if (key == 27) {							// ����������� ����� ��� ������� Esc
				consolPrintMsg("Game Over!!!\n");		// ����������� ������� ����� �����
				break; 
			}
			if (key == 224) key = getch();				// ��������� ����� �.�. ������������� ������� ���������� E0
			// �������
			/*gotoxy(pointForEndMessage);
			printf("%d\t%x", key, key);*/
			if (key == RIGHT && prevKey == LEFT) key = LEFT;	// ���� �� ����� ������ ����� ����
			if (key == LEFT && prevKey == RIGHT ) key = RIGHT;
			if (key == DOWN && prevKey == UP) key = UP;
			if (key == UP && prevKey == DOWN) key = DOWN;
			
		}
		//gotoxy(Snake[0]);										// ������� ������� � ������ ����

		if (key == LEFT || key == RIGHT) Sleep(speed);			// �������� �������
		else Sleep(speed * DIFF_SPEEDS);						// �������� ����� �������� ��������� � DIFF_SPEEDS ���						
		
		//gotoxy(Snake[longSnake - 1]);							// ���� ������� � ��������� ������ �����
		//putchar(EMPTY_SPACE);									// ��������� �������
		consolClearTail(Snake, longSnake);

		//for (int i = longSnake - 1; i > 0; i--)						// ����������� ���� ���� � ����� ���������
		//{
		//	Snake[i] = Snake[i - 1];
		//}

		//Snake[0] = stepSnake(key, Snake[0]);
		
		// ��������� ������ ��������� ������ ����
		stepSnake(Snake, key, longSnake);
		consolDrawSnake(Snake, longSnake);
	} // end while
} // end main

