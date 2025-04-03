#include <iostream>
#include <string>

using namespace std;

bool valid_double1(string& s)
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

double input_double1(int num)
{
	setlocale(LC_ALL, "Russian");
	string d;
	cout << "¬ведите " << num << "-е вещественное число: ";
	cin >> d;
	while (!(valid_double1(d)))
	{
		cin.ignore(string::npos, '\n');
		cout << "ќшибка ввода! ¬ведите число: ";
		cin >> d;
	}
	return stod(d);
}

int Sign(double X)
{
	if (X < 0) return -1;
	else if (X == 0) return 0;
	return 1;
}

int main()
{
	double A, B;
	A = input_double1(1);
	B = input_double1(2);
	cout << "—умма знаков первого и второго числа: " << Sign(A) + Sign(B);
	return 0;
}