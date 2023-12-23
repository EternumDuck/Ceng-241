#include "Hospital.h"
#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <string>
#include <ctime>
#include <iomanip>

#include "Doctor.h"
#include "Patient.h"




Hospital::~Hospital() {
    saveDataToFile(); // Verileri dosyaya kaydetme
}

void Hospital::bookAppointment(int patientID, const std::string& patientName, int department, int doctorNumber, int day, int hour) {
    if (doctorNumber >= 0 && doctorNumber < doctors.size()) {
        if (day >= 0 && day <= 13 && hour >= 0 && hour <= 8) {
            if (!doctors[doctorNumber].randevu[day][hour]) {
                // Slot is available, book the appointment
                Patient newPatient(patientID, patientName);
                doctors[doctorNumber].randevu[day][hour] = true;
                std::cout << "Appointment booked successfully at "<<day<<".gun "<<hour<<".saat\n";
            } else {
                std::cout << "Selected slot is already booked. Please choose another time.\n";
            }
        } else {
            std::cout << "Invalid day or hour input. Please enter a valid day (1-14) and hour (8-16).\n";
        }
    } else {
        std::cout << "Invalid doctor number.\n";
    }
}


void Hospital::saveDataToFile() const {
    //çalışmıyorsa txt dosyasını bulunduğu klasörün yolunu yazın (C:\Users\Hesap\Ceng-241-main\hospital_data.txt)
    std::ofstream file("hospital_data.txt");
    if (file.is_open()) {
        // Doktor bilgilerini dosyaya yazma
        for (const Doctor& doctor : doctors) {
            file << "Doctor " << doctor.getNumber() << " " << doctor.getName() << " " << doctor.getDepartment()<<" ";

            // Doktor için randevuları ayarlama
            for (int i = 0; i < 14; i++) {
                for (int j = 0; j < 9; j++) {
                    file << doctor.randevu[i][j] << " ";
                }
            }
            file << "\n";
        }

        // Hasta bilgilerini dosyaya yazma
        for (const Patient& patient : patients) {
            file << "Patient " << patient.getID() << " " << patient.getName() << "\n";
        }

        // Diğer gerekli bilgileri dosyaya yazabilirsiniz burada
        file.close();
    } else {
        std::cerr << "Unable to open file for writing.\n";
    }
}

void Hospital::loadDataFromFile() {
    //çalışmıyorsa txt dosyasını bulunduğu klasörün yolunu yazın (C:\Users\Hesap\Ceng-241-main\hospital_data.txt)
    std::ifstream file("hospital_data.txt",std::ios::in);
    if (file.is_open()) {
        std::string line;
        std::getline(file, line);
         do{
            std::istringstream iss(line);
            std::string type;
            iss >> type;

            if (type == "Doctor") {
                int number, department;
                std::string name;
                iss >> number >> name >> department;
                doctors.push_back(Doctor(number, name, department));
                for(int i=0;i<14;i++){
                    for(int j=0;j<9;j++){
                        bool deger;
                        iss >> deger;
                        doctors.back().randevu[i][j] =deger;
                    }
                }
            } else if (type == "Patient") {
                int ID, age;
                float weight, height, bloodsugar, treatmentcost;
                std::string name, bloodtype;
                iss >> ID >> name >> age >> weight >> height >> bloodtype >> bloodsugar >> treatmentcost;

                // Hasta nesnesi oluşturma
                Patient patient(ID, name);

                // Hasta nesnesine diğer özellikleri atama
                patient.setAge(age);
                patient.setWeight(weight);
                patient.setHeight(height);
                patient.setBloodType(bloodtype);
                patient.setBloodSugar(bloodsugar);
                patient.setTreatmentCost(treatmentcost);

                patients.push_back(patient);
            }
            // Diğer tipleri buraya ekleyebilirsiniz
        }while (std::getline(file, line));
        file.close();
    } else {
        std::cerr << "Unable to open file for reading. Assuming first run.\n";
    }
}
Hospital::Hospital() {
    loadDataFromFile(); // Verileri dosyadan yükleme
}
void Hospital::displayDoctors(int department) {
    std::cout << "Doctors in Department " << department << ":\n";
    int i=0;
    for (Doctor &doctor:doctors) {
        if (doctor.getDepartment() == department) {
            std::cout<<i << " - Doctor " << doctor.getNumber() << ": " << doctor.getName() << std::endl;

        }
    }
}

void Hospital::displayAvailableSlots(int doctorNumber) const {
    if (doctorNumber >= 0 && doctorNumber < doctors.size()) {
        const Doctor& doctor = doctors[doctorNumber];
        std::cout << "Available slots for Doctor " << doctor.getNumber() << ":\n";
            const int gün_sayısı = 14;

            // Şu anki zamanı alma
            time_t simdiki_zaman = time(nullptr);
            tm *zaman_bilgisi = localtime(&simdiki_zaman);

            // 14 gün boyunca döngü
            for (int gün = 0; gün < gün_sayısı; gün++) {
                //debugger
                //std::cout << "Gun " << gün + 1 << ": "<<std::endl;

                // 08:00-17:00 arasındaki saat dilimleri için döngü
                for (int saat = 8; saat < 17; saat++) {
                    // Yeni tarih ve saat bilgisi oluşturma
                    tm tarih_ve_saat = *zaman_bilgisi;
                    tarih_ve_saat.tm_mday += gün;
                    tarih_ve_saat.tm_hour = saat;
                    tarih_ve_saat.tm_min = 0;
                    tarih_ve_saat.tm_sec = 0;

                    // mktime fonksiyonu ile tarih ve saat bilgisini düzenleme
                    mktime(&tarih_ve_saat);

                    // Düzenlenmiş tarih ve saat bilgisini ekrana yazdırma
                    if(doctors[doctorNumber].randevu[gün][saat-8]!=0){
                        //std::cout<<" Dolu"<<std::endl;
                    }
                    else if(doctors[doctorNumber].randevu[gün][saat-8]==0){
                        std::cout <<gün<<".gun "<<saat-8<<".saat "<<std::put_time(&tarih_ve_saat, "%Y-%m-%d %H:%M") << " ";
                        std::cout<<" Bos"<<std::endl;
                    }
                }
                //debugger
                //std::cout << std::endl;
            }
    } else {
        std::cout << "Invalid doctor number.\n";
    }
}
