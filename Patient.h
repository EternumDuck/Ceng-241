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
public:
    Patient(string name,int ID,int age,double weight,double height,string bloodType,double bloodSugar,double treatmentCost,string department)
    : name(name),ID(ID),age(age),weight(weight),height(height),bloodType(bloodType),bloodSugar(bloodSugar),treatmentCost(treatmentCost),department(department){
    }

    Patient(){

    }

    const std::string& getName() const;
    int getID() const;
    void setTreatment(string treatment);
    void discharge();

    void setAge(int age);
    void setWeight(double weight);
    void setHeight(double height);
    void setBloodType(const std::string& bloodType);
    void setBloodSugar(double bloodSugar);
    void setTreatmentCost(double treatmentCost);

    double getBloodSugar(){return bloodSugar;}
    string getBloodType(){return bloodType;}
    double getWeight(){return weight;}
    double getHeight(){return height;}
    int getAge(){return age;}
    double getTreatmentCost(){return treatmentCost;}
    string getDepartment(){return department;}

};


#endif
