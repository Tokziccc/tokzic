#include "medical_system_ui.h"
#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>

using namespace std;

void MedicalSystemUI::clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int MedicalSystemUI::getIntInput(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail()) {
            clearInput();
            cout << "������ �����! ����������, ������� �����.\n";
        }
        else {
            clearInput();
            return value;
        }
    }
}

string MedicalSystemUI::getStringInput(const string& prompt) {
    string input;
    cout << prompt;
    getline(cin, input);
    return input;
}

string MedicalSystemUI::getDateInput(const string& prompt) {
    string date;
    while (true) {
        cout << prompt;
        getline(cin, date);
        if (date.length() == 10 && date[4] == '-' && date[7] == '-') {
            return date;
        }
        cout << "�������� ������ ����! ����������� YYYY-MM-DD.\n";
    }
}

void MedicalSystemUI::run() {
    while (true) {
        system("cls");
        cout << "=======================================\n"
            << "  ������� ������������ ����������\n"
            << "=======================================\n"
            << "1. ���������� ����������\n"
            << "2. ������� ������\n"
            << "3. ��������������\n"
            << "4. ���������� �������\n"  
            << "0. �����\n"
            << "=======================================\n";

        int choice = getIntInput("�������� ��������: ");
        switch (choice) {
        case 1: patientMenu(); break;
        case 2: serviceMenu(); break;
        case 3: hospitalizationMenu(); break;
        case 4: doctorMenu(); break;    
        case 0: return;
        default: cout << "�������� �����! ���������� �����.\n";
        }
    }
}

void MedicalSystemUI::patientMenu() {
    while (true) {
        system("cls");
        cout << "==============================\n"
            << "  ���������� ����������\n"
            << "==============================\n"
            << "1. ����������� ���� ���������\n"
            << "2. ����� �������� �� ID\n"
            << "3. �������� ������ ��������\n"
            << "0. �����\n"
            << "==============================\n";

        int choice = getIntInput("�������� ��������: ");
        switch (choice) {
        case 1: {
            system("cls");
            vector<Patient> patients = database.getAllPatients();
            cout << "������ ���������:\n"
                << "==========================================================\n"
                << "ID  | ���                          | �������\n"
                << "----------------------------------------------------------\n";
            for (const auto& patient : patients) {
                cout << setw(3) << patient.getId() << " | "
                    << setw(28) << left << patient.getFullName() << " | "
                    << patient.getPhone() << endl;
            }
            cout << "==========================================================\n";
            system("pause");
            break;
        }
        case 2: {
            int id = getIntInput("������� ID ��������: ");
            const Patient* patient = database.findPatientById(id);
            if (patient) {
                system("cls");
                patient->printInfo();
            }
            else {
                cout << "������� �� ������.\n";
            }
            system("pause");
            break;
        }
        case 3: {
            system("cls");
            cout << "���������� ������ ��������:\n";
            string name = getStringInput("��� ��������: ");
            string dob = getDateInput("���� �������� (����-��-��): ");
            string addr = getStringInput("�����: ");
            string phone = getStringInput("�������: ");

            int newId = database.getAllPatients().size() + 1;
            database.addPatient(Patient(newId, name, dob, addr, phone));
            cout << "\n������� ������� ��������!\n";
            system("pause");
            break;
        }
        case 0: return;
        default: cout << "�������� �����! ���������� �����.\n";
        }
    }
}

void MedicalSystemUI::serviceMenu() {
    system("cls");
    vector<MedicalService> services = database.getAllServices();
    vector<Patient> patients = database.getAllPatients();

    cout << "������� ����������� ������:\n"
        << "=================================================================\n"
        << "ID  | ������                     | ��������� | ������ | �������\n"
        << "-----------------------------------------------------------------\n";

    for (const auto& service : services) {
        string patientName = "����������";
        for (const auto& patient : patients) {
            if (patient.getId() == service.patientId) {
                patientName = patient.getFullName();
                break;
            }
        }

        cout << setw(3) << service.id << " | "
            << setw(25) << left << service.name << " | "
            << setw(9) << fixed << setprecision(2) << service.cost << " | "
            << setw(6) << (service.paid ? "��" : "���") << " | "
            << patientName << endl;
    }
    cout << "=================================================================\n";
    system("pause");
}

void MedicalSystemUI::hospitalizationMenu() {
    while (true) {
        system("cls");
        cout << "==============================\n"
            << "  ���������� ���������������\n"
            << "==============================\n"
            << "1. ����������� ��������������\n"
            << "2. �������� ��������������\n"
            << "0. �����\n"
            << "==============================\n";

        int choice = getIntInput("�������� ��������: ");
        switch (choice) {
        case 1: {
            system("cls");
            vector<Hospitalization> hospitalizations = database.getAllHospitalizations();
            vector<Patient> patients = database.getAllPatients();

            cout << "��������������:\n"
                << "====================================================================\n"
                << "�������                     | ����       | ���������   | �������\n"
                << "--------------------------------------------------------------------\n";

            for (const auto& hosp : hospitalizations) {
                string patientName = "����������";
                for (const auto& patient : patients) {
                    if (patient.getId() == hosp.patientId) {
                        patientName = patient.getFullName();
                        break;
                    }
                }

                cout << setw(28) << left << patientName << " | "
                    << setw(10) << hosp.startDate << " | "
                    << setw(12) << hosp.department << " | "
                    << hosp.reason << endl;
            }
            cout << "====================================================================\n";
            system("pause");
            break;
        }
        case 2: {
            system("cls");
            cout << "���������� ��������������:\n";
            int patientId = getIntInput("ID ��������: ");
            string date = getDateInput("���� �������������� (����-��-��): ");
            string department = getStringInput("���������: ");
            string reason = getStringInput("�������: ");

            database.addHospitalization(Hospitalization(patientId, date, department, reason));
            cout << "\n�������������� ���������!\n";
            system("pause");
            break;
        }
        case 0: return;
        default: cout << "�������� �����! ���������� �����.\n";
        }
    }
}
void MedicalSystemUI::doctorMenu() {
    while (true) {
        system("cls");
        cout << "==============================\n"
            << "  ���������� �������\n"
            << "==============================\n"
            << "1. ����������� ���� ������\n"
            << "2. �������� ������ �����\n"
            << "0. �����\n"
            << "==============================\n";

        int choice = getIntInput("�������� ��������: ");

        switch (choice) {
        case 1: {
            system("cls");
            const auto& doctors = database.getAllDoctors();
            cout << "������ ������:\n"
                << "==========================================================\n";
            for (const auto& doctor : doctors) {
                doctor->printInfo(); // ����������� �����
                cout << "----------------------------------------------------------\n";
            }
            system("pause");
            break;
        }
        case 2: {
            system("cls");
            cout << "���������� ������ �����:\n";
            string name = getStringInput("��� �����: ");
            string dob = getDateInput("���� �������� (����-��-��): ");
            string phone = getStringInput("�������: ");
            string spec = getStringInput("�������������: ");
            string dept = getStringInput("���������: ");
            int exp = getIntInput("���� (���): ");

            int newId = database.getAllDoctors().size() + 101;
            database.addDoctor(std::make_unique<Doctor>(
                newId, name, dob, phone, spec, dept, exp));
            cout << "\n���� ������� ��������!\n";
            system("pause");
            break;
        }
        case 0: return;
        default: cout << "�������� �����! ���������� �����.\n";
        }
    }
}