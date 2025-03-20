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
    const char* letters = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM������������������������������������������������������������������";
    cout << "������� ������: ";
    getline(cin, text);
    while (text.empty())
    {
        cin.ignore(18446744073709551615, '\n'); //��� ������ ������������ numeric_limits<streamsize>::max(), ��� ��� ��� ����������� � windows.h
        cout << "������ ������! ���������� ��� ���: ";
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
        cout << "� ������ ������ ����, ��� ����";
    }
    else if (balancer == 0)
    {
        cout << "� ������ ����� ���� � ���� ���������";
    }
    else
    {
        cout << "� ������ ������ ����, ��� ����";
    }
    return 0;
}