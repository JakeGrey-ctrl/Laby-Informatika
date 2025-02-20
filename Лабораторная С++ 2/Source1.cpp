#include <iostream>
#include <cstdlib> //используется в функциях rand() и srand()

using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	unsigned short A[10], G[10], F[10];
	float sr_algebra = 0;
	unsigned short counter = 0; //счётчик учеников, не имеющих 2
	unsigned short i = 0; //число в диапазоне 0-65535 (меньше типа не нашёл)
	unsigned short *pA = A;
	unsigned short *pG = G;
	unsigned short *pF = F;
	srand(time(NULL)); //изменяем параметры генератора чисел [srand(seed)], чтобы каждый раз выдавал разные
	//это делается потому, что rand() - это псевдо-рандом
	//time(NULL) - текущее время системы
	cout << "Массив оценок учеников алгебры:   "; //массивы можно выводить при формировании
	for (unsigned short i = 0; i < 10; i++)
	{
		unsigned short grade = rand() % 4 + 2;
		*(pA + i) = grade;
		cout << grade << " ";
	}
	cout << "\nМассив оценок учеников геометрии: "; //массивы можно выводить при формировании
	for (unsigned short i = 0; i < 10; i++)
	{
		unsigned short grade = rand() % 4 + 2;
		*(pG + i) = grade;
		cout << grade << " ";
	}
	cout << "\nМассив оценок учеников физики:    "; //массивы можно выводить при формировании
	for (unsigned short i = 0; i < 10; i++)
	{
		unsigned short grade = rand() % 4 + 2;
		*(pF + i) = grade;
		cout << grade << " ";
	}
	for (unsigned short i = 0; i < 10; i++) //подсчёт ср. значения оценок по алгебре
	{
		sr_algebra += *(pA + i);
	}
	sr_algebra /= 10;
	cout << "\nСреднее значение оценок по алгебре: " << sr_algebra;
	for (unsigned short i = 0; i < 10; i++) //подсчёт количества учеников, не имеющих "2"
	{
		if (*(pA + i) != 2 && *(pG + i) != 2 && *(pF + i) != 2) counter++;
	}
	cout << "Количество учеников, не имеющих 2: " << counter;
}