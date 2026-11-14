#ifndef POJAZDY_H
#define POJAZDY_H

#include <iostream>
#include <string>

using namespace std;


class Pojazd {
protected:
    string marka;
    string model;
    int rocznik;
    double cena;
    int przebieg;
    bool sprzedany;

public:
    Pojazd(string m, string mod, int rocz, double c, int przeb);
    virtual ~Pojazd();


    virtual void wyswietlInfo() const = 0;
    virtual string getTypNapedu() const = 0;

    
    double getCena() const;
    bool czySprzedany() const;
    void oznaczJakoSprzedany();
    string getMarka() const;
    string getModel() const;
};


class Benzyna : public Samochod {
private:
    double pojemnoscSilnika;

public:
    Benzyna(string m, string mod, int rocz, double c, int przeb, double poj);
    void wyswietlInfo() const override;
    string getTypNapedu() const override;
};


class Diesel : public Samochod {
private:
    double pojemnoscSilnika; 
    bool filtrDpf;

public:
    Diesel(string m, string mod, int rocz, double c, int przeb, double poj, bool dpf);
    void wyswietlInfo() const override;
    string getTypNapedu() const override;
};


class Hybryda : public Samochod {
private:
    double pojemnoscBaterii; 
    int mocSystemowa;        

public:
    Hybryda(string m, string mod, int rocz, double c, int przeb, double bat, int moc);
    void wyswietlInfo() const override;
    string getTypNapedu() const override;
};


class Elektryk : public Samochod {
private:
    double pojemnoscBaterii; 
    int zasiegWltp;          

public:
    Elektryk(string m, string mod, int rocz, double c, int przeb, double bat, int zasieg);
    void wyswietlInfo() const override;
    string getTypNapedu() const override;
};

#endif