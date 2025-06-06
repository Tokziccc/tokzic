#ifndef PATIENT_H
#define PATIENT_H

#include "person.h"

class Patient : public Person {
public:
    Patient(int id, const std::string& name, const std::string& dob,
        const std::string& addr, const std::string& phone);
};

#endif
