#include "SmartInput.h"
#include "Faculty.h"

using namespace std;

int main3()
{
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	vector <faculty> ml_facs = ml_faculties(form_vector_fac(input_uint("������� ����� ������-�������: ")));
	printFaculties(ml_facs);
	if (input_yesno("��������� ���������� � ����? ������� ��/���: ")) printFacultiestoFile(ml_facs, input_filename("������� ��� ����� ��� ������: "));
	return 0;
}