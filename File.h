#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class File
{
	fstream file;
public:
	void OpenFile(const ios_base::openmode mode);
	void Add();
	void Supplementing();
	void Editing();
	void View();
	void ToyList();
};

