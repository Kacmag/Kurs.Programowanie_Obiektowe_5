#include "Vector3D.hh"
#include "matrix3D.hh"



class UkladWsp
{
  Wektor3D wsp;
  Wektor3D Skala;

  public:
  Wektor3D get_wspolrzedne()const{return wsp;}
  Wektor3D &set_wsp(){return wsp;}
  Wektor3D get_Scale()const{return Skala;}
  Wektor3D &set_Scale(){return Skala;}

};

