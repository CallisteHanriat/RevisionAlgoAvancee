//  HB librement inspiré de
//  Data Abstraction & Problem Solving with C++: Walls and Mirrors
//  Frank M. Carrano and Tim Henry.
//  2013 – Pearson Education

/** implantation des arbres binaires de recherche avec des noeuds chaînés
 @file ArbreNoeudsBinaireRecherche.h */

#ifndef _ARBRE_NOEUDS_BINAIRES_RECHERCHE
#define _ARBRE_NOEUDS_BINAIRES_RECHERCHE

#include "ArbreBinaireInterface.h"
#include "NoeudBinaire.h"
#include "ExceptionPreconditionViolee.h"

template<class TypeInfo>
class ArbreNoeudBinaireRecherche : public ArbreBinaireInterface<TypeInfo> {
private:
    NoeudBinaire<TypeInfo>* ptrRacine;

    //------------------------------------------------------------
    // Méthodes utilitaires privées :
    // Worker (qui fait le travail) d'une méthode publique.
    //------------------------------------------------------------

    // Calcul récursif de la hauteur de cet ABR.
    int getHauteurWorker(NoeudBinaire<TypeInfo>* ptrRac) const;
    
    // Calcul récursif du nombre de noeuds de cet ABR.
    int getNombreDeNoeudsWorker(NoeudBinaire<TypeInfo>* ptrRac) const;

    // Suppression récursive de tous le noeuds de cet ABR.
    void videWorker(NoeudBinaire<TypeInfo>* ptrRac);

    // recherche récursive de la place où insérer ptrNouveauNoeud dans
    // ptrRac qui est un ABR et insertion à cette place.
    // on obtient un ABR
    void insertWorker(NoeudBinaire<TypeInfo>*& ptrRac, const TypeInfo& nouvelleInfo);

    // supprime l'information infoCible de ptrRac qui est ABR.
    // on obtient un ABR
    // suppressionPossible est vrai si la suppression a eu lieu
    // supprime l'information infoCible de ptrRac qui est ABR.
    // on obtient un ABR
    // suppressionPossible est vrai si la suppression a eu lieu
    NoeudBinaire<TypeInfo>* supprimeInfo(NoeudBinaire<TypeInfo>* ptrRac,
            const TypeInfo infoCible,
            bool& suppressionPossible);

    // supprime un noeud (ptrNoeud) de cet ABR.
    // on obtient un ABR
    NoeudBinaire<TypeInfo>* supprimeNoeud(NoeudBinaire<TypeInfo>* ptrNoeud);

    // Supprime le noeud le plus à gauche dans la sous arbre gauche de ptrRac.
    // donne la valeur de successeurLePlusProche (à droite) à ce noeud.
    // retourne un pointeur sur le sous arbre modifié
    NoeudBinaire<TypeInfo>* supprimeNoeudLePlusAGauche(NoeudBinaire<TypeInfo>* ptrRac, TypeInfo& successeurLePlusProche);
    
    // retourne un pointeur sur le noeuds l'ABR ptrABR qui contient infoCible,
    // nullptr si infoCible non trouvée.
    bool estInfoPresenteWorker(NoeudBinaire<TypeInfo>* ptrABR, const TypeInfo& infoCible) const;

    // copie l'ABR de rachine ptrABR et retourne un pointeur sur la copie.
    NoeudBinaire<TypeInfo>* copieArbre(const NoeudBinaire<TypeInfo>* ptrABR) const;
    
    // workers pour l'affichage récursif
    void affichePrefixeWorker(const NoeudBinaire<TypeInfo>* ptrRac) const;
    void afficheInfixeWorker(const NoeudBinaire<TypeInfo>* ptrRac) const;
    void affichePostfixeWorker(const NoeudBinaire<TypeInfo>* ptrRac) const;
    
    // workers des méthodes pédagogiques
    int getNombreDeFeuillesWorker(const NoeudBinaire<TypeInfo>* ptrRac) const;
    
    bool aMemeGeometrieQueWorker(const NoeudBinaire<TypeInfo>* monPtrRac, const NoeudBinaire<TypeInfo>* sonPtrRac) const;
    
    TypeInfo getMaxWorker(const NoeudBinaire<TypeInfo>* ptrRac) const;
    
    int getNombreOccurrencesWorker(const NoeudBinaire<TypeInfo>* ptrRac, const TypeInfo& uneInfo) const;


public:
    //------------------------------------------------------------
    // Constructeurs et destructeurs
    //------------------------------------------------------------
    ArbreNoeudBinaireRecherche();
    ArbreNoeudBinaireRecherche(const TypeInfo& infoRacine);
    ArbreNoeudBinaireRecherche(const ArbreNoeudBinaireRecherche<TypeInfo>& arbreOriginal);
    virtual ~ArbreNoeudBinaireRecherche();

    //------------------------------------------------------------
    // Méthodes publiques
    //------------------------------------------------------------
    bool estVide() const;
    int getHauteur() const;
    int getNombreDeNoeuds() const;
    TypeInfo getInfoRacine() const throw (PrecondViolatedExcep);
    void insere(const TypeInfo& nouvelleInfo);
    bool supprime(const TypeInfo& uneInfo);
    void vide();
    bool estInfoPresente(const TypeInfo& uneInfo) const;
    
    //------------------------------------------------------------
    // Méthodes publiques RECURSIVES pédagogiques
    //------------------------------------------------------------
    
    /**
     * 
     * @return  le nombre de feuilles de cet arbre
     */
    int getNombreDeFeuilles() const;
    
    /**
     * cet arbre a-t-il la même géométrie que l'autreArbre
     * @param autreArbre
     * @return  true les cet arbre et autreArbre ont la même géométrie ; false sinon
     */
    bool aMemeGeometrieQue(const ArbreNoeudBinaireRecherche<TypeInfo>& autreArbre) const;
    
    /**
     * retourne une exception si l'arbre est vide
     * @return  la plus grand information contenue dans cet arbre
     */
    TypeInfo getMax() const throw (PrecondViolatedExcep);
    
    /**
     * 
     * @param uneInfo
     * @return  nombre d'occurrences de uneInfo dans cet arbre
     */
    int getNombreOccurrences(const TypeInfo& uneInfo) const;
        
    
    //------------------------------------------------------------
    // Méthodes publiques d'affichage
    //------------------------------------------------------------
    void affichePrefixe() const;
    void affichePostfixe() const;
    void afficheInfixe() const;


    //------------------------------------------------------------
    // Opérateur surchargé
    //------------------------------------------------------------
    // On surchagre ici l'opérateur d'affectation nouvelArbre = arbreExistant;
    // nouvelArbre est une copie de arbreExistant
    ArbreNoeudBinaireRecherche<TypeInfo>& operator=(const ArbreNoeudBinaireRecherche<TypeInfo>& rightHandSide);
    
}; // end ArbreBinaireRecherche

#include "ArbreNoeudsBinairesRecherche.cpp"

#endif