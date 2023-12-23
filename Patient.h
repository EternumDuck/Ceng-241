#ifndef PATIENT_H
#define PATIENT_H
#include <vector>
#include <string>
using namespace std;

class Patient {
    private:
    string name;
    string bloodtype;
    int ID,age;
    float weight,height;
    float bloodsugar,treatmentcost;
    vector <string> prescription;
    vector <string> treatment;
public:
    Patient(){

    }
    Patient(int ID, const std::string& name);
    int getID() const;
    const std::string& getName() const;
    void setAge(int age);
    void setWeight(float weight);
    void setHeight(float height);
    void setBloodType(const std::string& bloodtype);
    void setBloodSugar(float bloodsugar);
    void setTreatmentCost(float treatmentcost);

};


#endif
