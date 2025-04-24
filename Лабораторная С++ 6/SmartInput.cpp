#include "SmartInput.h"

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

unsigned int input_uint(string input_text)
{
	string s;
	cout << input_text;
	cin >> s;
	while (!(valid_uint(s)))
	{
		cin.ignore(string::npos, '\n');
		cout << "ќшибка! ¬ведите целое положительное число: ";
		cin >> s;
	}
	return stoi(s);
}