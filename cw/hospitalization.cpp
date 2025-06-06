#include "hospitalization.h"

Hospitalization::Hospitalization(int patientId, const string& startDate,
    const string& department, const string& reason)
    : patientId(patientId), startDate(startDate), department(department), reason(reason) {
}
