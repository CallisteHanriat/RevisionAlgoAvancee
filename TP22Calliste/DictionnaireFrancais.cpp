/* 
 * File:   FrDico.cpp
 * Author: hb
 * 
 * Created on 22 mai 2014, 15:13
 */

#include "DictionnaireFrancais.h"

/*
 * in : chemin d'accès au fichier qui contient le dictionnaire
 * appel du constructeur de Dictionnaire
 */
DictionnaireFrancais::DictionnaireFrancais(const char* filename) : Dictionnaire(filename) {
}

DictionnaireFrancais::~DictionnaireFrancais() {
}

void DictionnaireFrancais::afficheSubLevelDefS(XMLElement* subDef) {
        
    /*
     *  A COMPLETER
     */

}

void DictionnaireFrancais::afficheTopLevelDef(XMLElement* def) {
        
    /*
     *  A COMPLETER
     */

}

/*
 * in : entryForm -> entrée du dictionnaire
 *      entryPos -> partie du discours considérée
 *      defsElement -> un element <defs> qui contient des <toplevel-def>
 */
void DictionnaireFrancais::afficheTopLevelDefS(const string entryForm, const string entryPos, XMLElement* defsElement) {
        
    /*
     *  A COMPLETER
     */

}

/*
 * in : entry une entrée du dictionnaire <etym>? <lexeme>* (dans la pratique +)
 * affiche les définitions de chaque lexème correspondant à l'entrée
 */
void DictionnaireFrancais::afficheEntryLexemesDefS(XMLElement* entry) {
        
    /*
     *  A COMPLETER
     */

}

/**
 * Un pretty print pour une entrée
 * @param entry
 */
void DictionnaireFrancais::afficheEntry(XMLElement* entry) {
        
    /*
     *  A COMPLETER
     */

}

/**
 * Un pretty print pour une entrée
 * @param entry
 */
void DictionnaireFrancais::afficheEntryForForm(const string aForm) {

        
    /*
     *  A COMPLETER
     */

}

/*
 * une entrée est ambiguë si pour une même partie du discours, l'entrée possède plusieurs lexèmes
 */
bool DictionnaireFrancais::isEntryAmbiguous(XMLElement* entry) {
        
    /*
     *  A COMPLETER
     */
    
    return true;

}

