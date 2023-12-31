#include "Department.h"
#include <fstream>
#include <vector>

Department::Department(string name, int rooms)
:name(name),rooms(rooms) {
    loadPeople();
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

    if (nurseFile.is_open() && this->name == "NurseCare") {
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
   // cout << "debug : Loaded departments" << endl;
}

void Department::showDepartment() {
    cout << this->name << "  ";

}

void Department::showDoctors() {
    int i = 0;
    for (auto Doctor:doctors) {
        cout << i << ". "<<Doctor.getName() << "  ";
        i++;
    }
    cout << endl;

}


string Department::getName() {
    return this->name;
}

void Department::hireDoctor(Doctor doctor) {
    this->doctors.push_back(doctor);
}

int Department::getRooms() {
    return this->rooms;
}

void Department::hireNurse(Nurse nurse) {
    this->nurses.push_back(nurse);
}

void Department::fireDoctor(Doctor &doctor) {
    this->doctors.erase(doctors.begin()+doctor.getID());
}

void Department::fireNurse(Nurse &nurse) {
    this->nurses.erase(nurses.begin()+nurse.getID());
}
