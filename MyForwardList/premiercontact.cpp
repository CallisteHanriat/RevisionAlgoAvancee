/* 
 * File:   main.cpp
 * Author: hb
 *
 */

/*
 * doc http://www.cplusplus.com/reference/forward_list/forward_list/
 * doc http://www.cplusplus.com/reference/stack/stack/
 */

#include <forward_list>     // pour la liste chaînée avant
#include <stack>            // pour la pile
#include <algorithm>        // pour le tri
#include <iostream>
#include <cstdlib>
#include "PrecondVioleeExcep.h"

using namespace std;

template<class T>
void affiche(forward_list<T> maListe) {
    for (T elem : maListe) {
        cout << elem << " ";
    }
}

/*
 * @param  maListeOriginale  liste à copier
 * @param  maListeCopie  copie de la liste (passage par référence pour pouvoir la mettre à jour !!
 */
template<typename TypeInfo>
void copieListe(forward_list<TypeInfo> maListeOriginale, forward_list<TypeInfo>& maListecopiee) {
    // pour conserver l'ordre dans la copie il faut :
    // 1 empiler les valeurs de la liste originale en faisant cun parcours complet gauche droite de la liste
    // 2 dépiler les valeurs de la liste originale en les insérant en tête de la copie
    // on peut au choix utiliser la ListeChaineePile déjà définie, une liste chainée en avant de la STL, ou une pile de la STL

    // AVEC UNE LISTE de la STL
    forward_list<TypeInfo> maCopieInversee;
    // étape 1
    for (TypeInfo& val : maListeOriginale) {
        maCopieInversee.push_front(val);
    } // end for
    // étape 2
    for (TypeInfo& val : maCopieInversee) {
        maListecopiee.push_front(val);
    } // end for
    
    /*
    // AVEC UNE PILE de la STL
    stack<TypeInfo> maPile;
    // étape 1
    for (TypeInfo& val : maListeOriginale) {
        maPile.push(val);
    } // end for
    // étape 2
    while (!maPile.empty()) {
        maListecopiee.push_front(maPile.top());
        maPile.pop();
    } // end while
    */
}

/**
 * Algorithme itératif avec un itérateur sur la liste
 * 
 * @param maListeOriginale
 * @param laPosition
 * @return information à laPosition dan laListe si laPosition Accessible
 *         lève une exception PrecondVioleeExcep si laPosition n'est pas accessible
 */
template<typename TypeInfo>
TypeInfo getInfoAtPosit(forward_list<TypeInfo> laListe, int laPosition) throw (PrecondVioleeExcep) {
    // version itérative
    // un itérateur sur la liste
    auto it = laListe.begin();
    int positionCourante = 1;
    // tantque l'on a pas atteint laPosition et que l'on est pas à la fin de la liste
    while ((positionCourante < laPosition) && (it != laListe.end())) {
        positionCourante++;
        // avancer dans la liste sur l'itérateur
        ++it;
    }
    if (it != laListe.end()) { // si on eu accès à laPosition
        // rendre l'élément pointé par l'itérateur
        return *it;
    } else { // sinon on lève une exception
        throw PrecondVioleeExcep("Accès imposible à l'indice " + to_string(laPosition));
    }
}

/**
 * Insertion itérative de nouvelleInfo à laPosition dans maListeOriginale
 * 
 * Lève une exception PrecondVioleeExcep si l'insertion n'est pas possible
 * 
 * @param maListeOriginale paramètre donnée résultat 
 * @param laPosition
 * @param nouvelleInfo
 */
template<typename T1, typename T2>
void insereInfoAtPosit(forward_list<T1>& maListeOriginale, int laPosition, T2 nouvelleInfo) throw (PrecondVioleeExcep) {
    // version itérative
    // itérateur positionné sur la postion avant le premier élément de la liste
    //  -> il faut être sur le précédent de laPosition pour fair l'insertion après !!
    auto it = maListeOriginale.before_begin();
    int positionCourante = 1;
    // tantque l'on a pas atteint laPosition et que l'on est pas à la fin de la liste
    while ((positionCourante < laPosition) && (it != maListeOriginale.end())) {
        positionCourante++;
        // avancer dans la liste sur l'itérateur
        ++it;
    }
    if (it != maListeOriginale.end()) { // si on a accès à laPosition
        // insérer après l'élément pointé par l'itérateur
        it = maListeOriginale.insert_after(it, nouvelleInfo);
    } else { // sinon on lève une exception
        throw PrecondVioleeExcep("Insertion imposible à l'indice " + to_string(laPosition));
    }
}

/**
 * tests
 * @return 
 */
int main() {
    cout << "SUR DES LISTES DE CHAINES DE CARACTERES" << endl;

    // Déclaration et contruction d'une liste avant de string  par agrégat
    /*
     * A COMPLETER
     */
    forward_list<string> uneListe = {"cinq", "quatre", "trois", "deux", "un", "zéro"};
    // Teste de la procédure d'affichage
    cout << "- La liste devrait contenir cinq quatre trois deux un zéro" << endl;
    cout << "- La liste contient -> ";
    /*
     * A COMPLETER
     */
    affiche(uneListe);

    // vidage de la liste
    cout << endl << "Nettoyage de la liste" << endl;
    /*
     * A COMPLETER
     */
    cout << "- La liste devrait être vide !" << endl;
    cout << "- La liste contient -> ";
    /*
     * A COMPLETER
     */


    // Séquence d'insertions en tête puis affichage
    cout << endl << "Insertions en tête de zéro, un, deux, trois, quatre, cinq" << endl;
    /*
     * A COMPLETER
     */

    cout << "- La liste devrait contenir cinq quatre trois deux un zéro" << endl;
    cout << "- La liste contient -> ";
    /*
     * A COMPLETER
     */

    
    //  //!!\\ pas pour étudiants
    // recopie d'une liste existantes dans une nouvelle liste
    cout << endl << "Copie de la liste précédente dans une nouvelle liste" << endl;
    /*
     * A COMPLETER
     */

    cout << "- La liste originale contient -> ";
    /*
     * A COMPLETER
     */

    cout << "- La liste copiée contient -> ";
    /*
     * A COMPLETER
     */


    cout << endl << "Accès à la première valeur" << endl;
    /*
     * A COMPLETER
     */

    cout << endl << "Accès à la deuxième valeur" << endl;
    /*
     * A COMPLETER
     */

    try {
        cout << endl << "Accès à une valeur non présente valeur" << endl;
    /*
     * A COMPLETER
     */
    } catch (PrecondVioleeExcep e) {
        cout << "  !!! CA C'EST MAL PASSEE, VOICI POURQUOI ---> " << endl;
        cout << e.what() << endl;
        cout << "  !!! ENFIN ON A QUAND MEME RECUPERER LE COUP !" << endl;
    }

    cout << endl << "Insertion à la première position de six" << endl;
    /*
     * A COMPLETER
     */
    cout << "- La liste devrait contenir six cinq quatre trois deux un zéro" << endl;
    cout << "- La liste contient -> ";
    /*
     * A COMPLETER
     */

    
    cout << endl << "Insertion à la deuxième position entre six et cinq" << endl;
    /*
     * A COMPLETER
     */
    cout << "- La liste devrait contenir six six_cinq cinq quatre trois deux un zéro" << endl;
        cout << "- La liste contient -> ";
    /*
     * A COMPLETER
     */


    cout << endl << "Insertion à la dernière position après zéro" << endl;
    /*
     * A COMPLETER
     */
    cout << "- La liste devrait contenir six six_cinq cinq quatre trois deux un zéro" << endl;
        cout << "- La liste contient -> ";
    /*
     * A COMPLETER
     */

    try {
        cout << endl << "Insertion de trop_loin à la postion 11" << endl;
    /*
     * A COMPLETER
     */
    } catch (PrecondVioleeExcep e) {
        cout << "  !!! CA C'EST MAL PASSEE, VOICI POURQUOI ---> " << endl;
        cout << e.what() << endl;
        cout << "  !!! ENFIN ON A QUAND MEME RECUPERER LE COUP !" << endl;
    }

    cout << endl << "On va maintenant trier la seconde liste" << endl;
    /*
     * A COMPLETER
     */
    cout << "- La liste devrait contenir cinq deux quatre trois un zéro" << endl;
        cout << "- La liste contient -> ";
    /*
     * A COMPLETER
     */


    return 0;
}

// TRACE A OBTENIR
/*
 SUR DES LISTES DE CHAINES DE CARACTERES

Construction de la liste par agrégat
- La liste devrait contenir cinq quatre trois deux un zéro
- La liste contient -> cinq quatre trois deux un zéro 

Nettoyage de la liste
- La liste devrait être vide !
- La liste contient -> 

Insertions en tête de zéro, un, deux, trois, quatre, cinq
- La liste devrait contenir cinq quatre trois deux un zéro
- La liste contient -> cinq quatre trois deux un zéro 

Copie de la liste précédente dans une nouvelle liste
- La liste originale contient -> cinq quatre trois deux un zéro 
- La liste copiée contient -> cinq quatre trois deux un zéro 

Accès à la première valeur
- On obtient : cinq ; on devrait avoir : cinq

Accès à la deuxième valeur
- On obtient : quatre ; on devrait avoir : quatre

Accès à une valeur non présente valeur
- On obtient :   !!! CA C'EST MAL PASSEE, VOICI POURQUOI ---> 
Précondition non respectée : Accès imposible à l'indice 7
  !!! ENFIN ON A QUAND MEME RECUPERER LE COUP !

Insertion à la première position de six
- La liste devrait contenir six cinq quatre trois deux un zéro
- La liste contient -> six cinq quatre trois deux un zéro 

Insertion à la deuxième position entre six et cinq
- La liste devrait contenir six six_cinq cinq quatre trois deux un zéro
- La liste contient -> six six_cinq cinq quatre trois deux un zéro 

Insertion à la dernière position après zéro
- La liste devrait contenir six six_cinq cinq quatre trois deux un zéro
- La liste contient -> six six_cinq cinq quatre trois deux un zéro zéro_ 

Insertion de trop_loin à la postion 11
  !!! CA C'EST MAL PASSEE, VOICI POURQUOI ---> 
Précondition non respectée : Insertion imposible à l'indice 11
  !!! ENFIN ON A QUAND MEME RECUPERER LE COUP !

On va maintenant trier la seconde liste
- La liste devrait contenir cinq deux quatre trois un zéro
- La liste contient -> cinq deux quatre trois un zéro 
*/

