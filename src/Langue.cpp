#include "Langue.h"
using namespace std;
Langue::Langue(string no,string niv) : nom(no), niveau(niv) {}
Langue::~Langue() {}

void Langue::afficherLangue()  {
    cout << "Langue : " << nom << "\t Niveau : " << niveau << "\n";
}
void Langue::saisirLangue(){
    cout<<"Saisir le nom de langue : "<<endl;
    cin>>nom;
    cout<<"Donner le niveau de formateur dans cette langue : "<<endl;
    cin>>niveau;
}
ostream& operator<< (ostream& out, Langue& L)
{
    out << "Langue : " << L.nom << "\t Niveau : " << L.niveau << "\n";
    return out;
}
istream& operator>> (istream& in, Langue& L)
{
    cout<<"Saisir le nom de langue : "<<endl;
    in>>L.nom;
    cout<<"Donner le niveau de formateur dans cette langue : "<<endl;
    in>>L.niveau;
    return in;
}
bool Langue::operator==(const Langue& l1)
{
    return(nom == l1.nom);
}
