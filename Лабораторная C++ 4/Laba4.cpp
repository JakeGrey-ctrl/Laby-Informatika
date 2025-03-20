#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string text;
    string symbol;
    cout << "Введите строку: ";
    getline(cin, text);
    while (text.empty())
    {
        cin.ignore(1, '\n');
        cout << "Пустая строка! Попробуйте ещё раз: ";
        getline(cin, text);
    }
    cout << "Введите символ: ";
    getline(cin, symbol);
    while (symbol.length() != 1)
    {
        cin.ignore(18446744073709551615, '\n'); //МАКС ДЛИНА СТРОКИ
        cout << "Вы ввели не символ. Попробуйте ещё раз: ";
        getline(cin, symbol);
    }
    unsigned int i = 0;
    while (i < text.length())
    {
        if (text[i] == symbol[0]) text.erase(i, 1);
        else i++;
    }
    cout << "Изменённая строка: " << text;
    return 0;
}

