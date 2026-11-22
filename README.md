# System zarządzania salonem samochodowym (C++)

Aplikacja konsolowa napisana w języku C++ realizująca podstawowe operacje w salonie samochodowym z wykorzystaniem programowania obiektowego (OOP), polimorfizmu, przeciążania operatorów oraz obsługi wyjątków.

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