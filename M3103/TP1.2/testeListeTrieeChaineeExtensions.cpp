/*
 * POUR TESTER LES EXTENTIONS
 */

#include <iostream>
#include <string>
#include "ListeTrieeChainee.h"
#include <cstdlib>


using namespace std;

void construitListe(ListeTrieeChainee<string>*& ptrListe) {
    cout << endl << "DEBUT construitListe()" << endl << endl;

    // vider la liste
    ptrListe->vide();
    cout << "La liste initiale est-elle vide ? : " << ptrListe->estVide() << " ; devrait répondre 1 (true)" << endl;

    string herve = "Hervé";
    string philippe = "Philippe";
    string jerome = "Jérôme";
    string francis = "Francis";
    string ana = "Ana";
    string sophie = "Sophie";

    ptrListe->insere(herve);
    ptrListe->insere(philippe);
    ptrListe->insere(jerome);
    ptrListe->insere(francis);
    ptrListe->insere(ana);
    ptrListe->insere(sophie);

    cout << "Après 6 insertions la liste contient : " << ptrListe->getLongueur() << " Cellules ; devrait répondre 6" << endl;
    cout << "La liste est elle vide ? : " << ptrListe->estVide() << " ; devrait répondre 0 (false)" << endl;
    cout << endl << "FIN construitListe()" << endl << endl;
}

void compteNbOccInfo(ListeTrieeChainee<string>*& ptrListe) {
    cout << endl << "DEBUT compteNbOccInfo()" << endl << endl;
    string herve = "Hervé";
    string philippe = "Philippe";
    cout << "Nombre d'occurence de \"Hervé\" : " << ptrListe->compteNbOccInfoIter(herve) << endl;
    cout << "Nombre d'occurence de \"Philippe\" : " << ptrListe->compteNbOccInfoIter(philippe) << endl;
    cout << endl << "FIN compteNbOccInfo()" << endl << endl;
}

/*
 * faire vos tests vous-même
 */
int main(int argc, char** argv) {

    ListeTrieeChainee<string>* ptrMaListe = new ListeTrieeChainee<string>();

    construitListe(ptrMaListe);
    compteNbOccInfo(ptrMaListe);
    
    return EXIT_SUCCESS;
}