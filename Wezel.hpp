#ifndef WEZEL_HPP
#define WEZEL_HPP

struct Wezel {
    int wartosc;
    int priorytet;
    int czasDodania;

    Wezel(int w = 0, int p = 0, int czas = 0)
        : wartosc(w), priorytet(p), czasDodania(czas) {}
};

#endif
