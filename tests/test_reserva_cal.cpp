#include <catch2/catch_all.hpp>
#include "Calendario.h"
#include <chrono>
#include <ctime>

using SysClock = std::chrono::system_clock;

static SysClock::time_point t(int h){
    std::tm tm{};
    tm.tm_year = 125; // 2025-1900
    tm.tm_mon  = 0;   // enero
    tm.tm_mday = 1;
    tm.tm_hour = h;
    std::time_t tt = std::mktime(&tm);
    return SysClock::from_time_t(tt);
}

TEST_CASE("Reserva valida"){
    Reserva r{"r1", t(10), t(11)};
    REQUIRE(r.fin > r.inicio);
}

TEST_CASE("Reserva fin<=inicio lanza"){
    REQUIRE_THROWS( (void)Reserva{"r2", t(11), t(11)} );
    REQUIRE_THROWS( (void)Reserva{"r3", t(12), t(11)} );

}

TEST_CASE("Calendario evita solapes"){
    Calendario c;
    REQUIRE(c.add(Reserva{"r1", t(10), t(11)}));
    REQUIRE_FALSE(c.add(Reserva{"r3", t(10), t(10) + std::chrono::minutes(30)})); // solapa
    REQUIRE(c.add(Reserva{"r4", t(11), t(12)})); // contiguo sí
    REQUIRE(c.todas().size() == 2);
}
