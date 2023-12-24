cmake_minimum_required(VERSION 3.26)
project(ceng241)

set(CMAKE_CXX_STANDARD 17)

add_executable(ceng241 main.cpp
        Patient.cpp
        Patient.h
        Doctor.cpp
        Doctor.h
        Nurse.cpp
        Nurse.h
        Hospital.cpp
        Hospital.h
        Department.cpp
        Department.h
        Appointment.cpp
        Appointment.h
        Staff.cpp
        Staff.h)
