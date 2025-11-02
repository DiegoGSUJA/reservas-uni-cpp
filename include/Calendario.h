#pragma once
#include "Reserva.h"
#include <vector>

class Calendario {
public:
    bool add(const Reserva& r);
    const std::vector<Reserva>& todas() const { return reservas_; }
private:
    std::vector<Reserva> reservas_;
};
