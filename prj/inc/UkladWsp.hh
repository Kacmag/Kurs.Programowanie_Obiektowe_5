#include "Vector3D.hh"
#include "matrix_3D.hh"



class UkladWsp
{
  Wektor3D wsp;
  Wektor3D przesun;
  Wektor3D Skala;
  matrix_3D matrix_obrot;
  public:
  Wektor3D get_wspolrzedne()const{return wsp;}
  Wektor3D &set_wsp(){return wsp;}
    Wektor3D get_movement()const{return przesun;}
  Wektor3D &set_movement(){return przesun;}
    Wektor3D get_Scale()const{return Skala;}
  Wektor3D &set_Scale(){return Skala;}
    matrix_3D get_macierz_obr()const{return matrix_obrot;}
  matrix_3D &set_macierz_obr(){return matrix_obrot;}

};

