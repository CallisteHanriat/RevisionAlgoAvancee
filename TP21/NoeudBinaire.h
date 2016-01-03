//  HB librement inspiré de
//  Data Abstraction & Problem Solving with C++: Walls and Mirrors
//  Frank M. Carrano and Tim Henry.
//  2013 – Pearson Education

/** La classe NoeudBinaire pour l'implantation des arbres dynamiques
 @file NoeudBinaire.h */

#ifndef _NOEUD_BINAIRE
#define _NOEUD_BINAIRE

template<class TypeInfo>
class NoeudBinaire {
private:
    TypeInfo info; // information portée par le nœud binaire
    NoeudBinaire<TypeInfo>* ptrFilsGauche; // pointeur sur le fils gauche
    NoeudBinaire<TypeInfo>* ptrFilsDroit; // pointeur sur le fils droit

public:
    NoeudBinaire();
    NoeudBinaire(const TypeInfo& uneInfo);
    NoeudBinaire(const TypeInfo& uneInfo,
            NoeudBinaire<TypeInfo>* ptrFilsG,
            NoeudBinaire<TypeInfo>* ptrFilsD);

    void setInfo(const TypeInfo& uneInfo);
    TypeInfo getInfo() const;

    bool estFeuille() const;

    NoeudBinaire<TypeInfo>* getPtrFilsGauche() const;
    NoeudBinaire<TypeInfo>* getPtrFilsDroit() const;
    
    NoeudBinaire<TypeInfo>*& getRefPtrFilsGauche();
    NoeudBinaire<TypeInfo>*& getRefPtrFilsDroit();

    void setPtrFilsGauche(NoeudBinaire<TypeInfo>* ptrFilsG);
    void setPtrFilsDroit(NoeudBinaire<TypeInfo>* ptrFilsD);
    
    void affiche() const;
    
}; // end NoeudBinaire

#include "NoeudBinaire.cpp"

#endif 
