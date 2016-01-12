//  HB librement inspiré de
//  Data Abstraction & Problem Solving with C++: Walls and Mirrors
//  Frank M. Carrano and Tim Henry.
//  2013 – Pearson Education


/** TDA liste triée : implémentation sous forme de liste chaînée.
 @file ListeTrieeChainee.h */

#ifndef _LISTE_CHAINEE_TRIEE
#define _LISTE_CHAINEE_TRIEE

#include "ListeTrieeInterface.h"
#include "Cellule.h"
#include "PrecondVioleeExcep.h"

template<class TypeInfo>
class ListeTrieeChainee : public ListeTrieeInterface<TypeInfo> {
private:
    Cellule<TypeInfo>* ptrTete; // Pointeur sur la première cellule de la liste
    int nbCellules; // nombre courant de cellules dans la liste

    /** Cherche la cellule qui précède la cellule qui contient ou devrait
     *   contenir la valeur donnée
     * 
     * @param unContenu  le contenu à trouver.
     * @return  soit un pointeur sur la cellule qui précède la cellule qui contient
     *    ou devrait contenir unContenu, soit nullptr si il n'existe pas de cellule prédédente.*/
    Cellule<TypeInfo>* getCellulePrecedente(const TypeInfo& unContenu) const;

    /**
     * Worker itératif
     * NOTE : utilise la macro assert pour vérifier que l'accès est possible
     *        (http://www.cplusplus.com/reference/cassert/assert/) avant de
     *        faire l'accès proprement dit
     * NOTE : si l'accès est impossible (assert) un message d'erreur est affiché
     *        sur la console et l'exécution du programme est interrompue
     * 
     * @param laPosition à laquelle accéder
     * @return un pointeur sur la cellule de cette ListeChaineeTriee
     */
    Cellule<TypeInfo>* getCelluleAtPosit(int laPosition) const;

    // Returne un pointeur sur une copie de la listeChaineeOriginale
    Cellule<TypeInfo>* copieListe(const Cellule<TypeInfo>* listeChaineeOriginale);

    /**
     * Worker récursif d'insertion de nouvelleInfo dans ptrCetteListe
     * @pre ptrCetteListe est triée avant insertion
     * @post ptrCetteListe est triée après insertion
     * @param ptrCetteListe : pointeur (donnée-référence) sur la "liste" de cellules dans laquelle insérer
     * @param nouvelleInfo : valeur à insérer
     */
    void insereRecWorker(Cellule<TypeInfo>*& ptrCetteListe, const TypeInfo& nouvelleInfo);

    /**
     * worker récursif de suppression de la première occurrence d'une uneInfo
     * @param ptrCetteListe : pointeur (donnée-résultat) sur la "liste" de Cellules
     * @param uneInfo : information à supprimer
     * @return : true si suppression possible (uneInfo présente) ; False sinon
     */
    bool supprimePremOccInfoRecWorker(Cellule<TypeInfo>*& ptrCetteListe, const TypeInfo& uneInfo);

    /**
     * worker récursif de suppression à position dans une liste
     * @param ptrCetteListe : pointeur (donnée-résultat) sur la "liste" de Cellules
     * @param laPosition : position à laquelle supprimer
     */
    void supprimeAtPositRecWorker(Cellule<TypeInfo>*& ptrCetteListe, const int laPosition);
 
    /**
     * worker d'accès à une information par position
     * @param ptrCetteListe : pointeur (donnée) sur la "liste" de Cellules
     * @param laPosition : position à consultée
     * @return : information trouvée si position accessible ; lève une exception sinon
     */
    TypeInfo getInfoAtPositRecWorker(const Cellule<TypeInfo>* ptrCetteListe, const int laPosition) const throw (PrecondVioleeExcep);

    void afficheCroissantRecWorker(const Cellule<TypeInfo>* ptrCetteListe) const;

    void afficheCroissantIterWorker(Cellule<TypeInfo>* ptrCetteListe) const;

    
    void insereTeteWorker(Cellule<TypeInfo>*& ptrTete, const TypeInfo& nouvelleInfo);
    
public:
    // Constructeur par défaut
    ListeTrieeChainee();
    // Constructeur à partir d'une liste chaînée exixtante
    ListeTrieeChainee(const ListeTrieeChainee<TypeInfo>& uneListe);
    // Destructeur
    virtual ~ListeTrieeChainee();

    /**
     *     /!\ ATTENTION /!\
     * 
     *  VOIR LA DOCUMENTATION DANS LA CLASSE ListeTrieeInterface 
     *
     */
    void supprimeTete(Cellule<TypeInfo>*& ptrTeteListe);
    void insere(const TypeInfo& nouvelleInfo);
    void insereRec(const TypeInfo& nouvelleInfo);
    bool supprimePremOccInfo(const TypeInfo& uneInfo);
    bool supprimePremOccInfoRec(const TypeInfo& uneInfo);
    int getPosit(const TypeInfo& uneInfo) const;
    void insereTete(const TypeInfo& nouvelleInfo);

    // Méthodes déjà founies dans ListeTrieeInterface:
    bool estVide() const;
    int getLongueur() const;
    bool supprimeAtPosit(int laPosition);
    bool supprimeAtPositRec(int laPosition);
    void vide();
    TypeInfo getInfoAtPosit(int laPosition) const throw (PrecondVioleeExcep);
    TypeInfo getInfoAtPositRec(int laPosition) const throw (PrecondVioleeExcep);

    // Méthodes pour l'affichage
    void afficheCroissantRec() const;
    void afficheCroissantIter() const;
}; // end ListeChaineeTriee

#include "ListeTrieeChainee.cpp"
#endif