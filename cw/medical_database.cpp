#include "medical_database.h"

MedicalDatabase::MedicalDatabase() {
 
    addPatient(Patient(1, "Иванов Иван Иванович", "1980-05-15",
        "ул. Ленина, д.10", "79161234567"));
    addPatient(Patient(2, "Петрова Мария Сергеевна", "1975-12-20",
        "пр. Мира, д.5", "79037654321"));
    addPatient(Patient(3, "Сидоров Алексей Викторович", "1990-03-10",
        "ул. Пушкина, д.15", "79219876543"));
    addPatient(Patient(4, "Козлова Екатерина Дмитриевна", "1985-07-22",
        "пр. Космонавтов, д.8", "79115556677"));
    addPatient(Patient(5, "Николаев Денис Олегович", "1978-11-30",
        "ул. Садовая, д.25", "79038889900"));

    services.push_back(MedicalService(1, "Консультация терапевта", 1500.0, true, 1));
    services.push_back(MedicalService(2, "Анализ крови", 500.0, false, 2));
    services.push_back(MedicalService(3, "УЗИ брюшной полости", 2500.0, true, 3));
    services.push_back(MedicalService(4, "Рентген грудной клетки", 1200.0, true, 1));
    services.push_back(MedicalService(5, "Массаж", 800.0, false, 4));

    hospitalizations.push_back(Hospitalization(1, "2023-09-15", "Кардиология", "Гипертонический криз"));
    hospitalizations.push_back(Hospitalization(3, "2023-10-01", "Хирургия", "Аппендицит"));

    doctors.push_back(std::make_unique<Doctor>(101, "Иванов Алексей Иванович", "1978-03-10",
        "79219876543", "Кардиолог", "Кардиология", 12));
    doctors.push_back(std::make_unique<Doctor>(102, "Иванов Григорий Иванович", "1985-07-22",
        "79115556677", "Хирург", "Хирургия", 4));
    doctors.push_back(std::make_unique<Doctor>(103, "Иванов Игорь Иванович", "1978-11-30",
        "79038889900", "Терапевт", "Терапия", 8));
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
