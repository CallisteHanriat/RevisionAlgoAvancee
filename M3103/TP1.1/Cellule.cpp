//  HB librement inspiré de
//  Data Abstraction & Problem Solving with C++: Walls and Mirrors
//  Frank M. Carrano and Tim Henry.
//  2013 – Pearson Education

/** Implémentation de la classe
    @file Cellule.cpp 
 */

#ifdef _CELLULE

#include <cstddef>
#include <iostream>

//#include "Cellule.h"

using namespace std;

template<class TypeInfo>
Cellule<TypeInfo>::Cellule() : ptrCellSuivante(nullptr) {
} // end constructeur par défaut

template<class TypeInfo>
Cellule<TypeInfo>::Cellule(const TypeInfo& uneInfo) : info(uneInfo), ptrCellSuivante(nullptr) {
} // end constructeur avec une information

template<class TypeInfo>
Cellule<TypeInfo>::Cellule(const TypeInfo& uneInfo, Cellule<TypeInfo>* ptrCelluleSuivante) : info(uneInfo), ptrCellSuivante(ptrCelluleSuivante) {
} // end constructeur avec une information et une liste (insertête dans une liste existante)

template<class TypeInfo>
void Cellule<TypeInfo>::setInfo(const TypeInfo& uneInfo) {
    info = uneInfo;
} // end setInfo

template<class TypeInfo>
void Cellule<TypeInfo>::setSuivante(Cellule<TypeInfo>* ptrCelluleSuivante) {
    ptrCellSuivante = ptrCelluleSuivante;
} // end setSuivant

template<class TypeInfo>
TypeInfo Cellule<TypeInfo>::getInfo() const {
    return info;
} // end getInfo

template<class TypeInfo>
Cellule<TypeInfo>* Cellule<TypeInfo>::getSuivante() const {
    return ptrCellSuivante;
} // end getSuivant

template<class TypeInfo>
Cellule<TypeInfo>*& Cellule<TypeInfo>::getRefSuivante() {
    return ptrCellSuivante;
} // end getRefSuivante

template<class TypeInfo>
void Cellule<TypeInfo>::affiche() const {
    cout << info;
} // end afficheCellule

#endif