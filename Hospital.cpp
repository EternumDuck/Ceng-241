#include "Hospital.h"
#include <string>
#include <fstream>

using namespace std;


Hospital::Hospital(string name):name(name) {
    loadDepartments();
}

Hospital::~Hospital() {
}

string Hospital::getName() {
    return name;
}
void Hospital::loadDepartments(){
    fstream departmentFile;
    departmentFile.open("Departments.txt",ios::in);

    string depname;
    int rooms;
    if (departmentFile.is_open()) {
        while(departmentFile >> depname >> rooms){
           // std::cout << "Department of " << depname << " has " << rooms << " rooms" << endl;
            departments.push_back(Department(depname,rooms));
        }
    }
    else
        cerr << "error opening file" << endl;
    //cout << "debug : Loaded departments" << endl;
    departmentFile.close();

}

void Hospital::addDepartment(string depname,int rooms) {
    fstream departmentFile;
    departmentFile.open("Departments.txt",ios::app);
    if (departmentFile.is_open()) {
        departmentFile << depname << " " << rooms << endl;
       cout << "Department " << depname << " added" << endl;
    } else {
        cerr << "error opening file" << endl;
    }
    cout << "debug : Loaded departments" << endl;
    departmentFile.close();


}

void Hospital::showHospital() {
    int i = 0;
    cout << "Showing hospital departments" << endl;

    for (auto Department:departments) {
    cout << i << ". ";
    Department.showDepartment();
    cout << endl;
    i++;
    }

}
