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
		cout << "Ошибка! Введите целое положительное число: ";
		cin >> s;
	}
	return stoi(s);
}

bool valid_filename(string s)
{
	return (s.find(".") > 0 && s.rfind(".") < s.length() - 1);
}

string input_filename(string input_text)
{
	string s;
	cout << input_text;
	cin >> s;
	while (!(valid_filename(s)))
	{
		cin.ignore(string::npos, '\n');
		cout << "Ошибка! Введите корректное имя файла: ";
		cin >> s;
	}
	return s;
}

bool input_yesno(string input_text)
{
	string answer;
	cout << input_text;
	cin >> answer;
	if (answer == "да" || answer == "Да" || answer == "ДА")
	{
		return true;
	}
	else if (answer == "нет" || answer == "Нет" || answer == "НЕТ")
	{
		return false;
	}
	else
	{
		cin.ignore(string::npos, '\n');
		return input_yesno("Ответ не принят. Введите да или нет: ");
	}
}

vector <string> input_data_from_file(string filename)
{
	vector <string> data;
	ifstream fin(filename);
	if (fin.fail())
	{
		fin.clear();
		fin.close();
		return input_data_from_file(input_filename("Ошибка при открытии несуществующего файла! Пожалуйста, задайте корректное имя существующего файла: "));
	}
	while (!fin.eof())
	{
		string line;
		getline(fin, line);
		data.emplace_back(line);
	}
	fin.close();
	if (data.size() == 1 && data[0] == "")
	{
		fin.clear();
		return input_data_from_file(input_filename("Файл пуст. Пожалуйста, задайте имя непустого файла: "));
	}
	return data;
}

int find_vector_element(vector <string> vec, string elem)
{
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] == elem) return i;
	}
	return -1;
}