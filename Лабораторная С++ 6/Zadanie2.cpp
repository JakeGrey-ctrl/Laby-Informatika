#include "SiteVisit.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	DictInt site_visits = form_count_dict(form_visits_from_data(input_data_from_file(input_filename("Введите имя файла для чтения: "))));
	print_visit_dict(site_visits);
	if (input_yesno("Сохранить результаты в файл? ")) print_visit_dict_to_file(site_visits, input_filename("Введите имя файла для записи: "));
	return 0;
}