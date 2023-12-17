#ifndef CENG241_PATIENT_H
#define CENG241_PATIENT_H
#include <vector>
#include <string>
using namespace std;

class Patient {
    string name;
    string bloodtype;
    int ID,age;
    float weight,height;
    float bloodsugar,treatmentcost;
    vector <string> prescription;
    vector <string> treatment;
public:
    Patient(int ID_val,string name_val)
    :ID{ID_val},name{name_val}{
    }
    Patient(){

    }

};


#endif
