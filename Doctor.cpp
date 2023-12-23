#include "Doctor.h"

Doctor::Doctor(int number, const std::string& name, int department)
        : number(number), name(name), department(department) {
    // İhtiyaç duyulursa başka başlatma işlemleri yapılabilir
}

int Doctor::getNumber() const {
    return number;
}

const std::string& Doctor::getName() const {
    return name;
}

int Doctor::getDepartment() const {
    return department;
}
void Doctor::setNumber(int number) {
    this->number = number;
}

void Doctor::setName(const std::string& name) {
    this->name = name;
}

void Doctor::setDepartment(int department) {
    this->department = department;
}
