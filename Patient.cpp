#include "Patient.h"

#include <utility>

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
    this->bloodType = bloodtype;
}

void Patient::setBloodSugar(float bloodsugar) {
    this->bloodSugar = bloodsugar;
}

void Patient::setTreatmentCost(float treatmentcost) {
    this->treatmentCost = treatmentcost;
}

int Patient::getID() const {
    return this->ID;
}

void Patient::setTreatment(string treatmentval) {
    this->treatment = std::move(treatmentval);
}

void Patient::discharge() {

}
