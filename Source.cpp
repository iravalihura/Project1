#include <iostream>
#include <fstream>
#include "File.h"
#include "Veteran.h"
#include "Administrator.h"
using namespace std;

bool LoginVeteran(const vector<Veteran*> veterans)
{
    string name, password;
    
    cout << "Введiть пароль: ";
    cin.ignore();
    getline(cin, password);
    cout << "Введiть iм'я: ";
    cin.ignore();
    getline(cin, name);

    for (const auto& veteran : veterans) {
        if (veteran->GetName() == name && veteran->GetPassword() == password) {
            cout << "Вхiд успiшний!\n";
            return true;
        }
    }
    return false;
}
int main() {
    setlocale(LC_ALL,"UKR");
    File file;
    vector< Veteran*> veterans;
	int choice;
    do {
        system("cls");
        cout << "Головне меню:\n";
        cout << "1. Зареєструватись\n";
        cout << "2. Увiйти як ветеран\n";
        cout << "3. Увiйти як адмiнiстратор\n";
        cout << "4. Вийти\n";
        cout << "Ваш вибiр: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            system("cls");
            Veteran* newVeteran = new Veteran();
            newVeteran->RegisterVeteran();
            veterans.push_back(newVeteran);
            ofstream fout;
            fout.open("RegistrInfor.dat", ios::out | ios::binary);
            if (!fout)
            {
                cerr << "Помилка вiдкриття файлу!" << endl;
                exit(1);
            }
            fout.write((char*)&newVeteran, sizeof(Veteran));
            system("pause");
        }
            break;
        case 2:
            system("cls");
            if (LoginVeteran(veterans))
                ;
            else
                cout << "Облiкового запису не знайдено.\n\n";
            system("pause");
            break;
        case 3:
            system("cls");
            system("pause");
            break;
        case 4:
            return 0;
            break;
        default:
            std::cout << "Невірний вибір. Спробуйте ще раз.\n";
            break;
        }
    } while (choice != '4');

    for (const auto& veteran : veterans) {
        delete veteran;
    }
    veterans.clear();
	return 0;
}