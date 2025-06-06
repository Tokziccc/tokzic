#ifndef PERSON_H
#define PERSON_H

#include "human.h"
#include <string>

class Person : public Human {
protected:
    std::string address;

public:
    Person(int id, const std::string& name, const std::string& dob,
        const std::string& addr, const std::string& phone);

    void printInfo() const override;

    std::string getAddress() const;
};

#endif