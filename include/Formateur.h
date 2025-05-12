#pragma once
#include <iostream>
#include <string>
#include "Langue.h"
#include<vector>
using namespace std;

class Formateur {
protected:
    int cinn;
    string nom;
    string prenom;
    vector<Langue*> Langues;
public:
    Formateur(int,string,string);
    Formateur(const Formateur&);
    Formateur();

    void setNom(string Nom){nom = Nom;}
    void setPrenom(string Prenom){prenom = Prenom;}
    void setCin(int Cin){cinn = Cin;}
    string getNom(){ return nom; }
    string getPrenom(){ return prenom; }
    int getCin(){return cinn;}
    vector<Langue*>& getLangues() { return Langues; }
    vector<Langue*> operator-(const Formateur&);
    void ajouterLangue(Langue* l);
    void retirerLangue();
    virtual void afficher();
    virtual ~Formateur();

    friend ostream& operator<< (ostream&, Formateur&);
    friend istream& operator>> (istream&, Formateur&);


};
