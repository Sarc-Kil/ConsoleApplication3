#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Patient {
public:
    string name;
    string contact;

    Patient(const string& name, const string& contact) : name(name), contact(contact) {}
};

class Doctor {
public:
    string name;
    string specialty;

    Doctor(const string& name, const string& specialty) : name(name), specialty(specialty) {}
};

class Appointment {
public:
    Patient patient;
    Doctor doctor;
    string date;

    Appointment(const Patient& patient, const Doctor& doctor, const string& date)
        : patient(patient), doctor(doctor), date(date) {
    }
};

class MedicalRecord {
public:
    Patient patient;
    vector<string> notes;

    MedicalRecord(const Patient& patient) : patient(patient) {}

    void addNote(const string& note) {
        notes.push_back(note);
    }
};

class Prescription {
public:
    Patient patient;
    string medication;

    Prescription(const Patient& patient, const string& medication)
        : patient(patient), medication(medication) {
    }
};

class Billing {
public:
    Patient patient;
    double amount;

    Billing(const Patient& patient, double amount) : patient(patient), amount(amount) {}
};

class MedicalSystem {
public:
    vector<Patient> patients;
    vector<Doctor> doctors;
    vector<Appointment> appointments;
    vector<MedicalRecord> medicalRecords;
    vector<Prescription> prescriptions;
    vector<Billing> billings;

    void addPatient(const Patient& patient) {
        patients.push_back(patient);
    }

    void addDoctor(const Doctor& doctor) {
        doctors.push_back(doctor);
    }

    void makeAppointment(const Patient& patient, const Doctor& doctor, const string& date) {
        appointments.push_back(Appointment(patient, doctor, date));
    }

    void addMedicalRecord(const MedicalRecord& record) {
        medicalRecords.push_back(record);
    }

    void addPrescription(const Prescription& prescription) {
        prescriptions.push_back(prescription);
    }

    void addBilling(const Billing& billing) {
        billings.push_back(billing);
    }

    void searchDoctors(const string& specialty) const {
        cout << "����� �� ������������� \"" << specialty << "\":" << endl;
        for (const auto& doctor : doctors) {
            if (doctor.specialty == specialty) {
                cout << doctor.name << endl;
            }
        }
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    MedicalSystem system;

    int patientCount;
    cout << "������� ���������� ���������: ";
    cin >> patientCount;
    cin.ignore();

    for (int i = 0; i < patientCount; ++i) {
        string name, contact;
        cout << "������� ��� ��������: ";
        getline(cin, name);
        cout << "������� ������� ��������: ";
        getline(cin, contact);
        system.addPatient(Patient(name, contact));
    }

    int doctorCount;
    cout << "������� ���������� ������: ";
    cin >> doctorCount;
    cin.ignore();

    for (int i = 0; i < doctorCount; ++i) {
        string name, specialty;
        cout << "������� ��� �����: ";
        getline(cin, name);
        cout << "������� ������������� �����: ";
        getline(cin, specialty);
        system.addDoctor(Doctor(name, specialty));
    }

    string specialtyToSearch;
    cout << "������� ������������� ��� ������ ������: ";
    getline(cin, specialtyToSearch);
    system.searchDoctors(specialtyToSearch);

    string patientName, doctorName, appointmentDate;
    cout << "������� ��� �������� ��� ������ �� �����: ";
    getline(cin, patientName);
    cout << "������� ��� ����� ��� ������ �� �����: ";
    getline(cin, doctorName);
    cout << "������� ���� ������: ";
    getline(cin, appointmentDate);

    auto patientIt = find_if(system.patients.begin(), system.patients.end(), [&](const Patient& p) {
        return p.name == patientName;
        });

    auto doctorIt = find_if(system.doctors.begin(), system.doctors.end(), [&](const Doctor& d) {
        return d.name == doctorName;
        });

    if (patientIt != system.patients.end() && doctorIt != system.doctors.end()) {
        system.makeAppointment(*patientIt, *doctorIt, appointmentDate);
        cout << "������ �� ����� ������� �������." << endl;
    }
    else {
        cout << "������� ��� ���� �� �������." << endl;
    }

    return 0;
}