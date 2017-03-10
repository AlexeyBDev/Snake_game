/* Программа представляет игру "Змейка"
 * Начальный текст программы получен на курсе "Программирование на языке C (Си)" (Специалист). 
 * Первоначальный автор неизвестен.
 * Версия 0.91
 * 080317 - разбивка тела программы на файлы, рефакторинг кода; 
*/
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <windows.h>
#include "snakeStruct.h"
#include "snakeFunction.h"
#include "frameStruct.h"
#include "foodFunction.h"

//#define OPEN_GL_SNAKE_MODE					// сборка проекта в OpenGL
//extern snakeElement startPointFrame;



int main()
{
	// Установка синего фона и желтого текста
	system("color 1E");						
	setlocale(LC_CTYPE, "rus");
	// приглашение начать игру и отрисовка рамки
	frameInit();							
	// текущая клавиша направления и предыдущая
	int key, prevKey;			
	key = startDirectionSnake();
	// начальная скорость змеи
	int speed = SLEEP;						

	int longSnake = SNAKE_SIZE;						// longSnake - текущий размер змеи
	snakeElement* Snake = snakeInit(longSnake);		// массив тела змеи
	consolDrawSnake(Snake, longSnake);				// отрисовка змеи
	// генерация еды для змеи
	foodPosition food;
	food = consolDrawFood(Snake, longSnake);							
	// вывод статистики по игре
	consolPrintStatistic(SLEEP / speed, longSnake);					
			
	// основной цикл программы
	while (true) 
	{
		// столкновение змеи с рамкой
		if (snakeCrash(Snake)) {					
			consolPrintMsg("Авария!!!\n");
			break;
		}
		// проверка на столкновение змеи с самой сабой
		if (crashWithItSelf(Snake, longSnake)) {	
			consolPrintMsg("Я запуталась.....!!!\n");
			break;
		}
		
		// проверка нажатия клавиши управления
		if (kbhit() != false)
		{
			prevKey = key;
			key = getch();								// перехват нажатия клавиш
			if (key == 27) {							// прекращение цикла при нажатии Esc
				consolPrintMsg("Game Over!!!\n");		// завершающая надпись после рамки
				break; 
			}
			if (key == 224) key = getch();				// повторный вызов т.к. первоначально стрелки возвращают E0

			if (key == RIGHT && prevKey == LEFT) key = LEFT;	// змея не может ползти через себя
			if (key == LEFT && prevKey == RIGHT ) key = RIGHT;
			if (key == DOWN && prevKey == UP) key = UP;
			if (key == UP && prevKey == DOWN) key = DOWN;
			
		}

		if (key == LEFT || key == RIGHT) Sleep(speed);			// задержка времени
		else Sleep(speed * DIFF_SPEEDS);						// скорость между строками медленнее в DIFF_SPEEDS раз						
		// стирание последнего элемента змеи									
		consolClearTail(Snake, longSnake);						
	
		// если положение головы совпало с положением еды
		if (takeFood(Snake, food)) {				
			longSnake++;												// увеличение змеи на один сектор
			food = consolDrawFood(Snake, longSnake - 1);					// генерация новой еды для змеи
			speed = SLEEP / (longSnake / SNAKE_SIZE);					// увеличение скорости при росте змеи
			consolPrintStatistic(SLEEP / speed, longSnake);				// вывод статистики
		}

		// следующий шаг змеи
		stepSnake(Snake, key, longSnake);
		consolDrawSnake(Snake, longSnake);
	} // end while
	system("pause");
	return 0;
} // end main

