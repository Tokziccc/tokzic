#ifndef MEDICAL_SYSTEM_UI_H
#define MEDICAL_SYSTEM_UI_H

#include "medical_database.h"
#include <string>
using namespace std;

class MedicalSystemUI {
private:
    MedicalDatabase database;

    void clearInput();
    int getIntInput(const string& prompt);
    string getStringInput(const string& prompt);
    string getDateInput(const string& prompt);

    void patientMenu();
    void doctorMenu();
    void serviceMenu();
    void hospitalizationMenu();
    

public:
    void run();
};

#endif
