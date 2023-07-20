#pragma once
#include <iostream>
#include <fstream>
const int LEN = 32;
using namespace std;

class Veteran
{
	char name[LEN];
	int age;
	char military_service[LEN];
	char contact_information[LEN];
	char password[LEN];
	char support_type[LEN]="";
public:
	Veteran() = default;
	void SetVeteran();
	void RegistVeteran();
	bool LoginVeteran();
	void EditInformation();
	void Account();
	void Show();
	char* GetName();
	void SetSuppType();
};