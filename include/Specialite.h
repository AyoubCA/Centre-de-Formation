#pragma once
#include <iostream>
#include <string>
using namespace std;

class Specialite {
private:
    string nom;
    string description;
public:
    Specialite(string nom = "",string desc = "");
    ~Specialite();
    string getNom() { return nom; }
    string getDescription() { return description; }
    void setNom(string n) { nom = n; }
    void setDescription(string d) { description = d; }
    void saisirSpecialite();
    void afficherSpecialite() ;
    friend ostream& operator<< (ostream&, Specialite&);
    friend istream& operator>> (istream&, Specialite&);
};
