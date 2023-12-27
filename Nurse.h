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


    //add more
    void setPatientBloodSugar(Patient &patient, double bloodSugar);

    void setPatientBloodType(Patient &patient, string bloodType);

    void setPatientWeight(Patient &patient, double weight);

    void setPatientHeight(Patient &patient, double height);
};


#endif //CENG241_NURSE_H
