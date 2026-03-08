cmake_minimum_required(VERSION 4.0)
project(Lab2 C)

set(CMAKE_C_STANDARD 11)

add_executable(Lab2 main.c
        Domain/tranzactie.h
        Domain/tranzactie.c
        Structure/vectordinamic.c
        Repository/repo.h
        Repository/repo.c
)
