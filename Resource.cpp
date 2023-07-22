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
	cout << "�����: ";
	cin.ignore();
	cin.getline(name, LEN);
	cout << "�������i�: "; 
	cin.getline(category, LEN);
	cout << "�����i�: ";
	cin.getline(location, LEN);
	cout << "���������� i�������i�: "; 
	cin.getline(contact_info, LEN);
	cout << "����i� ������: "; 
	cin.getline(work_schedule, LEN);
	cout << "�������: "; 
	cin.getline(services, LEN);
	cout << "��� �i�������: ";
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
	cout << "�i����: ";
	cin.ignore();
	getline(cin,review);
	reviews.push_back(review);
}

ostream& operator<<(ostream& o, const Resource& r)
{
	o << "�����: " << r.name << endl;
	o << "�������i�: " << r.category << endl;
	o << "�����i�: " << r.location << endl;
	o << "���������� i�������i�: " << r.contact_info << endl;
	o << "����i� ������: " << r.work_schedule << endl;
	o << "�������: " << r.services << endl;
	o << "�i�����: ";
	int i = 1;
	for (auto review : r.reviews) {
		cout<< endl<<i<<") " << review;
		i++;
	}
	cout << endl;
	return o;
}
