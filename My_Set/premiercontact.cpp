/* 
 * File:   main.cpp
 * Author: hb
 *
 */

// Documentation à http://www.cplusplus.com/reference/set/set/
// Documentation à http://www.cplusplus.com/reference/algorithm/

#include <set>          // pour les ensembles
#include <algorithm>    // pour les algos déjà faits
#include <string>       // pour les chaînes
#include <iostream>
#include <cstdlib>
#include "PrecondVioleeExcep.h"

using namespace std;

template<class T>
void affiche(set<T>& monEnsemble) {
    for (T elem : monEnsemble) {
        cout << elem << " ";
    }
}

void testeCopieEnsemble() {

    cout << "DEBUT testeCopieEnsemble() :" << endl << endl;
    set<string> ensembleInitial;
    set<string> ensembleCopie;
    //Ensemble initial avant copie : cinq deux quatre trois un zéro
    //Ensemble copié : cinq deux quatre trois un zéro
    //Ensemble initial après copie : cinq deux quatre trois un zéro
    ensembleInitial.insert("cinq");
    ensembleInitial.insert("deux");
    ensembleInitial.insert("quatre");
    ensembleInitial.insert("trois");
    ensembleInitial.insert("un");
    ensembleInitial.insert("zero");
    
    for (auto it : ensembleInitial) {
        ensembleCopie.insert(it);
    }
    
    cout << "On doit avoir le même ensemble qu'avant copie !" << endl << endl;
    cout << "Ensemble initial avant copie : "; affiche(ensembleInitial); cout << endl;
    cout << "Ensemble copié : "; affiche(ensembleCopie);   cout << endl;
    cout << "Ensemble initial après copie : "; affiche(ensembleInitial); cout << endl;
    cout << "FIN testeCopieEnsemble() !" << endl << endl;
} // end copieEnsemble

/**
 * retourner l'élément à laPosition dans monEnsemble
 * @param monEnsemble
 * @param laPosition
 * @return element à laPosition dans monEnsemble, s'il existe
 *                 lève une exception PrecondVioleeExcep sinon
 */
template<typename TypeElem>
TypeElem getElemAtPosition(set<TypeElem> monEnsemble, int laPosition) throw (PrecondVioleeExcep) {
    // Enforce precondition
    bool estPresente = (laPosition >= 1) && (laPosition <= monEnsemble.size());
    if (estPresente) {
        /*
         * completer le code
         */
        // SUPRRIMER LA LIGNE CI-DESSOUS
        return *monEnsemble.begin();
    } else {
        string message = "getValeurAPosition() appellée avec une liste vide où une position invalide !";
        throw (PrecondVioleeExcep(message));
    } // end if
} // end getValeurAtPosition

/**
 * retourne la postion (numéroté à partir de 1) de monElement dans monEnsemble
 * 
 * AIDE : utiliser find() et distance()
 * @param monEnsemble dans lequel on cherche
 * @param monElement élément dont on cherche la position
 * @return indice de monElement dans monEnsemble si présent
 *         -indice de monElement si element non présent,
 *               indice = place de monElement devrait occuper dans monEnsemble
 */
template<typename TypeElem>
int getPositionDansEnsemble(set<TypeElem>& monEnsemble, TypeElem monElement) {
    int num = 1;
    auto tmp = monEnsemble.begin();
    
    while (*tmp < monElement) {
        tmp++;
        num++;
    }
    
    if (*tmp != monElement) 
        return -num;
    else
        return num;
    
} // end getPositionDansEnsemble

/**
 * supprime monElement de monEnsemble
 * 
 * AIDE : utiliser find() et erase()
 * @param monEnsemble
 * @param monElement
 * @return true si monElement était présent avant suppression
 *         false si nomElemenet était absent avant supprsion
 */
template<typename TypeElem>
bool supprimeElement(set<TypeElem>& monEnsemble, TypeElem monElement) {
    // On va chercher puis effacer
    // mon monElement
    /*
     * completer le code
     */
    // SUPRRIMER LA LIGNE CI-DESSOUS
    return true;
} // end supprimeElement

void testeEnsembleString(set<string> lEnsemble) {
    cout << endl << "DEBUT testeEnsembleString() :" << endl;

    //L'ensemble est-il vide ? :
    // -> Oui !
    
    cout << "L'ensemble est il vide ? " << endl;
    cout << "->";
    if(lEnsemble.empty())
        cout << "Oui !";
    else
        cout << "Non ! ";
    cout << endl << endl;
    
    
    //L'ensemble devrait contenir : 
    //---  Ana Francis Hervé Jérôme Philippe Sophie
    cout << "L'ensemble devrait contenir : ";
    cout << endl;
    //Il contient : 
    //---  Ana Francis Hervé Jérôme Philippe Sophie 
    cout << "Il contient : ";
    
    lEnsemble.insert("Ana");
    lEnsemble.insert("Francis");
    lEnsemble.insert("Hervé");
    lEnsemble.insert("Jérôme");
    lEnsemble.insert("Philippe");
    lEnsemble.insert("Sophie");
    
    affiche(lEnsemble);
    
    cout << endl;
    //Hervé est à la position 3
    auto itRecherche = lEnsemble.find("Hervé");
    cout << "Hervé est à la position : "; 
    cout << getPositionDansEnsemble(lEnsemble, *itRecherche) << endl;
    //Philippe est à la position 5
    cout << "Philippe est à la position "; 
    itRecherche = lEnsemble.find("Philippe");
    cout << getPositionDansEnsemble(lEnsemble, *itRecherche) << endl;
    cout << endl;
    //Jérôme est à la position 4
    //Francis est à la position 2
    //Ana est à la position 1
    //Sophie est à la position 6
    //
    //--- Cédric n'est pas présent, il devrait occuper la position 2 dans l'ensemble -> Ana Francis Hervé Jérôme Philippe Sophie 
    itRecherche = lEnsemble.find("Cédric");
    itRecherche--;
    cout << "Cédric n'est pas présent, il devrait occuper la position ";
    cout << getPositionDansEnsemble(lEnsemble, *itRecherche) << endl;
    //--- Agnès n'est pas présent, elle devrait occuper la position 1 dans l'ensemble -> Ana Francis Hervé Jérôme Philippe Sophie 
    //
    //--- Yann n'est pas présent, il devrait occuper la position 7 dans l'ensemble -> Ana Francis Hervé Jérôme Philippe Sophie 
    //
    //Teste size() et getElemAtPosition() :
    //--- L'ensemble contient 6 éléments, comme suit :
    // Ana Francis Hervé Jérôme Philippe Sophie
    //
    //Teste supprime() : 
    //--> Suppression du premier élément (Ana) : 1 ; doit rendre 1 (vrai)
    //--> Après la suppression de Ana l'ensemble contient 5   éléments, comme suit : Francis Hervé Jérôme Philippe Sophie 
    //--> Suppression au milieu de l'ensemble (Jérome) : 1 ; doit rendre 1 (vrai)
    //--> Après la suppression de Jérôme l'ensemble contient 4   éléments, comme suit : Francis Hervé Philippe Sophie 
    //--> Supression du dernier élément (Sophie) : 1 ; doit rendre 1 (vrai)
    //--> Après la suppression de Sophie l'ensemble contient 3   éléments, comme suit : Francis Hervé Philippe 
    //--> Supression d'un éléméent absent (Cédric) : 0 ; doit rendre 0 (false)
    //--> Supression d'un éléméent absent (Agnès) : 0 ; doit rendre 0 (false)
    //--> Supression d'un éléméent absent (Yann) : 0 ; doit rendre 0 (false)
    cout << endl;
    lEnsemble.erase("Ana");
    //L'ensemble contient 3   éléments, comme suit : Francis Hervé Philippe 
    cout << "Ensemble contient ";
    affiche(lEnsemble);
    cout << endl;
    //Elle devrait contenir Francis Hervé Philippe !
    //
    //Teste insert() méthode de la classe set
    //--> insertion en tête de Agnès
    //Agnès Francis Hervé Philippe 
    //--> insertion en seconde position de Cédric
    //Agnès Cédric Francis Hervé Philippe 
    //--> insertion en queue de Yann
    //Agnès Cédric Francis Hervé Philippe Yann 
    //--> insertion de Agnès une seconde fois (en tête ?) -- l'ensemble devrait être inchangé
    //Agnès Cédric Francis Hervé Philippe Yann 
    //--> insertion de Cédric une seconde fois (au milieu ?) -- l'ensemble devrait être inchangé
    //Agnès Cédric Francis Hervé Philippe Yann 
    //--> insertion de Yann une seconde fois (avant la fin ?) -- l'ensemble devrait être inchangé
    //Agnès Cédric Francis Hervé Philippe Yann 
    //
    //Teste clear() : 
    //--> OK, l'ensemble est vide après vider() !

    cout << endl << "FIN testeEnsembleString() !" << endl << endl;

} // end testeEnsemble

void creeEnsembleEntiersImpairs(set<int>& lEnsemble) {
    for (int i = 1; i <= 100; i = i + 2) {
        lEnsemble.insert(i);
    }
}

void creeEnsembleMutliples(set<int>& maTable, int multiple) {
    for (int i = multiple; i <= 100; i = i + multiple) {
        maTable.insert(i);
    }
}

void testeOperationsEnsemblistes() {
    cout << "DEBUT testeOperationsEnsemblistes() :" << endl;
    set<int> multiplesDe2, multiplesDe3, multiplesDe4, multiplesDe5, multiplesDe6, multiplesDe7, multiplesDe8, multiplesDe9, multiplesDe10, multiplesDe21;
    set<int> entiersInf100, entiersImpairsInf100;

    creeEnsembleMutliples(entiersInf100, 1);
    creeEnsembleMutliples(multiplesDe2, 2);
    creeEnsembleMutliples(multiplesDe3, 3);
    creeEnsembleMutliples(multiplesDe4, 4);
    creeEnsembleMutliples(multiplesDe5, 5);
    creeEnsembleMutliples(multiplesDe6, 6);
    creeEnsembleMutliples(multiplesDe7, 7);
    creeEnsembleMutliples(multiplesDe8, 8);
    creeEnsembleMutliples(multiplesDe9, 9);
    creeEnsembleMutliples(multiplesDe21, 21);

    creeEnsembleEntiersImpairs(entiersImpairsInf100);

    /*
     * A COMPLETER POUR RESPECTER LA TRACE SUIVANTE
     */

    //Teste de l'égalité de 2 emsembles :
    //   égalité de deux ensembles égaux : 1 ; devrait rendre 1 (true)
    //   égalité de deux ensembles égaux : 0 ; devrait rendre 0 (false)
    
    //Teste de l'inculsion :
    //   j'ai une cardinalité supéreure à B : 
    //    -> les mutliples de 2 sont-ils des multiples de 3 :0 ; devrait rendre 0 (false)
    //   je suis égal à B : 
    //    -> les mutliples de 2 sont-ils des multiples de 2 :1 ; devrait rendre 1 (true)
    //   j'ai une cardinalité < à B et je suis inclus : 
    //    -> les mutliples de 9 sont-ils des multiples de 3 :0 ; devrait rendre 1 (true)
    //   j'ai une cardinalité < à B et je ne suis pas inclus: 
    //    -> les mutliples de 9 sont-ils des multiples de 5 :0 ; devrait rendre 0 (false)
    //
    //Teste de contient :
    //   8 est-il un multiple de 2 : 1 ; devrait rendre 1 (true)
    //   7 est-il un multiple de 2 : 0 ; devrait rendre 0 (false)
    //
    //Teste de l'intersection et de sa commutativité :
    //   Les multiples de 2 et de 4 sont : 4 8 12 16 20 24 28 32 36 40 44 48 52 56 60 64 68 72 76 80 84 88 92 96 100 
    //   Les multiples de 4 et de 2 sont : 4 8 12 16 20 24 28 32 36 40 44 48 52 56 60 64 68 72 76 80 84 88 92 96 100 
    //   Les deux ensembles devraient contenir les mêmes valeurs ! (sinon il faut corriger le code)
    //
    //   Les entiers à la fois pairs et impairs (intersection multipleDe2 et entierImpairs) sont : 
    //   L'ensemble devrait être vide ! (sinon il faut corriger le code)
    //
    //Teste de l'union et de sa commutativité :
    //
    //   L'union des entiers pairs et impairs (union multipleDe2 et entierImpairs) est : 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100 
    //   L'ensemble devrait être égal à l'ensemble des entiers inférieurs ou égal à 100 ! (sinon il faut corriger le code)
    //   L'égalité de ces deux ensembles retourne : 1 ; ce devrait être 1 (true)
    //
    //   L'union des entiers impairs et pairs (union entierImpairs et multipleDe2) est : 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100 
    //   L'ensemble devrait être aussi égal à l'ensemble des entiers inférieurs ou égal à 100 ! (sinon il faut corriger le code)
    //   L'égalité de ces deux ensembles retourne : 1 ; ce devrait être 1 (true)
    //
    //Teste du complémentaire :
    //
    //   Le complémentaire des entiers pairs (multiplesDe2) avec l'ensemble de référence entierInf100 est : 1 3 5 7 9 11 13 15 17 19 21 23 25 27 29 31 33 35 37 39 41 43 45 47 49 51 53 55 57 59 61 63 65 67 69 71 73 75 77 79 81 83 85 87 89 91 93 95 97 99 
    //   L'ensemble devrait être égale à l'ensemble des entiers impairs ! (sinon il faut corriger le code)
    //   L'égalité de ces deux ensembles retourne : 1 ; ce devrait être 1 (true)
    //
    //Teste de la différence :
    //
    //   Les entiers paires qui ne sont pas multiples de 4 sont : 2 6 10 14 18 22 26 30 34 38 42 46 50 54 58 62 66 70 74 78 82 86 90 94 98 
    //   L'ensemble devrait contenir les multiples de 2 qui ne sont pas multiples de 4 ! (sinon il faut corriger le code)
    //   L'intersection de cet ensemble avec les multiples de 4 devrait être vide : 
    //
    //Teste de la différence symétrique :
    //
    //   Les entiers multiplesDe3 ou multiplesDe7 qui ne sont pas à la fois multiplesDe3 et multiplesDe7 sont : 3 6 7 9 12 14 15 18 24 27 28 30 33 35 36 39 45 48 49 51 54 56 57 60 66 69 70 72 75 77 78 81 87 90 91 93 96 98 99 
    //   L'ensemble devrait contenir les multiples de 3 et les multiples de 7 qui ne sont pas multiples de 21 ! (sinon il faut corriger le code)
    //   Pour information les multiples de 21 sont : 21 42 63 84 
    //   L'intersection de cet ensemble avec les multiples de 21 devrait être vide : 

    cout << endl << "FIN testeOperationsEnsemblistes() !" << endl << endl;

} // end testeOperationsEnsemblistes

/*
 * 
 */
int main(int argc, char** argv) {
    /*
     * décommenter les instructions au fur et à mesure
     */

     testeCopieEnsemble();
     set<string> monEnsemble;
     testeEnsembleString(monEnsemble);
     testeOperationsEnsemblistes();
    return 0;
}

// TRACE ATTENDU
/*
DEBUT testeCopieEnsemble() :

Ensemble initial avant copie : cinq deux quatre trois un zéro
Ensemble copié : cinq deux quatre trois un zéro 
Ensemble initial après copie : cinq deux quatre trois un zéro 
On doit avoir le même ensemble qu'avant copie !

FIN testeCopieEnsemble() !


DEBUT testeEnsembleString() :

L'ensemble est-il vide ? :
 -> Oui !

L'ensemble devrait contenir : 
---  Ana Francis Hervé Jérôme Philippe Sophie
Il contient : 
---  Ana Francis Hervé Jérôme Philippe Sophie 
Hervé est à la position 3
Philippe est à la position 5
Jérôme est à la position 4
Francis est à la position 2
Ana est à la position 1
Sophie est à la position 6

--- Cédric n'est pas présent, il devrait occuper la position 2 dans l'ensemble -> Ana Francis Hervé Jérôme Philippe Sophie 

--- Agnès n'est pas présent, elle devrait occuper la position 1 dans l'ensemble -> Ana Francis Hervé Jérôme Philippe Sophie 

--- Yann n'est pas présent, il devrait occuper la position 7 dans l'ensemble -> Ana Francis Hervé Jérôme Philippe Sophie 

Teste size() et getElemAtPosition() :
--- L'ensemble contient 6 éléments, comme suit :
 Ana Francis Hervé Jérôme Philippe Sophie

Teste supprime() : 
--> Suppression du premier élément (Ana) : 1 ; doit rendre 1 (vrai)
--> Après la suppression de Ana l'ensemble contient 5   éléments, comme suit : Francis Hervé Jérôme Philippe Sophie 
--> Suppression au milieu de l'ensemble (Jérome) : 1 ; doit rendre 1 (vrai)
--> Après la suppression de Jérôme l'ensemble contient 4   éléments, comme suit : Francis Hervé Philippe Sophie 
--> Supression du dernier élément (Sophie) : 1 ; doit rendre 1 (vrai)
--> Après la suppression de Sophie l'ensemble contient 3   éléments, comme suit : Francis Hervé Philippe 
--> Supression d'un éléméent absent (Cédric) : 0 ; doit rendre 0 (false)
--> Supression d'un éléméent absent (Agnès) : 0 ; doit rendre 0 (false)
--> Supression d'un éléméent absent (Yann) : 0 ; doit rendre 0 (false)

L'ensemble contient 3   éléments, comme suit : Francis Hervé Philippe 
Elle devrait contenir Francis Hervé Philippe !

Teste insert() méthode de la classe set
--> insertion en tête de Agnès
Agnès Francis Hervé Philippe 
--> insertion en seconde position de Cédric
Agnès Cédric Francis Hervé Philippe 
--> insertion en queue de Yann
Agnès Cédric Francis Hervé Philippe Yann 
--> insertion de Agnès une seconde fois (en tête ?) -- l'ensemble devrait être inchangé
Agnès Cédric Francis Hervé Philippe Yann 
--> insertion de Cédric une seconde fois (au milieu ?) -- l'ensemble devrait être inchangé
Agnès Cédric Francis Hervé Philippe Yann 
--> insertion de Yann une seconde fois (avant la fin ?) -- l'ensemble devrait être inchangé
Agnès Cédric Francis Hervé Philippe Yann 

Teste clear() : 
--> OK, l'ensemble est vide après vider() !

FIN testeEnsembleString() !

DEBUT testeOperationsEnsemblistes() :

Teste de l'égalité de 2 emsembles :
   égalité de deux ensembles égaux : 1 ; devrait rendre 1 (true)
   égalité de deux ensembles égaux : 0 ; devrait rendre 0 (false)

Teste de l'inculsion :
   j'ai une cardinalité supéreure à B : 
    -> les mutliples de 2 sont-ils des multiples de 3 :0 ; devrait rendre 0 (false)
   je suis égal à B : 
    -> les mutliples de 2 sont-ils des multiples de 2 :1 ; devrait rendre 1 (true)
   j'ai une cardinalité < à B et je suis inclus : 
    -> les mutliples de 9 sont-ils des multiples de 3 :0 ; devrait rendre 1 (true)
   j'ai une cardinalité < à B et je ne suis pas inclus: 
    -> les mutliples de 9 sont-ils des multiples de 5 :0 ; devrait rendre 0 (false)

Teste de contient :
   8 est-il un multiple de 2 : 1 ; devrait rendre 1 (true)
   7 est-il un multiple de 2 : 0 ; devrait rendre 0 (false)

Teste de l'intersection et de sa commutativité :
   Les multiples de 2 et de 4 sont : 4 8 12 16 20 24 28 32 36 40 44 48 52 56 60 64 68 72 76 80 84 88 92 96 100 
   Les multiples de 4 et de 2 sont : 4 8 12 16 20 24 28 32 36 40 44 48 52 56 60 64 68 72 76 80 84 88 92 96 100 
   Les deux ensembles devraient contenir les mêmes valeurs ! (sinon il faut corriger le code)

   Les entiers à la fois pairs et impairs (intersection multipleDe2 et entierImpairs) sont : 
   L'ensemble devrait être vide ! (sinon il faut corriger le code)

Teste de l'union et de sa commutativité :

   L'union des entiers pairs et impairs (union multipleDe2 et entierImpairs) est : 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100 
   L'ensemble devrait être égal à l'ensemble des entiers inférieurs ou égal à 100 ! (sinon il faut corriger le code)
   L'égalité de ces deux ensembles retourne : 1 ; ce devrait être 1 (true)

   L'union des entiers impairs et pairs (union entierImpairs et multipleDe2) est : 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100 
   L'ensemble devrait être aussi égal à l'ensemble des entiers inférieurs ou égal à 100 ! (sinon il faut corriger le code)
   L'égalité de ces deux ensembles retourne : 1 ; ce devrait être 1 (true)

Teste du complémentaire :

   Le complémentaire des entiers pairs (multiplesDe2) avec l'ensemble de référence entierInf100 est : 1 3 5 7 9 11 13 15 17 19 21 23 25 27 29 31 33 35 37 39 41 43 45 47 49 51 53 55 57 59 61 63 65 67 69 71 73 75 77 79 81 83 85 87 89 91 93 95 97 99 
   L'ensemble devrait être égale à l'ensemble des entiers impairs ! (sinon il faut corriger le code)
   L'égalité de ces deux ensembles retourne : 1 ; ce devrait être 1 (true)

Teste de la différence :

   Les entiers paires qui ne sont pas multiples de 4 sont : 2 6 10 14 18 22 26 30 34 38 42 46 50 54 58 62 66 70 74 78 82 86 90 94 98 
   L'ensemble devrait contenir les multiples de 2 qui ne sont pas multiples de 4 ! (sinon il faut corriger le code)
   L'intersection de cet ensemble avec les multiples de 4 devrait être vide : 

Teste de la différence symétrique :

   Les entiers multiplesDe3 ou multiplesDe7 qui ne sont pas à la fois multiplesDe3 et multiplesDe7 sont : 3 6 7 9 12 14 15 18 24 27 28 30 33 35 36 39 45 48 49 51 54 56 57 60 66 69 70 72 75 77 78 81 87 90 91 93 96 98 99 
   L'ensemble devrait contenir les multiples de 3 et les multiples de 7 qui ne sont pas multiples de 21 ! (sinon il faut corriger le code)
   Pour information les multiples de 21 sont : 21 42 63 84 
   L'intersection de cet ensemble avec les multiples de 21 devrait être vide : 

FIN testeOperationsEnsemblistes() !
 */
