#include <iostream>
#include <vector>
#include <string>
#include "Patient.h"
#include "Staff.h"
#include "Doctor.h"
#include "Nurse.h"
#include "Hospital.h" // Yeni eklenen Hospital sınıfının başlık dosyası

int main() {
    Hospital hospital; // Yeni bir Hospital nesnesi oluşturma
    std::string name;

    int choice = 2;

    do {
        std::cout << "Welcome to X Hospital!" << std::endl;
        std::cout << "1 - Randevu alma" << std::endl;
        std::cout << "2 - Randevu kontrol etme" << std::endl;
        std::cout << "3 - Doktor giris" << std::endl;
        std::cout << "4 - Hemsire giris" << std::endl;
        std::cout << "5 - Staff giris" << std::endl;
        std::cout << "0 - Exit" << std::endl;
        std::cout << "Your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 0:
                std::cout << "Exiting ";
                break;
            case 1: {
                int ID, dept, day, hour;
                std::cout << "Please enter your ID: ";
                std::cin >> ID;
                std::cout << "Please enter your name: ";
                std::cin >> name;
                std::cout << "Please enter your desired department" << std::endl;
                std::cout << "1 - Neurology\n2 - KBB\n3 - Cardiology\nYour choice: ";
                std::cin >> dept;
                hospital.displayDoctors(dept); // Doktorları görüntüleme
                std::cout << "Select a doctor (Enter doctor number): ";
                int doctorNumber;
                std::cin >> doctorNumber;

                hospital.displayAvailableSlots(doctorNumber); //Doktorların Boş saatleri görüntüleme
                std::cout << "Enter preferred day: ";
                std::cin >> day;
                std::cout << "\nEnter preferred hour: ";
                std::cin >> hour;

                hospital.bookAppointment(ID, name, dept, doctorNumber, day, hour); // Randevu alma
                break;
            }
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
                std::cout << "Error: Wrong input" << std::endl;
        }
    } while (choice != 0);

    return 0;
}
