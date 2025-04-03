#include <iostream>
#include <string>

using namespace std;

bool valid_uint(string s)
{
	unsigned int len = s.length();
	if (len > 0)
	{
		const char* digits = "0123456789";
		for (unsigned int i = 0; i < len; i++)
		{
			if (strstr(digits, s.substr(i, 1).c_str()) == NULL) return false;
		}
		return true;
	}
	return false;
}

unsigned int input_uint(int num)
{
	setlocale(LC_ALL, "Russian");
	string u;
	cout << "¬ведите " << num << "-е положительное целое число: ";
	cin >> u;
	while (!(valid_uint(u)))
	{
		cin.ignore(string::npos, '\n');
		cout << "ќшибка ввода! ¬ведите число: ";
		cin >> u;
	}
	return stoi(u);
}

bool equal(string N, int S)
{
	cout << N << ' ' << S << ' ';
	unsigned int digit = stoi(N.substr(0, 1));
	cout << digit << endl;
	if (N.length() == 1) return (digit == S);
	return equal(N.substr(1, N.length() - 1), S - digit);
}

int main2()
{
	unsigned int N = input_uint(1);
	int S = input_uint(2);
	cout << "«начение функции: " << equal(to_string(N), S);
	return 0;
}