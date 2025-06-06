#include "person.h"
#include <iostream>

Person::Person(int id, const std::string& name, const std::string& dob,
    const std::string& addr, const std::string& phone)
    : Human(id, name, dob, phone), address(addr) {
}

void Person::printInfo() const {
    std::cout << "=== Информация о пациенте ===\n"
        << "ID: " << id << "\n"
        << "ФИО: " << fullName << "\n"
        << "Дата рождения: " << dateOfBirth << "\n"
        << "Адрес: " << address << "\n"
        << "Телефон: " << phone << "\n";
}

std::string Person::getAddress() const { return address; }