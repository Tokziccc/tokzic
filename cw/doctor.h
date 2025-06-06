#ifndef DOCTOR_H
#define DOCTOR_H

#include "human.h"
#include <string>

class Doctor : public Human {
private:
    std::string specialization;
    std::string department;
    int experienceYears;

public:
    Doctor(int id, const std::string& name, const std::string& dob,
        const std::string& phone, const std::string& spec,
        const std::string& dept, int exp);

    void printInfo() const override;

    std::string getSpecialization() const;
    std::string getDepartment() const;
    int getExperienceYears() const;
};

#endif