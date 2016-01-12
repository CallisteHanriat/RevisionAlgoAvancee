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
void affichePile(stack<T> unePile) {
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
    
    cout << "DEBUT testeEmpile()" << endl;
    cout << "Liste vide ? : " << maPile.empty() << " devrait répondre vrai (1) !" << endl;
    
    maPile.push("zero");
    cout << "empile zéro --> "; 
    affichePile(maPile);
    cout << " - le sommet contient : " << maPile.top() << endl;
    maPile.push("un");
    cout << "empile un --> "; 
    affichePile(maPile);
    cout << " - le sommet contient : " << maPile.top() << endl;
    maPile.push("deux");
    cout << "empile deux --> "; 
    affichePile(maPile);
    cout << " - le sommet contient : " << maPile.top() << endl;
    maPile.push("trois");
    cout << "empile trois --> "; 
    affichePile(maPile);
    cout << " - le sommet contient : " << maPile.top() << endl;
    maPile.push("quatre");
    cout << "empile quatre --> "; 
    affichePile(maPile);
    cout << " - le sommet contient : " << maPile.top() << endl;
    maPile.push("cinq");
    cout << "empile cinq --> "; 
    affichePile(maPile);
    cout << " - le sommet contient : " << maPile.top() << endl;
    
    cout << "Liste vide ? : " << maPile.empty() << " devrait répondre faux (0) !" << endl; 
    cout << "FIN testeEmpile()" << endl;
//  DEBUT testeEmpile()
//    
//  Liste vide ? : 1 devrait répondre vrai (1) !
//
//  empile zéro --> En partant du sommet pile contient -> zero 
//   - le sommet contient : zero
//  empile un --> En partant du sommet pile contient -> un zero 
//   - le sommet contient : un
//  empile deux --> En partant du sommet pile contient -> deux un zero 
//   - le sommet contient : deux
//  empile trois --> En partant du sommet pile contient -> trois deux un zero 
//   - le sommet contient : trois
//  empile quatre --> En partant du sommet pile contient -> quatre trois deux un zero 
//   - le sommet contient : quatre
//  empile cinq --> En partant du sommet pile contient -> cinq quatre trois deux un zero 
//   - le sommet contient : cinq
//  Liste vide ? : 0 devrait répondre faux (0) !
//
//  FIN testeEmpile()
    
}

void testeDepile() {
    // déclaration d'une pile de strings    
    stack<string> maPile;
    
    cout << "DEBUT testeDepile()" << endl;
    
    maPile.push("zero");
    maPile.push("un");
    maPile.push("deux");
    maPile.push("trois");
    maPile.push("quatre");
    maPile.push("cinq");
    cout << "Remplissage de la pile --> ";
    affichePile(maPile);
    
    cout << "3 consulteSommet() et depile()" << endl;
    cout << "ma pile actuelle --> ";
    affichePile(maPile);
    cout << "sommet actuel : " << maPile.top() << endl;
    maPile.pop();
    cout << "ma pile actuelle --> ";
    affichePile(maPile);
    cout << "sommet actuel : " << maPile.top() << endl;
    maPile.pop();
    cout << "ma pile actuelle --> ";
    affichePile(maPile);
    cout << "sommet actuel : " << maPile.top() << endl;
    maPile.pop();
    cout << "ma pile actuelle --> ";
    affichePile(maPile);
    cout << "sommet actuel : " << maPile.top() << endl;
    
    cout << "FIN testeDepile()" << endl;
    
//DEBUT testeDepile()
//
//  Remplissage de la pile --> En partant du sommet pile contient -> cinq quatre trois deux un zero 
//
//  3 consulteSommet() et depile()
//   ma pile actuelle --> En partant du sommet pile contient -> cinq quatre trois deux un zero 
//  sommet actuel : cinq
//   ma pile actuelle --> En partant du sommet pile contient -> quatre trois deux un zero 
//  sommet actuel : quatre
//   ma pile actuelle --> En partant du sommet pile contient -> trois deux un zero 
//  sommet actuel : trois
//   ma pile actuelle --> En partant du sommet pile contient -> deux un zero 
//  sommet actuel : deux
//
//FIN testeDepile()
    
}

void testeBorneDepile() {
    // déclaration d'une pile de strings 
    stack<string> maPile;
    
    cout << "DEBUT testeBorneDepile()" << endl;
    
    maPile.push("zero");
    maPile.push("un");
    maPile.push("deux");
    maPile.push("trois");
    maPile.push("quatre");
    maPile.push("cinq");
    cout << "Remplissage de la pile -->   ma pile actuelle -> ";
    affichePile(maPile);
    maPile.pop();
    cout << "ma pile actuelle -> ";
    affichePile(maPile);
    maPile.pop();
    cout << "ma pile actuelle -> ";
    affichePile(maPile);
    maPile.pop();
    cout << "ma pile actuelle -> ";
    affichePile(maPile);
    maPile.pop();
    cout << "ma pile actuelle -> ";
    affichePile(maPile);
    maPile.pop();
    cout << "ma pile actuelle -> ";
    affichePile(maPile);
    maPile.pop();
    cout << "ma pile actuelle -> ";
    affichePile(maPile);
    
    if(!maPile.empty())
        maPile.pop();
    
    cout << "FIN testeBorneDepile()" << endl;
    
//DEBUT testeBorneDepile()
//
//  Remplissage de la pile -->   ma pile actuelle -> En partant du sommet pile contient -> cinq quatre trois deux un zero 
//  ma pile actuelle -> En partant du sommet pile contient -> quatre trois deux un zero 
//  ma pile actuelle -> En partant du sommet pile contient -> trois deux un zero 
//  ma pile actuelle -> En partant du sommet pile contient -> deux un zero 
//  ma pile actuelle -> En partant du sommet pile contient -> un zero 
//  ma pile actuelle -> En partant du sommet pile contient -> zero 
//  ma pile actuelle -> En partant du sommet pile contient -> 
//
//pop() sur une pile vide :
//  /!\ pop() sur une pile vide ne délenche pas d'exeption ; on a un comportement idéfini
//  /!\ le programmeur doit s'assurer que cette situation ne se produit pas !
//
//  -> /!\ DESOLE, la pile est vide, pas de pop() possible !
//
//front() sur une pile vide : 
//  /!\ front() sur une pile vide ne délenche pas d'exeption ; on a un comportement idéfini
//  /!\ le programmeur doit s'assurer que cette situation ne se produit pas !
//
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
