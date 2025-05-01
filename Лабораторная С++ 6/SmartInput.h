#pragma once
#ifndef SMART_INPUT_H
#define SMART_INPUT_H
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <fstream>

using namespace std;

bool valid_uint(string);
unsigned int input_uint(string);
bool valid_filename(string);
string input_filename(string);
bool input_yesno(string);
vector <string> input_data_from_file(string);
int find_vector_element(vector <string>, string);

#endif
