#include "CentreFormation.h"
#include <typeinfo>
using namespace std;
CentreFormation::CentreFormation() {}
void CentreFormation::saisircentre() {
    char choix;
    int indice = 0;
    do {
        cout << "Voulez-vous ajouter un formateur ? (o/n) : ";
        cin >> choix;

        if (choix == 'o' || choix == 'O') {
            int typeFormateur;
            cout << "Tapez 1 pour ajouter un Formateur, 2 pour un Formateur Specialise et 3 pour un formateur online : ";
            cin >> typeFormateur;

            if (typeFormateur == 1) {
                int cinn, nbl;
                string nom, prenom;
                cout << "Entrez le CIN : ";
                cin >> cinn;
                cout << "Entrez le nom : ";
                cin >> nom;
                cout << "Entrez le prenom : ";
                cin >> prenom;
                Formateur* f = new Formateur(cinn, nom, prenom);
                ajouter(f, indice);
                indice++;
            } else if (typeFormateur == 2) {
                int cinn, nbl; 
                string nom, prenom;
                cout << "Entrez le CIN : ";
                cin >> cinn;
                cout << "Entrez le nom : ";
                cin >> nom;
                cout << "Entrez le prenom : ";
                cin >> prenom;
                FormateurSpec* fs = new FormateurSpec(Formateur(cinn, nom, prenom));
                ajouter(fs, indice);
                indice++;
            }
            else if (typeFormateur == 3) {
                int cinn, nbl;
                string nom, prenom, jdispo;
                cout << "Entrez le CIN : ";
                cin >> cinn;
                cout << "Entrez le nom : ";
                cin >> nom;
                cout << "Entrez le prenom : ";
                cin >> prenom;
                cout << "Entrez le jour disponible : ";
                cin >> jdispo;
                FormateurOnline* fo = new FormateurOnline(Formateur(cinn, nom, prenom), jdispo);
                ajouter(fo, indice);
                indice++;
            }
            else {
                cout << "Choix invalide, aucun formateur ajoute." << endl;
            }
        }
    } while (choix == 'o' || choix == 'O');
}
CentreFormation::CentreFormation(const CentreFormation &cf)
{
    Formateur* q;
    for(int i=0;i<cf.tab.size();i++)
    {
        if (typeid (*cf.tab[i]) == typeid (Formateur))
        {
            q=new Formateur(*cf.tab[i]);
        }
        else if (typeid (*cf.tab[i]) == typeid (FormateurSpec))
        {
            q=new FormateurSpec(static_cast<const FormateurSpec&>(*cf.tab[i]));
        }
        else if (typeid (*cf.tab[i]) == typeid (FormateurOnline))
        {
            q=new FormateurOnline(static_cast<const FormateurOnline&>(*cf.tab[i]));
        }
        tab.push_back(q);
    }
}
void CentreFormation::ajouter(Formateur f,int i)
{
        if (i >= 0 && i <= tab.size()) {
            Formateur* formateur = new Formateur(f);
            tab.insert(tab.begin() + i, formateur);
        } else {
            cout << "Indice invalide, aucun formateur ajoute." << endl;
        }
}
void CentreFormation::ajouter(FormateurSpec fs,int i)
{
        if (i >= 0 && i <= tab.size()) {
            Formateur* formateur = new FormateurSpec(fs);
            tab.insert(tab.begin() + i, formateur);
        } else {
            cout << "Indice invalide, aucun formateur ajoute." << endl;
        }
}
void CentreFormation::ajouter(FormateurOnline fo,int i)
{
    if (i >= 0 && i <= tab.size()) {
        Formateur* formateur = new FormateurOnline(fo);
        tab.insert(tab.begin() + i, formateur);
    } else {
        cout << "Indice invalide, aucun formateur ajoute." << endl;
    }
}
void CentreFormation::ajouter(Formateur* formateur, int i) {
    if (i >= 0 && i <= tab.size()) {
        tab.insert(tab.begin() + i, formateur);
    } else {
        cout << "Indice invalide, aucun formateur ajoute." << endl;
    }
}
void CentreFormation::afficher()
{
    for (int i = 0; i < tab.size(); i++) {
        tab[i]->afficher();
        cout << endl;
}
}
CentreFormation::~CentreFormation()
{
    for (int i=0;i<tab.size();i++) {
        delete tab[i];
    }
    tab.clear();
}
void CentreFormation::supprimer() {
    int indice;
    cout << "Entrez l'indice du formateur a supprimer : ";
    cin >> indice;
    if (indice >= 0 && indice < tab.size()) {
        delete tab[indice];
        tab.erase(tab.begin() + indice);
        cout << "Formateur a l'indice " << indice << " a ete supprime." << endl;
    } else {
        cout << "Indice invalide, suppression impossible." << endl;
    }
}

void CentreFormation::FormC1Dans2Lang() {
    for (Formateur* f : tab) {
        int compteurC1 = 0;
        for (Langue* l : f->getLangues()) {
            if (l->getNiveau() == "C1") compteurC1++;
        }
        if (compteurC1 >= 2) {
            f->afficher();
        }
    }
}

void CentreFormation::FormParSpec(string specialite) {
    for (Formateur* f : tab) {
        FormateurSpec* fs = dynamic_cast<FormateurSpec*>(f);
        if (fs) {
            for (Specialite* s : fs->getSpecialites()) {
                if (s->getNom() == specialite) {
                    fs->afficher();
                    break;
                }
            }
        }
    }
}

void CentreFormation::FormOnlDisp(string jour) {
    for (Formateur* f : tab) {
        FormateurOnline* fo = dynamic_cast<FormateurOnline*>(f);;
        if (fo && fo->getJdispo()== jour) {
            fo->afficher();
        }
    }
}

void CentreFormation::FormParLangEtNiv(string langue, string niveauMin) {
    for (Formateur* f : tab) {
        for (Langue* l : f->getLangues()) {
            if (l->getNom() == langue && l->getNiveau() >= niveauMin) {
                f->afficher();
                break;
            }
        }
    }
}

void CentreFormation::FormAvecPlusDeSpec(int nombreMin) {
    for (Formateur* f : tab) {
        FormateurSpec* fs = dynamic_cast<FormateurSpec*>(f);
        if (fs && fs->getSpecialites().size() >= nombreMin) {
            fs->afficher();
        }
    }
}
ostream& operator<< (ostream& out, CentreFormation& cf)
{
    for (int i = 0; i < cf.tab.size(); i++) {
        cf.tab[i]->afficher();
        out << endl;
}
    return out;
}
istream& operator>> (istream& in, CentreFormation& cf) {
    char choix;
    int indice = 0;
    do {
        cout << "Voulez-vous ajouter un formateur ? (o/n) : ";
        in >> choix;

        if (choix == 'o' || choix == 'O') {
            int typeFormateur;
            cout << "Tapez 1 pour ajouter un Formateur, 2 pour un Formateur Specialise et 3 pour un formateur online : ";
            in >> typeFormateur;

            if (typeFormateur == 1) {
                Formateur* f = new Formateur();
                cin>>*f;
                cf.ajouter(f, indice);
                indice++;
            } else if (typeFormateur == 2) {
                FormateurSpec* fs = new FormateurSpec();
                cin>>*fs;
                cf.ajouter(fs, indice);
                indice++;
            } else if (typeFormateur == 3) {
                FormateurOnline* fo = new FormateurOnline();
                cin>>*fo;
                cf.ajouter(fo, indice);
                indice++;
            } else {
                cout << "Choix invalide, aucun formateur ajoute." << endl;
            }
        }
    } while (choix == 'o' || choix == 'O');

    return in;
}
