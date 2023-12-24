#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include "Patient.h"
#include "Doctor.h"
#include "Nurse.h"
#include "Department.h"
#include "Hospital.h"
#include "Appointment.h"

using namespace std;

int main() {

    Hospital hospital("Saint Serdar Arslan Hospital");
   // hospital.addDepartment("KBB",10); // works

    int choice;
    string name;
    string complaints;
    string dayNames[] = {"Monday", "Tuesday", "Wednesday",
                         "Thursday", "Friday", "Saturday",
                         "Sunday"};

    cout << "Welcome to "<< hospital.getName() << std::endl;

    while(1){
    cout << "1 - Make an appointment" << std::endl;
    cout << "2 - Check or change your appointment" << std::endl;
    cout << "3 - Login (Staff only) " << std::endl;
    cin >> choice;

    switch (choice) {
        case 1:
            //
            int ID;
            int department;
            int date,time;

            cout << "Please enter your ID, name" << endl;
            cin >> ID >> name;
            cout << "Please enter your desired department" << endl;
            hospital.showHospital();
            cin >> department;
            cout << "Please enter your desired date and time" << endl;
            for (int day = 0; day < 7; ++day) {
                cout << setw(10) << " " << dayNames[day];
            }
            for(int hours = 0; hours < 6; ++hours){
                cout << setw(10);
                for (int day = 0; day < 7; ++day) {
                    if(!hospital.departments[department].schedule[day][hours]){
                        cout << hours + 12 << ":00" << setw(14);
                    }
                    else{
                        cout << "Busy" << setw(16);
                    }
                }
                cout << endl;
            }
            cin >> date >> time;

            cout << "Please write your symptoms" << endl;
            cin >> complaints;
            hospital.departments[department].takeAppointment(); // bos fonksiyon
            break;
        case 2:
            //
            cout << "Please enter your ID" << endl;
            // check rooms vector
            break;
        case 3:
            int password;
            // ID ve Password ile departments classindaki nurses ve doctors vektorlerindeki ID ve Passwordlari eslestirdiginde giris sagle
            cout << "Please enter your ID and password" << endl;
            cin >> ID >> password;
            /*if(checkIDpass()){
             cout << "Welcome"







              }

             */

            break;

        default:
            std::cout << "Error wrong input" << std::endl;
    }}












    return 0;
}
