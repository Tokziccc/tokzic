#ifndef MEDICAL_SERVICE_H
#define MEDICAL_SERVICE_H

#include <string>

class MedicalService {
public:
    int id;
    std::string name;
    double cost;
    bool paid;
    int patientId;

    MedicalService(int id, const std::string& name, double cost, bool paid, int patientId);
};

#endif