#include "medical_service.h"

MedicalService::MedicalService(int id, const std::string& name,
    double cost, bool paid, int patientId)
    : id(id), name(name), cost(cost), paid(paid), patientId(patientId) {
}
