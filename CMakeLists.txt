cmake_minimum_required(VERSION 4.0)
project(Lab2 C)

set(CMAKE_C_STANDARD 11)

add_executable(Lab2 main.c
        Domain/tranzactie.h
        Domain/tranzactie.c
        Structure/vectordinamic.c
        Repository/repo.h
        Repository/repo.c
        Tests/test_domain.c
        Tests/test_repo.c
        Service/service.h
        Service/service.c
        Validator/validator_tranzactie.c
        Validator/validator_tranzactie.h
        Tests/test_service.c
        Tests/test_structure.c
)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    add_compile_options(-fprofile-instr-generate -fcoverage-mapping)
    add_link_options(-fprofile-instr-generate)
    #Uncomment in case of linker errors
    #link_libraries(clang_rt.profile-x86_64)
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    add_compile_options(--coverage)
    #Uncomment in case of linker errors
    #link_libraries(gcov)
endif ()