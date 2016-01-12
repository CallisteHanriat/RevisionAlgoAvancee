//  HB librement inspiré de
//  Data Abstraction & Problem Solving with C++: Walls and Mirrors
//  Frank M. Carrano and Tim Henry.
//  2013 – Pearson Education


/** Interface pour le type abstrait de données ListeTrieeInterface
 @file SortedListInterface.h */

#ifndef _LISTE_TRIEE_INTERFACE
#define _LISTE_TRIEE_INTERFACE

template<class TypeInfo>
class ListeTrieeInterface {
public:
    /** insère, à sa place, une Cellule contenant nouvelleInfo dans cette liste
     *   triée de telle façon quelle demeure triée
     * @pre Cette liste est triée
     * @post  uneInfo est insérée, et cette liste reste triée
     * @param uneInfo : contenu pour lequel insérer uen Cellule */
    virtual void insere(const TypeInfo& nouvelleInfo) = 0;

    /** insère (RECURSIF), à sa place, une Cellule contenant nouvelleInfo dans cette liste
     *   triée de telle façon quelle demeure triée
     * @pre Cette liste est triés
     * @post  uneInfo est insérée, et cette liste reste triée
     * @param uneInfo : contenu pour lequel insérer uen Cellule */
    virtual void insereRec(const TypeInfo& nouvelleInfo) = 0;

    /** supprime la première ou l'unique Cellule de cette liste triée
     *    contenant uneInfo.
     * @pre  Cette liste est triée.
     * @post  Si la suppression est possible, la première occurrence de
     *    uneInfo n'est plus présente dans cette liste, et la valeur retournée
     *    est vrai (true). Sinon, cette liste triée est inchangée et la
     *    valeur retournée est faux (false).
     * @param uneInfo  le contenu à supprimer.
     * @return  true si la suppression est possible, false sinon. */
    virtual bool supprimePremOccInfo(const TypeInfo& uneInfo) = 0;

    /** supprime RECURSIF de la première ou l'unique Cellule de cette liste triée
     *    conenant uneInfo.
     * @pre  Cette liste est triée.
     * @post  Si la suppression est possible, la première occurrence de
     *    uneInfo n'est plus présente dans cette liste, et la valeur retournée
     *    est vrai (true). Sinon, cette liste triée est inchangée et la
     *    valeur retournée est faux (false).
     * @param uneInfo  le contenu à supprimer.
     * @return  true si la suppression est possible, false sinon. */
    virtual bool supprimePremOccInfoRec(const TypeInfo& uneInfo) = 0;

    /** Retourne la position de la première ou de l'unique occurrence de uneInfo
     *    dans cette liste triée. Si uneInfo n'est pas dans cette liste,
     *    retourne la position que uneInfo devrait occuper.
     * 
     * NOTE : version ITERATIVE uniquement (récursif inutilement compliquée)
     * @pre  Cette liste est triée.
     * @post  La position qu'occupe ou que devrait occuper uneInfo est retourné.
     *    Cette liste chaînée n'est pas modifiée.
     * @param uneInfo  contenu à localiser.
     * @return  Soit la première position de uneInfo si présent dans cette liste ;
     *    soit la position que uneInfo devrait occupé comme entier négatif */
    virtual int getPosit(const TypeInfo& uneInfo) const = 0;

    /** cette liste est-elle vide ? */
    virtual bool estVide() const = 0;

    /** retourne le nombre de Cellules de cette liste. */
    virtual int getLongueur() const = 0;

    /** supprime la Cellule à la postion donnée dans cette liste. */
    virtual bool supprimeAtPosit(int position) = 0;

    /** supprime, RECUSIVE, la Cellule visée au rang position.
     *  la méthode utilise "un WORKER" qui est une PROCEDURE avec un paramètre donnée-résultat 
     * 
     * @pre  Aucune.
     * @post  si 1 <= position <= getLongueur() la suppression est réussie,
     *        la Cellule visée est supprimée de cette liste,
     *        et la valeur retournée est True ; sinon la valeur retournée est False.
     * @param position  rang de la Cellule visée à supprimer.
     * @return  True si la suppression est réussie, False sinon. */
    virtual bool supprimeAtPositRec(int position) = 0;
    
    /** supprime toutes les Cellules de cette liste. */
    virtual void vide() = 0;

    /** retourne l'information portée par la Cellule à position dans cette liste. */
    virtual TypeInfo getInfoAtPosit(int position) const = 0;

    /** retourne l'information portée par la Cellule à position dans cette liste. */
    virtual TypeInfo getInfoAtPositRec(int position) const = 0;

}; // end ListeTrieeInterface
#endif