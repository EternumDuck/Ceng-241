#ifndef CENG241_STAFF_H
#define CENG241_STAFF_H

#include <string>
#include <iostream>

using namespace std;

class Staff {
private:
    int ID,password;
    double salary;
    std::string name;
public:
    Staff(const std::string& name, int ID, int password)
    :name(name), ID(ID), password(password) {

    }

    ~Staff() {

    }

};


#endif //CENG241_STAFF_H
