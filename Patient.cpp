#include "Patient.h"

#include <utility>
 std::string Patient::getName() {
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
    cout << "Patient " << this->name << " is discharged." << endl;
    this->~Patient();
}

void Patient::showPatient() {
    cout << "Patient Name: " << this->name;
    cout << " ID: " << this->ID << endl;
    cout << " Age: " << this->age;
    cout << "  Weight: " << this->weight;
    cout << "  Height: " << this->height << endl;
    cout << " Blood Type: " << this->bloodType;
    cout << "  Blood Sugar: " << this->bloodSugar << endl;
    cout << " Department: " << this->department << endl;
    cout << "Patient Treatment: " << this->treatment << endl;
}

