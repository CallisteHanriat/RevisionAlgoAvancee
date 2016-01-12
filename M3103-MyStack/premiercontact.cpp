/* 
 * File:   main.cpp
 * Author: hb
 *
 */

// documentation : http://www.cplusplus.com/reference/stack/stack/

#include <stack>          // pour les piles
#include <string>         // pour les chaînes
#include <iostream>
#include <cstdlib>
#include "PrecondVioleeExcep.h"

using namespace std;

/**
 * affiche les informations depuis le sommet jusqu'au fond de pile
 * @param unePile
 */
template<typename T>
void affichePile(stack<T>& unePile) {
    // dupliquer la pile pour faire un parcours destructif (depile) sur celle-ci
    stack<T> pileTemporaire(unePile);
    cout << "En partant du sommet pile contient -> ";
    while (!pileTemporaire.empty()) {
        cout << pileTemporaire.top() << " ";
        pileTemporaire.pop();
    }
    cout << endl;
} // end afficheListe


void testeEmpile() {
    // déclaration d'une pile de strings
    stack<string> maPile;
    
//  DEBUT testeEmpile()
//    
//  Liste vide ? : 1 devrait répondre vrai (1) !
    cout << maPile.empty();
//  empile zéro --> En partant du sommet pile contient -> zero 
//   - le sommet contient : zero
    maPile.push("zero");
    affichePile(maPile);
//  empile un --> En partant du sommet pile contient -> un zero 
//   - le sommet contient : un
    maPile.push("un");
//  empile deux --> En partant du sommet pile contient -> deux un zero 
//   - le sommet contient : deux
    maPile.push("deux");
//  empile trois --> En partant du sommet pile contient -> trois deux un zero 
//   - le sommet contient : trois
    maPile.push("trois");
//  empile quatre --> En partant du sommet pile contient -> quatre trois deux un zero 
//   - le sommet contient : quatre
    maPile.push("quatre");
//  empile cinq --> En partant du sommet pile contient -> cinq quatre trois deux un zero 
//   - le sommet contient : cinq
    maPile.push("cinq");
    cout << "la pile après insertion de zero à 5 : ";
    affichePile(maPile);
    
    cout << endl;
//  Liste vide ? : 0 devrait répondre faux (0) !
    cout << "liste vide ? : " << maPile.empty() << " devrait  repondre 0";
//FIN testeEmpile()
    
}

void testeDepile() {
    // déclaration d'une pile de strings    
    stack<string> maPile;
    cout << "\n\nTestDEPILE()";
//DEBUT testeDepile()
//
//  Remplissage de la pile --> En partant du sommet pile contient -> cinq quatre trois deux un zero 
////  empile zéro --> En partant du sommet pile contient -> zero 
//   - le sommet contient : zero
    maPile.push("zero");
//  empile un --> En partant du sommet pile contient -> un zero 
//   - le sommet contient : un
    maPile.push("un");
//  empile deux --> En partant du sommet pile contient -> deux un zero 
//   - le sommet contient : deux
    maPile.push("deux");
//  empile trois --> En partant du sommet pile contient -> trois deux un zero 
//   - le sommet contient : trois
    maPile.push("trois");
//  empile quatre --> En partant du sommet pile contient -> quatre trois deux un zero 
//   - le sommet contient : quatre
    maPile.push("quatre");
//  empile cinq --> En partant du sommet pile contient -> cinq quatre trois deux un zero 
//   - le sommet contient : cinq
    maPile.push("cinq");
//  3 consulteSommet() et depile()
//   ma pile actuelle --> En partant du sommet pile contient -> cinq quatre trois deux un zero 
//  sommet actuel : cinq
    cout << endl <<  "sommet actuel : "; 
    cout << maPile.top();
    maPile.pop();
//   ma pile actuelle --> En partant du sommet pile contient -> quatre trois deux un zero 
//  sommet actuel : quatre
    cout << "\nsommet actuel : ";
    cout << maPile.top();
    maPile.pop();
//   ma pile actuelle --> En partant du sommet pile contient -> trois deux un zero 
//  sommet actuel : trois
    cout << "\nsommet actuel : ";
    cout << maPile.top();
    maPile.pop();
//   ma pile actuelle --> En partant du sommet pile contient -> deux un zero 
//  sommet actuel : deux
    cout << "\nsommet actuel : ";
    cout << maPile.top();
    maPile.pop();
//
//FIN testeDepile()
    
}

void testeBorneDepile() {
    // déclaration d'une pile de strings 
    stack<string> maPile;
    cout << endl << endl;
    cout << "testeBorneDepile()";
//DEBUT testeBorneDepile()
//
//  Remplissage de la pile -->   ma pile actuelle -> En partant du sommet pile contient -> cinq quatre trois deux un zero 
//  Remplissage de la pile --> En partant du sommet pile contient -> cinq quatre trois deux un zero 
////  empile zéro --> En partant du sommet pile contient -> zero 
//   - le sommet contient : zero
    maPile.push("zero");
//  empile un --> En partant du sommet pile contient -> un zero 
//   - le sommet contient : un
    maPile.push("un");
//  empile deux --> En partant du sommet pile contient -> deux un zero 
//   - le sommet contient : deux
    maPile.push("deux");
//  empile trois --> En partant du sommet pile contient -> trois deux un zero 
//   - le sommet contient : trois
    maPile.push("trois");
//  empile quatre --> En partant du sommet pile contient -> quatre trois deux un zero 
//   - le sommet contient : quatre
    maPile.push("quatre");
//  empile cinq --> En partant du sommet pile contient -> cinq quatre trois deux un zero 
//   - le sommet contient : cinq
    maPile.push("cinq");
//  3 consulteSommet() et depile()
//   ma pile actuelle --> En partant du sommet pile contient -> cinq quatre trois deux un zero 
//  sommet actuel : cinq
    cout << endl <<  "sommet actuel : "; 
    cout << maPile.top();
    maPile.pop();
//  ma pile actuelle -> En partant du sommet pile contient -> quatre trois deux un zero 
    affichePile(maPile);
    maPile.pop();
//  ma pile actuelle -> En partant du sommet pile contient -> trois deux un zero 
    affichePile(maPile);
    maPile.pop();
//  ma pile actuelle -> En partant du sommet pile contient -> deux un zero 
    affichePile(maPile);
    maPile.pop();
//  ma pile actuelle -> En partant du sommet pile contient -> un zero 
    affichePile(maPile);
    maPile.pop();
//  ma pile actuelle -> En partant du sommet pile contient -> zero 
    affichePile(maPile);
    maPile.pop();
//  ma pile actuelle -> En partant du sommet pile contient -> 
    affichePile(maPile);
//
//pop() sur une pile vide :
//  /!\ pop() sur une pile vide ne délenche pas d'exeption ; on a un comportement idéfini
//  /!\ le programmeur doit s'assurer que cette situation ne se produit pas !
//
//  -> /!\ DESOLE, la pile est vide, pas de pop() possible !

   // maPile.pop();
//front() sur une pile vide : 
//  /!\ front() sur une pile vide ne délenche pas d'exeption ; on a un comportement idéfini
//  /!\ le programmeur doit s'assurer que cette situation ne se produit pas !

    
//  -> /!\ DESOLE, la pile est vide, pas de front() possible !
//
//FIN testeBorneDepile()

}

int main() {
    testeEmpile();
    testeDepile();
    testeBorneDepile();
    return 0;
} // end main

// TRACE ATTENDU
/*
DEBUT testeEmpile()

  Liste vide ? : 1 devrait répondre vrai (1) !

  empile zéro --> En partant du sommet pile contient -> zero 
   - le sommet contient : zero
  empile un --> En partant du sommet pile contient -> un zero 
   - le sommet contient : un
  empile deux --> En partant du sommet pile contient -> deux un zero 
   - le sommet contient : deux
  empile trois --> En partant du sommet pile contient -> trois deux un zero 
   - le sommet contient : trois
  empile quatre --> En partant du sommet pile contient -> quatre trois deux un zero 
   - le sommet contient : quatre
  empile cinq --> En partant du sommet pile contient -> cinq quatre trois deux un zero 
   - le sommet contient : cinq
  Liste vide ? : 0 devrait répondre faux (0) !

FIN testeEmpile()

DEBUT testeDepile()

  Remplissage de la pile --> En partant du sommet pile contient -> cinq quatre trois deux un zero 

  3 consulteSommet() et depile()
   ma pile actuelle --> En partant du sommet pile contient -> cinq quatre trois deux un zero 
  sommet actuel : cinq
   ma pile actuelle --> En partant du sommet pile contient -> quatre trois deux un zero 
  sommet actuel : quatre
   ma pile actuelle --> En partant du sommet pile contient -> trois deux un zero 
  sommet actuel : trois
   ma pile actuelle --> En partant du sommet pile contient -> deux un zero 
  sommet actuel : deux

FIN testeDepile()

DEBUT testeBorneDepile()

  Remplissage de la pile -->   ma pile actuelle -> En partant du sommet pile contient -> cinq quatre trois deux un zero 
  ma pile actuelle -> En partant du sommet pile contient -> quatre trois deux un zero 
  ma pile actuelle -> En partant du sommet pile contient -> trois deux un zero 
  ma pile actuelle -> En partant du sommet pile contient -> deux un zero 
  ma pile actuelle -> En partant du sommet pile contient -> un zero 
  ma pile actuelle -> En partant du sommet pile contient -> zero 
  ma pile actuelle -> En partant du sommet pile contient -> 

pop() sur une pile vide :
  /!\ pop() sur une pile vide ne délenche pas d'exeption ; on a un comportement idéfini
  /!\ le programmeur doit s'assurer que cette situation ne se produit pas !

  -> /!\ DESOLE, la pile est vide, pas de pop() possible !

front() sur une pile vide : 
  /!\ front() sur une pile vide ne délenche pas d'exeption ; on a un comportement idéfini
  /!\ le programmeur doit s'assurer que cette situation ne se produit pas !

  -> /!\ DESOLE, la pile est vide, pas de front() possible !

FIN testeBorneDepile()

 */
