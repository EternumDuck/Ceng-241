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
    bool schedule[7][6]{false};//move to schedule later
private:
    int rooms;
    string name;
    vector <Nurse> nurses;
    vector <Patient> patients;
    vector <Doctor> doctors;// move back to private
    vector <Appointment> appointments;
public:
    Department(string name, int rooms);
    void loadPeople();
    Patient takeAppointment();
    Patient takePatient();
    Patient dischargePatient();

    void showDepartment();
    void loadAppointments();
};


#endif //CENG241_DEPARTMENT_H
