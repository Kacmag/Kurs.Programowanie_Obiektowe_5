#pragma once
#include "ObiektGeom.hh"

class Hover : public GeometricOBJ
{
    double angle;
    double howFar;
    double speed;

public:
    /* sposob 2 inicjalizacji zmiennych
      Hover(const char *sNazwaPliku_BrylaWzKolorIDorcowa,const char *sNazwaObiektu,int KolorID)
      {
          _KolorID=KolorID;
        _NazwaPliku_BrylaWzorcowa=sNazwaPliku_BrylaWzKolorIDorcowa;
      _NazwaObiektu = sNazwaObiektu;
      _NazwaPliku_BrylaRysowana = NAZWA_KARTOTEKI_PLIKOW_DO_RYSOWANIA;
      _NazwaPliku_BrylaRysowana += "/";
      _NazwaPliku_BrylaRysowana += sNazwaObiektu;
      _NazwaPliku_BrylaRysowana += ".dat";
    }*/

    Hover()
    {
    }
    Hover(const char *sNazwaPliku_BrylaWzorcowa, const char *sNazwaObiektu, int KolorID) : GeometricOBJ(sNazwaPliku_BrylaWzorcowa, sNazwaObiektu, KolorID)
    {
    }
    /*!
     * \brief funkcja dostepowa anglea
     *
     * metoda zwraca nam zadany angle
     * \return zwraca atrybut angle
     */
    double get_angle() const { return angle; }
    /*!
     * \brief funkcja dostepowa howFari
     *
     * metoda zwraca nam zadany howFari
     * \return zwraca atrybut howFari
     */
    double get_howFar() const { return howFar; }
    /*!
     * \brief funkcja dostepowa speedi
     *
     * metoda zwraca nam zadany speedi
     * \return zwraca atrybut speedi
     */
    double get_speed() const { return speed; }
      /*!
     * \brief funkcja dostepowa angle
     *
     * metoda zwraca orginal zmiennej angle do zmiany
     * \return zwraca referencje anglea
     */
    double &set_angle() { return angle; }
        /*!
     * \brief funkcja dostepowa howFar
     *
     * metoda zwraca orginal zmiennej howFar do zmiany
     * \return zwraca referencje howFar
     */
    double &set_howFar() { return howFar; }
    /*!
     * \brief funkcja dostepowa speed
     *
     * metoda zwraca orginal zmiennej speed do zmiany
     * \return zwraca referencje speed
     */
    double &set_speed() { return speed; }
};