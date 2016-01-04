/* 
 * File:   xmlwiktionary.cpp
 * Author: hb
 * 
 * Created on 22 mai 2014, 14:57
 */

#include "Dictionnaire.h"
#include <iostream>     // pour cout
#include <iomanip>      // pour setw()
#include <limits>       // pour numeric_limits<unsigned int>::max()

using namespace std;

/**
 * Constucteur de dictionnaire
 * 
 * @param filename  chemin d'accès au fichier XML qui contient le dictionnaire
 */
Dictionnaire::Dictionnaire(const char* filename) {
    // Chargement du fichier XML en mémoire
    imageDictionnaire.LoadFile(filename);
    // Initialisation de l'attribut dictionnary avec le premier fils (element <wiktionary>)
    leDictionnaire = imageDictionnaire.FirstChildElement();
}

/*
 * out : nombre d'entrées dans le dictionnaire
 */
int Dictionnaire::getNbEntries() const {
    // initialisation du nombre d'entrées
    int nb = 0;
    
    XMLElement* currentEntry = leDictionnaire->FirstChildElement();
    
    while (currentEntry != nullptr) {
        currentEntry = currentEntry->NextSiblingElement();
        nb++;
    }

    return nb;
}

/*
 * in : entry une entrée du dictionnaire
 * out : nombres de lexmèmes (ou unité lexicale) -> unité de sens et de son
 */
int Dictionnaire::getNbLexemesEntry(XMLElement* entry) const {
    int nbLexems = 0; //on doit avoir de toute manière au moins un lexème par entrée
        
    entry = entry->FirstChildElement("lexeme");
    while (entry) {
        entry = entry->NextSiblingElement("lexeme");
        nbLexems++;
    }  

    return nbLexems;
}

/*
 * in : entry une entrée du dictionnaire
 * out : pointeur sur l'étymologie de entry si elle existe (NULL sinon)
 * l'étymologie est unique, il suffit donc d'accèder au fils de entry de type etym
 */
XMLElement* Dictionnaire::getEtymEntry(XMLElement* entry) {
    return entry->FirstChildElement("etym");
}



/*
 * in : defs un élement contenant les définitions d'un lexeme, peut être NULL !
 *      s'il n'est pas nul <tolevel-def>+ (dans la partique +)
 * out : nombres de définitions
 */
int Dictionnaire::getNbTopLevelDefS(XMLElement* defs) const {
    int nbDefs = 0; //on n'a pas forcément de définition
        
    if (defs) {
        defs = defs->FirstChildElement();
        while (defs) {
            defs = defs->NextSiblingElement();
            nbDefs++;
        }
    }

    return nbDefs;
}


int Dictionnaire::getNbEntriesRecWorker(const XMLElement* entreeCourante) const {
        
    if (entreeCourante == nullptr) {
        return 0;
    } else {
        return getNbEntriesRecWorker(entreeCourante->NextSiblingElement()) + 1;
    }
}


int Dictionnaire::getNbEntriesRec() const {
    return getNbEntriesRecWorker(leDictionnaire->FirstChildElement());
}


//void Dictionnaire::Print() const {
//    dictionaryfile.Print();
//}


void Dictionnaire::afficheEntriesForm() {
    int rank = 1;
    string entryFormValue;
    
    XMLElement* currentEntry = leDictionnaire->FirstChildElement();
    
    while (currentEntry != nullptr) {
        entryFormValue = currentEntry->Attribute("form");
        cout << setw(15) << rank << " : " << entryFormValue << endl;
        currentEntry = currentEntry->NextSiblingElement();
        rank++;
    }
}


/*
 * affichage des entrées du dictionnaire dans un intervalle
 */
void Dictionnaire::afficheRangedEntriesForm(unsigned int inf, unsigned int sup) {
    
    int rank = 1;
    string entryFormValue;
    
    XMLElement* currentEntry = leDictionnaire->FirstChildElement();
    
    while (currentEntry != nullptr && rank < inf) {
        currentEntry = currentEntry->NextSiblingElement();
        rank++;
    }
    
    while (currentEntry != nullptr && rank <= sup) {
        entryFormValue = currentEntry->Attribute("form");
        cout << setw(15) << rank << " : " << entryFormValue << endl;
        currentEntry = currentEntry->NextSiblingElement();
        rank++;
    }

}

/*
 * pointeur sur l'élément <entry> correspondant à la forme form
 */
XMLElement* Dictionnaire::getEntryForForm(string entryForm) {
    string entryFormValue;

    XMLElement* currentEntry = leDictionnaire->FirstChildElement();
    
    while (currentEntry != nullptr
           && currentEntry->Attribute("form") != entryForm) {
        currentEntry = currentEntry->NextSiblingElement();
    }
    
    return currentEntry;
}


Dictionnaire::~Dictionnaire() {
}

