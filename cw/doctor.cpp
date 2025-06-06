#include "doctor.h"
#include <iostream>

Doctor::Doctor(int id, const std::string& name, const std::string& dob,
    const std::string& phone, const std::string& spec,
    const std::string& dept, int exp)
    : Human(id, name, dob, phone), specialization(spec), department(dept), experienceYears(exp) {
}

void Doctor::printInfo() const {
    std::cout << "=== Информация о враче ===\n"
        << "ID: " << id << "\n"
        << "ФИО: " << fullName << "\n"
        << "Дата рождения: " << dateOfBirth << "\n"
        << "Телефон: " << phone << "\n"
        << "Специализация: " << specialization << "\n"
        << "Отделение: " << department << "\n"
        << "Стаж: " << experienceYears << " лет\n";
}

std::string Doctor::getSpecialization() const { return specialization; }
std::string Doctor::getDepartment() const { return department; }
int Doctor::getExperienceYears() const { return experienceYears; }
