#include <iostream>
#include <limits>

using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	double x, y;
	cout << "Введите x: ";
	while (!(cin >> x)) //проверка ввода пользователя
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Неверный ввод! Попробуйте ещё раз ввести x: ";
	}
	if (x < -2.5) y = pow(sin(5 * pow(x, 2) + 3 * x + 1), 5);
	else if (x < 4) y = x * sin(4 * x - 1);
	else y = exp(-6 * x) + 8;
	cout << "Значение y: " << y;
	return 0;
}