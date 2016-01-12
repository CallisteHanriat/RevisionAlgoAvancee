/* 
 * File:   FrDico.h
 * Author: hb
 *
 * Created on 22 mai 2014, 15:13
 */

#ifndef ENGLISHDICTIONARY_H
#define	ENGLISHDICTIONARY_H

#include "Dictionnaire.h"
#include <iostream> //nécessaire à l'édition de lien sur <map>
#include <map>

using namespace std;

class DictionnaireAnglais : public Dictionnaire {
public:
    /*
     * charge le dictionnaire sous from XML stocké dans le fichier filename
    */ 
    DictionnaireAnglais(const char* filename);
    virtual ~DictionnaireAnglais();
private:
    map<string, string> part_of_speech = {
        {"Adj", "adjectif"},
        {"Adv", "adverbe"},
        {"Conj", "conjonction"},
        {"Intj", "interjection"},
        {"N", "nom commun"},
        {"NP", "nom propre"},
        {"Num", "numéral"},
        {"Part", "particule"},
        {"Pr", "pronom"},
        {"Prep", "préposition"},
        {"V", "verbe"}
    };
};

#endif	/* ENGLISHDICTIONARY_H */

