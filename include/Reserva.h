// Reserva.h
#pragma once
#include <stdexcept>
#include <string>
#include <chrono>

struct Reserva {
    std::string id;
    std::chrono::system_clock::time_point inicio;
    std::chrono::system_clock::time_point fin;

    Reserva(std::string id_,
            std::chrono::system_clock::time_point ini,
            std::chrono::system_clock::time_point fi)
        : id(std::move(id_)), inicio(ini), fin(fi) {
        if (fin <= inicio) throw std::invalid_argument("fin <= inicio");
    }
};
