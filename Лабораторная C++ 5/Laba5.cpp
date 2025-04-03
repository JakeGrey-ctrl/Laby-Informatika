#include <iostream>
#include <string>

using namespace std;

void PowerA234(double A, double& B, double& C, double& D)
{
	B = pow(A, 2);
	C = pow(A, 3);
	D = pow(A, 4);
}

bool valid_double(string &s)
{
	unsigned int len = s.length();
	if (len > 0)
	{
		bool has_minus = (s[0] == '-');
		if (len > (unsigned short)has_minus)
		{
			bool has_point = false;
			const char* digits = "0123456789";
			for (unsigned int i = (short)has_minus; i < len; i++)
			{
				if (s[i] == '.')
				{
					if (has_point || i == (short)has_minus || i == len - 1) return false;
					else
					{
						s[i] = ',';
						has_point = true;
					}
				}
				else if (strstr(digits, s.substr(i, 1).c_str()) == NULL) return false;
			}
			return true;
		}
	}
	return false;
}

double input_double(int num)
{
	setlocale(LC_ALL, "Russian");
	string d;
	cout << "Введите " << num << "-е вещественное число: ";
	cin >> d;
	while (!(valid_double(d)))
	{
		cin.ignore(string::npos, '\n');
		cout << "Ошибка ввода! Введите число: ";
		cin >> d;
	}
	return stod(d);
}

int main1()
{
	for (unsigned short i = 1; i <= 5; i++)
	{
		double A = input_double(i);
		double B, C, D;
		PowerA234(A, B, C, D);
		cout << "Квадрат " << i << "-го числа: " << B << endl << "Куб " << i << "-го числа: " << C << endl << "Четвёртая степень " << i << "-го числа: " << D << endl;
		return 0;
	}
}