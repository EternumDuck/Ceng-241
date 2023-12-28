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
private:
    int rooms;
    string name;
public:
    vector <Nurse> nurses;
    vector <Patient> patients;
    vector <Doctor> doctors;
    Department(string name, int rooms);
    ~Department();
    void hireDoctor(Doctor doctor);
    void hireNurse(Nurse nurse);
    void loadPeople();
    void showDepartment();
    void showDoctors();

    string getName();
    int getRooms();

    void fireDoctor(Doctor &doctor);
    void fireNurse(Nurse &nurse);
};


#endif //CENG241_DEPARTMENT_H
