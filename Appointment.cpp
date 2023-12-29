#include <iostream>
#include "Appointment.h"


Appointment::Appointment(int ID,int day,int time,string complaint,string department,string preferred)
:ID(ID),day(day),time(time),complaint(complaint),department(department),preferred(preferred) {

}

Appointment::Appointment() {

}

void Appointment::showAppointment() {
    string dayNames[] = {"Monday", "Tuesday", "Wednesday",
                         "Thursday", "Friday", "Saturday",
                         "Sunday"};

    cout << "ID: " << ID << endl;
    cout << "Day: " << dayNames[day] << endl;
    cout << "Time: " << time + 12 << ":00" << endl;
    cout << "Complaint: " << complaint << endl;
}

void Appointment::cancel() {

}

int Appointment::getID() const {
    return this->ID;
}

int Appointment::getDay() const {
    return this->day;
}

int Appointment::getTime() const {
    return this->time;
}

string Appointment::getComplaint() {
    return this->complaint;
}

string Appointment::getDepartment() {
    return this->department;
}

string Appointment::getPreferred() {
    return this->preferred;
}
