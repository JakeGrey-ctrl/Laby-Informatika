#include <iostream>
#include <limits>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	double x, y, z;
	bool incorrect_input = true;
	cout << "Введите x: ";
	cin >> x;
	while (cin.fail()) //проверка ввода пользователя
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Некорректный ввод! Попробуйте ввести x ещё раз: ";
		cin >> x;
	}
	incorrect_input = true;
	cout << "Введите y: ";
	cin >> y;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Некорректный ввод! Попробуйте ввести y ещё раз: ";
		cin >> y;
	}
	z = sqrt(abs(pow(x, y) - cos(y)));
	cout << "Значение выражения: " << z;
	return 0;
}