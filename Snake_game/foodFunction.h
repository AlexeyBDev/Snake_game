#ifndef FOOD_FUNCTION_H
#define FOOD_FUNCTION_H

#include "pointStruct.h"
#include "snakeStruct.h"
#include "snakeFunction.h"
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
void consolDrawFood(snakeElement *Snake, int longSnake);
#endif

