#include "human.h"

Human::Human(int id, const std::string& name, const std::string& dob, const std::string& phone)
    : id(id), fullName(name), dateOfBirth(dob), phone(phone) {
}

int Human::getId() const { return id; }
std::string Human::getFullName() const { return fullName; }
std::string Human::getDateOfBirth() const { return dateOfBirth; }
std::string Human::getPhone() const { return phone; }
