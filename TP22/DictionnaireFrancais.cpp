/* 
 * File:   FrDico.cpp
 * Author: hb
 * 
 * Created on 22 mai 2014, 15:13
 */

#include "DictionnaireFrancais.h"
#include <iomanip>

/*
 * in : chemin d'accès au fichier qui contient le dictionnaire
 * appel du constructeur de Dictionnaire
 */
DictionnaireFrancais::DictionnaireFrancais(const char* filename) : Dictionnaire(filename) {
}

DictionnaireFrancais::~DictionnaireFrancais() {
}

void DictionnaireFrancais::afficheSubLevelDefS(XMLElement* subDef) {
        
    XMLElement* example = subDef->FirstChildElement("example");
    if (subDef) {
        if (subDef->FirstChildElement("gloss")) {
            cout << setw(12) << ""
                 << "Glose : " 
                 << subDef->FirstChildElement("gloss")->GetText()
                 << endl;
        }
        while (example) {
            cout << setw(12) << ""
                 << "Exemple : " 
                 << example->GetText()
                 << endl;
            example = example->NextSiblingElement("example");
        }
    }

}

void DictionnaireFrancais::afficheTopLevelDef(XMLElement* def) {
    XMLElement* subleveldef = def->FirstChildElement("sublevel-def");
    XMLElement* example = def->FirstChildElement("example");
    if (def) {
        if (def->FirstChildElement("gloss")) {
            cout << setw(8) << ""
                 << "Glose : " 
                 << def->FirstChildElement("gloss")->GetText()
                 << endl;
        }
        while (subleveldef) {
            afficheTopLevelDef(subleveldef);
            subleveldef = subleveldef->NextSiblingElement("sublevel-def");
        }
        while (example) {
            cout << setw(8) << ""
                 << "Exemple : " 
                 << example->GetText()
                 << endl;
            example = example->NextSiblingElement("example");
        }
    }

}

/*
 * in : entryForm -> entrée du dictionnaire
 *      entryPos -> partie du discours considérée
 *      defsElement -> un element <defs> qui contient des <toplevel-def>
 */
void DictionnaireFrancais::afficheTopLevelDefS(const string entryForm, const string entryPos, XMLElement* defsElement) {
    cout << setw(4) << "" << "Forme : " << entryForm << endl;
    cout << setw(4) << "" << "Partie du discours : " <<  entryPos << endl;
    if (defsElement) {
        defsElement = defsElement->FirstChildElement();
        while (defsElement) {
            afficheTopLevelDef(defsElement);
            defsElement = defsElement->NextSiblingElement();
        }
    }
}

/*
 * in : entry une entrée du dictionnaire <etym>? <lexeme>* (dans la pratique +)
 * affiche les définitions de chaque lexème correspondant à l'entrée
 */
void DictionnaireFrancais::afficheEntryLexemesDefS(XMLElement* entry) {
    string forme = entry->Attribute("form");
    entry = entry->FirstChildElement("lexeme");
    while (entry) {
        afficheTopLevelDefS(forme,
                            entry->Attribute("pos"),
                            entry->FirstChildElement("defs"));
        entry = entry->NextSiblingElement("lexeme");
    }  
}

/**
 * Un pretty print pour une entrée
 * @param entry
 */
void DictionnaireFrancais::afficheEntry(XMLElement* entry) {
    if (entry) {
        cout << "Page id : " << entry->Attribute("pageid") << endl;
        if (entry->FirstChildElement("etym")) {
            cout << setw(4) << ""
                 << "Etymologie : " 
                 << entry->FirstChildElement("etym")->GetText()
                 << endl;
        }
        afficheEntryLexemesDefS(entry);
    }
}

/**
 * Un pretty print pour une entrée
 * @param aForm
 */
void DictionnaireFrancais::afficheEntryForForm(const string aForm) {
    afficheEntry(getEntryForForm(aForm));
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

