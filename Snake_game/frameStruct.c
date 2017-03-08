// ���������� ������� ������ � ������
#include <windows.h>
#include <stdio.h>
#include "frameStruct.h"

// ������� ����������� ������� � �������� �������
void consolCursoreMove(framePosition position)
{
	COORD point = { position.x, position.y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
} // consolCursoreMove

// ����� � ������� ����������� � ������ ����
void consolInvitation()
{
	framePosition startPointInvitation = { START_POINT_INVITATION_X, START_POINT_INVITATION_Y };
	consolCursoreMove(startPointInvitation);
	printf("������! �������.......");
}

void consolDrawFrame(int width, int height)
{
	/*  o----> width
	|
	|
	height       */
	//consolInvitation();
	// ������ ��������� �����
	framePosition startPointFrame = { START_POINT_FRAME_X, START_POINT_FRAME_Y };

	consolCursoreMove(startPointFrame);					// ������ ��������� �����

	for (int i = 0; i <= height; i++)
	{
		for (int j = 0; j <= width; j++)
		{
			if (i == 0 || i == height)
			{
				if (j == 0 || j == width) putchar(NODE_FRAME);				// ��������� ����� �����
				else putchar(HORIZONT_LINE_FRAME);						// ��������� �������������� �����
			}
			else
			{
				if (j == 0 || j == width) putchar(VERTICAL_LINE_FRAME);		// ��������� ������������ �����
				else putchar(EMPTY_SYMBOL_FRAME);						// ��������� �������
			}
			if (j == width) putchar(NEW_LINE_FRAME);
		}
	}
}

// ���������� ���������� ��� ����������� � ������������ �������
#if defined(OPEN_GL_SNAKE_MODE)
// ��� ����� ���������� ������� frameInit() ��� ������ openGL



#else
void frameInit()
{
	consolInvitation();
	consolDrawFrame(FRAME_X, FRAME_Y);
}

void consolPrintStatistic(int speed, int size)
{
	// ����� ������ ����������� ������� �� ��������� ���������
	framePosition pointForEndStatistic = { 0, START_POINT_FRAME_Y + FRAME_Y + 2 }; 	
	consolCursoreMove(pointForEndStatistic);						// ������� ������� � ����� ������ ����������
	printf("������� ��������: %d  ������ ����: %d\n",
		 speed, size);												// ����� ����������
}
#endif
