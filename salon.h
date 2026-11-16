#ifndef SALON_H
#define SALON_H

#include <iostream>
#include <vector>
#include <string>
#include "pojazdy.h"

using namespace std;

class Klient {
private:
    string imie;
    string nazwisko;
    string telefon;

public:
    Klient(string im, string naz, string tel);
    void wyswietlKlienta() const;
};

class SalonSamochodowy {
private:
    vector<Pojazd*> flota;
    vector<Klient> klienci;

public:
    ~SalonSamochodowy();

    void dodajPojazd(Pojazd* nowyPojazd);
    void wyswietlOferte() const;
    void oznaczJakoSprzedany(int indeks);

    void dodajKlienta(const Klient& klient);
    void wyswietlKlientow() const;
};

#endif