#include <iostream>
#include <cstdlib> //������������ � �������� rand() � srand()

using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	unsigned short A[10], G[10], F[10];
	float sr_algebra = 0;
	unsigned short counter = 0; //������� ��������, �� ������� 2
	unsigned short i = 0; //����� � ��������� 0-65535 (������ ���� �� �����)
	unsigned short *pA = A;
	unsigned short *pG = G;
	unsigned short *pF = F;
	srand(time(NULL)); //�������� ��������� ���������� ����� [srand(seed)], ����� ������ ��� ������� ������
	//��� �������� ������, ��� rand() - ��� ������-������
	//time(NULL) - ������� ����� �������
	cout << "������ ������ �������� �������:   "; //������� ����� �������� ��� ������������
	for (unsigned short i = 0; i < 10; i++)
	{
		unsigned short grade = rand() % 4 + 2;
		*(pA + i) = grade;
		cout << grade << " ";
	}
	cout << "\n������ ������ �������� ���������: "; //������� ����� �������� ��� ������������
	for (unsigned short i = 0; i < 10; i++)
	{
		unsigned short grade = rand() % 4 + 2;
		*(pG + i) = grade;
		cout << grade << " ";
	}
	cout << "\n������ ������ �������� ������:    "; //������� ����� �������� ��� ������������
	for (unsigned short i = 0; i < 10; i++)
	{
		unsigned short grade = rand() % 4 + 2;
		*(pF + i) = grade;
		cout << grade << " ";
	}
	for (unsigned short i = 0; i < 10; i++) //������� ��. �������� ������ �� �������
	{
		sr_algebra += *(pA + i);
	}
	sr_algebra /= 10;
	cout << "\n������� �������� ������ �� �������: " << sr_algebra;
	for (unsigned short i = 0; i < 10; i++) //������� ���������� ��������, �� ������� "2"
	{
		if (*(pA + i) != 2 && *(pG + i) != 2 && *(pF + i) != 2) counter++;
	}
	cout << "���������� ��������, �� ������� 2: " << counter;
}