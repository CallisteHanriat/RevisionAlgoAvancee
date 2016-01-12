//  HB 

/** TAD pile : Implémentation sous forme de Cellules.
    @file PileCellules.h */

#ifndef PILECELLULES_H
#define	PILECELLULES_H

#include "PileInterface.h"
#include "Cellule.h"
#include "PrecondVioleeExcep.h"

template<class TypeInfo>
class PileCellules : public PileInterface<TypeInfo> {
private:
    Cellule<TypeInfo>* ptrSommet; // pointeur sur le sommet de la pile;

    void vide();
    
public:
    PileCellules();
    PileCellules(const PileCellules<TypeInfo>& unePile);
    virtual ~PileCellules();

    bool estVide() const;

    void empile(const TypeInfo& nouvelleInfo) throw (bad_alloc);

    bool depile() throw (PrecondVioleeExcep);
    
    TypeInfo consulteSommet() const throw (PrecondVioleeExcep);

}; // end PileCellules

#include "PileCellules.cpp"

#endif	/* PILECELLULES_H */

