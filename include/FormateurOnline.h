#pragma once
#include"Formateur.h"
using namespace std;

class FormateurOnline : public Formateur {
private:
    string Jdispo;

public:
    FormateurOnline();
    FormateurOnline(Formateur,string="");
    void setJdispo(string jd){Jdispo = jd;}
    string getJdispo(){ return Jdispo; }
    void afficher();
    ~FormateurOnline();
    friend ostream& operator<< (ostream&, FormateurOnline&);
    friend istream& operator>> (istream&, FormateurOnline&);
};
