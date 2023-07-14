#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Veteran
{
	string name;
	int age;
	string military_service;
	string contact_information;
	string password;
	
public:
	Veteran();
	void RegisterVeteran();
	//bool LoginVeteran(const std::vector<Veteran*>&);
	void Show();
	string GetName();
	string GetPassword();
};

