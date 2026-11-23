#include <iostream>
#include <stdexcept>
#include "pojazdy.h"
#include "salon.h"

using namespace std;

int main() {
    SalonSamochodowy salon;

    try {
        salon.dodajSamochod(new Benzyna("Volkswagen", "Golf GTI", 2011, 45000, 180000, 2.0));
        salon.dodajSamochod(new Elektryk("Tesla", "Model 3", 2022, 145000, 35000, 75.0, 450));
        salon.dodajSamochod(new Hybryda("Toyota", "Prius", 2020, 85000, 90000, 1.8, 8.8, 122));
        salon.dodajKlienta(Klient("Jan", "Kowalski", "500-600-700"), false);
    } catch (const exception& e) {
        cout << "Blad inicjalizacji: " << e.what() << endl;
        return 1;
    }

    int wybor = 0;
    do {
        cout << "\n=== PANEL PRACOWNIKA SALONU ===" << endl;
        cout << "1. Wyswietl oferte (flota)" << endl;
        cout << "2. Dodaj samochod do floty" << endl;
        cout << "3. Oznacz samochod jako sprzedany" << endl;
        cout << "4. Wyswietl liste klientow" << endl;
        cout << "5. Dodaj klienta" << endl;
        cout << "6. Zapisz klienta na jazde probna" << endl;
        cout << "7. Wyswietl najtanszy samochod" << endl;
        cout << "8. Wyjscie" << endl;
        cout << "Wybor: ";
        cin >> wybor;

        try {
            switch (wybor) {
                case 1: {
                    cout << "\n--- FLOTA SAMOCHODOW ---" << endl;
                    salon.wyswietlOferte();
                    break;
                }
                case 2: {
                    cout << "\n--- NOWY SAMOCHOD ---" << endl;
                    string marka, model;
                    int rocznik, przebieg;
                    double cena;

                    cout << "Marka: ";
                    cin >> marka;
                    cout << "Model: ";
                    cin >> model;
                    cout << "Rocznik: ";
                    cin >> rocznik;
                    cout << "Cena (PLN): ";
                    cin >> cena;
                    cout << "Przebieg (km): ";
                    cin >> przebieg;

                    cout << "Typ napedu:\n1. Benzyna\n2. Elektryk\n3. Hybryda\n4. Diesel\nWybor: ";
                    int typ;
                    cin >> typ;

                    if (typ == 1) {
                        double poj;
                        cout << "Pojemnosc silnika (L): ";
                        cin >> poj;
                        salon.dodajSamochod(new Benzyna(marka, model, rocznik, cena, przebieg, poj));
                    } else if (typ == 2) {
                        double bat;
                        int zasieg;
                        cout << "Pojemnosc baterii (kWh): ";
                        cin >> bat;
                        cout << "Zasieg (km): ";
                        cin >> zasieg;
                        salon.dodajSamochod(new Elektryk(marka, model, rocznik, cena, przebieg, bat, zasieg));
                    } else if (typ == 3) {
                        double poj, bat;
                        int moc;
                        cout << "Pojemnosc silnika (L): ";
                        cin >> poj;
                        cout << "Pojemnosc baterii (kWh): ";
                        cin >> bat;
                        cout << "Moc (KM): ";
                        cin >> moc;
                        salon.dodajSamochod(new Hybryda(marka, model, rocznik, cena, przebieg, poj, bat, moc));
                    } else if (typ == 4) {
                        double poj;
                        int dpfInt;
                        cout << "Pojemnosc silnika (L): ";
                        cin >> poj;
                        cout << "Filtr DPF (1 - tak, 0 - nie): ";
                        cin >> dpfInt;
                        bool dpf = (dpfInt != 0);
                        salon.dodajSamochod(new Diesel(marka, model, rocznik, cena, przebieg, poj, dpf));
                    } else {
                        throw invalid_argument("Nieprawidlowy typ napedu.");
                    }
                    break;
                }
                case 3: {
                    cout << "\n--- SPRZEDAZ ---" << endl;
                    salon.wyswietlOferte();
                    if (salon.getLiczbaSamochodow() > 0) {
                        int idx;
                        cout << "Indeks samochodu: ";
                        cin >> idx;
                        salon.oznaczJakoSprzedany(idx);
                    }
                    break;
                }
                case 4: {
                    cout << "\n--- KLIENCI ---" << endl;
                    salon.wyswietlKlientow();
                    break;
                }
                case 5: {
                cout << "\n--- NOWY KLIENT ---" << endl;
                string imie, nazwisko, tel;
                cout << "Imie: ";
                cin >> imie;
                cout << "Nazwisko: ";
                cin >> nazwisko;
                cout << "Telefon: ";
                cin >> tel;

                try {
                    Klient nowyKlient(imie, nazwisko, tel);
                    salon.dodajKlienta(nowyKlient);
                } catch (const exception& e) {
                    cout << "Blad: " << e.what() << " Klient NIE zostal dodany." << endl;
                }
                break;
                }
                case 6: {
                    cout << "\n--- JAZDA PROBNA ---" << endl;
                    salon.wyswietlOferte();
                    cout << endl;
                    salon.wyswietlKlientow();

                    if (salon.getLiczbaSamochodow() > 0 && salon.getLiczbaKlientow() > 0) {
                        int idAuto, idKlient;
                        cout << "Indeks samochodu: ";
                        cin >> idAuto;
                        cout << "Indeks klienta: ";
                        cin >> idKlient;
                        salon.zapiszNaJazdeProbna(idAuto, idKlient);
                    } else {
                        cout << "Brak samochodow lub klientow." << endl;
                    }
                    break;
                }
                case 7: {
                    cout << "\n--- NAJTANSZY SAMOCHOD ---" << endl;
                    salon.wyswietlNajtanszySamochod();
                    break; }
                case 8: {
                    cout << "Koniec pracy." << endl;
                    break;
                }
                default:
                    cout << "Nieprawidlowa opcja." << endl;
            }
        } catch (const exception& e) {
            cout << "Blad: " << e.what() << endl;
        }
    } while (wybor != 8);

    return 0;
}