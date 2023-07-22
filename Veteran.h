#pragma once
#include <iostream>
#include <fstream>
#include "Resource.h"
using namespace std;

class Veteran
{
	char name[LEN];
	int age;
	char military_service[LEN];
	char contact_information[LEN];
	char password[LEN];
	char support_type[LEN] = "";
public:
	Veteran() = default;
	void SetVeteran();
	void RegistVeteran();
	bool LoginVeteran();
	void EditInformation();
	void Account(vector<Resource*>&);
	void Show();
	void FindResource(vector<Resource*>&);
	void LeaveReview(vector<Resource*>&);
	char* GetName();
	void SetSuppType();
};