#include "FormateurSpec.h"
#include <iostream>
#include <algorithm>
using namespace std;
FormateurSpec::FormateurSpec() : Formateur() {}

FormateurSpec::FormateurSpec(Formateur f) : Formateur(f) {
    char choix;
    do {
        Specialite *l= new Specialite() ;
        l->saisirSpecialite();
        specialites.push_back(l);
        cout << "Voulez-vous ajouter une autre specialite ? (o/n) : ";
        cin >> choix;
    } while (choix == 'o' || choix == 'O');
}

FormateurSpec::FormateurSpec(const FormateurSpec& autre): Formateur(autre)
{
    for(int i = 0; i < autre.specialites.size(); i++)
    {
        Specialite* nouvelleSpecialite = new Specialite(*(autre.specialites[i]));
        specialites.push_back(nouvelleSpecialite);
    }
}
void FormateurSpec::ajouterSpecialite(Specialite* s) {
    specialites.push_back(s);
}

void FormateurSpec::retirerSpecialite() {
    int indice;
    cout << "Entrez l'indice du specialite a supprimer : ";
    cin >> indice;
    if (indice >= 0 && indice < specialites.size()) {
        specialites.erase(specialites.begin() + indice);
        cout << "specialite a l'indice " << indice << " a ete supprimee." << endl;
    } else {
        cout << "Indice invalide, suppression impossible." << endl;
    }
}

void FormateurSpec::afficher() {
    Formateur::afficher();
    for(Specialite* s : specialites) {
        s->afficherSpecialite();
    }
}

FormateurSpec::~FormateurSpec() {
    for(int i=0; i<specialites.size(); i++)
        delete specialites[i];

    specialites.clear();
}
ostream& operator<< (ostream& out, FormateurSpec& fs)
{
    out<<static_cast<Formateur&>(fs);
    for(Specialite* s : fs.specialites) {
        cout<<*s;
    }
    return out;
}
istream& operator>> (istream& in, FormateurSpec& fs) {
    in >> static_cast<Formateur&>(fs);
    char choix;
    do {
        Specialite* l = new Specialite();
        cin>>*l;
        fs.specialites.push_back(l);
        cout << "Voulez-vous ajouter une autre specialite ? (o/n) : ";
        in >> choix;
    } while (choix == 'o' || choix == 'O');

    return in;
}
