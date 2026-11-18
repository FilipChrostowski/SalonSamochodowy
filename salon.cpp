#include "salon.h"

using namespace std;

Klient::Klient(string im, string naz, string tel)
    : imie(im), nazwisko(naz), telefon(tel) {}

void Klient::wyswietlKlienta() const {
    cout << "Klient: " << imie << " " << nazwisko << " | Tel: " << telefon << endl;
}

string Klient::getPelneDane() const {
    return imie + " " + nazwisko + " (" + telefon + ")";
}

SalonSamochodowy::~SalonSamochodowy() {
    for (size_t i = 0; i < flota.size(); ++i) {
        delete flota[i];
    }
    flota.clear();
}

void SalonSamochodowy::dodajSamochod(Samochod* nowySamochod) {
    flota.push_back(nowySamochod);
}

void SalonSamochodowy::wyswietlOferte() const {
    if (flota.empty()) {
        cout << "Brak samochodow w salonie." << endl;
        return;
    }
    for (size_t i = 0; i < flota.size(); ++i) {
        cout << i << ". ";
        flota[i]->wyswietlInfo();
    }
}

void SalonSamochodowy::oznaczJakoSprzedany(int indeks) {
    if (indeks >= 0 && indeks < getLiczbaSamochodow()) {
        flota[indeks]->oznaczJakoSprzedany();
        cout << "Samochod zostal oznaczony jako sprzedany!" << endl;
    } else {
        cout << "Nieprawidlowy indeks samochodu!" << endl;
    }
}

void SalonSamochodowy::dodajKlienta(const Klient& klient) {
    klienci.push_back(klient);
    cout << "Dodano nowego klienta!" << endl;
}

void SalonSamochodowy::wyswietlKlientow() const {
    if (klienci.empty()) {
        cout << "Brak klientow w bazie." << endl;
        return;
    }
    for (size_t i = 0; i < klienci.size(); ++i) {
        cout << i << ". ";
        klienci[i].wyswietlKlienta();
    }
}

int SalonSamochodowy::getLiczbaSamochodow() const {
    return flota.size();
}

int SalonSamochodowy::getLiczbaKlientow() const {
    return klienci.size();
}

void SalonSamochodowy::zapiszNaJazdeProbna(int indexAuto, int indexKlient) {
    if (indexAuto >= 0 && indexAuto < getLiczbaSamochodow() &&
        indexKlient >= 0 && indexKlient < getLiczbaKlientow()) {
        
        cout << "\n[JAZDA PROBNA] Sukces!" << endl;
        cout << "Klient: ";
        klienci[indexKlient].wyswietlKlienta();
        cout << "Zostal zapisany na jazde probna samochodem: ";
        flota[indexAuto]->wyswietlInfo();
    } else {
        cout << "Blad: Nieprawidlowy indeks samochodu lub klienta!" << endl;
    }
}