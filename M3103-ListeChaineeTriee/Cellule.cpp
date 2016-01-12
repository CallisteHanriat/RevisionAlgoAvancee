//  HB librement inspiré de
//  Data Abstraction & Problem Solving with C++: Walls and Mirrors
//  Frank M. Carrano and Tim Henry.
//  2013 – Pearson Education


#ifdef _CELLULE

template<class TypeInfo>
Cellule<TypeInfo>::Cellule() : ptrCellSuivante(nullptr) {
} // end constructeur par défaut

template<class TypeInfo>
Cellule<TypeInfo>::Cellule(const TypeInfo& uneInfo) : info(uneInfo), ptrCellSuivante(nullptr) {
} // end constructeur avec uneInfo

template<class TypeInfo>
Cellule<TypeInfo>::Cellule(const TypeInfo& uneInfo, Cellule<TypeInfo>* nextNodePtr) : info(uneInfo), ptrCellSuivante(nextNodePtr) {
} // end constructeur avec uneInfo et une "liste" de Cellules à la suite (comme un insertête)

template<class TypeInfo>
void Cellule<TypeInfo>::setInfo(const TypeInfo& uneInfo) {
    info = uneInfo;
} // end setInfo

template<class TypeInfo>
void Cellule<TypeInfo>::setSuivante(Cellule<TypeInfo>* nextNodePtr) {
    ptrCellSuivante = nextNodePtr;
} // end setSuivante

template<class TypeInfo>
TypeInfo Cellule<TypeInfo>::getInfo() const {
    return info;
} // end getContenu

template<class TypeInfo>
Cellule<TypeInfo>* Cellule<TypeInfo>::getSuivante() const {
    return ptrCellSuivante;
} // end getSuivante

template<class TypeInfo>
Cellule<TypeInfo>*& Cellule<TypeInfo>::getRefSuivante() {
    return ptrCellSuivante;
} // end getRefSuivante

#endif
