#include "FormateurOnline.h"
#include <iostream>
using namespace std;
FormateurOnline::FormateurOnline() : Formateur(), Jdispo("") {}
FormateurOnline::FormateurOnline(Formateur f,string j):Formateur(f),Jdispo(j) {}
FormateurOnline::~FormateurOnline(){}
void FormateurOnline::afficher()
{
    Formateur::afficher();
    cout<<"Disponible pour  : "<<Jdispo<<endl;
}
ostream& operator<< (ostream& out, FormateurOnline& fo)
{
    out << static_cast<Formateur&>(fo);
    out<<"Disponible pour  : "<<fo.Jdispo<<endl;
    return out;
}
istream& operator>> (istream& in, FormateurOnline& fo) {
    in >> static_cast<Formateur&>(fo);
    string j;
    cout << "Entrez les jours de disponibilite : ";
    in >> j;
    fo.Jdispo = j;

    return in;
}
