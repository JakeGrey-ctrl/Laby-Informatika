#pragma once
#ifndef SITEVISIT_H
#define SITEVISIT_H
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Dict.h"
#include "SmartInput.h"

using namespace std;

struct SiteVisit
{
	string ip;
	string time;
};

vector <SiteVisit> form_visits_from_data(vector <string>);
DictInt form_count_dict(vector <SiteVisit>);
void print_visit_dict(DictInt);
void print_visit_dict_to_file(DictInt, string);

#endif