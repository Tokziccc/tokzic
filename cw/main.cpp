#include "medical_system_ui.h"
#include <clocale>

int main() {
    setlocale(LC_ALL, "Russian");

    MedicalSystemUI system;
    system.run();

    return 0;
}