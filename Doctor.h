#ifndef DOCTOR_H
#define DOCTOR_H
#include <vector>
#include <string>

class Doctor {
public:
    Doctor(int number, const std::string& name, int department);

    int getNumber() const;
    const std::string& getName() const;
    int getDepartment() const;
    void setNumber(int number);
    void setDepartment(int department);
    void setName(const std::string& name);
    bool randevu[14][9];

private:
    int number;
    std::string name;
    int department;
    // Diğer özellikler eklenebilir
};

#endif // DOCTOR_H
