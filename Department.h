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
private:
    int rooms;
    string name;
    vector <Nurse> nurses;
    vector <Patient> patients;
    //vector <Appointment> appointments;
public:
    vector <Doctor> doctors;// move back to private
    Department(string name, int rooms);
    void loadPeople();
    Patient takePatient();
    Patient dischargePatient();
    void showDepartment();
    void showDoctors();
    void loadAppointments();
};


#endif //CENG241_DEPARTMENT_H
