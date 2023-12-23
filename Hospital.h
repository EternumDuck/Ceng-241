#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <vector>
#include <fstream>
#include "Doctor.h"
#include "Patient.h"


class Hospital {
public:
    Hospital(); // Constructor
    ~Hospital(); // Destructor

    void displayDoctors(int department);
    void displayAvailableSlots(int doctorNumber) const;
    void bookAppointment(int patientID, const std::string& patientName, int department, int doctorNumber, int day, int hour);
    std::vector<Doctor> doctors;
    std::vector<Patient> patients;
    void saveDataToFile() const;
    void loadDataFromFile();

private:

    // Diğer gerekli veri yapıları eklenebilir


};

#endif // HOSPITAL_H
