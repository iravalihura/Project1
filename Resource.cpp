#include "Resource.h"

//Resource::~Resource()
//{
//	for (auto resource : resources) {
//		delete resource;
//	}
//	resources.clear();
//}

void Resource::SetResource()
{
	cout << "Назва: ";
	cin.ignore();
	cin.getline(name, LEN);
	cout << "Категорiя: "; 
	cin.getline(category, LEN);
	cout << "Локацiя: ";
	cin.getline(location, LEN);
	cout << "Конктактна iнформацiя: "; 
	cin.getline(contact_info, LEN);
	cout << "Графiк роботи: "; 
	cin.getline(work_schedule, LEN);
	cout << "Послуги: "; 
	cin.getline(services, LEN);
	cout << "Тип пiдтримки: ";
	cin.getline(type_support, LEN);
}

char* Resource::GetName()
{
	return name;
}

char* Resource::GetCategory()
{
	return category;
}

char* Resource::GetLocation()
{
	return location;
}

char* Resource::GetTypeSupport()
{
	return type_support;
}

void Resource::SetReview()
{
	string review;
	cout << "Вiдгук: ";
	cin.ignore();
	getline(cin,review);
	reviews.push_back(review);
}

ostream& operator<<(ostream& o, const Resource& r)
{
	o << "Назва: " << r.name << endl;
	o << "Категорiя: " << r.category << endl;
	o << "Локацiя: " << r.location << endl;
	o << "Конктактна iнформацiя: " << r.contact_info << endl;
	o << "Графiк роботи: " << r.work_schedule << endl;
	o << "Послуги: " << r.services << endl;
	o << "Вiдгуки: ";
	int i = 1;
	for (auto review : r.reviews) {
		cout<< endl<<i<<") " << review;
		i++;
	}
	cout << endl;
	return o;
}
