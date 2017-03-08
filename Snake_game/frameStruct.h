// ������ ���� ��������� ������� �������� � ���������� ����� � ������� ��������� �� �����
#ifndef FRAME_STRUCT_H
#define FRAME_STRUCT_H

#include "pointStruct.h"
//=======================================================
// �������
// ��������� �������������� �����
#define START_POINT_INVITATION_X 0			// ����� ������ ���������� �����������
#define START_POINT_INVITATION_Y 0
#define START_POINT_FRAME_X 0				// ��������� ����� ����� (X)
#define START_POINT_FRAME_Y 1				// ��������� ����� ����� (Y)
#define FRAME_X 60							// ������ ����� �� x
#define FRAME_Y 20							// ������ ����� �� y
#define NODE_FRAME '+'						// ������ � ����� ����� '+'
#define HORIZONT_LINE_FRAME '-'				// ������ �������������� ����� ����� '-'
#define VERTICAL_LINE_FRAME '|'				// ������ ������������ ����� ����� '|'
#define EMPTY_SYMBOL_FRAME ' '				// ������ ������ ����� ' '
#define NEW_LINE_FRAME '\n'					// ������ ������ ��������� ����� �����

// ��������� ��������� ����������� ��������� �����
typedef struct PointXY framePosition;

// �������
void consolCursoreMove(framePosition);						// ������� ����������� ������� �� �������� �����������
void consolInvitation(void);								// ����� � ������� ����������� � ������ ����
void consolDrawFrame(int width, int height);				// ������� ��������� �������������� �����
void frameInit();											// ������� ������������� �����
void consolPrintStatistic(int speed, int size);					// ����� �������� � ������� ����

#endif