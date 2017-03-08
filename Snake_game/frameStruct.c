// реализация функций работы с рамкой
#include <windows.h>
#include <stdio.h>
#include "frameStruct.h"

// функция перемещения курсора в заданную позицию
void consolCursoreMove(framePosition position)
{
	COORD point = { position.x, position.y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
} // consolCursoreMove

// вывод в консоль приглашения к началу игры
void consolInvitation()
{
	framePosition startPointInvitation = { START_POINT_INVITATION_X, START_POINT_INVITATION_Y };
	consolCursoreMove(startPointInvitation);
	printf("Змейка! Поехали.......");
}

void consolDrawFrame(int width, int height)
{
	/*  o----> width
	|
	|
	height       */
	//consolInvitation();
	// начало отрисовку рамки
	framePosition startPointFrame = { START_POINT_FRAME_X, START_POINT_FRAME_Y };

	consolCursoreMove(startPointFrame);					// начало отрисовки рамки

	for (int i = 0; i <= height; i++)
	{
		for (int j = 0; j <= width; j++)
		{
			if (i == 0 || i == height)
			{
				if (j == 0 || j == width) putchar(NODE_FRAME);				// отрисовка узвол рамки
				else putchar(HORIZONT_LINE_FRAME);						// отрисовка горизонтальной линии
			}
			else
			{
				if (j == 0 || j == width) putchar(VERTICAL_LINE_FRAME);		// отрисовка вертикальной линии
				else putchar(EMPTY_SYMBOL_FRAME);						// отрисовка пустоты
			}
			if (j == width) putchar(NEW_LINE_FRAME);
		}
	}
}

// разделение реализации для консольного и графического режимов
#if defined(OPEN_GL_SNAKE_MODE)
// тут будет реализация функции frameInit() для режима openGL



#else
void frameInit()
{
	consolInvitation();
	consolDrawFrame(FRAME_X, FRAME_Y);
}

void consolPrintStatistic(int speed, int size)
{
	// точка вывода завершающей надписи по окончании программы
	framePosition pointForEndStatistic = { 0, START_POINT_FRAME_Y + FRAME_Y + 2 }; 	
	consolCursoreMove(pointForEndStatistic);						// перевод курсора в точку вывода статистики
	printf("Текущая скорость: %d  Размер змеи: %d\n",
		 speed, size);												// вывод статистики
}
#endif
