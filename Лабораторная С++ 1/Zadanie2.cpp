#include <iostream>
#include <limits>

using namespace std;

int main1()
{
	setlocale(LC_ALL, "Russian");
	double x, y;
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
	if (x < -2.5) y = pow(sin(5 * pow(x, 2) + 3 * x + 1), 5);
	else if (x < 4) y = x * sin(4 * x - 1);
	else y = exp(-6 * x) + 8;
	cout << "Значение y: " << y;
	return 0;
}