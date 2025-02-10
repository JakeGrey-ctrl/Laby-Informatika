#include <iostream>
#include <string>

using namespace std;

int main1()
{
	setlocale(LC_ALL, "Russian");
	string Sx;
	double x, y;
	bool incorrect_input = true;
	cout << "Введите x: ";
	while (incorrect_input) //проверка ввода пользователя
	{
		try
		{
			cin >> Sx;
			x = stod(Sx);
			incorrect_input = false;
		}
		catch (invalid_argument)
		{
			cout << "Неверный ввод! Попробуйте ещё раз ввести x: ";
		}
	}
	if (x < -2.5) y = pow(sin(5 * pow(x, 2) + 3 * x + 1), 5);
	else if (x < 4) y = x * sin(4 * x - 1);
	else y = exp(-6 * x) + 8;
	cout << "Значение y: " << y;
	return 0;
}