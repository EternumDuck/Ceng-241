#ifndef CENG241_STAFF_H
#define CENG241_STAFF_H

#include <string>
#include <iostream>

using namespace std;

class Staff {
private:
    int ID,password;
    double salary;
protected:
    string name;
public:
    Staff(const string& name, int ID, int password)
    :name(name), ID(ID), password(password) {

    }

    ~Staff() {

    }
    string getName();

};


#endif //CENG241_STAFF_H
