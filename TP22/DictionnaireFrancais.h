/* 
 * File:   FrDico.h
 * Author: hb
 *
 * Created on 22 mai 2014, 15:13
 */

#ifndef FRENCHDICTIONARY_H
#define	FRENCHDICTIONARY_H

#include "Dictionnaire.h"
#include <iostream> //nécessaire à l'édition de lien sur <map>
#include <map>

using namespace std;

class DictionnaireFrancais : public Dictionnaire {
public:
    /*
     * charge le dictionnaire sous from XML stocké dans le fichier filename
     */
    DictionnaireFrancais(const char* filename);
    virtual ~DictionnaireFrancais();

    void afficheEntryLexemesDefS(XMLElement* entry);
    bool isEntryAmbiguous(XMLElement* entry);
    void afficheEntry(XMLElement* entry);
    void afficheEntryForForm(const string aForm);

    void afficheTopLevelDefS(const string entryForm, const string entryPos, XMLElement* defsElement);
    void afficheTopLevelDef(XMLElement* def);
    void afficheSubLevelDefS(XMLElement* subDef);
    

private:
    map<string, string> part_of_speech = {
        {"Adj", "adjectif"},
        {"adj-excl", "adjectif exclamatif"},
        {"adj-int", "adjectif interrogatif"},
        {"adj-num", "adjectif numéral"},
        {"adj-pos", "adjectif possessif"},
        {"Adv", "adverbe"},
        {"art-part", "article partitif"},
        {"conj", "conjonction"},
        {"conj-coord", "conjontion de coordination"},
        {"flex-adj", "forme d'adjectif"},
        {"flex-adv", "forme d'adverbe"},
        {"flex-conj", "forme de conjonction"},
        {"flex-interj", "forme d'interjection"},
        {"flex-nom", "forme de nom commun"},
        {"flex-pronom", "forme de pronom"},
        {"flex-suf", "forme de suffixe"},
        {"flex-verb", "forme verbale (verbe conjugué)"},
        {"interj", "interjection"},
        {"loc", "locution"},
        {"LocAdj", "locution adjectivale"},
        {"LocAdv", "locution adverbiale"},
        {"loc-conj", "locution conjonctive"},
        {"loc-interj", "locution interjective"},
        {"LocN", "locution nominale"},
        {"loc-phr", "locution-phrase"},
        {"loc-post", "locution propositive"},
        {"loc-prep", "locution prépositive"},
        {"loc-pronom", "locution pronominale"},
        {"LocV", "locution verbale"},
        {"N", "nom commun"},
        {"NP", "nom propre"},
        {"prép", "préposition"},
        {"pronom", "pronom"},
        {"pronom-int", "pronom interrogatif"},
        {"pronom-pers", "pronom personnel"},
        {"pronom-pos", "pronom possessif"},
        {"pronom-rel", "pronom relatif"},
        {"V", "verbe"},
        {"Vaux", "verbe auxiliaire"}
    };
};

#endif	/* FRDICO_H */

