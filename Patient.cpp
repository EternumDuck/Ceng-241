#include "Patient.h"

Patient::Patient(int ID, const std::string& name)
        : ID(ID), name(name) {
    // İhtiyaç duyulursa başka başlatma işlemleri yapılabilir
}

int Patient::getID() const {
    return ID;
}

const std::string& Patient::getName() const {
    return name;
}
void Patient::setAge(int age) {
    this->age = age;
}

void Patient::setWeight(float weight) {
    this->weight = weight;
}

void Patient::setHeight(float height) {
    this->height = height;
}

void Patient::setBloodType(const std::string& bloodtype) {
    this->bloodtype = bloodtype;
}

void Patient::setBloodSugar(float bloodsugar) {
    this->bloodsugar = bloodsugar;
}

void Patient::setTreatmentCost(float treatmentcost) {
    this->treatmentcost = treatmentcost;
}
