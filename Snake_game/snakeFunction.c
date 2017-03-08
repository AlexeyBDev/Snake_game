#include "snakeFunction.h"
#include "snakeStruct.h"

//snakeElement startPointFrame = { START_POINT_FRAME_X,// точка старта отрисовку рамки
//START_POINT_FRAME_Y };
//snakeElement pointForEndMessage = { 0,			// точка вывода завершающей надписи по окончании программы
//START_POINT_FRAME_Y + FRAME_Y + 2 };
//snakeElement pointForEndStatistic = { 0,		// точка вывода статистики во время работы программы
//START_POINT_FRAME_Y + FRAME_Y + 1 };

// реализация функций

void newSnake(snakeElement *Snake, int leight, int direction)
{
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
	}
}

int startDirection(void)							// функция генерации начального направления
{
	DWORD nStartValue = time(NULL);
	srand(nStartValue);
	int direction;
	direction = rand() % 4;						// генерация случайного направления

	switch (direction) {
	case 0: return LEFT;
	case 1: return RIGHT;
	case 2: return UP;
	case 3: return DOWN;
	default: return UP;
	}
}

snakeElement stepSnake(int direction, snakeElement head)					// функция генерации шага змеи
{
	snakeElement step;
	switch (direction) {
	case LEFT:	step.x = -1 + head.x;					// лево (был код 75)
		step.y = 0 + head.y;
		return step;
	case RIGHT: step.x = 1 + head.x;					// право (был код - 77)
		step.y = 0 + head.y;
		return step;
	case UP:	step.x = 0 + head.x;					// верх (был код - 72)
		step.y = -1 + head.y;
		return step;
	case DOWN:	step.x = 0 + head.x;					// низ (был код - 80)
		step.y = 1 + head.y;
		return step;
	default:	step.x = 0 + head.x;
		step.y = 0 + head.y;
		return step;
	}
}

void drawFrame(int x, int y)
{
	/*  o----> X
	|
	|
	Y       */
	printf("Змейка! Поехали.......");									//
	gotoxy(startPointFrame);					// начало отрисовки рамки
	for (int i = 0; i <= y; i++)
	{
		for (int j = 0; j <= x; j++)
		{
			if (i == 0 || i == y)
			{
				if (j == 0 || j == x) putchar(NODE_FRAME);				// отрисовка узвол рамки
				else putchar(HORIZONT_LINE_FRAME);						// отрисовка горизонтальной линии
			}
			else
			{
				if (j == 0 || j == x) putchar(VERTICAL_LINE_FRAME);		// отрисовка вертикальной линии
				else putchar(EMPTY_SYMBOL_FRAME);						// отрисовка пустоты
			}
			if (j == x) putchar(NEW_LINE_FRAME);
		}
	}
}

void gotoxy(snakeElement step)
{
	COORD position = { step.x, step.y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

bool snakeCrash(snakeElement position)						// функция определения столкновения змеи с рамкой
{
	if (position.x <= START_POINT_FRAME_X || position.x >= START_POINT_FRAME_X + FRAME_X ||
		position.y <= START_POINT_FRAME_Y || position.y >= START_POINT_FRAME_Y + FRAME_Y) return true;
	else return false;
}

foodPosition foodGenerator(snakeElement *Snake, int longSnake)								// генератор еды
{
	foodPosition food;
	DWORD nStartValue = time(NULL);
	srand(nStartValue);
	int food_x, food_y;
	food.x = START_POINT_FRAME_X + rand() % (FRAME_X - 2) + 1;				// генерация положения еды в рамке
	food.y = START_POINT_FRAME_Y + rand() % (FRAME_Y - 2) + 1;				// -2 - уменьшение диапазона чтобы не попало на рамки
																			// +1 - смещение относительно начало
																			// проверка на совпадение положения еды с положением самой змеи
																			// если попало на змею, генерируем заново
	for (int i = 0; i < longSnake; i++) {
		if (food.x == Snake[i].x && food.y == Snake[i].y)
		{
			food = foodGenerator(Snake, longSnake);							// если совпало, то вызываем повторно
			gotoxy(food);
			putchar(FOOD); // отрисовка еды
			return food;
		}
	}
	gotoxy(food);
	putchar(FOOD);											// отрисовка еды
	return food;
}

bool crashWithItSelf(snakeElement *Snake, int longSnake) {		// проверка змеи на столкновение с самой собой
	for (int i = 1; i < longSnake; i++)
	{
		if (Snake[0].x == Snake[i].x && Snake[0].y == Snake[i].y)
			return true;
	}
	return false;
}