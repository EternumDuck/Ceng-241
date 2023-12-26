#include <iostream>
#include "Appointment.h"

Appointment::Appointment(int ID,int day,int time,string complaint,string department,string preferred)
:ID(ID),day(day),time(time),complaint(complaint),department(department),preferred(preferred) {

}

Appointment::Appointment() {

}

void Appointment::showAppointment() {
    cout << "ID: " << ID << endl;
    cout << "Day: " << day << endl;
    cout << "Time: " << time << endl;
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
