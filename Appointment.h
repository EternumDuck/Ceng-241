#ifndef CENG241_APPOINTMENT_H
#define CENG241_APPOINTMENT_H

#include <string>

using namespace std;

class Appointment {
private:
    int day;
    int time;
    string complaint;
    string department;
public:
    Appointment(int day, int time, string complaint,string department);
    Appointment();
    void reschedule();
    void cancel();
    void changecomplaint();

};


#endif //CENG241_APPOINTMENT_H
