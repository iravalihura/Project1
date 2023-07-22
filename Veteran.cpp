#include "Veteran.h"

void Veteran::SetVeteran()
{
	cout << "Введiть пароль: ";
	cin.ignore();
	cin.getline(password, LEN);
	cout << "Введiть iм'я: ";
	cin.getline(name, LEN);
	cout << "Введiть вiк: ";
	while (!(cin >> age))
	{
		cout << "Некоректне значення вiку. Введiть ще раз: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Введiть iнформацiю про вiйськову службу: ";
	cin.getline(military_service, LEN);
	cout << "Введiть контактну iнформацiю: ";
	cin.getline(contact_information, LEN);
	cout << endl;
}

void Veteran::RegistVeteran()
{
	ofstream file;
	file.open("RegistrInform.txt", ios::out | ios::binary | ios::app);
	if (!file)
	{
		cerr << "Помилка відкриття файлу!" << endl;
		exit(1);
	}
	SetVeteran();
	file.write((char*)&(*this), sizeof(Veteran));
	file.close();
}

bool Veteran::LoginVeteran()
{
	Veteran veteran;
	char name[LEN], password[LEN];

	cout << "Введiть пароль: ";
	cin.ignore();
	cin.getline(password, LEN);
	cout << "Введiть iм'я: ";
	cin.getline(name, LEN);

	fstream file;
	file.open("RegistrInform.txt", ios::in | ios::binary);
	if (!file)
	{
		cerr << "Помилка вiдкриття файлу!" << endl;
		exit(1);
	}
	bool found = false;
	while (file.read((char*)&(*this), sizeof(Veteran)))
	{
		if (strcmp(this->name, name)==0 && strcmp(this->password , password)==0)
		{
			found = true;
			break;
		}
	}

	file.close();
	return found;
}

void Veteran::EditInformation()
{
	cout << "Введiть iм'я: ";
	cin.ignore();
	cin.getline(name, LEN);

	cout << "Введiть вiк: ";
	while (!(cin >> age))
	{
		cout << "Некоректне значення вiку. Введiть ще раз: ";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Введiть iнформацiю про вiйськову службу: ";
	cin.getline(military_service, LEN);

	cout << "Введiть контактну iнформацiю: ";
	cin.getline(contact_information, LEN);

	cout << endl;

	Veteran v;
	fstream file;
	file.open("RegistrInform.txt", ios::in | ios::out | ios::binary);
	if (!file)
	{
		cerr << "Помилка відкриття файлу!" << endl;
		exit(1);
	}
	bool found = false;
	while (file.read((char*)&v, sizeof(Veteran)))
	{
		if (strcmp(password, v.password) == 0)
		{
			file.seekp(-static_cast<int>(sizeof(Veteran)), ios::cur);
			file.write((char*)&(*this), sizeof(Veteran));
			if (file.fail())
			{
				cerr << "Помилка запису до файлу!" << endl;
				exit(1);
			}
			found = true;
			break;
		}
	}
	if (found)
	{
		cout << "Iнформацiю облiкового запису успiшно оновлено!" << endl;
	}
	else
	{
		cout << "Облiковий запис не знайдено." << endl;
	}
	file.close();
}

void Veteran::Account(vector<Resource*>&v)
{
	int choice;
	do {
		system("cls");
		cout << "Облiковий запис користувача: " << name << endl;
		cout << "1. Переглянути iнформацiю профiлю" << endl;
		cout << "2. Оновити iнформацiю" << endl;
		cout << "3. Знайти ресурс" << endl;
		cout << "4. Залишити вiдгук про ресурс" << endl;
		cout << "5. Назад" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			system("cls");
			Veteran veteran;
			fstream file;
			file.open("RegistrInform.txt", ios::in | ios::binary);
			if (!file)
			{
				cerr << "Помилка відкриття файлу!" << endl;
				exit(1);
			}
			while (file.read((char*)&(veteran), sizeof(Veteran)))
			{
				if (strcmp(password, veteran.password) == 0) {
					this->Show();
					break;
				}
			}
			file.close();
			system("pause");
			break;
		}
		case 2:
			system("cls");
			EditInformation();
			system("pause");
			break;
		case 3:
			system("cls");
			FindResource(v);
			system("pause");
			break;
		case 4:
			system("cls");
			LeaveReview(v);
			system("pause");
			break;
		case 5:
			return;
		default:
			cout << "Невірний вибір. Спробуйте ще раз.\n";
			break;
		}
	} while (true);
}

void Veteran::Show()
{
	cout << "Iм'я: " << name << endl;
	cout << "Вiк: " << age << endl;
	cout << "Iнформацiя про вiйськову службу: " << military_service << endl;
	cout << "Контактна iнформацiя: " << contact_information << endl;
	cout << "Тип пiдтримки: " << support_type << endl;
}

void Veteran::FindResource(vector<Resource*>& resources)
{
	char category[LEN], location[LEN], type_support[LEN];
	cout << "Категорiя: ";
	cin.ignore();
	cin.getline(category, LEN);
	cout << "Локацiя: ";
	cin.getline(location, LEN);
	cout << "Вид пiдтримки: ";
	cin.getline(type_support, LEN);
	bool flag = false;
	cout << endl << "Ресурси: " << endl;
	for (const auto& resource : resources)
	{
		if (strcmp(resource->GetCategory(), category) == 0 &&
			strcmp(resource->GetLocation(), location) == 0 &&
			strcmp(resource->GetTypeSupport(), type_support) == 0)
		{
			cout << *resource << endl;
			flag = true;
		}
	}
	if (!flag)
		cout << "Ресурсiв не знайдено!"<<endl;

	/*if (flag)
	{
		cout << "Залишити вiдгук про ресурс?(1-так, 0-ні)" << endl;
		int choice;
		cin >> choice;
		if (choice == 1)
		{

			cout<<
		}
		else return;
	}*/
}

void Veteran::LeaveReview(vector<Resource*>& resources)
{
	char name[LEN];
	cout << "Введiть назву ресурсу: ";
	cin.ignore();
	cin.getline(name, LEN);

	bool flag = false;
	for (const auto& resource : resources)
	{
		if (strcmp(resource->GetName(),name)==0)
		{
			resource->SetReview();
			flag = true;
		}
	}
	if (!flag)
		cout << "Ресурсiв не знайдено!" << endl;
}

char* Veteran::GetName()
{
	return name;
}

void Veteran::SetSuppType()
{
	cout << "Введiть тип пiдтримки: "; cin.getline(support_type, LEN);
}