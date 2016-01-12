/************************
 *    ETUDIANT
 ************************/

/** Implementation de la classe ListeChainee.
    @file ListeChainee.cpp */

#ifdef _LISTE_CHAINEE

#include <cassert>
#include <cstdlib>

#include "Cellule.h"
#include "ListeChainee.h"
#include "PileCellules.h"

/*
 * POUR LA DERNIERE PARTIE DU TP
 */
//#include "PileCellules.h"



using namespace std;

/****************************************************************************
      CONSTRUCTEURS                                                       
 ****************************************************************************/

/* FOURNI */
// Constructeur par défaut : fabrique une liste vide de longueur 0

template<class TypeInfo>
ListeChainee<TypeInfo>::ListeChainee() : ptrTete(nullptr), nbCellules(0) {
    // appel des constructeurs de ptrTete et de nbCellules
    // rien à faire dans le corps
} // end constructeur par défaut

/* FOURNI */
template<class TypeInfo>
ListeChainee<TypeInfo>::ListeChainee(const ListeChainee<TypeInfo>& uneListeChainee) : nbCellules(uneListeChainee.nbCellules) {
    // Constructeur par copie : fabrique une nouvelle liste par copie de la liste passée en paramètre

    // le nombre de Cellules de cette liste est égal au nombre de Cellules le la liste copiée nbCellules(uneListeChainee.nbCellules)

    // construction de la copie
    // pointeur sur uneListeChainee pour la parcourir sans la détruire (const)
    Cellule<TypeInfo>* ptrListeOriginale = uneListeChainee.ptrTete;

    if (ptrListeOriginale == nullptr) {
        // La liste uneListeChainee est vide donc cette liste est vide !
        ptrTete = nullptr;
    } else {
        // La liste uneListeChainee n'est pas vide !

        // Copie de la première cellule
        ptrTete = new Cellule<TypeInfo>(); //création de la nouvelle liste avec le constructeur par défaut
        ptrTete->setInfo(ptrListeOriginale->getInfo()); //màj de info

        // Ou en une seule instruction avec le constructeur qui prend une information
        // ptrTete = new Cellule<TypeInfo>(ptrListeOriginale->getInfo());

        // Copie des cellules suivantes
        Cellule<TypeInfo>* ptrNouvelleListe = ptrTete; // pointeur sur la dernière cellule de la nouvelle liste
        ptrListeOriginale = ptrListeOriginale->getSuivante(); // avancer sur la liste originale
        // tant que la liste originale n'est pas vide
        while (ptrListeOriginale != nullptr) {
            // obtenir l'information portée par la première cellule
            TypeInfo infoSuivante = ptrListeOriginale->getInfo();
            // créer une nouvelle cellule contenant l'infoSuivante
            Cellule<TypeInfo>* newCellulePtr = new Cellule<TypeInfo>(infoSuivante);
            // mettre à jour le suivant de la dernière cellule de la nouvelle liste
            ptrNouvelleListe->setSuivante(newCellulePtr);
            // mettre à jour le pointeur sur la dernière cellule de le nouvelle liste     
            ptrNouvelleListe = ptrNouvelleListe->getSuivante();
            // avancer dans la liste originale
            ptrListeOriginale = ptrListeOriginale->getSuivante();
        } // end while

        ptrNouvelleListe->setSuivante(nullptr); // arrêter cette liste (la denière cellule n'a pas de successeur)
    } // end if
} // end constructeur par copie

/****************************************************************************
      DESTRUCTEUR                                                         
 ****************************************************************************/

/* FOURNI */
template<class TypeInfo>
ListeChainee<TypeInfo>::~ListeChainee() {
    // appel de la méthode de nettoyage
    videIter();
} // end destructeur

/****************************************************************************
      METHODES UTILITAIRES PUBLIQUES                                      
 ****************************************************************************/

/* FOURNI */
template<class TypeInfo>
bool ListeChainee<TypeInfo>::estVide() const {
    // je suis vide si je ne contiens aucune cellule
    return nbCellules == 0;
} // end estVide

/* FOURNI */
template<class TypeInfo>
int ListeChainee<TypeInfo>::getLongueur() const {
    return nbCellules;
} // end getLongueur

/* FOURNI */
template<class TypeInfo>
void ListeChainee<TypeInfo>::insereTete(const TypeInfo& nouvelleInfo) {
    // appel de l'insertion en tête dans la liste ptrTete
    insereTeteWorker(ptrTete, nouvelleInfo);
} // end insereTete

/* FOURNI */
template<class TypeInfo>
void ListeChainee<TypeInfo>::supprimeTete() {
    // appel de l'insertion en tête dans la liste ptrTete
    supprimeTeteWorker(ptrTete);
} // end supprimeTete

/*
 * A COMPLETER
 */
template<class TypeInfo>
bool ListeChainee<TypeInfo>::insereAtPositIter(int nouvellePosition, const TypeInfo& nouvelleInfo) {

    /*
     * A COMPLETER
     */


    /* RAISONNEMENT
     */

    /* TABLEAU DE SORTIE
     */

    /* RESULTAT
     */
    if (nouvellePosition < 1 || nouvellePosition > nbCellules + 1) {
        return false;
    } else if (nouvellePosition == 1){
        insereTeteWorker(ptrTete, nouvelleInfo);
    } else {
        int posCour = 1;
        Cellule<TypeInfo>* ptrCour = ptrTete;
        while (posCour < nouvellePosition - 1) {
            posCour++;
            ptrCour = ptrCour->getSuivante();
        }
        insereTeteWorker(ptrCour->getRefSuivante(), nouvelleInfo);
        return true;
    }

} // end inserePositIter

/* FOURNI */
template<class TypeInfo>
bool ListeChainee<TypeInfo>::insereAtPositRecAvecProc(int nouvellePosition, const TypeInfo& nouvelleInfo) {
    // Insertion récursive avec un Worker procédure

    // si insertion possible appeller insereAtPositRecProcWorker() qui met à jour cette liste
    bool insertionPossible = (nouvellePosition >= 1) && (nouvellePosition <= nbCellules + 1);
    if (insertionPossible) {
        // mise à jour ce dette liste (ptrTete)
        insereAtPositRecProcWorker(ptrTete, nouvellePosition, nouvelleInfo);
    } // end if

    return insertionPossible;
} // end insereAtPositRecAvecProc

/*
 * A COMPLETER
 */
template<class TypeInfo>
bool ListeChainee<TypeInfo>::supprimeAtPositIter(int position) {
    /*
     * A COMPLETER
     */


    /* RAISONNEMENT
     */

    /* TABLEAU DE SORTIE
     */

    /* RESULTAT
     */
    if (position < 1 || position > nbCellules) {
        return false;
    } else {
        int posCour = 1;
        Cellule<TypeInfo>* ptrCour = ptrTete;
        while (posCour < position - 1) {
            posCour++;
            ptrCour = ptrCour->getSuivante();
        }
        supprimeTeteWorker(ptrCour->getRefSuivante());
        return true;
    }

    return true; // A SUPPRIMER

} // end supprimeAtPositIter

/* FOURNI */
template<class TypeInfo>
bool ListeChainee<TypeInfo>::supprimeAtPositRecAvecProc(int position) {
    // Suppression récursive avec un Worker procédure

    // si suppression possible appeller supprimeAtPositRecProcWorker() qui met à jour cette liste
    bool suppressionPossible = (position >= 1) && (position <= nbCellules);
    if (suppressionPossible) {
        supprimeAtPositRecProcWorker(ptrTete, position);
    }
    return suppressionPossible;
} // end supprimeAtPositRecAvecFunc

/* FOURNI */
template<class TypeInfo>
void ListeChainee<TypeInfo>::videRec() {
    // Utilisation du Worker récusif

    videRecWorker(ptrTete);
    ptrTete = nullptr;
} // end videRec

/* FOURNI */
template<class TypeInfo>
void ListeChainee<TypeInfo>::videIter() {
    // Version itérative supprimant en première position

    while (!estVide()) {
        // quand supprimeAtPositIter() est implanté
        //supprimeAtPositIter(1);
        supprimeTete();
    }
} // end vide

/* FOURNI */
template<class TypeInfo>
TypeInfo ListeChainee<TypeInfo>::getInfoAtPositRec(int position) const throw (PrecondVioleeExcep) {
    // Version hybride puisque l'on accède à la cellule avec getCelluleAtPositRec() et que l'on fait du contrôle
    // On pourrait faire une version complètement récursive avec un worker de prototype
    // TypeInfo ListeChainee<TypeInfo>::getInfoAtPositRecWorker(Cellule<TypeInfo>*& ptrCetteListe, int position)

    bool getPossible = (position >= 1) && (position <= nbCellules);
    // si l'accès est possible
    if (getPossible) {
        // récupérer un pointeur sur la cellule concernée
        Cellule<TypeInfo>* celluleVisee = getCelluleAtPositRec(ptrTete, position);
        // retourner l'information portée par la cellule concernée
        return celluleVisee->getInfo();

        // ou en une ligne
        //return getCelluleAtPositRec(ptrTete, position)->getInfo();
    } else
        throw (PrecondVioleeExcep("getInfoPositRec() appelée sur une liste vide ou un position invalide."));
} // end getInfoAtPositRec

/* FOURNI */
template<class TypeInfo>
void ListeChainee<TypeInfo>::setInfoAtPositRec(int position, const TypeInfo& nouvelleInfo) throw (PrecondVioleeExcep) {
    // Version hybride puisque l'on accède à la cellule avec getCelluleAtPositRec() et que l'on fait du contrôle
    // On pourrait faire une version complètement récursive avec un worker de prototype
    // TypeInfo ListeChainee<TypeInfo>::setInfoAtPositRecWorker(Cellule<TypeInfo>*& ptrCetteListe, int position, const TypeInfo& nouvelleInfo)

    bool setPossibe = (position >= 1) && (position <= nbCellules);
    // si l'accès est possible
    if (setPossibe) {
        // récuperer un pointeur sur la cellule visée
        Cellule<TypeInfo>* ptrCelluleVisee = getCelluleAtPositRec(ptrTete, position);
        // mettre à jour l'information
        ptrCelluleVisee->setInfo(nouvelleInfo);
    } else
        throw (PrecondVioleeExcep("setInfoPositRec() appelée avec une position non valide."));
} // end setInfoPositRec

template<class TypeInfo>
bool ListeChainee<TypeInfo>::estTrie() {
    return estTrieWorker(ptrTete);
}

template<class TypeInfo>
bool ListeChainee<TypeInfo>::estTrieWorker(Cellule<TypeInfo>* ptrListe){
    if (ptrListe == nullptr || ptrListe->getSuivante() == nullptr) {
        return true;
    } else if (ptrListe->getInfo() > ptrListe->getSuivante()->getInfo()){
        return false;
    } else {
        return estTrieWorker(ptrListe->getSuivante());
    }
}

template<class TypeInfo>
bool ListeChainee<TypeInfo>::estInfoPresentRecDicho(TypeInfo &infoCible) {
    return estInfoPresentRecDichoWorker(ptrTete, infoCible, 0, nbCellules - 1);
}

/*
template<class TypeInfo>
bool ListeChainee<TypeInfo>::estInfoPresentRecDichoWorker(Cellule<TypeInfo>* ptrListe, TypeInfo &infoCible, int inf, int sup){
    if (inf > sup){
        if (ptrListe->getInfo() == infoCible) {
            return inf + 1;
        } else {
            return estInfoPresentRecDichoWorker();
        }
    }
}
*/
/****************************************************************************
     METHODES PRIVEES RECURSIVES                                        
 ****************************************************************************/

/* FOURNI */

/* NOTE : Méthode privée, non définie dans l'interface*/
template<class TypeInfo>
Cellule<TypeInfo>* ListeChainee<TypeInfo>::getCelluleAtPositRec(Cellule<TypeInfo>* ptrCelluleCourante, int position) const {
    // Rappel
    // @pre  position est le rang de la cellule sur laquelle on veut pointer;
    //       position >= 1 and position <= itemCount.
    // On est donc certain de trouver pas besoin de considérer une liste vide !

    // > position == 1 => retrun ptrCelluleCourante; *
    // > postion > 1 => return getCelluleAtPositRec(ptrCelluleCourante->getSuivante(), position - 1);
    if (position == 1) {
        return ptrCelluleCourante;
    } else {
        return getCelluleAtPositRec(ptrCelluleCourante->getSuivante(), position - 1);
    }
}

/*
 * A COMPLETER
 */
template<class TypeInfo>
void ListeChainee<TypeInfo>::insereAtPositRecProcWorker(Cellule<TypeInfo>*& ptrCetteListe, int nouvellePosition, const TypeInfo& nouvelleInfo) {
    // Rappel
    // @pre  position est le rang de la cellule sur laquelle on veut pointer;
    //       position >= 1 and position <= itemCount.
    // On est donc certain de trouver pas besoin de considérer une liste vide !
    //
    // Noter que le premier paramètre est une référence sur un pointeur

    /* RAISONNEMENT
     */

    /* IMPLANTATION
     */
    if (nouvellePosition == 1) {
        insereTeteWorker(ptrCetteListe, nouvelleInfo);
    } else {
        insereAtPositRecProcWorker(ptrCetteListe->getRefSuivante(),
                                   nouvellePosition - 1,
                                   nouvelleInfo);
    }

} // end insereAtPositRecProcWorker

/*
 * A COMPLETER
 */
template<class TypeInfo>
void ListeChainee<TypeInfo>::supprimeAtPositRecProcWorker(Cellule<TypeInfo>*& ptrCetteListe, int position) {
    // Rappel
    // @pre  position est le rang de la cellule sur laquelle on veut pointer;
    //       position >= 1 and position <= itemCount.
    // On est donc certain de trouver pas besoin de considérer une liste vide !
    //
    // Noter que le premier paramètre est une référence sur un pointeur

    /* RAISONNEMENT
     */

    /* IMPLANTATION
     */
    if (position == 1) {
        supprimeTeteWorker(ptrCetteListe);
    } else {
        supprimeAtPositRecProcWorker(ptrCetteListe->getRefSuivante(),
                                   position - 1);
    }
    
} // end supprimeAtPositRecProcWorker

/****************************************************************************
     METHODES PRIVEES pour insereTete() et supprimeTete()                                          
 ****************************************************************************/

/* FOURNI */
template<class TypeInfo>
void ListeChainee<TypeInfo>::insereTeteWorker(Cellule<TypeInfo>*& ptrCetteListe, const TypeInfo& nouvelleInfo) {
    // création d'une cellule contenant la nouvelleInfo
    Cellule<TypeInfo>* ptrNouvelleCellule = new Cellule<TypeInfo>(nouvelleInfo);

    // la cellule suivante de cette cellule est la tête actuelle
    ptrNouvelleCellule->setSuivante(ptrCetteListe);

    // la nouvelle cellule de tête est la cellule contenant nouvelleInfo
    // MODIFICATION du paramètre résultat
    ptrCetteListe = ptrNouvelleCellule;

    nbCellules++; //une nouvelle cellule
} // end insereTeteWorker

/* FOURNI */
template<class TypeInfo>
void ListeChainee<TypeInfo>::supprimeTeteWorker(Cellule<TypeInfo>*& ptrCetteListe) {
    //  pointeur temporaire sur la première cellule
    Cellule<TypeInfo>* ptrCelluleASupprimer = ptrCetteListe;
    // si la liste n'est pas vide
    if (ptrCetteListe) {
        // la cellule suivante de la première cellule devient la nouvelle première cellule
        // MODIFICATION du paramètre résultat
        ptrCetteListe = ptrCetteListe->getSuivante();
        // rendre au tas la cellule à supprimer
        ptrCelluleASupprimer->setSuivante(nullptr);
        delete ptrCelluleASupprimer;
        ptrCelluleASupprimer = nullptr;
        nbCellules--; // une cellule en moins
    }
    // si la liste est déjà vide, ne rien faire
} // end supprimeTeteWorker

/****************************************************************************
     METHODES PRIVEES D'AFFICHAGE (workers récursifs)                                  
 ****************************************************************************/

/*
 * A COMPLETER
 */
template<class TypeInfo>
void ListeChainee<TypeInfo>::afficheGDWorker(const Cellule<TypeInfo>* ptrListe) const {
    /* RAISONNEMENT
     */

    /* IMPLANTATION
     */
    if (ptrListe){ 
        cout << ptrListe->getInfo() << " ";
        afficheGDWorker(ptrListe->getSuivante());
    }
    
}

/*
 * A COMPLETER
 */
template<class TypeInfo>
void ListeChainee<TypeInfo>::afficheDGWorker(const Cellule<TypeInfo>* ptrListe) const {
    /* RAISONNEMENT
     */

    /* IMPLANTATION
     */
    if (ptrListe){
        afficheDGWorker(ptrListe->getSuivante());
        cout << ptrListe->getInfo() << " ";
    }
}

/*
 * A COMPLETER
 */
template<class TypeInfo>
void ListeChainee<TypeInfo>::afficheGDIterWorker(Cellule<TypeInfo>* ptrListe) const {
    /* RAISONNEMENT
     */

    /* IMPLANTATION
     */
    while(ptrListe){
        cout << ptrListe->getInfo() << " ";
        ptrListe = ptrListe->getSuivante();
    }
}

/*
 * POUR LA DERNIERE PARTIE DU TP
 */
template<class TypeInfo>
void ListeChainee<TypeInfo>::afficheDGIterWorker(Cellule<TypeInfo>* ptrListe) const {
    PileCellules<Cellule<TypeInfo>*> pile;
    while(ptrListe){
        pile.empile(ptrListe);
        ptrListe = ptrListe->getSuivante();
    }
    while (!pile.estVide()) {
        cout << pile.consulteSommet()->getInfo() << " ";
        pile.depile();
    }
}

template<class TypeInfo>
bool ListeChainee<TypeInfo>::estInfoPresentRecWorker(Cellule<TypeInfo>* ptrCetteListe, const TypeInfo& infoCible) {
    if (ptrCetteListe){
        if (ptrCetteListe->getInfo() == infoCible) {
            return true;
        } else {
            return estInfoPresentRecWorker(ptrCetteListe->getSuivante(),
                                           infoCible);
        }
    } else {
        return false;
    }
}

/****************************************************************************
     METHODES PUBLIQUES D'AFFICHAGE qui font appel à un Worker                                         
 ****************************************************************************/

/* FOURNI */
template<class TypeInfo>
void ListeChainee<TypeInfo>::afficheGD() {
    cout << "En parcours récursif de gauche à droite, la liste contient -> ";
    afficheGDWorker(ptrTete);
    cout << endl;
}

/* FOURNI */
template<class TypeInfo>
void ListeChainee<TypeInfo>::afficheDG() {
    cout << "En parcours récursif de droite à gauche, la liste contient -> ";
    afficheDGWorker(ptrTete);
    cout << endl;
}

/* FOURNI */
template<class TypeInfo>
void ListeChainee<TypeInfo>::afficheGDIter() const {
    cout << "En parcours itératif de gauche à droite, la liste contient -> ";
    afficheGDIterWorker(ptrTete);
    cout << endl;
}

/*
 * POUR LA DERNIERE PARTIE DU TP
 * 
 * A COMPLETER
 */
template<class TypeInfo>
void ListeChainee<TypeInfo>::afficheDGIter() const {
    cout << "En parcours itératif de droite à gauche, la liste contient -> ";
    afficheDGIterWorker(ptrTete);
    cout << endl;
}

template<class TypeInfo>
bool ListeChainee<TypeInfo>::estInfoPresentRec(TypeInfo &infoCible) {
    return estInfoPresentRecWorker(ptrTete, infoCible);
}

/****************************************************************************
     METHODE PRVEE pour le nettoyage récursif                                        
 ****************************************************************************/

/* FOURNI */
template<class TypeInfo>
void ListeChainee<TypeInfo>::videRecWorker(Cellule<TypeInfo>* ptrCetteListe) {
    // > ptrCetteListe == nullptr => rien {la liste est vide} *
    // > ptrCetteListe != nullptr => supprimeTete(ptrCetteListe); nbcellules--; videRecWorker(ptrCetteListe);

    if (ptrCetteListe != nullptr) {
        // supprimer en tête (le nb de cellules est décrémenté dans supprimeTeteWorker())
        supprimeTeteWorker(ptrCetteListe);
        // vider la liste qui reste
        videRecWorker(ptrCetteListe);
    } // end if
} // end videRec


//  Fin implementation de la classe ListeChainee.

#endif