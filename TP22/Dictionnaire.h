/* 
 * File:   xmlwiktionary.h
 * Author: hb
 *
 * Created on 22 mai 2014, 14:57
 */

#ifndef DICTIONNAIRE_H
#define	DICTIONNAIRE_H

#include "tinyxml2.h"
#include <string>

using namespace tinyxml2; // dans l'espace de nom de la bibliothèque
using namespace std;

class Dictionnaire {
public:
    //charge le dictionnaire sous from XML stocké dans le fichier filename
    Dictionnaire(const char* filename);
    
    //nombre d'entrées du dictionnaire
    int getNbEntries() const;
    int getNbEntriesRec() const;
    
    // méthodes sur entrée
    int getNbLexemesEntry(XMLElement* entry) const;
    XMLElement* getEtymEntry(XMLElement* entry);
    
    // méthodes sur defs
    int getNbTopLevelDefS(XMLElement* defs) const;
    
    //void Print() const;
    
    // affichage des entrées du dictionnaire en le rang inf et le rang sup
    // si inf et sup de sont pas founis, affichage de toutes les entrées
    void afficheRangedEntriesForm(unsigned int inf = 0, unsigned int sup = 0);
    
    void afficheEntriesForm();

    //retourn un pointeur sur l'entrée si elle existe
    XMLElement* getEntryForForm(string entryFrom);
    
    virtual ~Dictionnaire();
private:
    // Un XMLDOcument permet d'accéder à toutes les fonctionnalités de la bibliothèque
    // Il peut être sauveragrdé, chargé, et affiché à l'écran.
    // Tous les noeuds sont connectés et aloués à un document.
    // Si le document est supprimer, tous ses noeuds sont aussi supprimé.
    XMLDocument imageDictionnaire;
    // XMLElement est une classe container.
    // Un element possède une valeur, un nom et peut contenir d'autres éléments, du texte, des commentaires, des inconnus
    // Un élément peut contenir un nombre arbitraire d'attributs    
    // dictionnary est un élément de la classe <wiktionary> qui permet de parcourir les entrées <entry> du dictionnaire
    XMLElement* leDictionnaire;
    
    int getNbEntriesRecWorker(const XMLElement* entreeCourante) const;
};

#endif	/* XMLWIKTIONARY_H */

