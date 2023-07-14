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
	cout << "¬ведiть пароль: ";
	cin.ignore();
	getline(cin, password);
	cout << "¬ведiть iм'€: ";
	cin.ignore();
	getline(cin, name);
	cout << "¬ведiть вiк: ";
	cin >> age;
	cout << "¬ведiть iнформацiю про вiйськову службу: ";
	cin.ignore();
	getline(cin, military_service);
	cout << "¬ведiть контактну iнформацiю: ";
	cin.ignore();
	getline(cin, contact_information);
	cout << endl;

	
}

//bool Veteran::LoginVeteran(const vector<Veteran*>& veterans)
//{
//	string name,password;
//
//	cout << "¬ведiть iм'€: ";
//	getline(std::cin, name);
//	cout << "¬ведiть пароль: ";
//	getline(std::cin, password);
//
//	for (const auto& veteran : veterans) {
//		if (veteran.GetName() == name) {
//			std::cout << "¬хiд успiшний!\n";
//			return true;
//		}
//	}
//
//	std::cout << "ќблiкового запису не знайдено.\n";
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
