#include "SmartInput.h"
#include <fstream>
#include <vector>
#include <time.h>

using namespace std;

struct faculty{
	string name;
	float debtor_percent;
};

string generate_next_name()
{
	static unsigned int _id = 0;
	return "Факультет" + to_string(++_id);
}

vector <faculty> form_vector_fac(unsigned int N)
{
	vector <faculty> new_faculties;
	for (unsigned int i = 0; i < N; i++)
	{
		faculty new_fac;
		new_fac.name = generate_next_name();
		new_fac.debtor_percent = (float)(rand() % 10001) / 100;
		new_faculties.emplace_back(new_fac);
	}
	return new_faculties;
}

vector <faculty> ml_faculties(vector <faculty> faculties)
{
	faculty min_fac = faculties[0], max_fac = faculties[0];
	for (unsigned int i = 1; i < faculties.size(); i++)
	{
		if (faculties[i].debtor_percent < min_fac.debtor_percent) min_fac = faculties[i];
		else if (faculties[i].debtor_percent > max_fac.debtor_percent) max_fac = faculties[i];
	}
	return {min_fac, max_fac};
}

void printFaculties(vector <faculty> faculties)
{
	for (unsigned int i = 0; i < faculties.size(); i++)
	{
		cout << "\nNo" << i << "\nНазвание: " << faculties[i].name << "\nПроцент должников: " << faculties[i].debtor_percent << "%\n";
	}
}

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	printFaculties(ml_faculties(form_vector_fac(input_uint("Введите длину массива: "))));
	return 0;
}