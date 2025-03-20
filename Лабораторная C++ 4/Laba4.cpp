#include <iostream>
#include <string>

using namespace std;

int main1()
{
    setlocale(LC_ALL, "Russian");
    string text;
    string symbol;
    cout << "Введите строку: ";
    getline(cin, text);
    while (text.empty())
    {
        cin.ignore(18446744073709551615, '\n'); //МАКС ДЛИНА СТРОКИ
        cout << "Пустая строка! Попробуйте ещё раз: ";
        getline(cin, text);
    }
    cout << "Введите символ: ";
    getline(cin, symbol);
    while (symbol.length() != 1)
    {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
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

