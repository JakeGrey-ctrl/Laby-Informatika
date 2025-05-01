#include "SiteVisit.h";

vector <SiteVisit> form_visits_from_data(vector <string> data)
{
	vector <SiteVisit> visits;
	vector <string> existing_names;
	vector <string> existing_times;
	for (string s : data)
	{
		SiteVisit new_visit;
		unsigned int space_pos = s.find(" ");
		if (space_pos != 0 && space_pos != s.length() - 1 && space_pos != string::npos && s.find(".") != string::npos)
		{
			new_visit.ip = s.substr(0, space_pos);
			new_visit.time = s.substr(space_pos + 1, s.length() - space_pos);
			if (find_vector_element(existing_names, new_visit.ip) == -1 || find_vector_element(existing_times, new_visit.time) == -1)
			{
				existing_names.emplace_back(new_visit.ip);
				existing_times.emplace_back(new_visit.time);
				visits.emplace_back(new_visit);
			}
			else
			{
				bool check = true;
				for (unsigned int i = 0; i < existing_names.size(); i++)
				{
					if (existing_names[i] == new_visit.ip && existing_times[i] == new_visit.time)
					{
						cout << "Найдено повторение " << s << " . Оно было проигнорировано.\n";
						check = false;
						break;
					}
				}
				if (check) visits.emplace_back(new_visit);
			}
		}
		else
		{
			cout << "Обнаружено неверно заданное посещение " << s << ". Оно было пропущено.\n";
		}
	}
	return visits;
}

DictInt form_count_dict(vector <SiteVisit> visits)
{
	DictInt dict;
	for (SiteVisit v : visits)
	{
		if (find_vector_element(dict.keys, v.ip) == -1)
		{
			dict.keys.emplace_back(v.ip);
			dict.values.emplace_back(1);
		}
		else
		{
			dict.values[find_vector_element(dict.keys, v.ip)]++;
		}
	}
	return dict;
}

void print_visit_dict(DictInt dict)
{
	for (unsigned int i = 0; i < dict.keys.size(); i++)
	{
		cout << dict.keys[i] << " - " << dict.values[i] << endl;
	}
}

void print_visit_dict_to_file(DictInt dict, string filename)
{
	ofstream fout(filename);
	for (unsigned int i = 0; i < dict.keys.size(); i++)
	{
		fout << dict.keys[i] << " - " << dict.values[i] << endl;
	}
	fout.close();
	cout << "Отлично! Ваши результаты записаны в файл " << filename;
}