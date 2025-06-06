#include "doctor.h"
#include <iostream>

Doctor::Doctor(int id, const std::string& name, const std::string& dob,
    const std::string& phone, const std::string& spec,
    const std::string& dept, int exp)
    : Human(id, name, dob, phone), specialization(spec), department(dept), experienceYears(exp) {
}

void Doctor::printInfo() const {
    std::cout << "=== ���������� � ����� ===\n"
        << "ID: " << id << "\n"
        << "���: " << fullName << "\n"
        << "���� ��������: " << dateOfBirth << "\n"
        << "�������: " << phone << "\n"
        << "�������������: " << specialization << "\n"
        << "���������: " << department << "\n"
        << "����: " << experienceYears << " ���\n";
}

std::string Doctor::getSpecialization() const { return specialization; }
std::string Doctor::getDepartment() const { return department; }
int Doctor::getExperienceYears() const { return experienceYears; }
