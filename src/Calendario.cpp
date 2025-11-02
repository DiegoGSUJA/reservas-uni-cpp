#include "Calendario.h"
#include <algorithm>

static bool solapan(const Reserva& a, const Reserva& b){
    return (a.inicio < b.fin) && (b.inicio < a.fin);
}

bool Calendario::add(const Reserva& r){
    bool choca = std::any_of(reservas_.begin(), reservas_.end(),
                              [&](const Reserva& x){ return solapan(x, r); });
    if (choca) return false;
    reservas_.push_back(r);
    return true;
}
