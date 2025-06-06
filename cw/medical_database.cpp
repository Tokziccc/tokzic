#include "medical_database.h"

MedicalDatabase::MedicalDatabase() {
 
    addPatient(Patient(1, "������ ���� ��������", "1980-05-15",
        "��. ������, �.10", "79161234567"));
    addPatient(Patient(2, "������� ����� ���������", "1975-12-20",
        "��. ����, �.5", "79037654321"));
    addPatient(Patient(3, "������� ������� ����������", "1990-03-10",
        "��. �������, �.15", "79219876543"));
    addPatient(Patient(4, "������� ��������� ����������", "1985-07-22",
        "��. �����������, �.8", "79115556677"));
    addPatient(Patient(5, "�������� ����� ��������", "1978-11-30",
        "��. �������, �.25", "79038889900"));

    services.push_back(MedicalService(1, "������������ ���������", 1500.0, true, 1));
    services.push_back(MedicalService(2, "������ �����", 500.0, false, 2));
    services.push_back(MedicalService(3, "��� ������� �������", 2500.0, true, 3));
    services.push_back(MedicalService(4, "������� ������� ������", 1200.0, true, 1));
    services.push_back(MedicalService(5, "������", 800.0, false, 4));

    hospitalizations.push_back(Hospitalization(1, "2023-09-15", "�����������", "��������������� ����"));
    hospitalizations.push_back(Hospitalization(3, "2023-10-01", "��������", "����������"));

    doctors.push_back(std::make_unique<Doctor>(101, "������ ������� ��������", "1978-03-10",
        "79219876543", "���������", "�����������", 12));
    doctors.push_back(std::make_unique<Doctor>(102, "������ �������� ��������", "1985-07-22",
        "79115556677", "������", "��������", 4));
    doctors.push_back(std::make_unique<Doctor>(103, "������ ����� ��������", "1978-11-30",
        "79038889900", "��������", "�������", 8));
}

void MedicalDatabase::addPatient(const Patient& patient) {
    patients.push_back(patient);
}

vector<Patient> MedicalDatabase::getAllPatients() const {
    return patients;
}

const Patient* MedicalDatabase::findPatientById(int id) const {
    for (const auto& patient : patients) {
        if (patient.getId() == id) {
            return &patient;
        }
    }
    return nullptr;
}

vector<MedicalService> MedicalDatabase::getAllServices() const {
    return services;
}

void MedicalDatabase::addHospitalization(const Hospitalization& hospitalization) {
    hospitalizations.push_back(hospitalization);
}

vector<Hospitalization> MedicalDatabase::getAllHospitalizations() const {
    return hospitalizations;
}

void MedicalDatabase::addDoctor(std::unique_ptr<Doctor> doctor) {
    doctors.push_back(std::move(doctor));
}

const std::vector<std::unique_ptr<Doctor>>& MedicalDatabase::getAllDoctors() const {
    return doctors;
}
