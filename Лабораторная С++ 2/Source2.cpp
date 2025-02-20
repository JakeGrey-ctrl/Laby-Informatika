#include <iostream>
#include <cstdlib> //используется в функциях rand() и srand()

using namespace std;

void main1()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	float M[10];
	float *p = M;
	float sum = 0;
	cout << "Исходный массив:\n";
	for (unsigned short i = 0; i < 10; i++)
	{
		float value = ((float)rand()/RAND_MAX * 100); //случайные вещественные значения от 0 до 100 с точностью 2 знаков после запятой
		*(p + i) = value;
		cout << value << endl;
	}
	for (unsigned short i = 0; i < 10; i += 2) sum += *(p + i);
	cout << "Сумма чётных элементов: " << sum;
}