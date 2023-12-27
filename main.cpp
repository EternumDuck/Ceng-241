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

    //write 2 nested for each loops

    while(choice!=5){
    cout << "1 - Make an appointment" << std::endl;
    cout << "2 - Check or change your appointment" << std::endl;
    cout << "3 - Login (Staff only) " << std::endl;
    cout << "4 - Login (Manager only) " << std::endl;
    cout << "5 - Exit" << std::endl;
    cin >> choice;

    switch (choice) {
        case 1:
            //
            int ID;
            int prefdepartment;
            int date,time;
            int prefdoc;

            cout << "Please enter your ID, name" << endl;
            cin >> ID >> name;
            cout << "Please enter your desired department" << endl;
            hospital.showHospital();
            cin >> prefdepartment;

            cout << "Please select your preferred doctor" << endl;
            hospital.departments[prefdepartment].showDoctors();
            cin >> prefdoc;

            cout << "Please enter your desired date and time" << endl;
            for (int day = 0; day < 7; ++day) {
                cout << setw(10) << " " << dayNames[day];
            }
            for(int hours = 0; hours < 6; ++hours){
                cout << setw(10);
                for (int day = 0; day < 7; ++day) {
                    if(!hospital.departments[prefdepartment].doctors[prefdoc].schedule[day][hours]){ // Hospital veya Department classina bunun isBusy fonksiyonunu yaz
                        cout << hours + 12 << ":00" << setw(14);
                    }
                    else{
                        cout << "Busy" << setw(16); // Duzgun calismiyor duzeltilmesi lazim
                    }
                }
                cout << endl;
            }
           cin >> date >> time;
            // check if empty
            //
            //
            // if empty
            cout << "Please write your symptoms" << endl;
            cin >> complaints;
            //
            // make appoiuntment class and change schedule to true


            break;
        case 2:
            // furkan
            {
            //doctor sınıfındaki "vector <Appointment> appointments;",
            // department sınıfındaki "string name;",
            // Appointment sınıfındaki "int ID;", "int day;" ve "int time;"
            // private olduğu için çalışmıyor bunların ya public olması lazım ya da getter setter fonksiyonları lazım ona göre fonksiyonun güncellenmesi lazım
            //aşağıdaki döngülerin düzgün çalışması için de ilgili değerlerin atanmış olması lazım.
            //vektörleri atayan kod 19.satıra gelecek: https://github.com/fc63/atayici/blob/main/debugger.cpp kopyala yapıştır
            int ID(0),IDCounter(0);
                cout << "Please enter your ID:";
                cin >> ID;

                //id'yi check edip id'nin vektör içinde bulunduğu konumu hafızaya atar
                vector<int> iVector;
                vector<int> jVector;
                vector<int> kVector;
                for(int i=0; i<hospital.departments.size();i++){
                    for (int j = 0; j < hospital.departments[i].doctors.size(); j++) {
                        for (int k = 0; k < hospital.departments[i].doctors[j].appointments.size(); k++) {
                            if(ID==hospital.departments[i].doctors[j].appointments[k].getID()){
                                if(IDCounter!=0) {
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
                if(IDCounter==0){
                    cout<<"No matching ID"<<endl;
                }
                else{
                    int VectorError=IDCounter;
                    switch (IDCounter) {
                        case 1: {
                            int fchoice(0);
                            cout <<"Day: "
                                 << hospital.departments[iVector[0]].doctors[jVector[0]].appointments[kVector[0]].getDay() << " Time: "
                                 << hospital.departments[iVector[0]].doctors[jVector[0]].appointments[kVector[0]].getTime()
                                 << " Department Name: " << hospital.departments[iVector[0]].getName() << " Doctor Name:"
                                 << hospital.departments[iVector[0]].doctors[jVector[0]].getName() << endl;
                            while(1) {
                                cout << "1-Change" << endl;
                                cout << "2-Cancel" << endl;
                                cout << "3-Back" << endl;
                                cin >> fchoice;
                                switch (fchoice) {
                                    case 1: {

                                        break;
                                    }
                                    case 2: {
                                        if (kVector[0] < hospital.departments[iVector[0]].doctors[jVector[0]].appointments.size()) {
                                            hospital.departments[iVector[0]].doctors[jVector[0]].appointments.erase(
                                                    hospital.departments[iVector[0]].doctors[jVector[0]].appointments.begin() + kVector[0]);
                                            cout<<"Your appointment record has been deleted"<<endl;
                                        }else cout<<"vector error"<<endl;
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
                            };
                            break;
                        }
                        default: {
                            cout<< IDCounter<<". Day: "
                                 << hospital.departments[iVector[0]].doctors[jVector[0]].appointments[kVector[0]].getDay() << " Time: "
                                 << hospital.departments[iVector[0]].doctors[jVector[0]].appointments[kVector[0]].getTime()
                                 << " Department Name: " << hospital.departments[iVector[0]].getName() << " Doctor Name:"
                                 << hospital.departments[iVector[0]].doctors[jVector[0]].getName() << endl;
                            cout<<"More than one matching appointment found, please select which one you would like to make a transaction with"<<endl<<"Your choice:";
                            int idchoice=0;
                            cin>>idchoice;
                            if(idchoice>VectorError--||idchoice<=0){
                                //kullanıcı IDCounter'dan büyük ya da 0 küçük değer girerse var olmayan bir vektörü seçmiş olur bu da hata verir bu yüzden ana menüye atıyoruz
                                //0 seçerse hata vermez ama seçim ekranında gözükmeyen bir vektörü seçmiş olur o yüzden <=0
                                break;
                            }
                            if(idchoice==IDCounter){
                                idchoice=0;
                            }
                            int fchoice(0);
                            do {
                                cout << "1-Change" << endl;
                                cout << "2-Cancel" << endl;
                                cout << "3-Back" << endl;
                                cin >> fchoice;
                                switch (fchoice) {
                                    case 1: {
                                        //buralar hep dutluktu
                                        break;
                                    }
                                        //vektörü siler ve ana menüye atar
                                    case 2: {
                                        if (kVector[idchoice] < hospital.departments[iVector[idchoice]].doctors[jVector[idchoice]].appointments.size()) {
                                            hospital.departments[iVector[idchoice]].doctors[jVector[idchoice]].appointments.erase(
                                                    hospital.departments[iVector[idchoice]].doctors[jVector[idchoice]].appointments.begin() + kVector[idchoice]);
                                            cout<<"Your appointment record has been deleted"<<endl;
                                        }else cout<<"vector error"<<endl;
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
                            } while (fchoice != 3&&fchoice != 2);
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
        case 3:
            int staffID;
            int password;

            cout << "Please enter your ID and password" << endl;

            cin >>  staffID >> password;
            //serhat
            // Doktor icin 1- Departman schedule gorme 2- Departmanindaki Patientlerin infolarini gorme
            // 3- Departmandaki patientler icin secip Patient.treatment icine doktorun yaptigi seyi koyucaz
            // 5- Patientleri silme hakki kendi departman icindeki patientleri taburcu edebilme.

            //write a nested for each loop to check all departments doctors and nurses
                for (auto& Department : hospital.departments) {
                    for (auto& doctor : Department.doctors) {
                        if (doctor.getID() == staffID && doctor.getPassword() == password) {
                            while(1){
                            cout << "Welcome Dr." << doctor.getName() << endl; // Sucessful login for doctor class
                            cout << "1 - View schedule" << endl;
                            cout << "2 - View patients" << endl;
                            cout << "3 - Diagnose patient" << endl;
                            cout << "4 - Discharge patient" << endl;
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
                                    for (auto& patient : Department.patients){ // Search the patients in the department
                                        if(patient.getID()==patientID){
                                            string diagnosis;
                                            cout<<"Please enter the diagnosis of "<<patient.getName()<<":"<<endl;
                                            cin.ignore(); // clear buffer for getline
                                            getline(cin, diagnosis);
                                            patient.setTreatment(diagnosis);
                                        }
                                        else
                                        cout << "Patient not found" << endl;
                                    }
                                    break;
                                case 4:
                                    cout << "Please enter the patient ID" << endl;
                                    int patientID2;
                                    cin >> patientID2;
                                    for (auto& patient : Department.patients){ // Search the patients in the department ( that our doc belongs to )
                                        int appointmentDay;
                                        int appointmentTime;
                                        if(patient.getID()==patientID2){
                                            for(auto& appointment : doctor.appointments){ // Search the appointments of the doctor for the patient that needs to be discharged
                                                if(appointment.getID()==patientID2){
                                                    appointmentDay = appointment.getDay();
                                                    appointmentTime = appointment.getTime();
                                                }
                                            }
                                            doctor.schedule[appointmentDay][appointmentTime] = false; // Set the schedule of the doctor to false
                                            patient.discharge();
                                            doctor.appointments.erase(doctor.appointments.begin()+patientID2); // iterator points to the beggining then adds the lkeft side as an offset and deletes that
                                        }
                                        else
                                            cout << "Patient not found" << endl;
                                    }
                                    break;
                                default:
                                    std::cout << "Error wrong input" << std::endl;
                            }
                        }
                    }
                    }
                    int choice{0};
                    for (auto& nurses : Department.nurses) { // Search the nurses in the NurseCare department
                        if (nurses.getID() == staffID && nurses.getPassword() == password) {
                            cout << "Welcome nurse " << nurses.getName() << endl;
                            while(choice!=3){
                            cout << "1 - View patients" << endl;
                            cout << "2 - Select Patient" << endl;
                            cout << "3 - Exit" << endl;
                            cin >> choice;
                            switch (choice) {
                                case 1:
                                    cout << "hi" << endl;
                                    break;
                                case 2:
                                    cout << "Please enter the patient ID" << endl;
                                    int patientID;
                                    cin >> patientID;
                                    for (auto& patient : Department.patients){ // Search the patients in the department
                                        if(patient.getID()==patientID){
                                            int setchoice;
                                            cout << "1 - Set blood sugar" << endl;
                                            cout << "2 - Set weight" << endl;
                                            cout << "3 - Set height" << endl;
                                            cin >> setchoice;
                                            switch (setchoice) {
                                                case 1:
                                                    cout << "Please enter the blood sugar" << endl;
                                                    double bloodSugar;
                                                    cin >> bloodSugar;
                                                    nurses.setPatientBloodSugar(patient, bloodSugar);
                                                    cout << "Blood sugar set to " << patient.getBloodSugar() << endl;
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
                                                case 4:
                                                {
                                                    cout << "Please enter the blood type" << endl;
                                                    string bloodType;
                                                    cin >> bloodType;
                                                    nurses.setPatientBloodType(patient, bloodType);
                                                    cout << "Blood type set to " << patient.getBloodType() << endl;
                                                    break;
                                                }
                                                default:
                                                    std::cout << "Error wrong input" << std::endl;
                                            }
                                        }
                                        else
                                            cout << "Patient not found" << endl;
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
                    }}
                }

            break;
        case 4:
            // Staff menejerler girisi yapabiliriz
            cout << "Please enter your ID and password" << endl;
            int staffID2;
            int password2;
            cin >>  staffID2 >> password2;
            if(staffID2 == 1 && password2 == 1){
                cout << "Welcome manager" << endl;
                int choice{0};
                while(choice!=4){
                cout << "1 - Add department" << endl;
                cout << "2 - Add doctor" << endl;
                cout << "3 - Add nurse" << endl;
                cout << "4 - Exit" << endl;
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
                        for (auto& department:hospital.departments) {
                            if(department.getName() == doctorDepartment){
                                department.hireDoctor(Doctor(doctorName, doctorID, doctorPassword, doctorDepartment));
                            }
                        }
                        break;
                    case 3:
                        cout << "Please enter the nurse name, ID and password" << endl;
                        int nurseID;
                        int nursePassword;
                        cin >> nurseName >> nurseID >> nursePassword;
                            for (auto& department:hospital.departments) {
                                if(department.getName() == "NurseCare"){
                                    department.hireNurse(Nurse(nurseName, nurseID, nursePassword, "NurseCare"));
                                }
                            };
                        break;
                    case 4:
                        cout << "Exiting..." << endl;
                        break;
                    default:
                        std::cout << "Error wrong input" << std::endl;
                }
            }
            }
            else
                cout << "Wrong ID or password" << endl;

            // Yeni nurse doktor eklemek icin
            // Yeni departman eklemek icin
            // Ayrica Patientlerin treatmentlerine gore ucretlerini burdan belirleyebiliriz.

            break;
        case 5:
            cout << "Exiting..." << endl;
            choice = 5;
            return 0;

        default:
            std::cout << "Error wrong input" << std::endl;
    }}












    return 0;
}
