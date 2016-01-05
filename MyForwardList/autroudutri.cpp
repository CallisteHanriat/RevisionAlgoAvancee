/* 
 * File:   autroudutri.cpp
 * Author: hb
 *
 * Created on 11 octobre 2014, 11:06
 */

#include <forward_list>     // pour la liste chaînée avant
#include <algorithm>        // pour ...
#include <iostream>
#include <cstdlib>

using namespace std;

template<class T>
void affiche(forward_list<T> maListe) {
    for (T elem : maListe) {
        cout << elem << " ";
    }
}

/**
 * uneListe est-elle triée ?
 * @param uneListe
 * @return true si uneListe est triée, false sinon.
 */
template<class T>
bool estTriee(forward_list<T>& uneListe) {
    /*
     * A COMPLETER
     */
    // PUIS ENLEVER L'INSTRUCTION SUIVANTE
    return true;
}

/**
 * @pre uneListe est triée !! peut contenir des valeurs dupliquées
 * @param uneListe
 * @return une nouvelle liste triée contenant les éléments de listeSource
 *         sans valeur dupliquée
 */
template<class T>
forward_list<T> nouvelleListeTrieeSansDuplication(forward_list<T>& listeSource) {
    /*
     * A COMPLETER
     */
    // PUIS ENLEVER L'INSTRUCTION SUIVANTE
    return listeSource;
}

int main(int argc, char** argv) {
    forward_list<int>::iterator iterListeInt;
    forward_list<int> listeTriee = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    forward_list<int> listeVide = {};
    forward_list<int> liste1Element = {2};
    forward_list<int> listeNonTriee = {1, 2, 3, 7, 6, 7, 8, 9, 10};

    cout << "La liste qui contient -> ";
    affiche(listeVide);
    cout << endl;
    if (estTriee(listeVide)) {
        cout << " --> est triée !" << endl;
    } else {
        cout << " --> n'est pas triée !" << endl;
    }
    cout << endl;
    cout << "La liste qui contient -> ";
    affiche(liste1Element);
    cout << endl;
    if (estTriee(liste1Element)) {
        cout << " --> est triée !" << endl;
    } else {
        cout << " --> n'est pas triée !" << endl;
    }
    cout << endl;
    cout << "La liste qui contient -> ";
    affiche(listeTriee);
    cout << endl;
    if (estTriee(listeTriee)) {
        cout << " --> est triée !" << endl;
    } else {
        cout << " --> n'est pas triée !" << endl;
    }
    cout << endl;
    cout << "La liste qui contient -> ";
    affiche(listeNonTriee);
    cout << endl;
    if (estTriee(listeNonTriee)) {
        cout << " --> est triée !" << endl;
    } else {
        cout << " --> n'est pas triée !" << endl;
    }
    cout << endl;
    forward_list<int> listeTrieeAvecDupliques = {1, 1, 2, 2, 3, 3, 3, 4, 5, 5, 6, 7, 8, 9, 9};
    cout << "La liste avec éléments dupliqués contient -> ";
    affiche(listeTrieeAvecDupliques);
    cout << endl;
    forward_list<int> listeTrieeSansDuplique = nouvelleListeTrieeSansDuplication(listeTrieeAvecDupliques);
    cout << endl;
    cout << "La liste qui contient les mêmes élements sans dupliqué -> ";
    affiche(listeTrieeSansDuplique);
    cout << endl;

    return 0;
}

// TRACE ATTENDUE
/*
 La liste qui contient -> 
 --> est triée !

La liste qui contient -> 2 
 --> est triée !

La liste qui contient -> 1 2 3 4 5 6 7 8 9 10 11 12 
 --> est triée !

La liste qui contient -> 1 2 3 7 6 7 8 9 10 
 --> n'est pas triée !

La liste avec éléments dupliqués contient -> 1 1 2 2 3 3 3 4 5 5 6 7 8 9 9 

La liste qui contient les mêmes élements sans dupliqué -> 1 2 3 4 5 6 7 8 9 
 */

