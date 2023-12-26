#ifndef CENG241_DEPARTMENT_H
#define CENG241_DEPARTMENT_H

#include <string>
#include <vector>
#include "Patient.h"
#include "Doctor.h"
#include "Nurse.h"
#include "Appointment.h"

using namespace std;
class Doctor;
class Nurse;
class Patient;

class Department {
public:
  //  bool schedule[7][6]{false}; //move to schedule later
    vector <Nurse> nurses;
    vector <Patient> patients;

private:
    int rooms;
    string name;
    //vector <Appointment> appointments;
public:
    vector <Doctor> doctors;// move back to private
    Department(string name, int rooms);
    void loadPeople();
    vector <Patient> getPatients();
    Patient takePatient();
    Patient dischargePatient();
    void showDepartment();
    void showDoctors();
    void loadAppointments();
    string getName();
};


#endif //CENG241_DEPARTMENT_H
