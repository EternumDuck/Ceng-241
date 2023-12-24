#ifndef CENG241_APPOINTMENT_H
#define CENG241_APPOINTMENT_H

#include <string>

using namespace std;

class Appointment {
private:
    int ID;
    int day;
    int time;
    string complaint;
    string department;
    string preferred;
public:
    Appointment(int ID,int day, int time, string complaint,string department,string preferred);
    Appointment();
    void reschedule();
    void cancel();
    void changecomplaint();

};


#endif //CENG241_APPOINTMENT_H
