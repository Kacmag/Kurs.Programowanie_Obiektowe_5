#include "Hover.hh"
#include "Kolory.hh"
#include "PowierzchniaMarsa.hh"
#include <list>
#include <memory>
#include "lacze_do_gnuplota.hh"

class Scena
{
    PzG::LaczeDoGNUPlota Lacze;
    std::shared_ptr<Hover> latest;
    std::list<std::shared_ptr<Hover>> lista_obiektow;

    void LaczeInit()
    {
        Lacze.ZmienTrybRys(PzG::TR_3D);
        Lacze.XrangeSet(-ROMIAR_POWIERZCHNI_X / 2, ROMIAR_POWIERZCHNI_X / 2);
        Lacze.YrangeSet(-ROMIAR_POWIERZCHNI_Y / 2, ROMIAR_POWIERZCHNI_Y / 2);
        Lacze.ZrangeSet(-0, 90);
        Lacze.XZrotationSet(40, 60); // Tutaj ustawiany jest widok

        Lacze.Inicjalizuj(); // Tutaj startuje gnuplot.
    }

public:
    Scena()
    {
        LaczeInit();
        Inicjalizuj_PowierzchnieMarsa(Lacze);
        shared_ptr<Hover> Ob1 = make_shared<Hover>("bryly_wzorcowe/szescian3.dat", "FSR", Kolor_JasnoNiebieski);
        lista_obiektow.push_back(Ob1);
        shared_ptr<Hover> Ob2 = make_shared<Hover>("bryly_wzorcowe/szescian3.dat", "Perseverance", Kolor_Czerwony);
        lista_obiektow.push_back(Ob2);
        shared_ptr<Hover> Ob3 = make_shared<Hover>("bryly_wzorcowe/szescian3.dat", "Curiosity", Kolor_Czerwony);
        lista_obiektow.push_back(Ob3);
        latest = Ob1;
        Lacze.Rysuj();
    }
    void Rysuj()
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
     
        Lacze.Rysuj();

        cout << "Nacisnij klawisz ENTER, aby zakonczyc." << endl;
        cin.ignore(100, '\n');
    }

    void DodajDoListyRysowania()
    {
        PzG::InfoPlikuDoRysowania *wInfoPliku;
        for (std::list<std::shared_ptr<Hover>>::iterator i = lista_obiektow.begin(); i != lista_obiektow.end(); i++)
        {
            wInfoPliku = &Lacze.DodajNazwePliku((*i)->WezNazwePliku_BrylaRysowana());
            wInfoPliku->ZmienKolor((*i)->WezKolorID());
        }
    }

    std::shared_ptr<Hover> get_lazik(int n)
    {
        int j = 0;
        std::list<std::shared_ptr<Hover>>::iterator i = lista_obiektow.begin();
        for (; j < n; n++, i++)
        {
            std::cout << (*i)->WezNazweObiektu() << std::endl;
            ;
        }

        return *i;
    }
};
