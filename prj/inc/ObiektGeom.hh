#ifndef OBIEKTGEOM_HH
#define OBIEKTGEOM_HH

#include <string>
#include "UkladWsp.hh"

using namespace std;

#define NAZWA_KARTOTEKI_PLIKOW_DO_RYSOWANIA "pliki_do_rysowania"

class GeometricOBJ:  public UkladWsp
{
  string _NazwaPliku_BrylaWzorcowa;
  string _NazwaPliku_BrylaRysowana;
  string _NazwaObiektu;

  int _KolorID;
  double angle_zadany;

  Wektor3D movement;
  Matrix3D matrix_obrot;
public:

     GeometricOBJ() 
          {     
          for(int i=0; i<3; i++)
          matrix_obrot[i][i]=1;
          }



 
  // @brief funkcja GeometricOBJ ustawiajaca parametry obiektu do wyrysowania
  // @param sNazwaPliku_BrylaWzorcowa przyjmuje wskaznik na char
  // @param sNazwaObiektu przyjmuje wskaznik na char
  // @param KolorID 
  GeometricOBJ(const char *sNazwaPliku_BrylaWzorcowa, const char *sNazwaObiektu, int KolorID);

  double &set_angle_zadany(){return angle_zadany;}
  int WezKolorID() const { return _KolorID; }

  Wektor3D &set_polozenie(){return  movement;}
  Wektor3D get_polozenie()const {return  movement;}
  
  Matrix3D &set_Matrix(){return  matrix_obrot;}
  Matrix3D get_Matrix()const{return  matrix_obrot;}
  
  const std::string &WezNazweObiektu() const { return _NazwaObiektu; }
  const std::string &WezNazwePliku_BrylaRysowana() const { return _NazwaPliku_BrylaRysowana; }

  Wektor3D &set_scale() { return  set_Scale(); }
  Wektor3D &set_movement() { return  movement; }

  bool Przelicz_i_Zapisz_Wierzcholki(std::ostream &StrmWy, std::istream &StrmWe);
  bool Przelicz_i_Zapisz_Wierzcholki();
};

#endif
