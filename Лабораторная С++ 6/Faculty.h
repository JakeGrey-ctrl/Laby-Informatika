#pragma once
#ifndef FACULTY_H
#define FACULTY_H
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <fstream>

using namespace std;

struct faculty
{
	string name;
	float debtor_percent;
};
string generate_next_name();
vector <faculty> form_vector_fac(unsigned int);
vector <faculty> ml_faculties(vector <faculty>);
void printFaculties(vector <faculty>);
void printFacultiestoFile(vector <faculty>, string);

#endif
