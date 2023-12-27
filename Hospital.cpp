#include "Hospital.h"
#include <string>
#include <fstream>

using namespace std;


Hospital::Hospital(string name):name(name) {
    loadDepartments();
}

Hospital::~Hospital() {
    saveDepartments();
    saveInfo();
}

string Hospital::getName() {
    return name;
}
void Hospital::loadDepartments(){
    fstream departmentFile;
    departmentFile.open("Departments.txt",ios::in);

    string depname;
    int rooms;
    if (departmentFile.is_open()) {
        while(departmentFile >> depname >> rooms){
           // std::cout << "Department of " << depname << " has " << rooms << " rooms" << endl;
            departments.push_back(Department(depname,rooms));
        }
    }
    else
        cerr << "error opening file" << endl;
    //cout << "debug : Loaded departments" << endl;
    departmentFile.close();

}

void Hospital::addDepartment(string depname,int rooms) {
        departments.push_back(Department(std::move(depname),rooms));
}

void Hospital::showHospital() {
    int i = 0;
    cout << "Showing hospital departments" << endl;

    for (auto Department:departments) {
    cout << i << ". ";
    Department.showDepartment();
    i++;
    }

}

void Hospital::saveDepartments() {
    fstream departmentFile;
    departmentFile.open("Departments.txt",ios::out);
    if (departmentFile.is_open()) {
        for (auto Department:departments) {
            departmentFile << Department.getName() << " " << Department.getRooms() << endl;
        }
    } else {
        cerr << "error opening file" << endl;
    }
    cout << "debug : Saved departments" << endl;
    departmentFile.close();
}

void Hospital::saveInfo() {
    // Saving doctors
    fstream doctorFile;
    doctorFile.open("Doctors.txt",ios::out);
    for(Department department:departments){
        for(Doctor doctor:department.doctors){
            doctorFile << doctor.getName() << " " << doctor.getID() << " " << doctor.getPassword() << " " << doctor.getDepartment() << endl;
        }
    }
    // Saving Nurses
    fstream nurseFile;
    nurseFile.open("Nurses.txt",ios::out);
    for(Department department:departments){
        if(department.getName() == "NurseCare"){
        for(Nurse nurse:department.nurses){
            nurseFile << nurse.getName() << " " << nurse.getID() << " " << nurse.getPassword() << endl;
        }
        }
    }
    // Saving Patients
    fstream patientFile;
    patientFile.open("Patients.txt",ios::out);
    for(Department department:departments){
        for(Patient patient:department.patients){
            patientFile << patient.getName() << " " << patient.getID() << " " << patient.getAge() << " " << patient.getWeight() << " " << patient.getHeight() << " " << patient.getBloodType() << " " << patient.getBloodSugar() << " " << patient.getTreatmentCost() << " " << patient.getDepartment() << endl;
        }
    }

}
