#include <iostream>
#include <vector>
#include <string>
#include "Patient.h"
#include "Staff.h"
#include "Doctor.h"
#include "Nurse.h"

int main() {
    Patient Rooms[6][3];
    string name;

    int choice=2;

    do{
    std::cout << "Welcome to X Hospital!" << std::endl;
    std::cout << "1 - Randevu alma" << std::endl;
    std::cout << "2 - Randevu kontrol etme" << std::endl;
    std::cout << "3 - Doktor giris" << std::endl;
    std::cout << "4 - Hemsire giris" << std::endl;
    std::cout << "5 - Staff giris" << std::endl;
    std::cout << "Your choice: ";
    std::cin >> choice;
    switch (choice) {
        case 0:
            std::cout << "Cikis ";
            break;
        case 1:
            //
            int ID,day,doctornumber;
            int dept,randevu,room;

            std::cout << "Please enter your ID: ";
            std::cin >> ID;
            std::cout << "Please enter your name: ";
            std::cin >> name;
            std::cout << "Please enter your desired department" << std::endl;
            std::cout << "1 - Neurology\n2-KBB\n3 - Cardiology\n Your choice: 1";
            std::cin >> dept;
            std::cout << "Select a doctor" << std::endl;
            std::cout << "1 - Doctor1\n2- Doctor2\n3 - Doctor3\n Your choice: ";
            //doctor list
            //std::cin >> doctornumber;

            //doctorun boş olduğu saatler
            //PAZARTESI     SALI        CARSAMBA        PERSEMBE        CUMA        CUMARTESI       PAZAR
            // Doctor1         .
            // Doctor2         .           .               .
            // Doctor3

            std::cin >> day >> room;
            //hastayi vektore at
            Rooms[day][room] = *new Patient(ID,name);
            break;
        case 2:
            //
            std::cout << "Please enter your ID" << std::endl;
            // check rooms vector
            break;
        case 3:
            //Doctor
            std::cout << "Please enter your ID and password" << std::endl;
            // Welcome Dr."name"
            std::cout;

            break;
        case 4:
            //Nurse
            std::cout << "Please enter your ID and password" << std::endl;

            break;
        case 5:
            //Staff
            std::cout << "Please enter your ID and password" << std::endl;

            break;

        default:
            std::cout << "Error wrong input" << std::endl;
    }}while(choice!=0);
    return 0;
}
