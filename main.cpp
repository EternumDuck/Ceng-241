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

    while(1){
    cout << "1 - Make an appointment" << std::endl;
    cout << "2 - Check or change your appointment" << std::endl;
    cout << "3 - Login (Staff only) " << std::endl;
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
            // 4- Aynisini yapip bu sefer eczane recetesini yazicaz
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
                                    for (auto& patient : Department.patients){
                                        if(patient.getID()==patientID){
                                            string diagnosis;
                                            cout<<"Please enter the diagnosis of "<<patient.getName()<<":"<<endl;
                                            cin.ignore();
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
                                    for (auto& patient : Department.patients){
                                        if(patient.getID()==patientID2){
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
                    for (auto& nurses : Department.nurses) {
                        if (nurses.getID() == staffID && nurses.getPassword() == password) {
                            cout << "Welcome nurse " << nurses.getName() << endl; // Sucessful login for doctor class

                        }
                    }

                }

            break;
        case 4:
            // Staff menejerler girisi yapabiliriz
            // Yeni nurse doktor eklemek icin
            // Yeni departman eklemek icin
            // Ayrica Patientlerin treatmentlerine gore ucretlerini burdan belirleyebiliriz.

            break;

        default:
            std::cout << "Error wrong input" << std::endl;
    }}












    return 0;
}
