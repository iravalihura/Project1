#pragma once
#include <iostream>
#include "Veteran.h"
#include "Resource.h"
using namespace std;

class Administrator
{
	char password[LEN] = "admin";
public:
	Administrator() = default;
	void LoginAdmin(vector<Resource*>&);
	void Account(vector<Resource*>&);
	void AddVeteran();
	void UpdateVeteran();
	void MarkVeteransWithSupport();
	void ShowVeterans();
	void AddResources(vector<Resource*>&);
	void ShowResources(vector<Resource*>&);
	void UpdateResource(vector<Resource*>&);
};