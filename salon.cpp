#include "salon.h"
#include <stdexcept>

using namespace std;

Klient::Klient()
    : imie("Brak"), nazwisko("Brak"), telefon("000-000-000") {}

Klient::Klient(string im, string naz, string tel)
    : imie(im), nazwisko(naz), telefon(tel) {
    if (im.empty() || naz.empty()) {
        throw invalid_argument("Imie i nazwisko klienta nie moga byc puste.");
    }
    if (tel.length() < 9) {
        throw invalid_argument("Numer telefonu musi miec co najmniej 9 znakow.");
    }
}

void Klient::wyswietlKlienta() const {
    cout << *this << endl;
}

string Klient::getPelneDane() const {
    return imie + " " + nazwisko + " (" + telefon + ")";
}

ostream& operator<<(ostream& os, const Klient& k) {
    os << "Klient: " << k.imie << " " << k.nazwisko << " | Tel: " << k.telefon;
    return os;
}

SalonSamochodowy::~SalonSamochodowy() {
    for (size_t i = 0; i < flota.size(); ++i) {
        delete flota[i];
    }
    flota.clear();
}

void SalonSamochodowy::dodajSamochod(Samochod* nowySamochod) {
    if (nowySamochod == nullptr) {
        throw invalid_argument("Wskaznik na samochod nie moze byc pusty.");
    }
    for (size_t i = 0; i < flota.size(); ++i) {
        if (*flota[i] == *nowySamochod) {
            cout << "Uwaga: Taki sam model z tego rocznika jest juz we flocie." << endl;
        }
    }
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
    if (indeks < 0 || indeks >= getLiczbaSamochodow()) {
        throw out_of_range("Nieprawidlowy indeks samochodu.");
    }
    flota[indeks]->oznaczJakoSprzedany();
    cout << "Samochod zostal oznaczony jako sprzedany!" << endl;
}

void SalonSamochodowy::dodajKlienta(const Klient& nowyKlient, bool wypiszKomunikat) {
    klienci.push_back(nowyKlient);
    if (wypiszKomunikat) {
        cout << "Dodano nowego klienta!" << endl;
    }
}

void SalonSamochodowy::wyswietlKlientow() const {
    if (klienci.empty()) {
        cout << "Brak klientow w bazie." << endl;
        return;
    }
    for (size_t i = 0; i < klienci.size(); ++i) {
        cout << i << ". " << klienci[i] << endl;
    }
}

int SalonSamochodowy::getLiczbaSamochodow() const {
    return flota.size();
}

int SalonSamochodowy::getLiczbaKlientow() const {
    return klienci.size();
}

void SalonSamochodowy::zapiszNaJazdeProbna(int indexAuto, int indexKlient) {
    if (indexAuto < 0 || indexAuto >= getLiczbaSamochodow()) {
        throw out_of_range("Nieprawidlowy indeks samochodu przy zapisie na jazde probna.");
    }
    if (indexKlient < 0 || indexKlient >= getLiczbaKlientow()) {
        throw out_of_range("Nieprawidlowy indeks klienta przy zapisie na jazde probna.");
    }
    if (flota[indexAuto]->czySprzedany()) {
        throw logic_error("Nie mozna zapisac na jazde probna: ten samochod zostal juz sprzedany.");
    }

    cout << "\n[JAZDA PROBNA] Sukces!" << endl;
    cout << klienci[indexKlient] << endl;
    cout << "Zostal zapisany na jazde probna samochodem: ";
    flota[indexAuto]->wyswietlInfo();
}

void SalonSamochodowy::wyswietlNajtanszySamochod() const {
    if (flota.empty()) {
        cout << "Brak samochodow we flocie." << endl;
        return;
    }

    size_t idxNajtanszego = 0;
    for (size_t i = 1; i < flota.size(); ++i) {
        if (*flota[i] < *flota[idxNajtanszego]) {
            idxNajtanszego = i;
        }
    }

    cout << "\n--- NAJTANSZY SAMOCHOD WE FLOCIE ---" << endl;
    flota[idxNajtanszego]->wyswietlInfo();
}

