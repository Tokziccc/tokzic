#ifndef HOSPITALIZATION_H
#define HOSPITALIZATION_H

#include <string>
using namespace std;

class Hospitalization {
public:
    int patientId;
    string startDate;
    string department;
    string reason;

    Hospitalization(int patientId, const string& startDate,
        const string& department, const string& reason);
};

#endif