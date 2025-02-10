#include <iostream>
#include <limits>

using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	double x, y, z;
	cout << "Введите x: ";
	while (!(cin >> x)) //проверка ввода пользователя
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Неверный ввод! Попробуйте ещё раз ввести x: ";
	}
	cin.clear();
	cout << "Введите y: ";
	while (!(cin >> y)) //проверка ввода пользователя
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Неверный ввод! Попробуйте ещё раз ввести y: ";
	}
	z = sqrt(abs(pow(x, y) - cos(y)));
	cout << "Значение выражения: " << z;
	return 0;
}
