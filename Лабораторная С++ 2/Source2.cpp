#include <iostream>
#include <cstdlib> //������������ � �������� rand() � srand()

using namespace std;

void main1()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	float M[10];
	float *p = M;
	float sum = 0;
	cout << "�������� ������:\n";
	for (unsigned short i = 0; i < 10; i++)
	{
		float value = ((float)rand()/RAND_MAX * 100); //��������� ������������ �������� �� 0 �� 100 � ��������� 2 ������ ����� �������
		*(p + i) = value;
		cout << value << endl;
	}
	for (unsigned short i = 0; i < 10; i += 2) sum += *(p + i);
	cout << "����� ������ ���������: " << sum;
}