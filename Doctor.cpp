#include "Doctor.h"
#include <fstream>
#include <iomanip>

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

void Doctor::viewSchedule() {
    string dayNames[] = {"Monday", "Tuesday", "Wednesday",
                         "Thursday", "Friday", "Saturday",
                         "Sunday"};
    cout << "Your schedule is as follows:" << endl;
    for (int day = 0; day < 7; ++day) {
        cout << setw(10) << " " << dayNames[day];
    }
    for (int hours = 0; hours < 6; ++hours) {
        cout << setw(10);
        for (int day = 0; day < 7; ++day) {
            if (!this->schedule[day][hours]) { // Hospital veya Department classina bunun isBusy fonksiyonunu yaz
                cout << hours + 12 << ":00" << setw(14);
            } else {
                cout << "Busy" << setw(16); // Duzgun calismiyor duzeltilmesi lazim
            }
        }
        cout << endl;
    }
}

void Doctor::viewPatients() {
    cout << "Your patients are as follows:" << endl;
    for (Appointment appointment: appointments) {
         appointment.showAppointment();
    }

}
