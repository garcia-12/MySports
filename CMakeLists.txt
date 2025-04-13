cmake_minimum_required(VERSION 3.16)

project(ProbeKlausur_pg2_MuellerSS2023 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ProbeKlausur_pg2_MuellerSS2023 main.cpp
    athlete.h athlete.cpp
    runner.h runner.cpp
    swimmer.h swimmer.cpp
    trainer.h trainer.cpp
    mysports.h mysports.cpp)

include(GNUInstallDirs)
install(TARGETS ProbeKlausur_pg2_MuellerSS2023
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
