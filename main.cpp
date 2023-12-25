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
            int prefdoc;

            cout << "Please enter your ID, name" << endl;
            cin >> ID >> name;
            cout << "Please enter your desired department" << endl;
            hospital.showHospital();
            cin >> department;

            cout << "Please select your preferred doctor" << endl;
            hospital.departments[department].showDoctors();
            cin >> prefdoc;

            cout << "Please enter your desired date and time" << endl;
            for (int day = 0; day < 7; ++day) {
                cout << setw(10) << " " << dayNames[day];
            }
            for(int hours = 0; hours < 6; ++hours){
                cout << setw(10);
                for (int day = 0; day < 7; ++day) {
                    if(!hospital.departments[department].doctors[prefdoc].schedule[day][hours]){ // Hospital veya Department classina bunun isBusy fonksiyonunu yaz
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
                        if(ID==hospital.departments[i].doctors[j].appointments[k].ID){
                            cout<<IDCounter<<". Day: "<< hospital.departments[i].doctors[j].appointments[k].day << " Time: "<< hospital.departments[i].doctors[j].appointments[k].time<<" Department Name: "<<hospital.departments[i].name<<" Doctor Name:"<<hospital.departments[i].doctors[j].getName()<<endl;
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
                switch (IDCounter) {
                    case 1: {
                        int fchoice(0);
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
                                    if (kVector[IDCounter-1] < hospital.departments[iVector[IDCounter-1]].doctors[jVector[IDCounter-1]].appointments.size()) {
                                        hospital.departments[iVector[IDCounter-1]].doctors[jVector[IDCounter-1]].appointments.erase(
                                                hospital.departments[iVector[IDCounter-1]].doctors[jVector[IDCounter-1]].appointments.begin() + kVector[IDCounter-1]);
                                    }else cout<<"IDCounter vektörden büyük olamaz büyük hata var"<<endl;
                                    cout<<"Your appointment record has been deleted"<<endl;
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
                        cout<<"More than one matching appointment found, please select which one you would like to make a transaction with"<<endl<<"Your choice:";
                        int idchoice=0;
                        cin>>idchoice;
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
                                    }else cout<<"idchoice vektörden büyük olamaz büyük hata var xdd"<<endl;
                                    cout<<"Your appointment record has been deleted"<<endl;
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
            int password;
            Doctor* doctorPtr;
            //serhat
            // ID ve Password ile departments classindaki nurses ve doctors vektorlerindeki ID ve Passwordlari eslestirdiginde giris sagla, O doktor objesine pointer dondur
            // Doktor icin 1- Departman schedule gorme 2- Departmanindaki Patientlerin infolarini gorme
            // 3- Departmandaki patientler icin secip Patient.treatment icine doktorun yaptigi seyi koyucaz
            // 4- Aynisini yapip bu sefer eczane recetesini yazicaz
            // 5- Patientleri silme hakki kendi departman icindeki patientleri taburcu edebilme.
            //
            cout << "Please enter your ID and password" << endl;
            cin >> ID >> password;
            /* doctorPtr = if(checkIDpass()){
             cout << "Welcome"







              }

             */

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
