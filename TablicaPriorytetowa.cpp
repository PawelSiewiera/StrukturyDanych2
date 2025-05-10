#include "TablicaPriorytetowa.hpp"
#include <stdexcept>

using namespace std;

TablicaPriorytetowa::TablicaPriorytetowa()
    : rozmiar(0), pojemnosc(10), licznikCzasu(0) {
    tablica = new Wezel[pojemnosc];
}

TablicaPriorytetowa::~TablicaPriorytetowa() {
    delete[] tablica;
}

void TablicaPriorytetowa::powieksz() {
    pojemnosc *= 2;
    Wezel* nowa = new Wezel[pojemnosc];
    for (size_t i = 0; i < rozmiar; ++i) {
        nowa[i] = tablica[i];
    }
    delete[] tablica;
    tablica = nowa;
}

void TablicaPriorytetowa::zmniejsz() {
    if (rozmiar <= pojemnosc / 3 && pojemnosc > 10) {
        pojemnosc /= 2;
        Wezel* nowa = new Wezel[pojemnosc];
        for (size_t i = 0; i < rozmiar; ++i) {
            nowa[i] = tablica[i];
        }
        delete[] tablica;
        tablica = nowa;
    }
}

void TablicaPriorytetowa::insert(int wartosc, int priorytet) {
    if (rozmiar == pojemnosc) powieksz();
    tablica[rozmiar++] = Wezel(wartosc, priorytet, licznikCzasu++);
}

int TablicaPriorytetowa::find_max() const {
    if (rozmiar == 0) throw out_of_range("empty");

    size_t idx = 0;
    for (size_t i = 1; i < rozmiar; ++i) {
        if (tablica[i].priorytet > tablica[idx].priorytet ||
           (tablica[i].priorytet == tablica[idx].priorytet &&
            tablica[i].czasDodania < tablica[idx].czasDodania)) {
            idx = i;
        }
    }
    return tablica[idx].wartosc;
}

int TablicaPriorytetowa::extract_max() {
    if (rozmiar == 0) throw out_of_range("empty");

    size_t idx = 0;
    for (size_t i = 1; i < rozmiar; ++i) {
        if (tablica[i].priorytet > tablica[idx].priorytet ||
           (tablica[i].priorytet == tablica[idx].priorytet &&
            tablica[i].czasDodania < tablica[idx].czasDodania)) {
            idx = i;
        }
    }

    int wynik = tablica[idx].wartosc;
    for (size_t i = idx; i < rozmiar - 1; ++i) {
        tablica[i] = tablica[i + 1];
    }
    --rozmiar;
    zmniejsz();
    return wynik;
}

void TablicaPriorytetowa::modify_key(int wartosc, int nowyPriorytet) {
    for (size_t i = 0; i < rozmiar; ++i) {
        if (tablica[i].wartosc == wartosc) {
            tablica[i].priorytet = nowyPriorytet;
            return;
        }
    }
}

size_t TablicaPriorytetowa::return_size() const {
    return rozmiar;
}
