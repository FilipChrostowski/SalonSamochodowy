#include <iostream>
#include "pojazdy.h"
#include "salon.h"

using namespace std;

int main() {
    SalonSamochodowy salon;

    // Dodanie samochodów startowych
    salon.dodajSamochod(new Benzyna("Volkswagen", "Golf GTI", 2011, 45000, 180000, 2.0));
    salon.dodajSamochod(new Elektryk("Tesla", "Model 3", 2022, 145000, 35000, 75.0, 450));
    salon.dodajSamochod(new Hybryda("Toyota", "Prius", 2020, 85000, 90000, 1.8, 8.8, 122));

    // Dodanie klienta testowego
    salon.dodajKlienta(Klient("Jan", "Kowalski", "500-600-700"));

    int wybor = 0;
    do {
        cout << "\n=== SYSTEM ZARZADZANIA SALONEM SAMOCHODOWYM ===" << endl;
        cout << "1. Wyswietl liste samochodow (oferta)" << endl;
        cout << "2. Oznacz samochod jako sprzedany" << endl;
        cout << "3. Wyswietl liste klientow" << endl;
        cout << "4. Dodaj nowego klienta" << endl;
        cout << "5. Wyjscie" << endl;
        cout << "Wybierz opcje: ";
        cin >> wybor;

        switch (wybor) {
            case 1: {
                cout << "\n--- DOSTEPNA FLOTA SAMOCHODOW ---" << endl;
                salon.wyswietlOferte();
                break;
            }
            case 2: {
                cout << "\n--- SPRZEDAZ SAMOCHODU ---" << endl;
                salon.wyswietlOferte();
                if (salon.getLiczbaSamochodow() > 0) {
                    cout << "Podaj numer samochodu do sprzedazy: ";
                    int idx;
                    cin >> idx;
                    salon.oznaczJakoSprzedany(idx);
                }
                break;
            }
            case 3: {
                cout << "\n--- BAZA KLIENTOW ---" << endl;
                salon.wyswietlKlientow();
                break;
            }
            case 4: {
                cout << "\n--- DODAWANIE KLIENTA ---" << endl;
                string imie, nazwisko, tel;
                cout << "Podaj imie: ";
                cin >> imie;
                cout << "Podaj nazwisko: ";
                cin >> nazwisko;
                cout << "Podaj telefon: ";
                cin >> tel;
                salon.dodajKlienta(Klient(imie, nazwisko, tel));
                break;
            }
            case 5:
                cout << "Zamykanie programu. Powodzenia jutro!" << endl;
                break;
            default:
                cout << "Nieznana opcja. Wybierz ponownie." << endl;
        }
    } while (wybor != 5);

    return 0;
}