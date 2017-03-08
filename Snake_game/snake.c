/* ��������� ������������ ���� "������"
 * ��������� ����� ��������� ������� �� ����� "���������������� �� ����� C (��)" (����������). 
 * �������������� ����� ����������.
 * ������ 0.91
 * 080317 - �������� ���� ��������� �� �����, ����������� ����; 
*/

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

	int speed = SLEEP;						// ��������� �������� ����

	int longSnake = SNAKE_SIZE;						// longSnake - ������� ������ ����
	snakeElement* Snake = snakeInit(longSnake);		// ������ ���� ����
	
	foodPosition food;
	food = foodGenerator(Snake, longSnake);							// ��������� ��� ��� ����

	consolPrintStatistic(SLEEP / speed, longSnake);					// ����� ����������
			

	while (true) // �������� ���� ���������
	{
		if (snakeCrash(Snake[0])) {					// ������������ ���� � ������
			gotoxy(pointForEndMessage);				// ����������� ������� ����� �����
			printf("������!!!\n");
			break;
		}
		if (crashWithItSelf(Snake, longSnake)) {	// ������������ ���� � ������
			gotoxy(pointForEndMessage);				// ����������� ������� ����� �����
			printf("� ����������.....!!!\n");
			break;
		}
		// �������� �� ������������ ���� � ����� �����


		if (food.x == Snake[0].x && food.y == Snake[0].y) {				// ���� ��������� ������ ������� � ���������� ���
			longSnake++;												// ���������� ���� �� ���� ������
			food = foodGenerator(Snake, longSnake - 1);					// ��������� ����� ��� ��� ����
			speed = SLEEP / (longSnake / SNAKE_SIZE);					// ���������� �������� ��� ����� ����
			gotoxy(pointForEndStatistic);								// ������� ������� � ����� ������ ����������
			printf("������� ��������: %d  ������ ����: %d\n", 
				SLEEP / speed, longSnake);								// ����� ����������
		}
		// �������� food
		// printf("%d %d\n", food.x, food.y);

		gotoxy(Snake[0]);												// ����������� ������� � ������ ������ ����
		putchar(HEAD_SNAKE);											// ��������� ������ ����
		for (int i = 1; i < longSnake; i++)
		{
			gotoxy(Snake[i]);
			putchar(BODY_SNAKE);
			gotoxy(Snake[i]);
		}
		if (kbhit() != false)
		{
			prevKey = key;
			key = getch();								// �������� ������� ������
			if (key == 27) {							// ����������� ����� ��� ������� Esc
				gotoxy(pointForEndMessage);				// ����������� ������� ����� �����
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
		gotoxy(Snake[0]);										// ������� ������� � ������ ����

		if (key == LEFT || key == RIGHT) Sleep(speed);			// �������� �������
		else Sleep(speed * DIFF_SPEEDS);						// �������� ����� �������� ��������� � DIFF_SPEEDS ���						
		
		gotoxy(Snake[longSnake - 1]);							// ���� ������� � ��������� ������ �����
		putchar(EMPTY_SPACE);									// ��������� �������

		for (int i = longSnake - 1; i > 0; i--)						// ����������� ���� ���� � ����� ���������
		{
			Snake[i] = Snake[i - 1];
		}

		Snake[0] = stepSnake(key, Snake[0]);					// ��������� ������ ��������� ������ ����
	} // end while
} // end main

