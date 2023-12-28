#ifndef CENG_241_HOSPITAL_H
#define CENG_241_HOSPITAL_H
#include <string>
#include <vector>
#include "Department.h"
#include "Patient.h"
#include "Doctor.h"
#include <fstream>


using namespace std;

class Hospital {
private:
    string name;
public:
    vector<Department> departments;
    Hospital(string name);
    ~Hospital();
    void addDepartment(string depname,int rooms);
    Doctor hireNewDoc();
    Doctor fireDoc();
    void showHospital();
    string getName();

    void loadDepartments();

    void saveDepartments();
    void saveInfo();

    void removeDepartment(Department &department);
};


#endif //CENG_241_HOSPITAL_H
