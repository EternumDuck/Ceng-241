#ifndef CENG241_DOCTOR_H
#define CENG241_DOCTOR_H
#include <vector>
#include <string>
#include "Appointment.h"
#include "Staff.h"

using namespace std;

class Doctor : public Staff{
private:
    string department;
public:
    Doctor(const string& name, int ID, int password, const std::string& department) :
            Staff(name, ID, password), department(department) {}
    void viewSchedule();
    void diagnosePatient();
    void prescribeMedicine();

};


#endif //CENG241_DOCTOR_H
