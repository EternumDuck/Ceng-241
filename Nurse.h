#ifndef CENG241_NURSE_H
#define CENG241_NURSE_H
#include <vector>
#include <string>
#include "Appointment.h"
#include "Staff.h"
#include "Patient.h"

using namespace std;

class Nurse : public Staff {
public:
    Nurse(const std::string& name, int ID, int password) :
            Staff(name, ID, password) {};
    void setPatientBloodSugar(Patient);
    void setPatientWeight(Patient);
    void setPatientHeight(Patient);
    //add more
};


#endif //CENG241_NURSE_H
