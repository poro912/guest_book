#pragma once
#include<fstream>

#include"GB_moudles.h"

#define FILE_PATH L"../data"
using namespace std;

bool file_save(vector <PINFO>& info_vector, const wchar_t* name);
bool file_load(vector <PINFO>& info_vector, const wchar_t* name);


