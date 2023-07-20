#pragma once
#include <iostream>
#include "Veteran.h"
using namespace std;

class Administrator
{
	char password[LEN] = "admin";

public:
	Administrator() = default;
	void LoginAdmin();
	void Account();
	void AddVeteran();
	void UpdateVeteran();
	void MarkVeteransWithSupport();
};