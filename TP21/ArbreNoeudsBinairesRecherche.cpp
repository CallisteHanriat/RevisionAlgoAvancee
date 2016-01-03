//  HB librement inspiré de
//  Data Abstraction & Problem Solving with C++: Walls and Mirrors
//  Frank M. Carrano and Tim Henry.
//  2013 – Pearson Education

/** @file ArbreNoeudsBinairesRecherche.cpp */

#ifdef _ARBRE_NOEUDS_BINAIRES_RECHERCHE

#include <iostream>

#include "ArbreNoeudsBinairesRecherche.h"

using namespace std;

//////////////////////////////////////////////////////////////
//
//      METHODES UTILITAIRES PRIVEES 
//
//////////////////////////////////////////////////////////////

template<class TypeInfo>
int ArbreNoeudBinaireRecherche<TypeInfo>::getHauteurWorker(NoeudBinaire<TypeInfo>* ptrRac) const {
    
    
    /*
     * À COMPLETER : ALGORITHME  (NOTER LE, C'EST POUR VOUS !!!
     */
    
    /*
     * À COMPLETER : IMPLANTATION
     */
    
    // A ENLEVER LORSQUE L'IMPLANTATION EST FAITE !!
    return 0;
    
    
} // end getHauteurWorker

template<class TypeInfo>
int ArbreNoeudBinaireRecherche<TypeInfo>::getNombreDeNoeudsWorker(NoeudBinaire<TypeInfo>* ptrRac) const {
        
    
    /*
     * À COMPLETER : ALGORITHME  (NOTER LE, C'EST POUR VOUS !!!
     */
    
    /*
     * À COMPLETER : IMPLANTATION
     */
    
    // A ENLEVER LORSQUE L'IMPLANTATION EST FAITE !!
    return 0;
    
    
} // end getNombreDeNoeudsWorker

template<class TypeInfo>
void ArbreNoeudBinaireRecherche<TypeInfo>::videWorker(NoeudBinaire<TypeInfo>* ptrRac) {
    // on applique directement la définition récursive
    // Note, il faut faire un parcours postfixé !!!!!
    // > ptrRac == null -> rien à faire !
    // > ptrRac != null -> vider(sous-arbre gauche); vider(sous-arbre droit); libérer(ptrRac)
    if (ptrRac != nullptr) {
        videWorker(ptrRac->getPtrFilsGauche());
        videWorker(ptrRac->getPtrFilsDroit());
        delete ptrRac;
    } // end if
} // end videWorker

template<class TypeInfo>
NoeudBinaire<TypeInfo>* ArbreNoeudBinaireRecherche<TypeInfo>::copieArbre(const NoeudBinaire<TypeInfo>* ptrABR) const {
    // initialiser la copie avec un arbre vide
    NoeudBinaire<TypeInfo>* ptrCopieABR = nullptr;

    // copier les noeuds de ptrABR dans la copie en faisant un parcours 
    // récursif préfixé (racine, gauche, droite) de ptrABR
    if (ptrABR != nullptr) {
        // Copy node
        ptrCopieABR = new NoeudBinaire<TypeInfo>(ptrABR->getInfo(), nullptr, nullptr);
        ptrCopieABR->setPtrFilsGauche(copieArbre(ptrABR->getPtrFilsGauche()));
        ptrCopieABR->setPtrFilsDroit(copieArbre(ptrABR->getPtrFilsDroit()));
    } // end if
    // rendre la copie
    return ptrCopieABR;
} // end copieArbre

template<class TypeInfo>
void ArbreNoeudBinaireRecherche<TypeInfo>::insertWorker(NoeudBinaire<TypeInfo>*& ptrRac, const TypeInfo& nouvelleInfo) {   
    
    /*
     * À COMPLETER : ALGORITHME  (NOTER LE, C'EST POUR VOUS !!!
     */
    
    /*
     * À COMPLETER : IMPLANTATION
     */
    
    
} // end insertWorker

template<class TypeInfo>
NoeudBinaire<TypeInfo>* ArbreNoeudBinaireRecherche<TypeInfo>::supprimeInfo(NoeudBinaire<TypeInfo>* ptrRac,
        const TypeInfo infoCible,
        bool& suppressionPossible) {
    // On applique la définiton décursive de la suppression
    if (ptrRac == nullptr) {
        // arbre vide, on ne peut pas supprimer, l'arbre résutlat est vide aussi
        suppressionPossible = false;
    } else if (ptrRac->getInfo() == infoCible) {
        // infoCible est à la racine de l'arbre
        ptrRac = supprimeNoeud(ptrRac);
        suppressionPossible = true;
    } else if (ptrRac->getInfo() > infoCible) {
        // supprimer dans le sous-arbre gauche
        ptrRac->setPtrFilsGauche(supprimeInfo(ptrRac->getPtrFilsGauche(), infoCible, suppressionPossible));
    } else {
        // upprimer dans le sous-arbre droit
        ptrRac->setPtrFilsDroit(supprimeInfo(ptrRac->getPtrFilsDroit(), infoCible, suppressionPossible));
    } // end if
    return ptrRac;
} // end supprimeInfo

template<class TypeInfo>
NoeudBinaire<TypeInfo>* ArbreNoeudBinaireRecherche<TypeInfo>::supprimeNoeud(NoeudBinaire<TypeInfo>* ptrNoeud) {
    // Cas 1) ptrNoeud est une feuille - il est supprimé, l'arbre est vide
    // Cas 2) ptrNoeud a un seul sous-arbre - le parent adopte ce sous-arbre
    // Cas 3) ptrNoeud a deux sous-arbres :
    //               implémentation traditionnelle : trouver le noeud successeur.
    //               implémentation alternative : trouver la valeur successeur et remplacer la valeur du noeud ;
    //                  cette approche ne requière pas un passage par référence
    if (ptrNoeud->estFeuille()) {
        delete ptrNoeud;
        return (ptrNoeud = nullptr); // affectation et retour
    } else if (ptrNoeud->getPtrFilsGauche() == nullptr) { // un sous-arbre droit uniquement
        // récupérer le sous-arbre droit
        NoeudBinaire<TypeInfo>* prtNoeudAConnecter = ptrNoeud->getPtrFilsDroit();
        // supprimer le noeud
        delete ptrNoeud;
        ptrNoeud = nullptr;
        // retourner le sous-arbre droit (adoption)
        return prtNoeudAConnecter;
    } else if (ptrNoeud->getPtrFilsDroit() == nullptr) { // un sous-arbre gauche uniquement
        // récupérer le sous-arbre gauche
        NoeudBinaire<TypeInfo>* prtNoeudAConnecter = ptrNoeud->getPtrFilsGauche();
        // supprimer le noeud
        delete ptrNoeud;
        ptrNoeud = nullptr;
        // retourner le sous-arbre gauche
        return prtNoeudAConnecter;
    } else { // deux sous arbres !!
        // APPROCHE TRADITIONNELLE pour supprimer une valeur sur un noeud avec deux sous-arbres
        // besoin d'une nouvelle info -> PASSAGE PAR REFERENCE !!! dans supprimeNoeudLePlusAGauche infra
        TypeInfo valeurNouveauNoeud;
        // le sous-arbre droit est le sous-arbre droit privé de son noeud le plus à gauche
        ptrNoeud->setPtrFilsDroit(supprimeNoeudLePlusAGauche(ptrNoeud->getPtrFilsDroit(), valeurNouveauNoeud));
        // le sous-arbre gauche est inchangé !
        // l'info portée par le noeud est l'info portée par le noeud le plus à gauche du sous-arbre droit que l'on vient de supprimer
        ptrNoeud->setInfo(valeurNouveauNoeud);
        // retourner le nouveau noeud ainsi construit
        return ptrNoeud;
    } // end if
} // end supprimeNoeud

template<class TypeInfo>
NoeudBinaire<TypeInfo>* ArbreNoeudBinaireRecherche<TypeInfo>::supprimeNoeudLePlusAGauche(NoeudBinaire<TypeInfo>* ptrNoeud,
        TypeInfo& successeurLePlusProche) {
    // on applique la définition récursive
    // > je (ptrNoeud) n'ai pas de sous-arbre-gauche
    //                  -> je suis donc le successeur le plus à gauche
    //                  ->(mettre à jour successeurLePlusProche, retouner l'abre dans lequel je me supprime)
    // > j'ai un sous-arbre-gauche
    //                  -> faire le traitement sur mon sous-arbre gauche
    //                  -> (successeurLePlusProche sera mis à jour, retourner le sous-arbre construit)
    if (ptrNoeud->getPtrFilsGauche() == nullptr) {
        successeurLePlusProche = ptrNoeud->getInfo();
        return supprimeNoeud(ptrNoeud);
    } else {
        ptrNoeud->setPtrFilsGauche(supprimeNoeudLePlusAGauche(ptrNoeud->getPtrFilsGauche(), successeurLePlusProche));
        return ptrNoeud;
    } // end if      
} // end supprimeNoeudLePlusAGauche

template<class TypeInfo>
bool ArbreNoeudBinaireRecherche<TypeInfo>::estInfoPresenteWorker(NoeudBinaire<TypeInfo>* ptrRac,
        const TypeInfo& infoCible) const {
        
    
    /*
     * À COMPLETER : ALGORITHME  (NOTER LE, C'EST POUR VOUS !!!
     */
    
    /*
     * À COMPLETER : IMPLANTATION
     */
    
    // A ENLEVER LORSQUE L'IMPLANTATION EST FAITE !!
    return true;
    
    
} // end estInfoPresenteWorker


//////////////////////////////////////////////////////////////
//      MWorkers des méthodes publiques pédagogiques
//////////////////////////////////////////////////////////////

/**
 * 
 * @param ptrRac
 * @return  nombre de feuilles dans la descendance de ptrRac
 */
template<class TypeInfo>
int ArbreNoeudBinaireRecherche<TypeInfo>::getNombreDeFeuillesWorker(const NoeudBinaire<TypeInfo>* ptrRac) const {
        
    
    /*
     * À COMPLETER : ALGORITHME  (NOTER LE, C'EST POUR VOUS !!!
     */
    
    /*
     * À COMPLETER : IMPLANTATION
     */
    
    // A ENLEVER LORSQUE L'IMPLANTATION EST FAITE !!
    return 0;
    
}

template<class TypeInfo>
bool ArbreNoeudBinaireRecherche<TypeInfo>::aMemeGeometrieQueWorker(const NoeudBinaire<TypeInfo>* monPtrRac, const NoeudBinaire<TypeInfo>* sonPtrRac) const {
        
    
    /*
     * À COMPLETER : ALGORITHME  (NOTER LE, C'EST POUR VOUS !!!
     */
    
    /*
     * À COMPLETER : IMPLANTATION
     */
    
    // A ENLEVER LORSQUE L'IMPLANTATION EST FAITE !!
    return true;
  
}

/**
 * @pre  ptrRac!=nulllptr
 * @param ptrRac
 * @return 
 */
template<class TypeInfo>
TypeInfo ArbreNoeudBinaireRecherche<TypeInfo>::getMaxWorker(const NoeudBinaire<TypeInfo>* ptrRac) const {
        
    
    /*
     * À COMPLETER : ALGORITHME  (NOTER LE, C'EST POUR VOUS !!!
     */
    
    /*
     * À COMPLETER : IMPLANTATION
     */
    
    // A ENLEVER LORSQUE L'IMPLANTATION EST FAITE !!
    return 0;
    
}

template<class TypeInfo>
int ArbreNoeudBinaireRecherche<TypeInfo>::getNombreOccurrencesWorker(const NoeudBinaire<TypeInfo>* ptrRac, const TypeInfo& uneInfo) const {
        
    
    /*
     * À COMPLETER : ALGORITHME  (NOTER LE, C'EST POUR VOUS !!!
     */
    
    /*
     * À COMPLETER : IMPLANTATION
     */
    
    // A ENLEVER LORSQUE L'IMPLANTATION EST FAITE !!
    return 0;
    
}

//////////////////////////////////////////////////////////////
//      worker d'affichage privés
//////////////////////////////////////////////////////////////

template<class TypeInfo>
void ArbreNoeudBinaireRecherche<TypeInfo>::affichePrefixeWorker(const NoeudBinaire<TypeInfo>* ptrRac) const {
        
    
    /*
     * À COMPLETER : ALGORITHME  (NOTER LE, C'EST POUR VOUS !!!
     */
    
    /*
     * À COMPLETER : IMPLANTATION
     */
        
}

template<class TypeInfo>
void ArbreNoeudBinaireRecherche<TypeInfo>::afficheInfixeWorker(const NoeudBinaire<TypeInfo>* ptrRac) const {
        
    
    /*
     * À COMPLETER : ALGORITHME  (NOTER LE, C'EST POUR VOUS !!!
     */
    
    /*
     * À COMPLETER : IMPLANTATION
     */
        
}

template<class TypeInfo>
void ArbreNoeudBinaireRecherche<TypeInfo>::affichePostfixeWorker(const NoeudBinaire<TypeInfo>* ptrRac) const {
        
    
    /*
     * À COMPLETER : ALGORITHME  (NOTER LE, C'EST POUR VOUS !!!
     */
    
    /*
     * À COMPLETER : IMPLANTATION
     */
        
}



//////////////////////////////////////////////////////////////
//      METHODES PUBIQUES - DEBUT ICI
//////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////
//      Section contructeurs et destructeur
//////////////////////////////////////////////////////////////

template<class TypeInfo>
ArbreNoeudBinaireRecherche<TypeInfo>::ArbreNoeudBinaireRecherche() : ptrRacine(nullptr) {
    // cet ABR est vide -> constuction de ptrRacine
} // end du constructeur par défaut

template<class TypeInfo>
ArbreNoeudBinaireRecherche<TypeInfo>::ArbreNoeudBinaireRecherche(const TypeInfo& infoRacine) {
    // cet arbre a noeud racine contenant infoRacine et sans sous-arbre
    ptrRacine = new NoeudBinaire<TypeInfo>(infoRacine, nullptr, nullptr);
} // end constructeur avec une information

template<class TypeInfo>
ArbreNoeudBinaireRecherche<TypeInfo>::ArbreNoeudBinaireRecherche(const ArbreNoeudBinaireRecherche<TypeInfo>& arbreOriginal) {
    // cet arbre est une copie de arbreOriginal
    ptrRacine = copieArbre(arbreOriginal.ptrRacine);
} // end constructeur par copie

template<class TypeInfo>
ArbreNoeudBinaireRecherche<TypeInfo>::~ArbreNoeudBinaireRecherche() {
    // cet arbre est vidé
    this->videWorker(ptrRacine);
} // end destructeur


//////////////////////////////////////////////////////////////
//      Méthodes publiques de ArbreBinaireInterface
//////////////////////////////////////////////////////////////

template<class TypeInfo>
bool ArbreNoeudBinaireRecherche<TypeInfo>::estVide() const {
    // cet arbre est vide s'il n'a pas de noeud racine
    return ptrRacine == nullptr;
} // end estVide

template<class TypeInfo>
int ArbreNoeudBinaireRecherche<TypeInfo>::getHauteur() const {
    return getHauteurWorker(ptrRacine);
} // end getHauteur

template<class TypeInfo>
int ArbreNoeudBinaireRecherche<TypeInfo>::getNombreDeNoeuds() const {
    return getNombreDeNoeudsWorker(ptrRacine);
} // end getNombreDeNoeuds

template<class TypeInfo>
void ArbreNoeudBinaireRecherche<TypeInfo>::vide() {
    this->videWorker(ptrRacine);
    ptrRacine = nullptr;
} // end vide

template<class TypeInfo>
TypeInfo ArbreNoeudBinaireRecherche<TypeInfo>::getInfoRacine() const throw (PrecondViolatedExcep) {
    if (estVide()) {
        throw PrecondViolatedExcep("getInfoRacine() appelée sur un arbre binaire de recherche vide.");
    } else {
        return ptrRacine->getInfo();
    }
} // end getInfoRacine

template<class TypeInfo>
void ArbreNoeudBinaireRecherche<TypeInfo>::insere(const TypeInfo& nouvelleInfo) {
    insertWorker(ptrRacine, nouvelleInfo);
} // end insere

template<class TypeInfo>
bool ArbreNoeudBinaireRecherche<TypeInfo>::supprime(const TypeInfo& uneInfo) {
    bool isSuccessful = false;
    supprimeInfo(ptrRacine, uneInfo, isSuccessful);
    return isSuccessful;
} // end supprime

template<class TypeInfo>
bool ArbreNoeudBinaireRecherche<TypeInfo>::estInfoPresente(const TypeInfo& uneInfo) const {
    return estInfoPresenteWorker(ptrRacine, uneInfo); // nullptr is same as false
} // end estInfoPresente

//////////////////////////////////////////////////////////////
//      Méthodes publiques pédagogiques
//////////////////////////////////////////////////////////////

template<class TypeInfo>
int ArbreNoeudBinaireRecherche<TypeInfo>::getNombreDeFeuilles() const {
    return getNombreDeFeuillesWorker(ptrRacine);
}

template<class TypeInfo>
bool ArbreNoeudBinaireRecherche<TypeInfo>::aMemeGeometrieQue(const ArbreNoeudBinaireRecherche<TypeInfo>& autreArbre) const {
    return aMemeGeometrieQueWorker(ptrRacine, autreArbre.ptrRacine);
}

template<class TypeInfo>
TypeInfo ArbreNoeudBinaireRecherche<TypeInfo>::getMax() const throw (PrecondViolatedExcep) {
    // peut-on retourner le max
    if (ptrRacine == nullptr) {
        throw PrecondViolatedExcep("Pas de maximum sur un arbre vide !");
    } else {
        return getMaxWorker(ptrRacine);
    }
}

template<class TypeInfo>
int ArbreNoeudBinaireRecherche<TypeInfo>::getNombreOccurrences(const TypeInfo& uneInfo) const {
    return getNombreOccurrencesWorker(ptrRacine, uneInfo);
}


//////////////////////////////////////////////////////////////
//      Méthodes d'affichage publiques
//////////////////////////////////////////////////////////////

template<class TypeInfo>
void ArbreNoeudBinaireRecherche<TypeInfo>::affichePrefixe() const {
    cout << "En parcours préfixé, l'ABO contient : ";
    affichePrefixeWorker(ptrRacine);
    cout << endl;
}

template<class TypeInfo>
void ArbreNoeudBinaireRecherche<TypeInfo>::afficheInfixe() const {
    cout << "En parcours infixé, l'ABO contient : ";
    afficheInfixeWorker(ptrRacine);
    cout << endl;
}

template<class TypeInfo>
void ArbreNoeudBinaireRecherche<TypeInfo>::affichePostfixe() const {
    cout << "En parcours postfixé, l'ABO contient : ";
    affichePostfixeWorker(ptrRacine);
    cout << endl;
}


//////////////////////////////////////////////////////////////
//      Opérateur surchargé d'affectation
//////////////////////////////////////////////////////////////

template<class TypeInfo>
ArbreNoeudBinaireRecherche<TypeInfo>& ArbreNoeudBinaireRecherche<TypeInfo>::operator=(const ArbreNoeudBinaireRecherche<TypeInfo>& rightHandSide) {
    if (!estVide())
        vide();
    this = copieArbre(&rightHandSide);

    return *this;
} // end operator=

#endif


