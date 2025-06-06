#ifndef MEDICAL_DATABASE_H
#define MEDICAL_DATABASE_H

#include "patient.h"
#include "medical_service.h"
#include "hospitalization.h"
#include "doctor.h"
#include <vector>
#include <memory>

class MedicalDatabase {
private:
    std::vector<Patient> patients;
    std::vector<MedicalService> services;
    std::vector<Hospitalization> hospitalizations;
    std::vector<std::unique_ptr<Doctor>> doctors;

public:
    MedicalDatabase();

    void addPatient(const Patient& patient);
    std::vector<Patient> getAllPatients() const;
    const Patient* findPatientById(int id) const;

    std::vector<MedicalService> getAllServices() const;

    void addHospitalization(const Hospitalization& hospitalization);
    std::vector<Hospitalization> getAllHospitalizations() const;

    void addDoctor(std::unique_ptr<Doctor> doctor);
    const std::vector<std::unique_ptr<Doctor>>& getAllDoctors() const;
};

#endif
