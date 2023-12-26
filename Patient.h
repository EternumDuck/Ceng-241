#ifndef CENG241_PATIENT_H
#define CENG241_PATIENT_H
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Patient {
    string name;
    string bloodType;
    string department;
    string treatment;

    int ID,age;
    double weight,height;
    double bloodSugar,treatmentCost;
    vector <string> prescription;
public:
    Patient(string name,int ID,int age,double weight,double height,string bloodType,double bloodSugar,double treatmentCost,string department)
    : name(name),ID(ID),age(age),weight(weight),height(height),bloodType(bloodType),bloodSugar(bloodSugar),treatmentCost(treatmentCost),department(department){
    }

    Patient(){

    }
    // destructor
    ~Patient(){
        std::cout << "Patient " << this->name << " is discharged." << std::endl;
    }

    const std::string& getName() const;
    int getID() const;
    void setTreatment(string treatment);
    void discharge();
    void setAge(int age);
    void setWeight(float weight);
    void setHeight(float height);
    void setBloodType(const std::string& bloodType);
    void setBloodSugar(float bloodSugar);
    void setTreatmentCost(float treatmentCost);

};


#endif
