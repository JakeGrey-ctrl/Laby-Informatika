#include <iostream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	double x, y, z;
	string Sx, Sy;
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
	incorrect_input = true;
	cout << "Введите y: ";
	while (incorrect_input) //проверка ввода пользователя
	{
		try
		{
			cin >> Sy;
			y = stod(Sy);
			incorrect_input = false;
		}
		catch (invalid_argument)
		{
			cout << "Неверный ввод! Попробуйте ещё раз ввести y: ";
		}
	}
	z = sqrt(abs(pow(x, y) - cos(y)));
	cout << "Значение выражения: " << z;
	return 0;
}