#include "SmartInput.h"
#include "Faculty.h"

using namespace std;

int main3()
{
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	vector <faculty> ml_facs = ml_faculties(form_vector_fac(input_uint("¬ведите длину вектор-массива: ")));
	printFaculties(ml_facs);
	if (input_yesno("—охранить результаты в файл? ¬ведите да/нет: ")) printFacultiestoFile(ml_facs, input_filename("¬ведите им€ файла дл€ записи: "));
	return 0;
}