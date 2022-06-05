#ifndef SCENA_HH
#define SCENA_HH
#include "Hover.hh"
#include "Kolory.hh"
#include "PowierzchniaMarsa.hh"
#include <list>
#include <memory>
#include "lacze_do_gnuplota.hh"
#include <unistd.h>

class Scena
{
    PzG::LaczeDoGNUPlota Lacze;
    std::shared_ptr<Hover> latest;
    std::list<std::shared_ptr<Hover>> lista_obiektow;

    void LaczeInit();

public:
    Scena();
    std::string nazwa_aktywnego()
        {
        return latest->WezNazweObiektu();
        }
    Wektor3D polozenie_aktywnego()
        {
        return latest->get_polozenie();
        }
   
    void Rysuj();
    void Ruch(double angle, double droga, double pretkosc);
    void wybierz_drona(int n);
    void DodajDoListyRysowania();
    void wypisz();
};
#endif