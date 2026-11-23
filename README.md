# System zarządzania salonem samochodowym (C++)

Aplikacja konsolowa napisana w języku C++ realizująca podstawowe operacje w salonie samochodowym z wykorzystaniem programowania obiektowego, polimorfizmu, przeciążania operatorów oraz obsługi wyjątków.

## Struktura projektu

- `main.cpp` – punkt wejścia aplikacji, obsługa menu użytkownika oraz przechwytywanie wyjątków (`try` / `catch`).
- `pojazdy.h` / `pojazdy.cpp` – hierarchia klas pojazdów: klasa abstrakcyjna `Samochod` oraz klasy pochodne (`Benzyna`, `Diesel`, `Hybryda`, `Elektryk`).
- `salon.h` / `salon.cpp` – obsługa klientów (`Klient`) oraz zarządzanie flotą, sprzedażą, klientami i jazdami próbnymi (`SalonSamochodowy`).

## Główne funkcje programu

- Dodawanie pojazdów różnych typów napędowych do oferty salonu.
- Przeglądanie dostępnych i sprzedanych samochodów z wykorzystaniem wywołań polimorficznych.
- Oznaczanie wybranego samochodu jako sprzedanego.
- Dodawanie klientów z walidacją danych (m.in. poprawności numeru telefonu) oraz przeglądanie listy klientów.
- Zapisywanie klientów na jazdy próbne wybranym pojazdem.
- Obsługa błędów i nieprawidłowych danych wejściowych za pomocą wyjątków standardowych.

## Kompilacja i uruchomienie

Wymagany kompilator wspierający standard C++17 (np. `g++` z pakietu MinGW).

### Kompilacja

```bash
g++ -std=c++17 main.cpp pojazdy.cpp salon.cpp -o salon.exe
#windows

./salon.exe

#linux
./salon


Przykłady działania programu
1. Próba dodania klienta z nieprawidłowym numerem telefonu (obsługa wyjątku)

--- NOWY KLIENT ---
Imie: Jan
Nazwisko: Kowalski
Telefon: 22
Blad: Numer telefonu musi miec co najmniej 9 znakow. Klient NIE zostal dodany.

2. Dodanie poprawnego klienta i zapis na jazdę próbną
--- NOWY KLIENT ---
Imie: Anna
Nazwisko: Nowak
Telefon: 501-202-303
Dodano nowego klienta!



[JAZDA PROBNA] Sukces!
Klient: Anna Nowak | Tel: 501-202-303
Zostal zapisany na jazde probna samochodem: [Benzyna] Volkswagen Golf GTI | Rok: 2011 | Przebieg: 180000 km | Silnik: 2 L | Cena: 45000 PLN | Status: Dostepny
3. Wyszukanie najtańszego samochodu we flocie (opcja 8)


--- NAJTANSZY SAMOCHOD WE FLOCIE ---
[Benzyna] Volkswagen Golf GTI | Rok: 2011 | Przebieg: 180000 km | Silnik: 2 L | Cena: 45000 PLN | Status: Dostepny

4. Próba operacji na niepoprawnym indeksie

Blad: Nieprawidlowy indeks samochodu.