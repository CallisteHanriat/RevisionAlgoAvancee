/* 
 * File:   main.cpp
 * Author: hb
 *
 * Created on 22 mai 2014, 14:56
 */

#include <cstdlib>
#include "Dictionnaire.h"
#include "DictionnaireFrancais.h"
#include "DictionnaireAnglais.h"

using namespace std;

/*
 * 
 */
int main() {
    
   /*
    *  ATTENTION CHANGER LES CHEMINS D'ACCES AUX FICHIERS
    */
    DictionnaireFrancais frenchDico("/home/couim/Documents/wiktionaryXfr2010.xml");
            
    DictionnaireAnglais englishDico("/home/couim/Documents/wiktionaryXen2010.xml");
    
    
    
    cout << "Le dictionnaire français compte " << frenchDico.getNbEntries() << " entrées." << endl;
    cout << "Le dictionnaire anglais compte " << englishDico.getNbEntries() << " entrées." << endl;
    
    //frenchDico.Print();
    //frenchDico.Print();
    
    //affichage de toutes les entrées
    //frenchDico.afficheEntriesForm();
    //englishDico.afficheEntriesForm();
    
    //affichage des entrées à partitr du rang 5
    //frenchDico.PrintDicoEntriesForm(5);
    
    //affichage des entées de rang 5 à 10
    //frenchDico.PrintDicoEntriesForm(1, 5);
    //englishDico.PrintDicoEntriesForm(1, 5);
    
    string uneForme;
    cout << endl << "A quelle entrée du dictionnaire voulez-vous accéder : ";
    cin >> uneForme ;
    frenchDico.afficheEntryForForm(uneForme);
//    englishDico.GetDicoEntry(entry);
    
    return 0;
}

