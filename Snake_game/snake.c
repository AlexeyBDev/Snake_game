/* Программа представляет игру "Змейка"
 * Начальный текст программы получен на курсе "Программирование на языке C (Си)" (Специалист). 
 * Первоначальный автор неизвестен.
 * Версия 0.91
 * 080317 - разбивка тела программы на файлы, рефакторинг кода; 
*/

#include "snakeStruct.h"
#include "snakeFunction.h"
#include "frameStruct.h"
#include "foodFunction.h"

//#define OPEN_GL_SNAKE_MODE					// сборка проекта в OpenGL
//extern snakeElement startPointFrame;


						// проверка змеи на столкновение с самой собой

int main()
{
	system("color 1E");						// Установка синего фона и желтого текста
	setlocale(LC_CTYPE, "rus");

	frameInit();							// приглашение начать игру и отрисовка рамки

	int key, prevKey;			// текущая клавиша направления и предыдущая

	int speed = SLEEP;						// начальная скорость змеи

	int longSnake = SNAKE_SIZE;						// longSnake - текущий размер змеи
	snakeElement* Snake = snakeInit(longSnake);		// массив тела змеи
	
	foodPosition food;
	food = foodGenerator(Snake, longSnake);							// генерация еды для змеи

	consolPrintStatistic(SLEEP / speed, longSnake);					// вывод статистики
			

	while (true) // основной цикл программы
	{
		if (snakeCrash(Snake[0])) {					// столкновение змеи с рамкой
			gotoxy(pointForEndMessage);				// завершающая надпись после рамки
			printf("Авария!!!\n");
			break;
		}
		if (crashWithItSelf(Snake, longSnake)) {	// столкновение змеи с рамкой
			gotoxy(pointForEndMessage);				// завершающая надпись после рамки
			printf("Я запуталась.....!!!\n");
			break;
		}
		// проверка на столкновение змеи с самой сабой


		if (food.x == Snake[0].x && food.y == Snake[0].y) {				// если положение головы совпало с положением еды
			longSnake++;												// увеличение змеи на один сектор
			food = foodGenerator(Snake, longSnake - 1);					// генерация новой еды для змеи
			speed = SLEEP / (longSnake / SNAKE_SIZE);					// увеличение скорости при росте змеи
			gotoxy(pointForEndStatistic);								// перевод курсора в точку вывода статистики
			printf("Текущая скорость: %d  Размер змеи: %d\n", 
				SLEEP / speed, longSnake);								// вывод статистики
		}
		// проверка food
		// printf("%d %d\n", food.x, food.y);

		gotoxy(Snake[0]);												// перемещение курсора в первых сектор змеи
		putchar(HEAD_SNAKE);											// отрисовка головы змеи
		for (int i = 1; i < longSnake; i++)
		{
			gotoxy(Snake[i]);
			putchar(BODY_SNAKE);
			gotoxy(Snake[i]);
		}
		if (kbhit() != false)
		{
			prevKey = key;
			key = getch();								// перехват нажатия клавиш
			if (key == 27) {							// прекращение цикла при нажатии Esc
				gotoxy(pointForEndMessage);				// завершающая надпись после рамки
				break; 
			}
			if (key == 224) key = getch();				// повторный вызов т.к. первоначально стрелки возвращают E0
			// отладка
			/*gotoxy(pointForEndMessage);
			printf("%d\t%x", key, key);*/
			if (key == RIGHT && prevKey == LEFT) key = LEFT;	// змея не может ползти через себя
			if (key == LEFT && prevKey == RIGHT ) key = RIGHT;
			if (key == DOWN && prevKey == UP) key = UP;
			if (key == UP && prevKey == DOWN) key = DOWN;
			
		}
		gotoxy(Snake[0]);										// перевод курсора в голову змеи

		if (key == LEFT || key == RIGHT) Sleep(speed);			// задержка времени
		else Sleep(speed * DIFF_SPEEDS);						// скорость между строками медленнее в DIFF_SPEEDS раз						
		
		gotoxy(Snake[longSnake - 1]);							// уход курсора в последний сектор замеи
		putchar(EMPTY_SPACE);									// отрисовка пустоты

		for (int i = longSnake - 1; i > 0; i--)						// перемещение тела змеи в новое состояние
		{
			Snake[i] = Snake[i - 1];
		}

		Snake[0] = stepSnake(key, Snake[0]);					// отрисовка нового положения головы змеи
	} // end while
} // end main

