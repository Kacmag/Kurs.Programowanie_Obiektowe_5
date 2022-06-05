#include <iostream>
#include <fstream>
#include "ObiektGeom.hh"

using namespace std;

GeometricOBJ::GeometricOBJ(const char *sNazwaPliku_BrylaWzorcowa,
                       const char *sNazwaObiektu,
                       int KolorID) : _NazwaPliku_BrylaWzorcowa(sNazwaPliku_BrylaWzorcowa), _KolorID(KolorID)
{
  _NazwaObiektu = sNazwaObiektu;
  _NazwaPliku_BrylaRysowana = NAZWA_KARTOTEKI_PLIKOW_DO_RYSOWANIA;
  _NazwaPliku_BrylaRysowana += "/";
  _NazwaPliku_BrylaRysowana += sNazwaObiektu;
  _NazwaPliku_BrylaRysowana += ".dat";
}

bool GeometricOBJ::Przelicz_i_Zapisz_Wierzcholki(std::ostream &StrmWy, std::istream &StrmWe)
{


  int Indeks_Wiersza = 0;

  StrmWe >> ukl.set_wsp();
  if (StrmWe.fail())
    return false;

  do
  {
    ukl.set_wsp() = ukl.get_wspolrzedne() & ukl.get_Scale() + ukl.get_movement();

    StrmWy << ukl.get_wspolrzedne() << endl;
    ++Indeks_Wiersza;

    if (Indeks_Wiersza >= 4)
    {
      StrmWy << endl;
      Indeks_Wiersza = 0;
    }

    StrmWe >> ukl.set_wsp();

  } while (!StrmWe.fail());

  if (!StrmWe.eof())
    return false;

  return Indeks_Wiersza == 0 && !StrmWy.fail();
}

bool GeometricOBJ::Przelicz_i_Zapisz_Wierzcholki()
{
  ifstream StrmWe(_NazwaPliku_BrylaWzorcowa);
  ofstream StrmWy(_NazwaPliku_BrylaRysowana);

  if (!(StrmWe.is_open() && StrmWy.is_open()))
  {
    cerr << endl
         << "Nie mozna otworzyc jednego z plikow:" << endl
         << "    " << _NazwaPliku_BrylaWzorcowa << endl
         << "    " << _NazwaPliku_BrylaRysowana << endl
         << endl;
    return false;
  }

  int Indeks_Wiersza = 0;

  StrmWe >> ukl.set_wsp();
  if (StrmWe.fail())
    return false;

  do
  {
    ukl.set_wsp() = (ukl.get_wspolrzedne() & ukl.get_Scale()) + ukl.get_movement();

    StrmWy << ukl.get_wspolrzedne() << endl;
    ++Indeks_Wiersza;

    if (Indeks_Wiersza >= 4)
    {
      StrmWy << endl;
      Indeks_Wiersza = 0;
    }

    StrmWe >> ukl.set_wsp();

  } while (!StrmWe.fail());

  if (!StrmWe.eof())
    return false;

  return Indeks_Wiersza == 0 && !StrmWy.fail();
}
