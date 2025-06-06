#ifndef HUMAN_H
#define HUMAN_H

#include <string>
#include <iostream>

class Human {
protected:
    int id;
    std::string fullName;
    std::string dateOfBirth;
    std::string phone;

public:
    Human(int id, const std::string& name, const std::string& dob, const std::string& phone);
    virtual ~Human() = default;

    virtual void printInfo() const = 0; 

    int getId() const;
    std::string getFullName() const;
    std::string getDateOfBirth() const;
    std::string getPhone() const;
};

#endif