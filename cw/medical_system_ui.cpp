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
            cout << "Ошибка ввода! Пожалуйста, введите число.\n";
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
        cout << "Неверный формат даты! Используйте YYYY-MM-DD.\n";
    }
}

void MedicalSystemUI::run() {
    while (true) {
        system("cls");
        cout << "=======================================\n"
            << "  Система медицинского учреждения\n"
            << "=======================================\n"
            << "1. Управление пациентами\n"
            << "2. Платные услуги\n"
            << "3. Госпитализация\n"
            << "4. Управление врачами\n"  
            << "0. Выход\n"
            << "=======================================\n";

        int choice = getIntInput("Выберите действие: ");
        switch (choice) {
        case 1: patientMenu(); break;
        case 2: serviceMenu(); break;
        case 3: hospitalizationMenu(); break;
        case 4: doctorMenu(); break;    
        case 0: return;
        default: cout << "Неверный выбор! Попробуйте снова.\n";
        }
    }
}

void MedicalSystemUI::patientMenu() {
    while (true) {
        system("cls");
        cout << "==============================\n"
            << "  Управление пациентами\n"
            << "==============================\n"
            << "1. Просмотреть всех пациентов\n"
            << "2. Найти пациента по ID\n"
            << "3. Добавить нового пациента\n"
            << "0. Назад\n"
            << "==============================\n";

        int choice = getIntInput("Выберите действие: ");
        switch (choice) {
        case 1: {
            system("cls");
            vector<Patient> patients = database.getAllPatients();
            cout << "Список пациентов:\n"
                << "==========================================================\n"
                << "ID  | ФИО                          | Телефон\n"
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
            int id = getIntInput("Введите ID пациента: ");
            const Patient* patient = database.findPatientById(id);
            if (patient) {
                system("cls");
                patient->printInfo();
            }
            else {
                cout << "Пациент не найден.\n";
            }
            system("pause");
            break;
        }
        case 3: {
            system("cls");
            cout << "Добавление нового пациента:\n";
            string name = getStringInput("ФИО пациента: ");
            string dob = getDateInput("Дата рождения (ГГГГ-ММ-ДД): ");
            string addr = getStringInput("Адрес: ");
            string phone = getStringInput("Телефон: ");

            int newId = database.getAllPatients().size() + 1;
            database.addPatient(Patient(newId, name, dob, addr, phone));
            cout << "\nПациент успешно добавлен!\n";
            system("pause");
            break;
        }
        case 0: return;
        default: cout << "Неверный выбор! Попробуйте снова.\n";
        }
    }
}

void MedicalSystemUI::serviceMenu() {
    system("cls");
    vector<MedicalService> services = database.getAllServices();
    vector<Patient> patients = database.getAllPatients();

    cout << "Платные медицинские услуги:\n"
        << "=================================================================\n"
        << "ID  | Услуга                     | Стоимость | Оплата | Пациент\n"
        << "-----------------------------------------------------------------\n";

    for (const auto& service : services) {
        string patientName = "Неизвестно";
        for (const auto& patient : patients) {
            if (patient.getId() == service.patientId) {
                patientName = patient.getFullName();
                break;
            }
        }

        cout << setw(3) << service.id << " | "
            << setw(25) << left << service.name << " | "
            << setw(9) << fixed << setprecision(2) << service.cost << " | "
            << setw(6) << (service.paid ? "Да" : "Нет") << " | "
            << patientName << endl;
    }
    cout << "=================================================================\n";
    system("pause");
}

void MedicalSystemUI::hospitalizationMenu() {
    while (true) {
        system("cls");
        cout << "==============================\n"
            << "  Управление госпитализацией\n"
            << "==============================\n"
            << "1. Просмотреть госпитализации\n"
            << "2. Добавить госпитализацию\n"
            << "0. Назад\n"
            << "==============================\n";

        int choice = getIntInput("Выберите действие: ");
        switch (choice) {
        case 1: {
            system("cls");
            vector<Hospitalization> hospitalizations = database.getAllHospitalizations();
            vector<Patient> patients = database.getAllPatients();

            cout << "Госпитализации:\n"
                << "====================================================================\n"
                << "Пациент                     | Дата       | Отделение   | Причина\n"
                << "--------------------------------------------------------------------\n";

            for (const auto& hosp : hospitalizations) {
                string patientName = "Неизвестно";
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
            cout << "Добавление госпитализации:\n";
            int patientId = getIntInput("ID пациента: ");
            string date = getDateInput("Дата госпитализации (ГГГГ-ММ-ДД): ");
            string department = getStringInput("Отделение: ");
            string reason = getStringInput("Причина: ");

            database.addHospitalization(Hospitalization(patientId, date, department, reason));
            cout << "\nГоспитализация добавлена!\n";
            system("pause");
            break;
        }
        case 0: return;
        default: cout << "Неверный выбор! Попробуйте снова.\n";
        }
    }
}
void MedicalSystemUI::doctorMenu() {
    while (true) {
        system("cls");
        cout << "==============================\n"
            << "  Управление врачами\n"
            << "==============================\n"
            << "1. Просмотреть всех врачей\n"
            << "2. Добавить нового врача\n"
            << "0. Назад\n"
            << "==============================\n";

        int choice = getIntInput("Выберите действие: ");

        switch (choice) {
        case 1: {
            system("cls");
            const auto& doctors = database.getAllDoctors();
            cout << "Список врачей:\n"
                << "==========================================================\n";
            for (const auto& doctor : doctors) {
                doctor->printInfo(); // Полиморфный вызов
                cout << "----------------------------------------------------------\n";
            }
            system("pause");
            break;
        }
        case 2: {
            system("cls");
            cout << "Добавление нового врача:\n";
            string name = getStringInput("ФИО врача: ");
            string dob = getDateInput("Дата рождения (ГГГГ-ММ-ДД): ");
            string phone = getStringInput("Телефон: ");
            string spec = getStringInput("Специализация: ");
            string dept = getStringInput("Отделение: ");
            int exp = getIntInput("Стаж (лет): ");

            int newId = database.getAllDoctors().size() + 101;
            database.addDoctor(std::make_unique<Doctor>(
                newId, name, dob, phone, spec, dept, exp));
            cout << "\nВрач успешно добавлен!\n";
            system("pause");
            break;
        }
        case 0: return;
        default: cout << "Неверный выбор! Попробуйте снова.\n";
        }
    }
}