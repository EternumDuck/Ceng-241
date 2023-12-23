cmake_minimum_required(VERSION 3.26)
project(ceng241)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(ceng241 
        Doctor.cpp
        Doctor.h
        Hospital.cpp
        Hospital.h
        hospital_data.txt
        main.cpp
        Nurse.cpp
        Nurse.h
        Patient.cpp
        Patient.h
        Staff.cpp
        Staff.h)
