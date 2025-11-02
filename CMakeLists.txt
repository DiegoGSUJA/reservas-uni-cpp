cmake_minimum_required(VERSION 3.20)
project(reservas_uni_cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Librería con el código del dominio
add_library(domain
        src/Calendario.cpp
)
target_include_directories(domain PUBLIC include)

# Ejecutable principal
add_executable(reservas_uni_cpp
        src/main.cpp
)
target_link_libraries(reservas_uni_cpp PRIVATE domain)

# Dependencias de test y configuración de tests
include(FetchContent)
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.5.4
)
FetchContent_MakeAvailable(Catch2)

enable_testing()
add_executable(tests
        tests/test_reserva_cal.cpp
)
target_link_libraries(tests PRIVATE domain Catch2::Catch2WithMain)
target_include_directories(tests PRIVATE include)

include(CTest)
include(Catch)
catch_discover_tests(tests)
