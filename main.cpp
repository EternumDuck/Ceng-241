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

    int choice;

    while(1){
    std::cout << "Welcome to X Hospital!" << std::endl;
    std::cout << "1 - Randevu alma" << std::endl;
    std::cout << "2 - Randevu kontrol etme" << std::endl;
    std::cout << "3 - Doktor giris" << std::endl;
    std::cout << "4 - Hemsire giris" << std::endl;
    std::cout << "5 - Staff giris" << std::endl;
    std::cin >> choice;
    switch (choice) {
        case 1:
            //
            int ID,day;
            int dept,randevu,room;

            std::cout << "Please enter your ID, name" << std::endl;
            std::cin >> ID >> name;
            std::cout << "Please enter your desired department" << std::endl;
            std::cout << "1 - Neurology\n2-KBB\n3 - Cardiology" << std::endl;
            std::cin >> dept;

            std::cout << "Select time and date (Name of day and NO of room)" << std::endl;
            //departmanin tum odalarini listele bir hafta icin
            //PAZARTESI     SALI        CARSAMBA        PERSEMBE        CUMA        CUMARTESI       PAZAR
            // ODA1         .
            // ODA2         .           .               .
            // ODA3

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
    }}












    return 0;
}
