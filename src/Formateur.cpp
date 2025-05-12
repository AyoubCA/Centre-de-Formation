#include "Formateur.h"
#include <iostream>
#include <string>
using namespace std;
Formateur::Formateur() : cinn(0), nom(""), prenom("") {}
Formateur::Formateur(int c,string Nom,string Prenom) : cinn(c),nom(Nom),prenom(Prenom)
{
    char choix;
    do {
        Langue *l= new Langue() ;
        l->saisirLangue();
        Langues.push_back(l);
        cout << "Voulez-vous ajouter une autre langue ? (o/n) : ";
        cin >> choix;
    } while (choix == 'o' || choix == 'O');
}
Formateur::Formateur(const Formateur& autre) : cinn(autre.cinn),nom(autre.nom),prenom(autre.prenom)
{
    for(int i = 0; i < autre.Langues.size(); i++)
    {
        Langue* nouvelleLangue = new Langue(*(autre.Langues[i]));
        Langues.push_back(nouvelleLangue);
    }
}

void Formateur::afficher()
{
    cout << "Cin: " <<cinn<< ", Nom: " << nom << ", Prenom: " <<prenom <<endl;

    for(int i=0;i<Langues.size();i++)
        Langues[i]->afficherLangue();

    cout<<endl;
}
void Formateur::retirerLangue(){
    int indice;
    cout << "Entrez l'indice du Langue a supprimer : ";
    cin >> indice;
    if (indice >= 0 && indice < Langues.size()) {
        Langues.erase(Langues.begin() + indice);
        cout << "Langue a l'indice " << indice << " a ete supprimee." << endl;
    } else {
        cout << "Indice invalide, suppression impossible." << endl;
    }
}
void Formateur::ajouterLangue(Langue* l){
    Langues.push_back(l);
}
Formateur::~Formateur()
{
    for(int i=0; i<Langues.size(); i++)
        delete Langues[i];

    Langues.clear();
}
ostream& operator<< (ostream& out , Formateur& f)
{
    out << "Cin: " <<f.cinn<< ", Nom: " << f.nom << ", Prenom: " <<f.prenom<<endl ;
    for(Langue* Lang:f.getLangues())
    cout<<*Lang;
    return out;
}
istream& operator>> (istream& in , Formateur& f)
{
    cout<<"Cin : ";
    in>>f.cinn;
    cout<<"\nNom : ";
    in>>f.nom;
    cout<<"\nPrenom : ";
    in>>f.prenom;
    char choix;
    do {
        Langue *l= new Langue() ;
        cin>>*l;
        f.Langues.push_back(l);
        cout << "Voulez-vous ajouter une autre langue ? (o/n) : ";
        in >>choix;
    } while (choix == 'o' || choix == 'O');;
    return in;
}
vector<Langue*> Formateur::operator-(const Formateur& autre)  {
    vector<Langue*> difference;
    for (Langue* LangAct : Langues) {
        bool trouve = false;
        for (Langue* LangAut : autre.Langues) {
            if (*LangAct == *LangAut) { 
                trouve = true;
                break;
            }
        }
        if (!trouve) {
            difference.push_back(LangAct);
        }
    }
    return difference;
}
