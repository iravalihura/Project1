#include "Administrator.h"

void Administrator::LoginAdmin()
{
	char password[LEN];
	cout << "Пароль: ";
	cin.ignore();
	cin.getline(password, LEN);
	if (strcmp(this->password,password)!=0)
		cout << "Не вiрний пароль!" << endl;
	else
		Account();
}

void Administrator::Account()
{
	int choice;
	do {
		system("cls");
		cout << "1. Додати нового ветерана" << endl;
		cout << "2. Оновити iнформацiю про ветерана" << endl;
		cout << "3. Позначити ветерана, який отримує певний тип пiдтримки" << endl;
		cout << "4. Назад" << endl;
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