#include <iostream>
#include <fstream>
#include "Veteran.h"
#include "Administrator.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "UKR");
    system("color F0");
    Veteran veteran;
    Administrator admin;
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
            veteran.RegistVeteran();
            system("pause");
        }
              break;
        case 2:
            system("cls");
            if (veteran.LoginVeteran())
                veteran.Account();
            else
                cout << "Облiкового запису не знайдено.\n\n";
            system("pause");
            break;
        case 3:
            system("cls");
            admin.LoginAdmin();
            system("pause");
            break;
        case 4:
            return 0;
            break;
        default:
            cout << "Невірний вибір. Спробуйте ще раз.\n";
            break;
        }
    } while (true);

    return 0;
}