#include <iostream>
#include <fstream>
#include "File.h"
#include "Veteran.h"
#include "Administrator.h"
using namespace std;

bool LoginVeteran(const vector<Veteran*> veterans)
{
    string name, password;
    
    cout << "����i�� ������: ";
    cin.ignore();
    getline(cin, password);
    cout << "����i�� i�'�: ";
    cin.ignore();
    getline(cin, name);

    for (const auto& veteran : veterans) {
        if (veteran->GetName() == name && veteran->GetPassword() == password) {
            cout << "��i� ���i����!\n";
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
        cout << "������� ����:\n";
        cout << "1. ��������������\n";
        cout << "2. ��i��� �� �������\n";
        cout << "3. ��i��� �� ���i�i�������\n";
        cout << "4. �����\n";
        cout << "��� ���i�: ";
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
                cerr << "������� �i������� �����!" << endl;
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
                cout << "���i������ ������ �� ��������.\n\n";
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
            std::cout << "������� ����. ��������� �� ���.\n";
            break;
        }
    } while (choice != '4');

    for (const auto& veteran : veterans) {
        delete veteran;
    }
    veterans.clear();
	return 0;
}