#include "Administrator.h"

void Administrator::LoginAdmin(vector<Resource*>& resources)
{
	char password[LEN];
	cout << "Пароль: ";
	cin.ignore();
	cin.getline(password, LEN);
	if (strcmp(this->password,password)!=0)
		cout << "Не вiрний пароль!" << endl;
	else
		Account(resources);
}

void Administrator::Account(vector<Resource*>& resources)
{
	int choice;
	do {
		system("cls");
		cout << "1. Додати нового ветерана" << endl;
		cout << "2. Оновити iнформацiю про ветерана" << endl;
		cout << "3. Позначити ветерана, який отримує певний тип пiдтримки" << endl;
		cout << "4. Переглянути всi записи" << endl;
		cout << "5. Додати ресурс" << endl;
		cout << "6. Оновити iнформацiю про ресурс" << endl;
		cout << "7. Переглянути всi ресурси" << endl;
		cout << "8. Назад" << endl;
		cout << "Ваш вибiр: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			system("cls");
			AddVeteran();
			system("pause");
			break;
		}
		case 2:
			system("cls");
			UpdateVeteran();
			system("pause");
			break;
		case 3:
			system("cls");
			MarkVeteransWithSupport();
			system("pause");
			break;
		case 4:
			system("cls");
			ShowVeterans();
			system("pause");
			break;
		case 5:
			system("cls");
			AddResources(resources);
			system("pause");

			break;
		case 6:
			system("cls");
			UpdateResource(resources);
			system("pause");
			break;
		case 7:
			system("cls");
			ShowResources(resources);
			system("pause");
			break;
		case 8:
			return;
		default:
			cout << "Невірний вибір. Спробуйте ще раз.\n";
			break;
		}
	} while (true);
}

void Administrator::AddVeteran()
{
	Veteran veteran;
	veteran.SetVeteran();

	ofstream file("RegistrInform.txt", ios::out | ios::binary | ios::app);
	if (!file)
	{
		cerr << "Failed to open the file." << endl;
		exit(1);
	}

	file.write((char*)&veteran, sizeof(Veteran));
	file.close();

	cout << "Ветеран успiшно доданий!" << endl;
}

void Administrator::UpdateVeteran()
{
	char name[LEN];
	cout << "Введiть iм'я шуканого ветерана: ";
	
	cin.ignore();
	cin.getline(name, LEN);

	Veteran veteran;
	bool found = false;

	fstream file("RegistrInform.txt", ios::in | ios::out | ios::binary);
	if (!file)
	{
		cerr << "Failed to open the file." << endl;
		exit(1);
	}

	while (file.read((char*)&veteran, sizeof(Veteran)))
	{
		if (strcmp(veteran.GetName() , name)==0)
		{
			found = true;
			veteran.EditInformation(); 
			file.seekp(-static_cast<int>(sizeof(Veteran)), ios::cur);
			file.write((char*)&veteran, sizeof(Veteran));
			break;
		}
	}

	file.close();

	if (found)
	{
		cout << "Iнформацiю облiкового запису успiшно оновлено!" << endl;
	}
	else
	{
		cout << "Облiковий запис не знайдено." << endl;
	}
}

void Administrator::MarkVeteransWithSupport()
{
	char name[LEN];
	cout << "Введiть iм'я: ";
	
	cin.ignore();
	cin.getline(name, LEN);

	fstream file("RegistrInform.txt", ios::in | ios::out | ios::binary);
	if (!file)
	{
		cerr << "Failed to open the file." << endl;
		exit(1);
	}

	Veteran veteran;

	bool found = false;
	while (file.read((char*)&(veteran), sizeof(Veteran)))
	{
		if (strcmp(name , veteran.GetName())==0)
		{
			veteran.SetSuppType();
			file.seekp(-static_cast<int>(sizeof(Veteran)), ios::cur);
			file.write((char*)&(veteran), sizeof(Veteran));
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

void Administrator::ShowVeterans()
{
	Veteran v;
	fstream file;
	file.open("RegistrInform.txt", ios::in | ios::binary);
	if (!file)
	{
		cerr << "Помилка відкриття файлу!" << endl;
		exit(1);
	}
	while (file.read((char*)&(v), sizeof(Veteran)))
	{
		v.Show();
	}
	file.close();
}

void Administrator::AddResources(vector<Resource*>& resources)
{
	Resource* resourse = new Resource;
	resourse->SetResource();
	resources.push_back(resourse);
}

void Administrator::ShowResources(vector<Resource*>& resources)
{
	if (resources.empty()) {
		cout << "Немає доступних ресурсiв." << endl;
		return;
	}
	for (auto& resource : resources)
	{
		cout << *resource;
	}
}

void Administrator::UpdateResource(vector<Resource*>& resources)
{
	char name[LEN];
	cout << "Назва шуканого ресурсу: ";
	cin.ignore();
	cin.getline(name,LEN);

	if (resources.empty()) {
		cout << "Немає доступних ресурсiв." << endl;
		return;
	}

	for (auto& resource : resources)
	{
		if (strcmp(resource->GetName(), name) == 0)
			resource->SetResource();
	}
}
