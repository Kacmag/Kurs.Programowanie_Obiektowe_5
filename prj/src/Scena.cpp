#include "Scena.hh"

void Scena::LaczeInit()
{
    Lacze.ZmienTrybRys(PzG::TR_3D);
    Lacze.XrangeSet(-ROMIAR_POWIERZCHNI_X / 2, ROMIAR_POWIERZCHNI_X / 2);
    Lacze.YrangeSet(-ROMIAR_POWIERZCHNI_Y / 2, ROMIAR_POWIERZCHNI_Y / 2);
    Lacze.ZrangeSet(-0, 90);
    Lacze.XZrotationSet(40, 60); // Tutaj ustawiany jest widok

    Lacze.Inicjalizuj(); // Tutaj startuje gnuplot.
}

Scena::Scena()
{
    Wektor3D prze;
    prze[0] = 70;

    Inicjalizuj_PowierzchnieMarsa(Lacze);

    prze[0] = 70;
    shared_ptr<Hover> Ob1 = make_shared<Hover>("bryly_wzorcowe/szescian3.dat", "FSR", Kolor_JasnoNiebieski);
    Ob1->set_movement() = prze;
    lista_obiektow.push_back(Ob1);

    shared_ptr<Hover> Ob2 = make_shared<Hover>("bryly_wzorcowe/szescian3.dat", "Perseverance", Kolor_Czerwony);
    prze[0] = -70;
    Ob2->set_movement() = prze;
    lista_obiektow.push_back(Ob2);

    shared_ptr<Hover> Ob3 = make_shared<Hover>("bryly_wzorcowe/szescian3.dat", "Curiosity", Kolor_Czerwony);
    lista_obiektow.push_back(Ob3);

    latest = Ob1;

    DodajDoListyRysowania();
    LaczeInit();
    Rysuj();
    Lacze.Rysuj();
}

void Scena::wybierz_drona(int n)
{
    int j = 0;
    std::list<std::shared_ptr<Hover>>::iterator i = lista_obiektow.begin();
    for (; j < n; j++, i++)
    {
        latest = (*i);
    }
}
void Scena::Ruch(double angle, double droga, double pretkosc)
{

    latest->set_howFar() = droga;
    latest->set_speed() = pretkosc;
    latest->set_angle() = angle;
    latest->jazda(Lacze);
    latest->obrot(Lacze);
}

void Scena::Rysuj()
{
    Wektor3D wek;
    wek[0] = 20;
    wek[1] = 20;
    wek[2] = 10;
    for (std::list<std::shared_ptr<Hover>>::iterator i = lista_obiektow.begin(); i != lista_obiektow.end(); i++)
    {
        (*i)->set_scale() = wek;
        (*i)->Przelicz_i_Zapisz_Wierzcholki();
    }
}

void Scena::DodajDoListyRysowania()
{
    PzG::InfoPlikuDoRysowania *wInfoPliku;
    for (std::list<std::shared_ptr<Hover>>::iterator i = lista_obiektow.begin(); i != lista_obiektow.end(); i++)
    {

        wInfoPliku = &Lacze.DodajNazwePliku((*i)->WezNazwePliku_BrylaRysowana());
        wInfoPliku->ZmienKolor((*i)->WezKolorID());
    }
}

void Scena::wypisz()
{
    int j = 0;

    for (std::list<std::shared_ptr<Hover>>::iterator i = lista_obiektow.begin(); i != lista_obiektow.end(); i++)
    {
        j++;
        std::cout << j << ":" << (*i)->WezNazweObiektu() << std::endl;
    }
}