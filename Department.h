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
    vector <Nurse> nurses;
    vector <Patient> patients;

private:
    int rooms;
    string name;
public:
    vector <Doctor> doctors;// move back to private
    Department(string name, int rooms);
    ~Department(){
        saveDepartment();
    }
    void hireDoctor(Doctor doctor);
    void hireNurse(Nurse nurse);
    void loadPeople();
    void showDepartment();
    void showDoctors();
    void saveDepartment();
    void loadAppointments();
    string getName();
    int getRooms();
};


#endif //CENG241_DEPARTMENT_H
