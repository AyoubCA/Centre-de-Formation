#pragma once
#include "Formateur.h"
#include "Specialite.h"
#include <vector>
using namespace std;

class FormateurSpec : public Formateur {
private:
    vector<Specialite*> specialites;

public:
    FormateurSpec();
    FormateurSpec(Formateur);
    FormateurSpec(const FormateurSpec&);
    const vector<Specialite*>& getSpecialites() const { return specialites; }
    void ajouterSpecialite(Specialite* s);
    void retirerSpecialite();
    void afficher();
    ~FormateurSpec();
    friend ostream& operator<< (ostream&, FormateurSpec&);
    friend istream& operator>> (istream&, FormateurSpec&);
};
