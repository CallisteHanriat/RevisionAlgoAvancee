/* 
 * File:   main.cpp
 * Author: hb
 *
 * Created on 10 octobre 2014, 17:42
 */

#include <forward_list>     // pour la liste chaînée avant
#include <algorithm>        // pour find_if
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
 */
bool estPair(int val) {
    return ((val % 2) == 0);
}

/**
 * Premier entier pair
 * 
 * @param uneListe liste dans laquelle chercher le premier entier pair
 * @return itérateur sur l'élément qui contient le premier entier pair, uneListe.end()
 *                   si il n'y a pas d'entier pair dans uneListe
 */
forward_list<int>::iterator premierEntierPair(forward_list<int>& uneListe) {
    /*
     * A COMPLETER
     */
    // PUIS ENLEVER L'INSTRUCTION SUIVANTE
    return uneListe.begin();
}

/**
 * i-ème entier pair
 * 
 * INDICATION : l'algorithme qui utilise find_if(x, y, estPair) est plus simple
 *              que celui qui utilise uniquement estPair()
 * 
 * @param uneListe liste dans laquelle chercher le i-ème entier pair
 * @return itérateur sur l'élément qui contient le i-ème entier pair, uneListe.end()
 *                   si il n'y a pas de i-ème entier pair dans uneListe
 */
forward_list<int>::iterator iemeEntierPair(forward_list<int>& uneListe, int i) {
    /*
     * A COMPLETER
     */
    // PUIS ENLEVER L'INSTRUCTION SUIVANTE
    return uneListe.begin();
}

int main() {
    int posit;
    forward_list<int>::iterator iterListeInt;
    forward_list<int> listeMixte = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    forward_list<int> listePaire = {4, 6, 8, 10, 12};
    forward_list<int> listeImpaire = {1, 3, 5, 7, 9, 11};

    iterListeInt = premierEntierPair(listeMixte);
    if (iterListeInt != listeMixte.end()) {
        cout << "Le premier entier pair de la liste -> ";
        affiche(listeMixte);
        cout << "est : " << *iterListeInt << endl;
    } else {
        cout << "La liste -> ";
        affiche(listeMixte);
        cout << "ne contient pas d'entier pair !" << endl;
    }
    cout << endl;
    iterListeInt = premierEntierPair(listePaire);
    if (iterListeInt != listePaire.end()) {
        cout << "Le premier entier pair de la liste -> ";
        affiche(listePaire);
        cout << "est : " << *iterListeInt << endl;
    } else {
        cout << "La liste -> ";
        affiche(listePaire);
        cout << "ne contient pas d'entier pair !" << endl;
    }
    cout << endl;
    iterListeInt = premierEntierPair(listeImpaire);
    if (iterListeInt != listeImpaire.end()) {
        cout << "Le premier entier pair de la liste -> ";
        affiche(listeImpaire);
        cout << "est : " << *iterListeInt << endl;
    } else {
        cout << "La liste -> ";
        affiche(listeImpaire);
        cout << "ne contient pas d'entier pair !" << endl;
    }
    cout << endl;
    posit = 5;
    iterListeInt = iemeEntierPair(listeMixte, posit);
    if (iterListeInt != listeMixte.end()) {
        cout << "Le ";
        if (posit == 1) {
            cout << "premier";
        } else {
            cout << posit << "-ième";
        }
        cout << " entier pair de la liste -> ";
        affiche(listeMixte);
        cout << "est : " << *iterListeInt << endl;
    } else {
        cout << "La liste -> ";
        affiche(listeMixte);
        cout << "ne contient pas de ";
        if (posit == 1) {
            cout << "premier";
        } else {
            cout << posit << "-ième";
        }
        cout << " entier pair !" << endl;
    }
    cout << endl;
    posit = 1;
    iterListeInt = iemeEntierPair(listeMixte, posit);
    if (iterListeInt != listeMixte.end()) {
        cout << "Le ";
        if (posit == 1) {
            cout << "premier";
        } else {
            cout << posit << "-ième";
        }
        cout << " entier pair de la liste -> ";
        affiche(listeMixte);
        cout << "est : " << *iterListeInt << endl;
    } else {
        cout << "La liste -> ";
        affiche(listeMixte);
        cout << "ne contient pas de ";
        if (posit == 1) {
            cout << "premier";
        } else {
            cout << posit << "-ième";
        }
        cout << " entier pair !" << endl;
    }
    cout << endl;
    posit = 10;
    iterListeInt = iemeEntierPair(listeMixte, posit);
    if (iterListeInt != listeMixte.end()) {
        cout << "Le ";
        if (posit == 1) {
            cout << "premier";
        } else {
            cout << posit << "-ième";
        }
        cout << " entier pair de la liste -> ";
        affiche(listeMixte);
        cout << "est : " << *iterListeInt << endl;
    } else {
        cout << "La liste -> ";
        affiche(listeMixte);
        cout << "ne contient pas de ";
        if (posit == 1) {
            cout << "premier";
        } else {
            cout << posit << "-ième";
        }
        cout << " entier pair !" << endl;
    }

    return 0;
}

// Trace Attendue
/*
 Le premier entier pair de la liste -> 1 2 3 4 5 6 7 8 9 10 11 12 est : 2

Le premier entier pair de la liste -> 4 6 8 10 12 est : 4

La liste -> 1 3 5 7 9 11 ne contient pas d'entier pair !

Le 5-ième entier pair de la liste -> 1 2 3 4 5 6 7 8 9 10 11 12 est : 10

Le premier entier pair de la liste -> 1 2 3 4 5 6 7 8 9 10 11 12 est : 2

La liste -> 1 2 3 4 5 6 7 8 9 10 11 12 ne contient pas de 10-ième entier pair !

 */

