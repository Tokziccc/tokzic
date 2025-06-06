#include "patient.h"

Patient::Patient(int id, const std::string& name, const std::string& dob,
    const std::string& addr, const std::string& phone)
    : Person(id, name, dob, addr, phone) {
}