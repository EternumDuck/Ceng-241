#include "Doctor.h"
#include <fstream>

void Doctor::loadAppointments() {
    fstream appointmentFile;
    appointmentFile.open("Appointments.txt",ios::in);
    int day,time,ID;
    string complaint;
    string appointmentDepartment;
    string prefferedDoctor;

    if (appointmentFile.is_open()) {
        while (appointmentFile >> ID >> day >> time >> complaint >> appointmentDepartment >> prefferedDoctor) {
            if (appointmentDepartment == this->department && prefferedDoctor == this->name) {
                appointments.push_back(Appointment(ID, day, time, complaint, appointmentDepartment, prefferedDoctor));
                schedule[day][time] = true; //Randevuyu doldur
            }
        }
    }
}
