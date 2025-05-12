#include <iostream>
#include <string>
#include <vector>

#include "Formateur.h"
#include "FormateurSpec.h"
#include "FormateurOnline.h"
#include "CentreFormation.h"
#include "Langue.h"
#include "Specialite.h"

using namespace std;

int main() {
    Formateur formateur;
    FormateurSpec formateurSpec;
    FormateurOnline formateurOnline;
    CentreFormation centre;
    int choix;

    do {
        cout << "\n=== Menu Gestion Centre de Formation ===\n";
        cout << "1. Gestion d'un Formateur\n";
        cout << "2. Gestion d'un FormateurSpec\n";
        cout << "3. Gestiond d'un FormateurOnline\n";
        cout << "4. Gestion d'un CentreFormation\n";
        cout << "5. Verifier si deux langues sont Similaires !\n";
        cout << "6. Langues distincts entre deux Formateurs !\n"; //On a etudié une exception ici
        cout << "0. Quitter\n";
        cout << "Entrez votre choix : ";
        cin >> choix;

        switch (choix) {
            case 1:
            {
                int sousChoix;
                do {
                    cout << "\n--- Etudier Formateur ---\n";
                    cout << "1. Saisir un formateur\n";
                    cout << "2. Modifier nom\n";
                    cout << "3. Modifier prenom\n";
                    cout << "4. Afficher formateur\n";
                    cout << "5. Ajouter une langue\n";
                    cout << "6. Retirer une langue\n";
                    cout << "7. Afficher langues\n";
                    cout << "0. Retour\n";
                    cout << "Entrez votre choix : ";
                    cin >> sousChoix;

                    if (sousChoix == 1) {
                        cin >> formateur;
                        cout << "Formateur saisi. \n " << endl;
                    } else if (sousChoix == 2) {
                        string nom;
                        cout << "Entrez le nouveau nom : ";
                        cin>>nom;
                        formateur.setNom(nom);
                        cout << "Nom modifie.\n";
                    } else if (sousChoix == 3) {
                        string prenom;
                        cout << "Entrez le nouveau prenom : ";
                        cin>>prenom;
                        formateur.setPrenom(prenom);
                        cout << "Prenom modifie.\n";
                    } else if (sousChoix == 4) {
                        formateur.afficher();
                    } else if (sousChoix == 5) {
                        string nomLang, niveau;
                        cout << "Entrez le nom de la langue et le niveau : ";
                        cin>>nomLang>>niveau;
                        Langue l(nomLang,niveau);
                        formateur.ajouterLangue(&l);
                        cout << "Langue ajoutee.\n";
                    } else if (sousChoix == 6) {
                        formateur.retirerLangue();
                        cout << "Langue retiree .\n";
                    } else if (sousChoix == 7) {
                        const vector<Langue*>& langues = formateur.getLangues();
                        cout << "Langues du formateur :\n";
                            for (Langue* langue : langues) {
                            cout << *langue << endl;
                        }
                    } else if (sousChoix != 0) {
                        cout << "Choix invalide.\n";
                    }
                } while (sousChoix != 0);
                break;
            }

            case 2:
            {
                int sousChoix;
                do {
                    cout << "\n--- Etudier FormateurSpec ---\n";
                    cout << "1. Saisir un formateur specialise\n";
                    cout << "2. Ajouter une specialite\n";
                    cout << "3. Retirer une specialite\n";
                    cout << "4. Afficher formateur specialise\n";
                    cout << "5. Afficher specialites\n";
                    cout << "0. Retour\n";
                    cout << "Entrez votre choix : ";
                    cin >> sousChoix;

                    if (sousChoix == 1) {
                        cin >> formateurSpec;
                        cout << "Formateur specialise saisi. \n" << endl;
                    } else if (sousChoix == 2) {
                        Specialite spec;
                        cout << "Entrez la specialite : ";
                        cin>>spec;
                        formateurSpec.ajouterSpecialite(&spec);
                        cout << "Specialite ajoutee.\n";
                    } else if (sousChoix == 3) {
                        formateurSpec.retirerSpecialite();
                        cout << "Specialite retiree.\n";
                    } else if (sousChoix == 4) {
                        formateurSpec.afficher();
                    } else if (sousChoix == 5) {
                        const vector<Specialite*>& specialites = formateurSpec.getSpecialites();
                        cout << "Specialites du formateur specialise :\n";
                        for ( Specialite* spec : specialites) {
                            cout << *spec << endl;
                            }
                    } else if (sousChoix != 0) {
                        cout << "Choix invalide.\n";
                    }
                } while (sousChoix != 0);
                break;
            }

            case 3:
            {
                int sousChoix;
                do {
                    cout << "\n--- Etudier FormateurOnline ---\n";
                    cout << "1. Saisir un formateur online\n";
                    cout << "2. Modifier jour de disponibilite\n";
                    cout << "3. Afficher formateur online\n";
                    cout << "4. Afficher jour de disponibilite\n";
                    cout << "0. Retour\n";
                    cout << "Entrez votre choix : ";
                    cin >> sousChoix;

                    if (sousChoix == 1) {
                        cin >> formateurOnline;
                        cout << "Formateur online saisi. \n" <<  endl;
                    } else if (sousChoix == 2) {
                        string jdispo;
                        cout << "Entrez le nouveau jour de disponibilite : ";
                        cin>>jdispo;
                        formateurOnline.setJdispo(jdispo);
                        cout << "Jour de disponibilite modifie.\n";
                    } else if (sousChoix == 3) {
                        formateurOnline.afficher();
                    } else if (sousChoix == 4) {
                        cout << "Jour de disponibilite : " << formateurOnline.getJdispo() << endl;
                    } else if (sousChoix != 0) {
                        cout << "Choix invalide.\n";
                    }
                } while (sousChoix != 0);
                break;
            }

            case 4:
            {
                int sousChoix;
                do {
                    cout << "\n--- Etudier CentreFormation ---\n";
                    cout << "1. Saisir centre de formation\n";
                    cout << "2. Ajouter un formateur\n";
                    cout << "3. Afficher centre\n";
                    cout << "4. Supprimer formateurs\n";
                    cout << "5. Traitements\n";
                    cout << "0. Retour\n";
                    cout << "Entrez votre choix : ";
                    cin >> sousChoix;

                    if (sousChoix == 1) {
                        centre.saisircentre();
                        cout << "Centre de formation saisi.\n";
                    } else if (sousChoix == 2) {
                        int type;
                        cout << "Type de formateur : 1. Formateur, 2. FormateurSpec, 3. FormateurOnline : ";
                        cin >> type;
                        if (type == 1) {
                            Formateur f ;
                            cin>>f;
                            centre.ajouter(f);
                            cout << "Formateur ajoute.\n";
                        } else if (type == 2) {
                            FormateurSpec fs ;
                            cin>>fs;
                            centre.ajouter(fs);
                            cout << "FormateurSpec ajoute.\n";
                        } else if (type == 3) {
                            FormateurOnline fo ;
                            cin>>fo;
                            centre.ajouter(fo);
                            cout << "FormateurOnline ajoute.\n";
                        } else {
                            cout << "Type invalide.\n";
                        }
                    } else if (sousChoix == 3) {
                        centre.afficher();
                    } else if (sousChoix == 4) {
                        centre.supprimer();
                        cout << "Formateurs supprimes .\n";
                    }else if (sousChoix == 5){
                    int traitement;
                    do {
                    cout << "\n--- Traitements ---\n";
                    cout << "1. Chercher formateurs avec C1 dans 2 langues\n";
                    cout << "2. Chercher formateurs par specialite\n";
                    cout << "3. Chercher disponibilite d'un formateur online\n";
                    cout << "4. Chercher formateurs par langue et niveau\n";
                    cout << "5. Chercher formateurs avec plus de n specialites\n";
                    cout << "0. Retour\n";
                    cout << "Entrez votre choix : ";
                    cin >> traitement;

                    if (traitement == 1) {
                        centre.FormC1Dans2Lang();
                    } else if (traitement == 2) {
                        string spec;
                        cout << "Entrez la specialite : ";
                        cin>>spec;
                        centre.FormParSpec(spec);
                    } else if (traitement == 3) {
                        string jour;
                        cout << "Entrez le jour a verifier : ";
                        cin>>jour;
                        centre.FormOnlDisp(jour);
                    } else if (traitement == 4) {
                        string langue, niveau;
                        cout << "Entrez la langue : ";
                        cin>>langue;
                        cout << "Entrez le niveau : ";
                        cin>>niveau;
                        centre.FormParLangEtNiv(langue, niveau);
                    } else if (traitement == 5) {
                        int n;
                        cout << "Entrez le nombre minimum de specialites : ";
                        cin >> n;
                        centre.FormAvecPlusDeSpec(n);
                    } else if (traitement != 0) {
                        cout << "Choix invalide.\n";
                    }
                } while (traitement != 0);
                break;
                    }
                    else if (sousChoix != 0) {
                        cout << "Choix invalide.\n";
                    }
                } while (sousChoix != 0);
                break;
            }
            case 5:
            {
                Langue l1,l2;
                cout<<"Saisie du premier langue : "<<endl;
                cin>>l1;
                cout<<"Saisie du deuxieme langue : "<<endl;
                cin>>l2;
                if (l1==l2)
                {
                    cout<<"Meme Langue"<<endl;
                }
                else
                {
                    cout<<"Langues Differentes"<<endl;
                }
                break;
            }
            case 6:
            {
                Formateur f1,f2;
                cout<<"Saisie du premier formateur : "<<endl;
                cin>>f1;
                cout<<"Saisie du deuxieme formateur : "<<endl;
                cin>>f2;
                try
                {
                    if(f1.getCin() == f2.getCin()) throw runtime_error("deux formateurs ne peuvent pas avoir meme CIN !!!");
                    const vector<Langue*>& langues = f2-f1;
                    const vector<Langue*>& languess = f1-f2;
                    cout << "\n Langues distincts :\n";
                        for (Langue* langue : langues) {
                        cout << *langue << endl;
                    }
                    for (Langue* langue : languess) {
                        cout << *langue << endl;
                    }
                }
                catch(exception &e)
                {
                    cout<<e.what()<<endl;
                }
                break;

            }
            case 0:
                cout << "Arret du Programme\n";
                break;

            default:
                cout << "Choix invalide. Veuillez reessayer.\n";
        }
    } while (choix != 0);

    return 0;
}
