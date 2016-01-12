/* 
 * File:   main.cpp
 * Author: hb
 * 
 * TRACE ATTENDUE EN FIN DE FICHIER
 *
 */

#include <iostream>
#include <string>
#include "ListeTrieeChainee.h"

using namespace std;

/*
 *  /!\ TRACE ATTENDUE EN FIN DE FICHIER
 */


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

void testeGetPosit(ListeTrieeChainee<string>*& ptrListe) {
    cout << endl << "DEBUT testeGetPosit()" << endl << endl;
    cout << "La liste contient initialement : ";
    ptrListe->afficheCroissantRec();
    cout << endl << endl;
    cout << "Recherches de valeurs présentes ->" << endl;
    cout << " Postion de \"Ana\" : " << ptrListe->getPosit("Ana") << " ; devrait retourner 1" << endl;
    cout << " Postion de \"Jérôme\" : " << ptrListe->getPosit("Jérôme") << " ; devrait retourner 4" << endl;
    cout << " Postion de \"Sophie\" : " << ptrListe->getPosit("Sophie") << " ; devrait retourner 6" << endl;
    cout << endl << "Recherches de valeurs absentes ->" << endl;
    cout << " Postion de \"Adam\" : " << ptrListe->getPosit("Adam") << " ; devrait retourner -1" << endl;
    cout << " Postion de \"Jacques\" : " << ptrListe->getPosit("Jacques") << " ; devrait retourner -4" << endl;
    cout << " Postion de \"Violette\" : " << ptrListe->getPosit("Violette") << " ; devrait retourner -7" << endl;
    cout << endl << "FIN testeGetPosit()" << endl << endl;
}

void testeAffiche(ListeTrieeChainee<string>*& ptrListe) {
    cout << endl << "DEBUT testeAffiche()" << endl << endl;
    cout << "Dans l'ordre croissant avec une procédure récursive, la liste contient :" << endl << "   -> ";
    ptrListe->afficheCroissantRec();
    cout << endl;
    cout << "Dans l'ordre croissant avec une procédure itérative, la liste contient :" << endl << "   -> ";
    ptrListe->afficheCroissantIter();
    cout << endl;
    cout << endl << "DEBUT testeAffiche()" << endl << endl;
}

void testeInsereRec(ListeTrieeChainee<string>*& ptrListe) {
    cout << endl << "DEBUT testeInsertRec()" << endl << endl;
    cout << "La liste contient initialement : ";
    ptrListe->afficheCroissantRec();
    cout << endl << endl;
    cout << "Insertion de Adam en début de liste " << endl;
    ptrListe->insereRec("Adam");
    cout << "  -> la liste contient : ";
    ptrListe->afficheCroissantRec();
    cout << endl;
    cout << "Insertion de Jacques en milieu de liste " << endl;
    ptrListe->insereRec("Jacques");
    cout << "  -> la liste contient : ";
    ptrListe->afficheCroissantRec();
    cout << endl;
    cout << "Insertion de Violette en fin de liste " << endl;
    ptrListe->insereRec("Violette");
    cout << "  -> la liste contient : ";
    ptrListe->afficheCroissantRec();
    cout << endl;
    cout << endl << "FIN testeInsertRec()" << endl << endl;
}

void testeGetInfoAtPositRec(ListeTrieeChainee<string>*& ptrListe) {
    cout << endl << "DEBUT testeGetInfoAtPositRec()" << endl << endl;
    cout << "La liste contient initialement : ";
    ptrListe->afficheCroissantRec();
    cout << endl << endl;
    cout << "Recherches de valeurs présentes ->" << endl;
    cout << " Info en position 1 : " << ptrListe->getInfoAtPositRec(1) << " ; devrait retourner \"Ana\"" << endl;
    cout << " Info en position 4 : " << ptrListe->getInfoAtPositRec(4) << " ; devrait retourner \"Jérôme\"" << endl;
    cout << " Info en position 6 : " << ptrListe->getInfoAtPositRec(6) << " ; devrait retourner \"Sophie\"" << endl;
    cout << endl << "Recherches trop loin ->" << endl;
    try {
        cout << " Info en position 12 : ";
        cout << ptrListe->getInfoAtPositRec(12);
    } catch (PrecondVioleeExcep e) {
        cout << endl << "  !!! CA C'EST MAL PASSEE, VOICI POURQUOI ---> " << endl;
        cout << e.what() << endl;
        cout << "  !!! ENFIN ON A QUAND MEME RECUPERER LE COUP !" << endl;
    }
    cout << endl << "FIN testeGetInfoAtPositRec()" << endl << endl;
}

void testeSupprimeAtPositRec(ListeTrieeChainee<string>*& ptrListe) {
    cout << endl << "DEBUT testeSupprimeAtPositRec()" << endl << endl;
    cout << "La liste contient initialement : ";
    ptrListe->afficheCroissantRec();
    cout << endl << endl;
    ptrListe->supprimeAtPositRec(1);
    cout << "Après suppression en position 1 (le premier), la liste contient : ";
    ptrListe->afficheCroissantRec();
    cout << endl;
    ptrListe->supprimeAtPositRec(3);
    cout << "Après suppression en position 4 (au milieu),  la liste contient : ";
    ptrListe->afficheCroissantRec();
    cout << endl;
    ptrListe->supprimeAtPositRec(4);
    cout << "Après suppression en position 4 (le dernier), la liste contient : ";
    ptrListe->afficheCroissantRec();
    cout << endl;
    ptrListe->supprimeAtPositRec(4);
    cout << "Après suppression en position 4 (trop loin),  la liste contient : ";
    ptrListe->afficheCroissantRec();
    cout << endl;
    cout << endl << "FIN testeSupprimeAtPositRec()" << endl << endl;
}

void testeSupprimePremOccInfoRec(ListeTrieeChainee<string>*& ptrListe) {
    cout << endl << "DEBUT testeSupprimePremOccInfoRec()" << endl << endl;
    cout << "La liste contient initialement : ";
    ptrListe->afficheCroissantRec();
    cout << endl << endl;
    ptrListe->supprimePremOccInfoRec("Ana");
    cout << "Après suppression de \"Ana\" (le premier), la liste contient : ";
    ptrListe->afficheCroissantRec();
    cout << endl;
    ptrListe->supprimePremOccInfoRec("Jérôme");
    cout << "Après suppression de \"Jérôme\" (au milieu), la liste contient : ";
    ptrListe->afficheCroissantRec();
    cout << endl;
    ptrListe->supprimePremOccInfoRec("Sophie");
    cout << "Après suppression de \"Sophie\" (le dernier), la liste contient : ";
    ptrListe->afficheCroissantRec();
    cout << endl;
    ptrListe->supprimePremOccInfoRec("Adam");
    cout << "Après suppression de \"Adam\" (avant le premier), la liste contient : ";
    ptrListe->afficheCroissantRec();
    cout << endl;
    ptrListe->supprimePremOccInfoRec("Jacques");
    cout << "Après suppression de \"Jacques\" (entre deux valeurs au milieu), la liste contient : ";
    ptrListe->afficheCroissantRec();
    cout << endl;
    ptrListe->supprimePremOccInfoRec("Violette");
    cout << "Après suppression de \"Violette\" (après le dernier), la liste contient : ";
    ptrListe->afficheCroissantRec();
    cout << endl;
    cout << endl << "FIN testeSupprimePremOccInfoRec()" << endl << endl;
}

void testeValeursDupliquees(ListeTrieeChainee<string>*& ptrListe) {
    cout << endl << "DEBUT testeValeursDupliquees()" << endl << endl;
    cout << "La liste contient initialement : ";
    ptrListe->afficheCroissantRec();
    cout << endl << endl;
    cout << "Insertion de \"Francis\", \"Ana\", \"Francis\", \"Hervé\", \"Francis\", \"Philippe\"" << endl << "  -> ";
    ptrListe->insereRec("Francis");
    ptrListe->insereRec("Ana");
    ptrListe->insereRec("Francis");
    ptrListe->insereRec("Hervé");
    ptrListe->insereRec("Francis");
    ptrListe->insereRec("Philippe");
    cout << "La liste contient maintenant : ";
    ptrListe->afficheCroissantRec();
    cout << endl << endl;
    cout << "Recherches de valeurs présentes ->" << endl;
    cout << " Postion de \"Ana\" : " << ptrListe->getPosit("Ana") << " ; devrait retourner 1" << endl;
    cout << " Postion de \"Francis\" : " << ptrListe->getPosit("Francis") << " ; devrait retourner 3" << endl;
    cout << " Postion de \"Hervé\" : " << ptrListe->getPosit("Hervé") << " ; devrait retourner 7" << endl;
    cout << " Postion de \"Jérôme\" : " << ptrListe->getPosit("Jérôme") << " ; devrait retourner 9" << endl;
    cout << " Postion de \"Philippe\" : " << ptrListe->getPosit("Philippe") << " ; devrait retourner 10" << endl;
    cout << " Postion de \"Sophie\" : " << ptrListe->getPosit("Sophie") << " ; devrait retourner 12" << endl;
    ptrListe->supprimePremOccInfoRec("Ana");
    cout << endl << "Après suppression de la première occurrence de \"Ana\", la liste contient : " << endl << " -> ";
    ptrListe->afficheCroissantRec();
    cout << endl;
    ptrListe->supprimePremOccInfoRec("Jérôme");
    cout << endl << "Après suppression de la première et unique occurrence de \"Jérôme\", la liste contient : " << endl << " -> ";
    ptrListe->afficheCroissantRec();
    cout << endl;
    ptrListe->supprimePremOccInfoRec("Francis");
    cout << endl << "Après suppression de la première occurrence de \"Francis\", la liste contient : " << endl << " -> ";
    ptrListe->afficheCroissantRec();
    cout << endl;
    ptrListe->supprimePremOccInfoRec("Philippe");
    cout << endl << "Après suppression de la première occurrence de \"Philippe\", la liste contient : " << endl << " -> ";
    ptrListe->afficheCroissantRec();
    cout << endl;
    ptrListe->supprimePremOccInfoRec("Ana");
    cout << endl << "Après suppression de la première occurrence de \"Ana\", la liste contient : " << endl << " -> ";
    ptrListe->afficheCroissantRec();
    cout << endl;
    cout << endl << "FIN testeValeursDupliquees()" << endl << endl;
}

int main(int argc, char** argv) {

    ListeTrieeChainee<string>* ptrMaListe = new ListeTrieeChainee<string>();

    construitListe(ptrMaListe);
    
    testeGetPosit(ptrMaListe);

    testeAffiche(ptrMaListe);

    testeInsereRec(ptrMaListe);

    // réinitialisation de la liste
    construitListe(ptrMaListe);

    testeGetPosit(ptrMaListe);

    testeSupprimeAtPositRec(ptrMaListe);

    // réinitialisation de la liste
    construitListe(ptrMaListe);
    
    testeGetPosit(ptrMaListe);
    
    testeSupprimePremOccInfoRec(ptrMaListe);
    
    // réinitialisation de la liste
    //construitListe(ptrMaListe);
    
    //testeValeursDupliquees(ptrMaListe);

    return 0;
} // end main


/*
       TRACE ATTENDUE
 */
/*
DEBUT construitListe()

La liste initiale est-elle vide ? : 1 ; devrait répondre 1 (true)
Après 6 insertions la liste contient : 6 Cellules ; devrait répondre 6
La liste est elle vide ? : 0 ; devrait répondre 0 (false)

FIN construitListe()


DEBUT testeGetPosit()

La liste contient initialement : Ana Francis Hervé Jérôme Philippe Sophie 

Recherches de valeurs présentes ->
 Postion de "Ana" : 1 ; devrait retourner 1
 Postion de "Jérôme" : 4 ; devrait retourner 4
 Postion de "Sophie" : 6 ; devrait retourner 6

Recherches de valeurs absentes ->
 Postion de "Adam" : -1 ; devrait retourner -1
 Postion de "Jacques" : -4 ; devrait retourner -4
 Postion de "Violette" : -7 ; devrait retourner -7

FIN testeGetPosit()


DEBUT testeAffiche()

Dans l'ordre croissant avec une procédure récursive, la liste contient :
   -> Ana Francis Hervé Jérôme Philippe Sophie 
Dans l'ordre croissant avec une procédure récursive, la liste contient :
   -> 
Ana Francis Hervé Jérôme Philippe Sophie 
DEBUT testeAffiche()


DEBUT testeInsertRec()

La liste contient initialement : Ana Francis Hervé Jérôme Philippe Sophie 

Insertion de Adam en début de liste 
  -> la liste contient : Adam Ana Francis Hervé Jérôme Philippe Sophie 
Insertion de Jacques en milieu de liste 
  -> la liste contient : Adam Ana Francis Hervé Jacques Jérôme Philippe Sophie 
Insertion de Violette en fin de liste 
  -> la liste contient : Adam Ana Francis Hervé Jacques Jérôme Philippe Sophie Violette 

FIN testeInsertRec()


DEBUT construitListe()

La liste initiale est-elle vide ? : 1 ; devrait répondre 1 (true)
Après 6 insertions la liste contient : 6 Cellules ; devrait répondre 6
La liste est elle vide ? : 0 ; devrait répondre 0 (false)

FIN construitListe()


DEBUT testeGetInfoAtPositRec()

La liste contient initialement : Ana Francis Hervé Jérôme Philippe Sophie 

Recherches de valeurs présentes ->
 Info en position 1 : Ana ; devrait retourner "Ana"
 Info en position 4 : Jérôme ; devrait retourner "Jérôme"
 Info en position 6 : Sophie ; devrait retourner "Sophie"

Recherches trop loin ->
 Info en position 12 : 
  !!! CA C'EST MAL PASSEE, VOICI POURQUOI ---> 
Précondition non respectée : getInfoAtPositRec() appellée avec une liste vide où une position invalide !
  !!! ENFIN ON A QUAND MEME RECUPERER LE COUP !

FIN testeGetInfoAtPositRec()


DEBUT testeSupprimeAtPositRec()

La liste contient initialement : Ana Francis Hervé Jérôme Philippe Sophie 

Après suppression en position 1 (le premier), la liste contient : Francis Hervé Jérôme Philippe Sophie 
Après suppression en position 4 (au milieu),  la liste contient : Francis Hervé Philippe Sophie 
Après suppression en position 4 (le dernier), la liste contient : Francis Hervé Philippe 
Après suppression en position 4 (trop loin),  la liste contient : Francis Hervé Philippe 

FIN testeSupprimeAtPositRec()


DEBUT construitListe()

La liste initiale est-elle vide ? : 1 ; devrait répondre 1 (true)
Après 6 insertions la liste contient : 6 Cellules ; devrait répondre 6
La liste est elle vide ? : 0 ; devrait répondre 0 (false)

FIN construitListe()


DEBUT testeSupprimePremOccInfoRec()

La liste contient initialement : Ana Francis Hervé Jérôme Philippe Sophie 

Après suppression de "Ana" (le premier), la liste contient : Francis Hervé Jérôme Philippe Sophie 
Après suppression de "Jérôme" (au milieu), la liste contient : Francis Hervé Philippe Sophie 
Après suppression de "Sophie" (le dernier), la liste contient : Francis Hervé Philippe 
Après suppression de "Adam" (avant le premier), la liste contient : Francis Hervé Philippe 
Après suppression de "Jacques" (entre deux valeurs au milieu), la liste contient : Francis Hervé Philippe 
Après suppression de "Violette" (après le dernier), la liste contient : Francis Hervé Philippe 

FIN testeSupprimePremOccInfoRec()


DEBUT construitListe()

La liste initiale est-elle vide ? : 1 ; devrait répondre 1 (true)
Après 6 insertions la liste contient : 6 Cellules ; devrait répondre 6
La liste est elle vide ? : 0 ; devrait répondre 0 (false)

FIN construitListe()


DEBUT testeValeursDupliquees()

La liste contient initialement : Ana Francis Hervé Jérôme Philippe Sophie 

Insertion de "Francis", "Ana", "Francis", "Hervé", "Francis", "Philippe"
  -> La liste contient maintenant : Ana Ana Francis Francis Francis Francis Hervé Hervé Jérôme Philippe Philippe Sophie 

Recherches de valeurs présentes ->
 Postion de "Ana" : 1 ; devrait retourner 1
 Postion de "Francis" : 3 ; devrait retourner 3
 Postion de "Hervé" : 7 ; devrait retourner 7
 Postion de "Jérôme" : 9 ; devrait retourner 9
 Postion de "Philippe" : 10 ; devrait retourner 10
 Postion de "Sophie" : 12 ; devrait retourner 12

Après suppression de la première occurrence de "Ana", la liste contient : 
 -> Ana Francis Francis Francis Francis Hervé Hervé Jérôme Philippe Philippe Sophie 

Après suppression de la première et unique occurrence de "Jérôme", la liste contient : 
 -> Ana Francis Francis Francis Francis Hervé Hervé Philippe Philippe Sophie 

Après suppression de la première occurrence de "Francis", la liste contient : 
 -> Ana Francis Francis Francis Hervé Hervé Philippe Philippe Sophie 

Après suppression de la première occurrence de "Philippe", la liste contient : 
 -> Ana Francis Francis Francis Hervé Hervé Philippe Sophie 

Après suppression de la première occurrence de "Ana", la liste contient : 
 -> Francis Francis Francis Hervé Hervé Philippe Sophie 

FIN testeValeursDupliquees()
 */
