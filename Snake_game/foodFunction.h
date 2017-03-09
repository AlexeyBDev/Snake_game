#ifndef FOOD_FUNCTION_H
#define FOOD_FUNCTION_H

#include "pointStruct.h"
#include "snakeStruct.h"
//#include "snakeFunction.h"

#define FOOD '*'							// ������ ���
//---------------------------------------------------------
// ��������� ��������� ����������� ���
typedef struct PointXY foodPosition;

// �������
// ����������� � �������� ���������
// ���������� � snakeFunction.h
extern void moveTo(position);

// ���������� ��� � ��������� �� ����������� �� ����
foodPosition foodGenerator(snakeElement *Snake, int longSnake);		
// ���������� ���������� ���

// ��������� ��� � �������
foodPosition consolDrawFood(snakeElement *Snake, int longSnake);
#endif

