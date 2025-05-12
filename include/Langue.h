#pragma once
#include<iostream>
#include<string>
using namespace std;

class Langue
{
    string nom;
    string niveau;
    public:
        Langue(string nom = "",string niveau = "");

        string getNom() { return nom; }
        string getNiveau() { return niveau; }
        void setNom(string n) { nom = n; }
        void setNiveau(string n) { niveau = n; }
        bool operator==(const Langue&);
        void afficherLangue() ;
        void saisirLangue();
        ~Langue();
        friend ostream& operator<< (ostream&, Langue&);
        friend istream& operator>> (istream&, Langue&);
};

