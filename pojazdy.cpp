#include "pojazdy.h"
#include <stdexcept>

using namespace std;

Samochod::Samochod()
    : marka("Nieznana"), model("Nieznany"), rocznik(2000), cena(0.0), przebieg(0), sprzedany(false) {}

Samochod::Samochod(string m, string mod, int rocz, double c, int przeb)
    : marka(m), model(mod), rocznik(rocz), cena(c), przebieg(przeb), sprzedany(false) {
    if (rocz < 1900 || rocz > 2030) {
        throw invalid_argument("Nieprawidlowy rocznik samochodu.");
    }
    if (c < 0.0) {
        throw invalid_argument("Cena samochodu nie moze byc ujemna.");
    }
    if (przeb < 0) {
        throw invalid_argument("Przebieg samochodu nie moze byc ujemny.");
    }
}

string Samochod::getMarka() const { return marka; }
string Samochod::getModel() const { return model; }
int Samochod::getRocznik() const { return rocznik; }
double Samochod::getCena() const { return cena; }
int Samochod::getPrzebieg() const { return przebieg; }
bool Samochod::czySprzedany() const { return sprzedany; }
void Samochod::oznaczJakoSprzedany() { sprzedany = true; }

bool Samochod::operator==(const Samochod& inny) const {
    return marka == inny.marka && model == inny.model && rocznik == inny.rocznik;
}

bool Samochod::operator<(const Samochod& inny) const {
    return cena < inny.cena;
}

Benzyna::Benzyna(string m, string mod, int rocz, double c, int przeb, double poj)
    : Samochod(m, mod, rocz, c, przeb), pojemnoscSilnika(poj) {
    if (poj <= 0.0) {
        throw invalid_argument("Pojemnosc silnika musi byc dodatnia.");
    }
}

void Benzyna::wyswietlInfo() const {
    cout << "[Benzyna] " << marka << " " << model
         << " | Rok: " << rocznik
         << " | Przebieg: " << przebieg << " km"
         << " | Silnik: " << pojemnoscSilnika << " L"
         << " | Cena: " << cena << " PLN"
         << " | Status: " << (sprzedany ? "SPRZEDANY" : "Dostepny") << endl;
}

Diesel::Diesel(string m, string mod, int rocz, double c, int przeb, double poj, bool dpf)
    : Samochod(m, mod, rocz, c, przeb), pojemnoscSilnika(poj), posiadaDPF(dpf) {
    if (poj <= 0.0) {
        throw invalid_argument("Pojemnosc silnika musi byc dodatnia.");
    }
}

void Diesel::wyswietlInfo() const {
    cout << "[Diesel] " << marka << " " << model
         << " | Rok: " << rocznik
         << " | Przebieg: " << przebieg << " km"
         << " | Silnik: " << pojemnoscSilnika << " L"
         << " | DPF: " << (posiadaDPF ? "Tak" : "Nie")
         << " | Cena: " << cena << " PLN"
         << " | Status: " << (sprzedany ? "SPRZEDANY" : "Dostepny") << endl;
}

Hybryda::Hybryda(string m, string mod, int rocz, double c, int przeb, double poj, double bat, int moc)
    : Samochod(m, mod, rocz, c, przeb), pojemnoscSilnika(poj), pojemnoscBaterii(bat), mocSilnika(moc) {
    if (poj <= 0.0 || bat <= 0.0 || moc <= 0) {
        throw invalid_argument("Nieprawidlowe parametry napedu hybrydowego.");
    }
}

void Hybryda::wyswietlInfo() const {
    cout << "[Hybryda] " << marka << " " << model
         << " | Rok: " << rocznik
         << " | Przebieg: " << przebieg << " km"
         << " | Silnik: " << pojemnoscSilnika << " L | Bateria: " << pojemnoscBaterii << " kWh | Moc: " << mocSilnika << " KM"
         << " | Cena: " << cena << " PLN"
         << " | Status: " << (sprzedany ? "SPRZEDANY" : "Dostepny") << endl;
}

Elektryk::Elektryk(string m, string mod, int rocz, double c, int przeb, double bat, int zasieg)
    : Samochod(m, mod, rocz, c, przeb), pojemnoscBaterii(bat), zasiegKm(zasieg) {
    if (bat <= 0.0 || zasieg <= 0) {
        throw invalid_argument("Nieprawidlowe parametry napedu elektrycznego.");
    }
}

void Elektryk::wyswietlInfo() const {
    cout << "[Elektryk] " << marka << " " << model
         << " | Rok: " << rocznik
         << " | Przebieg: " << przebieg << " km"
         << " | Bateria: " << pojemnoscBaterii << " kWh | Zasieg: " << zasiegKm << " km"
         << " | Cena: " << cena << " PLN"
         << " | Status: " << (sprzedany ? "SPRZEDANY" : "Dostepny") << endl;
}