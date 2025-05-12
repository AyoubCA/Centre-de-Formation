#pragma once
#include<iostream>
#include"Formateur.h"
#include "FormateurSpec.h"
#include "FormateurOnline.h"
#include <vector>
using namespace std;

class CentreFormation
{
vector<Formateur*> tab;
public:
    CentreFormation();
    CentreFormation(const CentreFormation&);
    ~CentreFormation();
    void saisircentre();
    void afficher();
    void supprimer();
    void ajouter(Formateur,int=0);
    void ajouter(FormateurSpec,int=0);
    void ajouter(FormateurOnline,int=0);
    void ajouter(Formateur*,int=0);
    void FormC1Dans2Lang();     //chercher Formateur ayant C1 Dans 2 Langues
    void FormParSpec(string); // chercher formateur ayant la specialite cherchee
    void FormOnlDisp(string); //disponibilite d un formateur online dans un jour donnee
    void FormParLangEtNiv(string, string);//chercher un formateur par langue et niveau
    void FormAvecPlusDeSpec(int); //chercher formateur ayant plus du nb donne de specialites
    friend ostream& operator<< (ostream&, CentreFormation&);
    friend istream& operator>> (istream&, CentreFormation&);
};
