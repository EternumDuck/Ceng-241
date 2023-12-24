#include "Department.h"
#include <fstream>
#include <vector>

Department::Department(string name, int rooms)
:name(name),rooms(rooms) {
    loadPeople();
    loadAppointments();
}

void Department::loadPeople() {
    // DOCTORS FIRST
    fstream doctorFile;
    doctorFile.open("Doctors.txt",ios::in);

    string docName;
    int ID,password;
    string docDepartment;
    int rooms;

    if (doctorFile.is_open()) {
        while(doctorFile >> docName >> ID >> password >> docDepartment){
            if(docDepartment == this->name){
                doctors.push_back(Doctor(docName,ID,password,docDepartment));
            }
        }
    }

    // LOADING NURSES

    fstream nurseFile;
    nurseFile.open("Nurses.txt",ios::in);

    if (nurseFile.is_open()) {
        while(nurseFile >> docName >> ID >> password){
                nurses.push_back(Nurse(docName,ID,password));
        }
    }

    // LOADING PATIENTS

    fstream patientFile;
    patientFile.open("Patients.txt",ios::in);
    string patientName;
    int patientID,age;
    double weight,height;
    string bloodType;
    double bloodSugar,treatmentCost;
    string patientDepartment;

    if (patientFile.is_open()) {
        while(patientFile >> patientName >> patientID >> age >> weight >> height >> bloodType >> bloodSugar >> treatmentCost >> patientDepartment){
            if(patientDepartment == this->name){
                patients.push_back(Patient(patientName,patientID,age,weight,height,bloodType,bloodSugar,treatmentCost,patientDepartment));
            }
        }
    }
    cout << "debug : Loaded departments" << endl;
}

void Department::loadAppointments() {

    fstream appointmentFile;
    appointmentFile.open("Appointments.txt",ios::in);
    int day,time,ID;
    string complaint;
    string appointmentDepartment;

    if (appointmentFile.is_open()) {
        while(appointmentFile >> ID >> day >> time >> complaint >> appointmentDepartment){
            if(appointmentDepartment == this->name){
                appointments.push_back(Appointment(ID,day,time,complaint,appointmentDepartment));
                schedule[day][time] = true; //Randevuyu doldur
            }
        }
    }

}

void Department::showDepartment() {
    cout << this->name << endl;

}

Patient Department::takeAppointment() {
    return Patient();
}
