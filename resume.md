Listes : 

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
