#include "Patient.h"

#include <utility>

const std::string& Patient::getName() const {
    return name;
}
void Patient::setAge(int age) {
    this->age = age;
}

void Patient::setWeight(double weight) {
    this->weight = weight;
}

void Patient::setHeight(double height) {
    this->height = height;
}

void Patient::setBloodType(const std::string& bloodtype) {
    this->bloodType = bloodtype;
}

void Patient::setBloodSugar(double bloodsugar) {
    this->bloodSugar = bloodsugar;
}

void Patient::setTreatmentCost(double treatmentcost) {
    this->treatmentCost = treatmentcost;
}

int Patient::getID() const {
    return this->ID;
}

void Patient::setTreatment(string treatmentval) {
    this->treatment = std::move(treatmentval);
}

void Patient::discharge() {
    std::cout << "Patient " << this->name << " is discharged." << std::endl;
    this->~Patient();
}

