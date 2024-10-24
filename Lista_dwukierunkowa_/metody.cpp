#include "naglowek.h"
#include <iostream>

using namespace std;

wezel::wezel(int a) : a(a), nastepny_element(nullptr), poprzedni_element(nullptr) {}
lista_dwukierunkowa::lista_dwukierunkowa(int a) { poczatek = new wezel(a), koniec = poczatek; }
lista_dwukierunkowa::~lista_dwukierunkowa(void) { this->usun(); }
void lista_dwukierunkowa::dodajpoczatek(int a) {

    wezel* wezeln = new wezel(a);

    if (!poczatek) { poczatek = koniec = wezeln; }

    else {
        wezeln->nastepny_element = poczatek;
        poczatek->poprzedni_element = wezeln;
        poczatek = wezeln;
    }

}

void lista_dwukierunkowa::minuspoczatek(void) {

    if (!poczatek) {
        cout << "brak poczatku listy\n";
        return;
    }

    poczatek = poczatek->nastepny_element;

    if (poczatek) {
        poczatek->poprzedni_element = nullptr;
    }

    else { koniec = nullptr; }

}
