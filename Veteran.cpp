#include "Veteran.h"

Veteran::Veteran()
{
	/*name = ' ';
	age = 0;
	military_service = ' ';
	contact_information = ' ';*/
}

void Veteran::RegisterVeteran()
{
	cout << "����i�� ������: ";
	cin.ignore();
	getline(cin, password);
	cout << "����i�� i�'�: ";
	cin.ignore();
	getline(cin, name);
	cout << "����i�� �i�: ";
	cin >> age;
	cout << "����i�� i�������i� ��� �i������� ������: ";
	cin.ignore();
	getline(cin, military_service);
	cout << "����i�� ��������� i�������i�: ";
	cin.ignore();
	getline(cin, contact_information);
	cout << endl;

	
}

//bool Veteran::LoginVeteran(const vector<Veteran*>& veterans)
//{
//	string name,password;
//
//	cout << "����i�� i�'�: ";
//	getline(std::cin, name);
//	cout << "����i�� ������: ";
//	getline(std::cin, password);
//
//	for (const auto& veteran : veterans) {
//		if (veteran.GetName() == name) {
//			std::cout << "��i� ���i����!\n";
//			return true;
//		}
//	}
//
//	std::cout << "���i������ ������ �� ��������.\n";
//	return false;
//}

void Veteran::Show()
{
	cout << name << age << military_service << contact_information;
}

string Veteran::GetName()
{
	return name;
}

string Veteran::GetPassword()
{
	return password;
}
