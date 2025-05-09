#ifndef TABLICA_PRIORYTETOWA_HPP
#define TABLICA_PRIORYTETOWA_HPP

#include "Wezel.hpp"
#include <cstddef>

class TablicaPriorytetowa {
private:
    Wezel* tablica;
    std::size_t rozmiar;
    std::size_t pojemnosc;
    int licznikCzasu;

    void powieksz();
    void zmniejsz();

public:
    TablicaPriorytetowa();
    ~TablicaPriorytetowa();

    void insert(int wartosc, int priorytet);
    int find_max() const;
    int extract_max();
    void modify_key(int wartosc, int nowyPriorytet);
    std::size_t return_size() const;
};

#endif
