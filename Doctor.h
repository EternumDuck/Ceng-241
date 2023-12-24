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
    vector <Appointment> appointments;
public:
    bool schedule[7][6]{false};
    Doctor(const string& name, int ID, int password, const std::string& department) :
            Staff(name, ID, password), department(department) {
        loadAppointments();
    }
    void loadAppointments();
    void viewSchedule();
    void diagnosePatient();
    void prescribeMedicine();

};


#endif //CENG241_DOCTOR_H
