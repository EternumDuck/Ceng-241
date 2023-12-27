#include "Hospital.h"
#include <string>
#include <fstream>

using namespace std;


Hospital::Hospital(string name):name(name) {
    loadDepartments();
}

Hospital::~Hospital() {
    saveDepartments();
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
        departments.push_back(Department(std::move(depname),rooms));
}

void Hospital::showHospital() {
    int i = 0;
    cout << "Showing hospital departments" << endl;

    for (auto Department:departments) {
    cout << i << ". ";
    Department.showDepartment();
    i++;
    }

}

void Hospital::saveDepartments() {
    fstream departmentFile;
    departmentFile.open("Departments.txt",ios::out);
    if (departmentFile.is_open()) {
        for (auto Department:departments) {
            departmentFile << Department.getName() << " " << Department.getRooms() << endl;
        }
    } else {
        cerr << "error opening file" << endl;
    }
    cout << "debug : Saved departments" << endl;
    departmentFile.close();
}