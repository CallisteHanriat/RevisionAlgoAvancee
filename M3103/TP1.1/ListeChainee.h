/*
 * ETUDIANT
 */


//  HB librement inspiré de
//  Data Abstraction & Problem Solving with C++: Walls and Mirrors
//  HB librement inspiré de
//  Data Abstraction & Problem Solving with C++: Walls and Mirrors
//  Frank M. Carrano and Tim Henry.
//  2013 – Pearson Education

/** TAD liste: Implémentation sous forme de liste chaînée.
    @file ListeChainee.h */

#ifndef _LISTE_CHAINEE
#define _LISTE_CHAINEE

#include "ListeInterface.h"
#include "Cellule.h"
#include "PrecondVioleeExcep.h"

template<class TypeInfo>
class ListeChainee : public ListeInterface<TypeInfo> {
private:
    Cellule<TypeInfo>* ptrTete; // pointeur sur la première Cellule de la liste;
    int nbCellules; // nombre de cellules

    // retourne un pointeur sur la cellule de rang position dans cette (this) liste.
    // @pre  position est le rang de la cellule sur laquelle on veut pointer;
    //       position >= 1 and position <= itemCount.
    // @post  la cellule est trouvée et un pointeur est retourné.
    // @param position  rang de la cellule visée.
    // @return  un pointeur sur la cellule de rang position.
    Cellule<TypeInfo>* getCelluleAtPositIter(int position) const;

    // retourne un pointeur sur la cellule de rang position dans cette liste.
    // @pre  position est le rang de la cellule sur laquelle on veut pointer;
    //       position >= 1 and position <= itemCount.
    // @post  la cellule est trouvée et un pointeur est retourné.
    // @param position  rang de la cellule visée.
    // @return  un pointeur sur la cellule de rang position.
    Cellule<TypeInfo>* getCelluleAtPositRec(Cellule<TypeInfo>* ptrCetteListe, int position) const;

    //------------------------------------------------------------
    // Section de méthodes utilitaires worker récursives :
    // Méthodes "helper" récursive pour les méthodes publiques.
    //------------------------------------------------------------

    void videRecWorker(Cellule<TypeInfo>* ptrCetteListe);

    // Les deux méthodes suivantes sont des fonctions qui retournent une nouvelle
    // liste qui "remplace" cette liste
    //Cellule<TypeInfo>* insereAtPositRecFuncWorker(Cellule<TypeInfo>* ptrCetteListe, int nouvellePosition, const TypeInfo& nouvelleInfo);    
    //Cellule<TypeInfo>* supprimeAtPositRecFuncWorker(Cellule<TypeInfo>* ptrCetteListe, int position);


    // Les deux méthodes suivantes sont des procédures qui ont un premier paramètre
    // cette liste qui est un paramètre donnée résultat
    void insereAtPositRecProcWorker(Cellule<TypeInfo>*& ptrCetteListe, int nouvellePosition, const TypeInfo& nouvelleInfo);
    void supprimeAtPositRecProcWorker(Cellule<TypeInfo>*& ptrCetteListe, int position);


    //------------------------------------------------------------
    // Section des méthodes "atomiques"
    //------------------------------------------------------------
    void insereTeteWorker(Cellule<TypeInfo>*& ptrCetteListe, const TypeInfo& nouvelleInfo);
    void supprimeTeteWorker(Cellule<TypeInfo>*& ptrCetteListe);

    //------------------------------------------------------------
    // Section des méthodes de parcours
    //------------------------------------------------------------
    void afficheGDWorker(const Cellule<TypeInfo>* ptrListe) const;
    void afficheDGWorker(const Cellule<TypeInfo>* ptrListe) const;
    void afficheGDIterWorker(Cellule<TypeInfo>* ptrListe) const;
    void afficheDGIterWorker(Cellule<TypeInfo>* ptrListe) const;
    
    bool estInfoPresentRecWorker(Cellule<TypeInfo>* ptrCetteListe, const TypeInfo& infoCible);
    // retourne true si infoCible est présente dans cetteListeChainee; 
    // retourne false si infoCible est absente decette ListeChainee


public:
    ListeChainee();
    ListeChainee(const ListeChainee<TypeInfo>& uneListeChainee);
    virtual ~ListeChainee();

    bool estVide() const;
    int getLongueur() const;

    void insereTete(const TypeInfo& nouvelleInfo);
    void supprimeTete();

    bool insereAtPositIter(int nouvellePosition, const TypeInfo& nouvelleInfo);

    bool insereAtPositRecAvecProc(int nouvellePosition, const TypeInfo& nouvelleInfo);

    bool supprimeAtPositIter(int position);

    bool supprimeAtPositRecAvecProc(int position);

    void videIter();
    void videRec();

    TypeInfo getInfoAtPositRec(int position) const throw (PrecondVioleeExcep);

    void setInfoAtPositRec(int position, const TypeInfo& nouvelleInfo) throw (PrecondVioleeExcep);

    // Affichage récursif de la liste ; parcours de gauche à droite
    void afficheGD();

    // Affichage récursif de la liste ; parcours de droite à gauche
    void afficheDG();

    // Affichage itératif de la liste ; parcours de gauche à droite
    void afficheGDIter() const;

    // Affichage itératif de la liste ; parcours de gauche à droite
    void afficheDGIter() const;
    
    bool estInfoPresentRec(TypeInfo &infoCible);
    // retourne true si infoCible est présente dans cetteListeChainee; 
    // retourne false si infoCible est absente decette ListeChainee

    /**
     * 
     * @return true si trié false sinon
     */
    bool estTrie();
    
    bool estTrieWorker(Cellule<TypeInfo>* ptrListe);
    
    /**
     * 
     * @param infoCible l'info à rechercher
     * @return true si présent false sinon
     */
    bool estInfoPresentRecDicho(TypeInfo &infoCible);
    
    bool estInfoPresentRecDichoWorker(Cellule<TypeInfo>* ptrListe, TypeInfo &infoCible, int inf, int sup);
    
}; // end ListeChainee

#include "ListeChainee.cpp"

#endif 
