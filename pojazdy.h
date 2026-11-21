#ifndef POJAZDY_H
#define POJAZDY_H

#include <iostream>
#include <string>

using namespace std;

class Samochod {
protected:
    string marka;
    string model;
    int rocznik;
    double cena;
    int przebieg;
    bool sprzedany;

public:
    Samochod();
    Samochod(string m, string mod, int rocz, double c, int przeb);
    virtual ~Samochod() = default;

    string getMarka() const;
    string getModel() const;
    int getRocznik() const;
    double getCena() const;
    int getPrzebieg() const;
    bool czySprzedany() const;
    void oznaczJakoSprzedany();

    bool operator==(const Samochod& inny) const;
    bool operator<(const Samochod& inny) const;

    virtual void wyswietlInfo() const = 0;
};

class Benzyna : public Samochod {
private:
    double pojemnoscSilnika;

public:
    Benzyna(string m, string mod, int rocz, double c, int przeb, double poj);
    void wyswietlInfo() const override;
};

class Diesel : public Samochod {
private:
    double pojemnoscSilnika;
    bool posiadaDPF;

public:
    Diesel(string m, string mod, int rocz, double c, int przeb, double poj, bool dpf);
    void wyswietlInfo() const override;
};

class Hybryda : public Samochod {
private:
    double pojemnoscSilnika;
    double pojemnoscBaterii;
    int mocSilnika;

public:
    Hybryda(string m, string mod, int rocz, double c, int przeb, double poj, double bat, int moc);
    void wyswietlInfo() const override;
};

class Elektryk : public Samochod {
private:
    double pojemnoscBaterii;
    int zasiegKm;

public:
    Elektryk(string m, string mod, int rocz, double c, int przeb, double bat, int zasieg);
    void wyswietlInfo() const override;
};

#endif