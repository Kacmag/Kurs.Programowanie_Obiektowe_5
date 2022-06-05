#ifndef WEKTOR_HH
#define WEKTOR_HH


#include <iostream>

using namespace std;

template <class S_Type, int S_Size>
class Vector
{
    S_Type Tablica[S_Size];

public:
    S_Type get_Tablica(int i) const;
    S_Type& set_Tablica(int i);
    S_Type operator[](int i) const;
    S_Type& operator[](int i);
    S_Type operator*(Vector const Skl);

    Vector operator+(Vector const Skl);
    Vector operator-(Vector const Skl);    
    Vector operator*(S_Type const Skl);
    Vector operator/(S_Type const Skl);
    Vector operator&(Vector const Skl);
};

template <class S_Type, int S_Size>
std::istream& operator>>(std::istream& Strm, Vector<S_Type, S_Size>& wek)
{
    for (int i = 0; i < S_Size; i++)
    {
        Strm >> wek[i];
    }

    return Strm;
}
template <class S_Type, int S_Size>
std::ostream& operator<<(std::ostream& Strm, const Vector<S_Type, S_Size>& wek)
{
    for (int i = 0; i < S_Size; i++)
        Strm << wek[i] << " ";

    return Strm;
}

template <class S_Type, int S_Size>
S_Type Vector<S_Type,S_Size>::get_Tablica(int i) const
{
    return Tablica[i];
}



template <class S_Type, int S_Size>
S_Type &Vector<S_Type,S_Size>::set_Tablica(int i)
{
    return Tablica[i];
}



template <class S_Type, int S_Size>
S_Type Vector<S_Type,S_Size>::operator*(Vector<S_Type,S_Size> const Skl)
{
    double Wynik = 0;
    for (int i = 0; i < S_Size; i++)
        Wynik += Tablica[i] * Skl[i];

    return Wynik;
}

template <class S_Type, int S_Size>
Vector<S_Type,S_Size> Vector<S_Type,S_Size>::operator&(Vector const Skl)
{
        Vector Wynik;
    for (int i = 0; i < S_Size; i++)
        Wynik[i] = Tablica[i] * Skl[i];

    return Wynik;
}

template <class S_Type, int S_Size>
Vector<S_Type,S_Size> Vector<S_Type,S_Size>::operator*(S_Type const Skl)
{
    Vector Wynik;
    for (int i = 0; i < S_Size; i++)
        Wynik[i] = Tablica[i] * Skl;

    return Wynik;
}



template <class S_Type, int S_Size>
Vector<S_Type,S_Size> Vector<S_Type,S_Size>::operator/(S_Type const Skl)
{
    Vector Wynik;
    for (int i = 0; i < S_Size; i++)
        Wynik[i] = Tablica[i] / Skl;

    return Wynik;
}


template <class S_Type, int S_Size>
S_Type Vector<S_Type,S_Size>::operator[](int i) const
{
    if (i >= 0 && i < S_Size)
        return Tablica[i];
    else
        cerr << "Blad indexu" << endl;
    return Tablica[i];
}



template <class S_Type, int S_Size>
S_Type &Vector<S_Type,S_Size>::operator[](int i)
{
    if (i >= 0 && i < S_Size)
        return Tablica[i];
    else
        cerr << "Blad indexu" << endl;
    return  Tablica[i];
}



template <class S_Type, int S_Size>
Vector<S_Type,S_Size> Vector<S_Type,S_Size>::operator+(Vector<S_Type,S_Size> const Skl)
{
    Vector Wynik;
    for (int i = 0; i < S_Size; i++)
        Wynik[i] = Tablica[i] + Skl[i];

    return Wynik;
}



template <class S_Type, int S_Size>
Vector<S_Type,S_Size> Vector<S_Type,S_Size>::operator-(Vector<S_Type,S_Size> const Skl)
{
    Vector Wynik;
    for (int i = 0; i < S_Size; i++)
        Wynik[i] = Tablica[i] - Skl[i];

    return Wynik;
}

#endif
