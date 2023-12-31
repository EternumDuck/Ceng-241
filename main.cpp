#include <iostream>
#include <vector>
#include <string>
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

    int choice;
    string date;
    string name;
    string complaints;
    string dayNames[] = {"Monday", "Tuesday", "Wednesday",
                         "Thursday", "Friday", "Saturday",
                         "Sunday"};

    cout << "Welcome to " << hospital.getName() << std::endl;

    while (choice != 5) {
        cout << "1 - Make an appointment" << std::endl;
        cout << "2 - Check or change your appointment" << std::endl;
        cout << "3 - Login (Staff only) " << std::endl;
        cout << "4 - Login (Manager only) " << std::endl;
        cout << "5 - Exit" << std::endl;
        cin >> choice;

        switch (choice) {
            case 1: {

                int ID;
                int prefdepartment;
                int time;
                int datevalue{-1};
                int prefdoc;
                int tryagain{0};


                cout << "Please enter your desired department" << endl;
                hospital.showHospital();
                cin >> prefdepartment;

                cout << "Please select your preferred doctor" << endl;
                hospital.departments[prefdepartment].showDoctors();
                cin >> prefdoc;

                for (int day = 0; day < 7; ++day) {
                    cout << setw(10) << " " << dayNames[day];
                }
                for (int hours = 0; hours < 6; ++hours) {
                    cout << setw(10);
                    for (int day = 0; day < 7; ++day) {
                        if (!hospital.departments[prefdepartment].doctors[prefdoc].schedule[day][hours]) {
                            cout << hours + 12 << ":00" << setw(14);
                        } else {
                            cout << "Busy" << setw(14); // Duzgun calismiyor duzeltilmesi lazim
                        }
                    }
                    cout << endl;
                }
                cout << "Please enter your desired date and time" << endl;
                cin >> date >> time;
                while (!tryagain) {
                    for (int i = 0; i < 7; ++i) { // Assign the string to an int value
                        if (date == dayNames[i]) {
                            datevalue = i;
                        }
                    }

                    if (!(datevalue == -1 || (time < 12 || time > 17))) { // If the date is not found in the array
                        if (!hospital.departments[prefdepartment].doctors[prefdoc].schedule[datevalue][time -
                                                                                                       12]) { // check if time is not busy
                            hospital.departments[prefdepartment].doctors[prefdoc].schedule[datevalue][time -
                                                                                                      12] = true; // Set schedule to busy
                            cout << "Please enter your ID, name" << endl;
                            cin >> ID >> name;
                            cout << "Please enter your complaints" << endl;
                            cin.ignore(); // clear buffer for getline
                            getline(cin, complaints);
                            hospital.departments[prefdepartment].doctors[prefdoc].appointments.push_back(
                                    Appointment(ID, datevalue, time - 12, complaints,
                                                hospital.departments[prefdepartment].getName(),
                                                hospital.departments[prefdepartment].doctors[prefdoc].getName()));
                            // Creating A patient class works now
                            string tempname = hospital.departments[prefdepartment].getName();
                            hospital.departments[prefdepartment].patients.push_back(Patient(name, ID, tempname));
                            tryagain = 1;
                            cout << "Your appointment has been made " << name << endl;

                        } else {
                            cout << "Time is busy, please select another time" << endl;
                            cin >> date >> time;
                        }
                    } else {
                        cout << "Wrong date or time" << endl;
                        break;
                    }
                }

                break;
            }
            case 2:
                // furkan
            {
                int ID(0), IDCounter(0),tryagain(0),datevalue(-1),prefdoc(0),prefdepartment(0),time(0);
                cout << "Please enter your ID:";
                cin >> ID;

                //id'yi check edip id'nin vektör içinde bulunduğu konumu hafızaya atar
                vector<int> iVector;
                vector<int> jVector;
                vector<int> kVector;
                for (int i = 0; i < hospital.departments.size(); i++) {
                    for (int j = 0; j < hospital.departments[i].doctors.size(); j++) {
                        for (int k = 0; k < hospital.departments[i].doctors[j].appointments.size(); k++) {
                            if (ID == hospital.departments[i].doctors[j].appointments[k].getID()) {
                                if (IDCounter != 0) {
                                    cout << IDCounter << ". Day: "
                                         << hospital.departments[i].doctors[j].appointments[k].getDay() << " Time: "
                                         << hospital.departments[i].doctors[j].appointments[k].getTime()
                                         << " Department Name: " << hospital.departments[i].getName() << " Doctor Name:"
                                         << hospital.departments[i].doctors[j].getName() << endl;
                                }
                                iVector.push_back(i);
                                jVector.push_back(j);
                                kVector.push_back(k);
                                IDCounter++;
                            }
                        }
                    }
                }
                //id bulunamazsa ana menüye atar, bulunursa ve sadece 1 id varsa direkt seçeneklere geçer, birden çok id varsa idleri sıralar ve seçtirir sonra seçeneklere geçer
                if (IDCounter == 0) {
                    cout << "No matching ID" << endl;
                } else {
                    int VectorError = IDCounter;
                    switch (IDCounter) {
                        case 1: {
                            int fchoice(0);
                            cout << "Day: "
                                 << hospital.departments[iVector[0]].doctors[jVector[0]].appointments[kVector[0]].getDay()
                                 << " Time: "
                                 << hospital.departments[iVector[0]].doctors[jVector[0]].appointments[kVector[0]].getTime()
                                 << " Department Name: " << hospital.departments[iVector[0]].getName()
                                 << " Doctor Name:"
                                 << hospital.departments[iVector[0]].doctors[jVector[0]].getName() << endl;
                            while (1) {
                                cout << "1-Change" << endl;
                                cout << "2-Cancel" << endl;
                                cout << "3-Back" << endl;
                                cin >> fchoice;
                                switch (fchoice) {
                                    case 1: {
                                        for (int i = 0; i < hospital.departments[iVector[0]].patients.size(); i++) {
                                            if(ID==hospital.departments[iVector[0]].patients[i].getID()){
                                                name=hospital.departments[iVector[0]].patients[i].getName();
                                            }
                                        }
                                        cout << "Please enter your desired department" << endl;
                                        hospital.showHospital();
                                        cin >> prefdepartment;

                                        cout << "Please select your preferred doctor" << endl;
                                        hospital.departments[prefdepartment].showDoctors();
                                        cin >> prefdoc;
                                        hospital.departments[prefdepartment].doctors[prefdoc].viewSchedule();
                                        cout << "Please enter your desired date and time" << endl;
                                        cin >> date >> time;
                                        while (!tryagain) {
                                            for (int i = 0; i < 7; ++i) {
                                                if (date == dayNames[i]) {
                                                    datevalue = i;
                                                }
                                            }

                                            if (!(datevalue == -1 || (time < 12 || time > 17))) {
                                                if (!hospital.departments[prefdepartment].doctors[prefdoc].schedule[datevalue][time -
                                                                                                                               12]) {
                                                    hospital.departments[prefdepartment].doctors[prefdoc].schedule[datevalue][time -
                                                                                                                              12] = true;
                                                    cout << "Please enter your complaints" << endl;
                                                    cin.ignore();
                                                    getline(cin, complaints);
                                                    if (kVector[0] <
                                                        hospital.departments[iVector[0]].doctors[jVector[0]].appointments.size()) {
                                                        hospital.departments[iVector[0]].doctors[jVector[0]].schedule[hospital.departments[iVector[0]].doctors[jVector[0]].appointments[kVector[0]].getDay()][hospital.departments[iVector[0]].doctors[jVector[0]].appointments[kVector[0]].getTime()] = false;
                                                        hospital.departments[iVector[0]].doctors[jVector[0]].appointments.erase(
                                                                hospital.departments[iVector[0]].doctors[jVector[0]].appointments.begin() +
                                                                kVector[0]);
                                                    } else cout << "vector error" << endl;
                                                    hospital.departments[prefdepartment].doctors[prefdoc].appointments.push_back(
                                                            Appointment(ID, datevalue, time - 12, complaints,
                                                                        hospital.departments[prefdepartment].getName(),
                                                                        hospital.departments[prefdepartment].doctors[prefdoc].getName()));
                                                    string tempname = hospital.departments[prefdepartment].getName();
                                                    hospital.departments[prefdepartment].patients.push_back(Patient(name, ID, tempname));
                                                    cout << "Your appointment has been changed " << name << endl;
                                                    tryagain = 1;
                                                } else {
                                                    cout << "Time is busy, please select another time" << endl;
                                                    cin >> date >> time;
                                                }
                                            } else {
                                                cout << "Wrong date or time" << endl;
                                                break;
                                            }
                                        }
                                        break;
                                    }
                                    case 2: {
                                        if (kVector[0] <
                                            hospital.departments[iVector[0]].doctors[jVector[0]].appointments.size()) {
                                            hospital.departments[iVector[0]].doctors[jVector[0]].schedule[hospital.departments[iVector[0]].doctors[jVector[0]].appointments[kVector[0]].getDay()][hospital.departments[iVector[0]].doctors[jVector[0]].appointments[kVector[0]].getTime()] = false;
                                            hospital.departments[iVector[0]].doctors[jVector[0]].appointments.erase(
                                                    hospital.departments[iVector[0]].doctors[jVector[0]].appointments.begin() +
                                                    kVector[0]);
                                            cout << "Your appointment record has been deleted" << endl;
                                        } else cout << "vector error" << endl;
                                        break;
                                    }
                                    case 3: {
                                        cout << "Exiting..." << endl;
                                        break;
                                    }
                                    default: {
                                        cout << "Error wrong input(1-3)" << endl;
                                        break;
                                    }
                                }
                                break;
                            }
                            break;
                        }
                        default: {
                            cout << IDCounter << ". Day: "
                                 << hospital.departments[iVector[0]].doctors[jVector[0]].appointments[kVector[0]].getDay()
                                 << " Time: "
                                 << hospital.departments[iVector[0]].doctors[jVector[0]].appointments[kVector[0]].getTime()
                                 << " Department Name: " << hospital.departments[iVector[0]].getName()
                                 << " Doctor Name:"
                                 << hospital.departments[iVector[0]].doctors[jVector[0]].getName() << endl;
                            cout
                                    << "More than one matching appointment found, please select which one you would like to make a transaction with"
                                    << endl << "Your choice(Back for 0):";
                            int idchoice = 0;
                            cin >> idchoice;
                            if (idchoice > VectorError-- || idchoice <= 0) {
                                //kullanıcı IDCounter'dan büyük ya da 0 küçük değer girerse var olmayan bir vektörü seçmiş olur bu da hata verir bu yüzden ana menüye atıyoruz
                                //0 seçerse hata vermez ama seçim ekranında gözükmeyen bir vektörü seçmiş olur o yüzden <=0
                                break;
                            }
                            if (idchoice == IDCounter) {
                                idchoice = 0;
                            }
                            int fchoice(0);
                            do {
                                cout << "1-Change" << endl;
                                cout << "2-Cancel" << endl;
                                cout << "3-Back" << endl;
                                cin >> fchoice;
                                switch (fchoice) {
                                    case 1: {
                                        for (int i = 0; i < hospital.departments[iVector[idchoice]].patients.size(); i++) {
                                            if(ID==hospital.departments[iVector[idchoice]].patients[i].getID()){
                                                name=hospital.departments[iVector[idchoice]].patients[i].getName();
                                            }
                                        }
                                        cout << "Please enter your desired department" << endl;
                                        hospital.showHospital();
                                        cin >> prefdepartment;

                                        cout << "Please select your preferred doctor" << endl;
                                        hospital.departments[prefdepartment].showDoctors();
                                        cin >> prefdoc;
                                        hospital.departments[prefdepartment].doctors[prefdoc].viewSchedule();
                                        cout << "Please enter your desired date and time" << endl;
                                        cin >> date >> time;
                                        while (!tryagain) {
                                            for (int i = 0; i < 7; ++i) {
                                                if (date == dayNames[i]) {
                                                    datevalue = i;
                                                }
                                            }

                                            if (!(datevalue == -1 || (time < 12 || time > 17))) {
                                                if (!hospital.departments[prefdepartment].doctors[prefdoc].schedule[datevalue][time -
                                                                                                                               12]) {
                                                    hospital.departments[prefdepartment].doctors[prefdoc].schedule[datevalue][time -
                                                                                                                              12] = true;
                                                    cout << "Please enter your complaints" << endl;
                                                    cin.ignore();
                                                    getline(cin, complaints);
                                                    if (kVector[idchoice] <
                                                        hospital.departments[iVector[idchoice]].doctors[jVector[idchoice]].appointments.size()) {
                                                        hospital.departments[iVector[idchoice]].doctors[jVector[idchoice]].schedule[hospital.departments[iVector[idchoice]].doctors[jVector[idchoice]].appointments[kVector[idchoice]].getDay()][hospital.departments[iVector[idchoice]].doctors[jVector[idchoice]].appointments[kVector[idchoice]].getTime()] = false;
                                                        hospital.departments[iVector[idchoice]].doctors[jVector[idchoice]].appointments.erase(
                                                                hospital.departments[iVector[idchoice]].doctors[jVector[idchoice]].appointments.begin() +
                                                                kVector[idchoice]);
                                                    } else cout << "vector error" << endl;
                                                    hospital.departments[prefdepartment].doctors[prefdoc].appointments.push_back(
                                                            Appointment(ID, datevalue, time - 12, complaints,
                                                                        hospital.departments[prefdepartment].getName(),
                                                                        hospital.departments[prefdepartment].doctors[prefdoc].getName()));
                                                    string tempname = hospital.departments[prefdepartment].getName();
                                                    hospital.departments[prefdepartment].patients.push_back(Patient(name, ID, tempname));
                                                    cout << "Your appointment has been changed " << name << endl;
                                                    tryagain = 1;
                                                } else {
                                                    cout << "Time is busy, please select another time" << endl;
                                                    cin >> date >> time;
                                                }
                                            } else {
                                                cout << "Wrong date or time" << endl;
                                                break;
                                            }
                                        }
                                        break;
                                    }
                                        //vektörü siler ve ana menüye atar
                                    case 2: {
                                        if (kVector[idchoice] <
                                            hospital.departments[iVector[idchoice]].doctors[jVector[idchoice]].appointments.size()) {
                                            hospital.departments[iVector[idchoice]].doctors[jVector[idchoice]].schedule[hospital.departments[iVector[idchoice]].doctors[jVector[idchoice]].appointments[kVector[idchoice]].getDay()][hospital.departments[iVector[idchoice]].doctors[jVector[idchoice]].appointments[kVector[idchoice]].getTime()] = false;
                                            hospital.departments[iVector[idchoice]].doctors[jVector[idchoice]].appointments.erase(
                                                    hospital.departments[iVector[idchoice]].doctors[jVector[idchoice]].appointments.begin() +
                                                    kVector[idchoice]);
                                            cout << "Your appointment record has been deleted" << endl;
                                        } else cout << "vector error" << endl;
                                        break;
                                    }
                                    case 3: {
                                        //ana menüye atar
                                        cout << "Exiting..." << endl;
                                        break;
                                    }
                                    default: {
                                        cout << "Error wrong input(1-3)" << endl;
                                        break;
                                    }
                                }
                            } while (fchoice != 3 && fchoice != 2&&fchoice != 1);
                            break;
                        }
                    }
                }

                // Department classinin Appointment vectorundeki tum uyelere bakip idsi eslesince, Day hour department ismi doktorismi yazdiktan sonra 1-degistir 2-iptal et 3-geri menuye gel
                // 1- degistir icin Appointment vektorundeki bilgileri degistir
                // 2- idsi eslesen appointment vektorunu tamamen sil
                // bu guncellemeleri kaydetmek icin sonradan savetofile fonksiyonu
                break;
            }
            case 3: {
                int staffID;
                int password;

                cout << "Please enter your ID and password" << endl;

                cin >> staffID >> password;

                // nested for each loop to check all departments doctors and nurses
                for (auto &Department: hospital.departments) {
                    for (auto &doctor: Department.doctors) {
                        if (doctor.getID() == staffID && doctor.getPassword() == password) {
                            while (choice != 6) {
                                cout << "Welcome Dr." << doctor.getName() << endl; // Sucessful login for doctor class
                                cout << "1 - View schedule" << endl;
                                cout << "2 - View patients" << endl;
                                cout << "3 - Diagnose patient" << endl;
                                cout << "4 - Discharge patient" << endl;
                                cout << "6 - Exit" << endl;
                                cin >> choice;
                                switch (choice) {
                                    case 1:
                                        doctor.viewSchedule();
                                        break;
                                    case 2:
                                        doctor.viewPatients();
                                        break;
                                    case 3:
                                        cout << "Please enter the patient ID" << endl;
                                        int patientID;
                                        cin >> patientID;
                                        for (auto &patient: Department.patients) { // Search the patients in the department
                                            if (patient.getID() == patientID) {
                                                string diagnosis;
                                                cout << "Please enter the diagnosis of " << patient.getName() << ":"
                                                     << endl;
                                                cin.ignore(); // clear buffer for getline
                                                getline(cin, diagnosis);
                                                patient.setTreatment(diagnosis);
                                            } else
                                                cout << "Patient not found" << endl;
                                        }
                                        break;
                                    case 4:
                                        cout << "Please enter the patient ID" << endl;
                                        int patientID2;
                                        cin >> patientID2;
                                        for (auto &patient: Department.patients) { // Search the patients in the department ( that our doc belongs to )
                                            int appointmentDay;
                                            int appointmentTime;
                                            if (patient.getID() == patientID2) {
                                                for (auto &appointment: doctor.appointments) { // Search the appointments of the doctor for the patient that needs to be discharged
                                                    if (appointment.getID() == patientID2) {
                                                        appointmentDay = appointment.getDay();
                                                        appointmentTime = appointment.getTime();
                                                    }
                                                }
                                                doctor.schedule[appointmentDay][appointmentTime] = false; // Set the schedule of the doctor to false
                                                patient.discharge();
                                                doctor.appointments.erase(doctor.appointments.begin() +
                                                                          patientID2); // iterator points to the beggining then adds the lkeft side as an offset and deletes that
                                            } else
                                                cout << "Patient not found" << endl;
                                        }
                                        break;
                                    case 6:
                                        cout << "Exiting..." << endl;
                                        choice = 6;
                                        break;
                                    default:
                                        std::cout << "Error wrong input" << std::endl;
                                }
                            }
                        }
                    }
                    int choice{0};
                    for (auto &nurses: Department.nurses) { // Search the nurses in the NurseCare department
                        if (nurses.getID() == staffID && nurses.getPassword() == password) {
                            cout << "Welcome nurse " << nurses.getName() << endl;
                            while (choice != 3) {
                                cout << "1 - View patients" << endl;
                                cout << "2 - Select Patient" << endl;
                                cout << "3 - Exit" << endl;
                                cin >> choice;
                                switch (choice) {
                                    case 1: {
                                        cout << "Which department would you like to view patients from?" << endl;
                                        string departmentChoice;
                                        cin >> departmentChoice;
                                        for (auto &department: hospital.departments) { // For every department
                                            if (department.getName() == departmentChoice) {
                                                for (auto &patient: department.patients) {
                                                    patient.showPatient();
                                                    cout << endl;
                                                }
                                            }
                                        }
                                    }
                                        break;
                                    case 2: {
                                        cout << "Please enter the patient ID" << endl;
                                        int patientID;
                                        cin >> patientID;
                                        for (auto &department: hospital.departments) { // For every department
                                            for (auto &patient: department.patients) {// Search the patients in the department

                                                if (patient.getID() == patientID) {
                                                    int setchoice{0};
                                                    while (setchoice != 6) {
                                                        cout << "1 - Set blood sugar" << endl;
                                                        cout << "2 - Set weight" << endl;
                                                        cout << "3 - Set height" << endl;
                                                        cout << "4 - Set blood type" << endl;
                                                        cout << "5 - Set age" << endl;
                                                        cout << "6 - Exit" << endl;
                                                        cin >> setchoice;
                                                        switch (setchoice) {
                                                            case 1:
                                                                cout << "Please enter the blood sugar" << endl;
                                                                double bloodSugar;
                                                                cin >> bloodSugar;
                                                                nurses.setPatientBloodSugar(patient, bloodSugar);
                                                                cout << "Blood sugar set to " << patient.getBloodSugar()
                                                                     << endl;
                                                                break;
                                                            case 2:
                                                                cout << "Please enter the weight" << endl;
                                                                double weight;
                                                                cin >> weight;
                                                                nurses.setPatientWeight(patient, weight);
                                                                cout << "Weight set to " << patient.getWeight() << endl;
                                                                break;
                                                            case 3:
                                                                cout << "Please enter the height" << endl;
                                                                double height;
                                                                cin >> height;
                                                                nurses.setPatientHeight(patient, height);
                                                                cout << "Height set to " << patient.getHeight() << endl;
                                                                break;
                                                            case 4: {
                                                                cout << "Please enter the blood type" << endl;
                                                                string bloodType;
                                                                cin >> bloodType;
                                                                nurses.setPatientBloodType(patient, bloodType);
                                                                cout << "Blood type set to " << patient.getBloodType()
                                                                     << endl;
                                                                break;
                                                            }
                                                            case 5:
                                                                cout << "Please enter the age" << endl;
                                                                int age;
                                                                cin >> age;
                                                                nurses.setPatientAge(patient, age);
                                                                cout << "Age set to " << patient.getAge() << endl;
                                                                break;
                                                            case 6:
                                                                cout << "Exiting..." << endl;
                                                                setchoice = 6;
                                                                break;

                                                            default:
                                                                std::cout << "Error wrong input" << std::endl;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                        break;
                                        case 3:
                                            cout << "Exiting..." << endl;
                                        choice = 3;
                                        break;
                                        default:
                                            std::cout << "Error wrong input" << std::endl;
                                    }
                                }
                            }
                        }
                    }
                }
                break;
                case 4:
                    // Staff menejerler girisi yapabiliriz
                    cout << "Please enter your ID and password" << endl;
                int staffID2;
                int password2;
                cin >> staffID2 >> password2;
                if (staffID2 == 1 && password2 == 1) {
                    cout << "Welcome manager" << endl;
                    int choice{0};
                    while (choice != 7) {

                        cout << "1 - Add department" << endl;
                        cout << "2 - Add doctor" << endl;
                        cout << "3 - Add nurse" << endl;
                        cout << "4 - Fire doctor" << endl;
                        cout << "5 - Fire nurse" << endl;
                        cout << "6 - Remove department" << endl;
                        cout << "7 - Exit" << endl;

                        cin >> choice;
                        string departmentName;
                        string doctorName;
                        string doctorDepartment;
                        string nurseName;

                        switch (choice) {
                            case 1:
                                cout << "Please enter the department name and number of rooms" << endl;
                                int numberOfRooms;
                                cin >> departmentName >> numberOfRooms;
                                hospital.addDepartment(departmentName, numberOfRooms);
                                break;
                            case 2:
                                cout << "Please enter the doctor name, ID, password and department" << endl;
                                int doctorID;
                                int doctorPassword;
                                cin >> doctorName >> doctorID >> doctorPassword >> doctorDepartment;
                                for (auto &department: hospital.departments) {
                                    if (department.getName() == doctorDepartment) {
                                        department.hireDoctor(Doctor(doctorName, doctorID, doctorPassword,
                                                                     doctorDepartment)); // works
                                    }
                                }
                                break;
                            case 3:
                                cout << "Please enter the nurse name, ID and password" << endl;
                                int nurseID;
                                int nursePassword;
                                cin >> nurseName >> nurseID >> nursePassword;
                                for (auto &department: hospital.departments) {
                                    if (department.getName() == "NurseCare") {
                                        department.hireNurse(Nurse(nurseName, nurseID, nursePassword)); // fix
                                    }
                                };
                                break;
                            case 4:
                                cout << "Please enter the doctor ID" << endl;
                                int doctorID2;
                                cin >> doctorID2;
                                for (auto &department: hospital.departments) {
                                    for (auto &doctor: department.doctors) {
                                        if (doctor.getID() == doctorID2) {
                                            department.fireDoctor(doctor);
                                        }
                                    }
                                }
                                break;
                            case 5:
                                cout << "Please enter the nurse ID" << endl;
                                int nurseID2;
                                cin >> nurseID2;
                                for (auto &department: hospital.departments) {
                                    for (auto &nurse: department.nurses) {
                                        if (nurse.getID() == nurseID2) {
                                            department.fireNurse(nurse);
                                        }
                                    }
                                }
                                break;
                            case 6: { // works but is a dumb way of doing it
                                cout << "Please enter the department name" << endl;
                                string departmentName2;
                                cin >> departmentName2;
                                for (auto &department: hospital.departments) {
                                    if (department.getName() == departmentName2) {
                                        hospital.removeDepartment(department);
                                    }
                                }
                            }

                            case 7:
                                cout << "Exiting..." << endl;
                                break;
                            default:
                                std::cout << "Error wrong input" << std::endl;
                        }
                    }
                } else
                    cout << "Wrong ID or password" << endl;

                // Ayrica Patientlerin treatmentlerine gore ucretlerini burdan belirleyebiliriz.

                break;
                case 5:
                    cout << "Exiting..." << endl;
                choice = 5;
                return 0;

                default:
                    std::cout << "Error wrong input" << std::endl;
            }
        }
        return 0;
    }
}
