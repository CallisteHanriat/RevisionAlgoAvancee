//  HB librement inspiré de
//  Data Abstraction & Problem Solving with C++: Walls and Mirrors
//  Frank M. Carrano and Tim Henry.
//  2013 – Pearson Education


#ifndef _CELLULE
#define _CELLULE

template<class TypeInfo>
class Cellule {
private:
    TypeInfo info; // une information
    Cellule<TypeInfo>* ptrCellSuivante; // un pointeur sur la Cellule suivante

public:
    /**
     * Constuctueur par défaut (info à 0, ptrCellSuivante à nullptr
     */
    Cellule();
    
    /**
     * Constructeur avec une information et ptrCellSuivante à nullptr
     * 
     * @param uneInfo : info portée par cette Cellule
     */
    Cellule(const TypeInfo& uneInfo);
    
    /**
     * Constructeur avec une information et une cellule suivante
     * 
     * @param uneInfo : info portée par cette Cellule
     * @param ptrCelluleSuivante : valeur de ptrCellSuivante
     */
    Cellule(const TypeInfo& uneInfo, Cellule<TypeInfo>* ptrCelluleSuivante);
    
    void setInfo(const TypeInfo& uneInfo);
    void setSuivante(Cellule<TypeInfo>* ptrCelluleSuivante);
    TypeInfo getInfo() const;
    Cellule<TypeInfo>* getSuivante() const;
    
    /**
     * Méthode utile pour les procédure récursives qui modifient des Cellules
     * 
     * @return : une référence de pointeur
     */
    Cellule<TypeInfo>*& getRefSuivante();
    
}; // end Cellule

#include "Cellule.cpp"
#endif