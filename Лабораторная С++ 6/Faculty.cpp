#include "Faculty.h";

string generate_next_name()
{
	static unsigned int _id = 0;
	return "Факультет" + to_string(++_id);
}

vector <faculty> form_vector_fac(unsigned int N)
{
	
	vector <faculty> faculties;
	for (unsigned int i = 0; i < N; i++)
	{
		faculty new_fac;
		new_fac.name = generate_next_name();
		new_fac.debtor_percent = (float)(rand() % 6001) / 100;
		faculties.emplace_back(new_fac);
	}
	return faculties;
}

vector <faculty> ml_faculties(vector <faculty> faculties)
{
	faculty min_fac = faculties[0], max_fac = faculties[0];
	for (unsigned int i = 1; i < faculties.size(); i++)
	{
		if (faculties[i].debtor_percent < min_fac.debtor_percent) min_fac = faculties[i];
		else if (faculties[i].debtor_percent > max_fac.debtor_percent) max_fac = faculties[i];
	}
	vector <faculty> ml = { min_fac, max_fac };
	return ml;
}

void printFaculties(vector <faculty> faculties)
{
	for (unsigned int i = 0; i < faculties.size(); i++)
	{
		cout << "\nNo" << i << "\nНазвание: " << faculties[i].name << "\nПроцент должников: " << faculties[i].debtor_percent << "%\n";
	}
}

void printFacultiestoFile(vector <faculty> faculties, string filename)
{
	ofstream fout(filename);
	for (unsigned int i = 0; i < faculties.size(); i++)
	{
		fout << "\nNo" << i << "\nНазвание: " << faculties[i].name << "\nПроцент должников: " << faculties[i].debtor_percent << "%\n";
	}
	fout.close();
	cout << "Отлично! Ваши результаты записаны в файл " << filename;
}