Listes : 


template <class TypeInfo>
void ListeTrieeChainee<TypeInfo>::insereTeteWorker(Cellule<TypeInfo>*& ptrTete, const TypeInfo& nouvelleInfo) {
    Cellule<TypeInfo>* nouvellCellule = new Cellule<TypeInfo>(nouvelleInfo, ptrTete);
    nouvellCellule->setSuivante(ptrTete);
    ptrTete = nouvellCellule;
    nbCellules++;
}



template<class TypeInfo>
void ListeTrieeChainee<TypeInfo>::afficheCroissantRecWorker(const Cellule<TypeInfo>* ptrCetteListe) const {
    /*
     * ALGORITHME
     * =>ptrCour = nullptr
     *              ==>*
     * =>ptrCour != nullptr
     *              ==>affiche(ptrCour->getInfo())
     *              ==>afficheCroissantRecWorker(ptrCour->getSuivante())
     */

    /*
     * A COMPLETER
     */

    if(ptrCetteListe != nullptr) {
        cout << ptrCetteListe->getInfo() << endl;
        afficheCroissantRecWorker(ptrCetteListe->getSuivante());
    } 
} // end afficheCroissantRec




template<class TypeInfo>
void ListeTrieeChainee<TypeInfo>::afficheCroissantIterWorker(Cellule<TypeInfo>* ptrCetteListe) const {
    /*
     * ALGORITHME
     * =>ptrCour == null
     *          ==> *
     * =>ptrCour != null
     *          ==> affiche(info)
     *          ==> ptrCour = ptrCour->getSuivant()
     *  */
    
    /*
     * A COMPLETER
     */
    
    Cellule<TypeInfo>* ptrCour = ptrCetteListe;
    while(ptrCour != nullptr) {
        cout << ptrCour->getInfo() << endl;
        ptrCour = ptrCour->getSuivante();
    }
} // end afficheCroissantIter




template<class TypeInfo>
void ListeTrieeChainee<TypeInfo>::insereRecWorker(Cellule<TypeInfo>*& ptrCetteListe, const TypeInfo& nouvelleInfo) {

    
    if (ptrCetteListe == nullptr) {
        insereTete(nouvelleInfo);
    } else {
        if (nouvelleInfo < ptrCetteListe->getInfo()) {
            insereTeteWorker(ptrCetteListe, nouvelleInfo);
        } else {
            insereRecWorker(ptrCetteListe->getRefSuivante(), nouvelleInfo);
        }
    }
}




template<class TypeInfo>
int ListeTrieeChainee<TypeInfo>::getPosit(const TypeInfo& uneInfo) const {
    int position = 1; // initialisation
    // pointeur temporaire pour parcourir cette liste sans la détruire
    Cellule<TypeInfo>* ptrTemp = ptrTete;

    // tant que la liste n'est pas vide et que la valeur courante est strictement inférieure à la valeur à supprimer
    while ((ptrTemp != nullptr) && (uneInfo > ptrTemp->getInfo())) {
        // avancer sur cette liste et dans la position
        ptrTemp = ptrTemp->getSuivante();
        position++;
    } // end while

    // si on n'a pas trouvé (on a la position que la valeur devrait occuper)
    if ((ptrTemp == nullptr) || (uneInfo != ptrTemp->getInfo()))
        position = -position;

    return position;
} // end getPosit



template<class TypeInfo>
void ListeTrieeChainee<TypeInfo>::supprimeTete(Cellule<TypeInfo>*& ptrTeteListe) {
    Cellule<TypeInfo>* ptrCellASuppr = ptrTeteListe;
    if (ptrTeteListe != nullptr) {
        ptrTeteListe = ptrTeteListe->getSuivante();
        delete ptrCellASuppr;
        ptrCellASuppr = nullptr;
        nbCellules--;
    } 
}


template<class TypeInfo>
bool ListeTrieeChainee<TypeInfo>::supprimePremOccInfoRecWorker(Cellule<TypeInfo>*& ptrCetteListe, const TypeInfo & uneInfo) {
    if (ptrCetteListe != nullptr) {
        if (uneInfo > ptrCetteListe->getInfo()) {
            //cout << endl << "uneInfo < ptrCetteListe->getInfo()" << endl;
            return supprimePremOccInfoRecWorker(ptrCetteListe->getRefSuivante(), uneInfo);
        }
        else if (uneInfo == ptrCetteListe->getInfo()){
            //cout << endl << "uneInfo == ptrCetteListe->getInfo()" << endl;
            supprimeTete(ptrCetteListe);
            return true;
        } else
            return false;
    }
    return true;
}


template<class TypeInfo>
void ListeTrieeChainee<TypeInfo>::supprimeAtPositRecWorker(Cellule<TypeInfo>*& ptrCetteListe, const int laPosition) {
    if (ptrCetteListe != nullptr){
        if (laPosition > 1)
            supprimeAtPositRecWorker(ptrCetteListe->getRefSuivante(), laPosition-1);
        else
            supprimeTete(ptrCetteListe);
    }
}





