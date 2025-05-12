#include "Specialite.h"
using namespace std;

Specialite::Specialite(string no,string desc) : nom(no), description(desc) {}
Specialite::~Specialite() {}

void Specialite::afficherSpecialite()  {
    cout << "Specialite: " << nom << "\t Description: " << description << "\n";
}
void Specialite::saisirSpecialite(){
    cout<<"Saisir le nom de specialite : "<<endl;
    cin>>nom;
    cout<<"Donner sa description : "<<endl;
    cin>>description;
}
ostream& operator<< (ostream& out, Specialite& S)
{
    out << "Specialite: " << S.nom << "\t Description: " << S.description << "\n";
    return out;
}
istream& operator>> (istream& in, Specialite& S)
{
    cout<<"Saisir le nom de specialite : "<<endl;
    in>>S.nom;
    cout<<"\nDonner sa description : "<<endl;
    in>>S.description;
    return in;
}
