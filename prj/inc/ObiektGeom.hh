#ifndef OBIEKTGEOM_HH
#define OBIEKTGEOM_HH

#include <string>
#include "UkladWsp.hh"

#define NAZWA_KARTOTEKI_PLIKOW_DO_RYSOWANIA "pliki_do_rysowania"

class GeometricOBJ
{
  /* potrzebne do  sposob 2 inicjalizacji zmiennych  protected: */
  std::string _NazwaPliku_BrylaWzorcowa;
  std::string _NazwaPliku_BrylaRysowana;
  std::string _NazwaObiektu;
  int _KolorID;
  UkladWsp ukl;

public:
  GeometricOBJ() {}
  /*!
   * \brief funkcja GeometricOBJ
   *
   * metoda ustawiajaca nam glowne parametry obiektu do wyrysowania
   * \param[in] sNazwaPliku_BrylaWzorcowa przyjmuje wskaznik na lancuchj znakow
   * \param[in] sNazwaObiektu przyjmuje wskaznik na lancuchj znakow
   * \param[in] KolorID id koloru (4-zolty)
   */
  GeometricOBJ(const char *sNazwaPliku_BrylaWzorcowa, const char *sNazwaObiektu, int KolorID);

  int WezKolorID() const { return _KolorID; }

  const std::string &WezNazweObiektu() const { return _NazwaObiektu; }

  const std::string &WezNazwePliku_BrylaRysowana() const 
      { return _NazwaPliku_BrylaRysowana; }

  Wektor3D &set_scale() { return ukl.set_Scale(); }
  Wektor3D &set_Movement() { return ukl.set_movement(); }
  bool Przelicz_i_Zapisz_Wierzcholki(std::ostream &StrmWy, std::istream &StrmWe);
  bool Przelicz_i_Zapisz_Wierzcholki();
};

#endif
