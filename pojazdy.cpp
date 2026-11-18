#include "pojazdy.h"

using namespace std;

Samochod::Samochod(string m, string mod, int rocz, double c, int przeb)
    : marka(m), model(mod), rocznik(rocz), cena(c), przebieg(przeb), sprzedany(false) {}

string Samochod::getMarka() const { return marka; }
string Samochod::getModel() const { return model; }
double Samochod::getCena() const { return cena; }
bool Samochod::czySprzedany() const { return sprzedany; }
void Samochod::oznaczJakoSprzedany() { sprzedany = true; }

Benzyna::Benzyna(string m, string mod, int rocz, double c, int przeb, double poj)
    : Samochod(m, mod, rocz, c, przeb), pojemnoscSilnika(poj) {}

void Benzyna::wyswietlInfo() const {
    cout << "[Benzyna] " << marka << " " << model 
         << " | Rok: " << rocznik 
         << " | Przebieg: " << przebieg << " km"
         << " | Silnik: " << pojemnoscSilnika << " L"
         << " | Cena: " << cena << " PLN"
         << " | Status: " << (sprzedany ? "SPRZEDANY" : "Dostepny") << endl;
}

Diesel::Diesel(string m, string mod, int rocz, double c, int przeb, double poj, bool dpf)
    : Samochod(m, mod, rocz, c, przeb), pojemnoscSilnika(poj), posiadaDPF(dpf) {}

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
    : Samochod(m, mod, rocz, c, przeb), pojemnoscSilnika(poj), pojemnoscBaterii(bat), mocSilnika(moc) {}

void Hybryda::wyswietlInfo() const {
    cout << "[Hybryda] " << marka << " " << model 
         << " | Rok: " << rocznik 
         << " | Przebieg: " << przebieg << " km"
         << " | Silnik: " << pojemnoscSilnika << " L | Bateria: " << pojemnoscBaterii << " kWh | Moc: " << mocSilnika << " KM"
         << " | Cena: " << cena << " PLN"
         << " | Status: " << (sprzedany ? "SPRZEDANY" : "Dostepny") << endl;
}

Elektryk::Elektryk(string m, string mod, int rocz, double c, int przeb, double bat, int zasieg)
    : Samochod(m, mod, rocz, c, przeb), pojemnoscBaterii(bat), zasiegKm(zasieg) {}

void Elektryk::wyswietlInfo() const {
    cout << "[Elektryk] " << marka << " " << model 
         << " | Rok: " << rocznik 
         << " | Przebieg: " << przebieg << " km"
         << " | Bateria: " << pojemnoscBaterii << " kWh | Zasieg: " << zasiegKm << " km"
         << " | Cena: " << cena << " PLN"
         << " | Status: " << (sprzedany ? "SPRZEDANY" : "Dostepny") << endl;
}