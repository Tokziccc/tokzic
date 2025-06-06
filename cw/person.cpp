#include "person.h"
#include <iostream>

Person::Person(int id, const std::string& name, const std::string& dob,
    const std::string& addr, const std::string& phone)
    : Human(id, name, dob, phone), address(addr) {
}

void Person::printInfo() const {
    std::cout << "=== ���������� � �������� ===\n"
        << "ID: " << id << "\n"
        << "���: " << fullName << "\n"
        << "���� ��������: " << dateOfBirth << "\n"
        << "�����: " << address << "\n"
        << "�������: " << phone << "\n";
}

std::string Person::getAddress() const { return address; }