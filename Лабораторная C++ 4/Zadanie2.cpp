#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int main1()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string text;
    int balancer = 0;
    const char* digits = "0123456789";
    const char* letters = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNMЄйцукенгшщзхъфывапролджэ€чсмитьбю®…÷” ≈Ќ√Ўў«’Џ‘џ¬јѕ–ќЋƒ∆Ёя„—ћ»“№Ѕё";
    cout << "¬ведите строку: ";
    getline(cin, text);
    while (text.empty())
    {
        cin.ignore(18446744073709551615, '\n'); //тут нельз€ использовать numeric_limits<streamsize>::max(), так как оно конфликтует с windows.h
        cout << "ѕуста€ строка! ѕопробуйте ещЄ раз: ";
        getline(cin, text);
    }
    for (unsigned int i = 0; i < text.length(); i++)
    {
        cout << &text[i] << ' ' << endl;
        if (strstr(digits, text.substr(i, 1).c_str()) != NULL) balancer++;
        else if (strstr(letters, text.substr(i, 1).c_str()) != NULL) balancer--;
    }
    if (balancer > 0)
    {
        cout << "¬ тексте больше букв, чем цифр";
    }
    else if (balancer == 0)
    {
        cout << "¬ тексте число букв и цифр одинаково";
    }
    else
    {
        cout << "¬ тексте больше цифр, чем букв";
    }
    return 0;
}