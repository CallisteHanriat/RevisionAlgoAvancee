
#include "ArbreNoeudsBinairesRecherche.h" 
#include <iostream>

using namespace std;

void check(bool succes) {
    if (succes)
        cout << " Opération réussie." << endl;
    else
        cout << " Opération impossible." << endl;
} // end check

void testeInsertAffiche() {
    cout << "DÉBUT testeInsertAffiche() " << endl << endl;
    ArbreNoeudBinaireRecherche<int>* ptrArbre1 = new ArbreNoeudBinaireRecherche<int>();
    cout << "Arbre1 -> un arbre binaire de recherche dégénéré" << endl;
    ptrArbre1->insere(10);
    ptrArbre1->insere(20);
    ptrArbre1->insere(30);
    ptrArbre1->insere(40);
    ptrArbre1->insere(50);
    ptrArbre1->insere(60);
    ptrArbre1->insere(70);
    ptrArbre1->insere(80);
    //10
    //  \
    //  20
    //    \
    //    30
    //      \
    //      40
    //        \
    //        50
    //          \
    //          60
    //            \
    //            70
    //              \
    //              80

    cout << " Arbre1 en parcours préfixé doit être 10 20 30 40 50 60 70 80" << endl << "  ";
    ptrArbre1->affichePrefixe();

    cout << " Arbre1 en parcours infixé doit être 10 20 30 40 50 60 70 80" << endl << "  ";
    ptrArbre1->afficheInfixe();

    cout << " Arbre1 en parcours postfixé doit être 80 70 60 50 40 30 20 10" << endl << "  ";
    ptrArbre1->affichePostfixe();
    cout << endl << "FIN testeInsertAffiche() " << endl << endl;
}

void testeHauteur() {
    cout << "DÉBUT testeHauteur() " << endl << endl;
    ArbreNoeudBinaireRecherche<int>* ptrArbre1 = new ArbreNoeudBinaireRecherche<int>();
    cout << "Arbre1 -> un arbre binaire de recherche dégénéré" << endl;
    ptrArbre1->insere(10);
    ptrArbre1->insere(20);
    ptrArbre1->insere(30);
    ptrArbre1->insere(40);
    ptrArbre1->insere(50);
    ptrArbre1->insere(60);
    ptrArbre1->insere(70);
    ptrArbre1->insere(80);
    //10
    //  \
    //  20
    //    \
    //    30
    //      \
    //      40
    //        \
    //        50
    //          \
    //          60
    //            \
    //            70
    //              \
    //              80
    cout << " Hauteur de Arbre1 : " << ptrArbre1->getHauteur() << " ; doit être 8." << endl;
    cout << endl << "FIN testeHauteur() " << endl << endl;
}

void testeGetNombreNoeuds() {
    cout << "DÉBUT testeGetNbNoeuds() " << endl << endl;
    ArbreNoeudBinaireRecherche<int>* ptrArbre1 = new ArbreNoeudBinaireRecherche<int>();
    cout << "Arbre1 -> un arbre binaire de recherche dégénéré" << endl;
    ptrArbre1->insere(10);
    ptrArbre1->insere(20);
    ptrArbre1->insere(30);
    ptrArbre1->insere(40);
    ptrArbre1->insere(50);
    ptrArbre1->insere(60);
    ptrArbre1->insere(70);
    ptrArbre1->insere(80);
    //10
    //  \
    //  20
    //    \
    //    30
    //      \
    //      40
    //        \
    //        50
    //          \
    //          60
    //            \
    //            70
    //              \
    //              80

    cout << " Nombre de noeuds de Arbre1 : " << ptrArbre1->getNombreDeNoeuds() << " ; doit être 8." << endl;
    cout << endl << "FIN testeGetNbNoeuds() " << endl << endl;
}

void testeSuppression() {
    cout << "DÉBUT testeSuppression() " << endl << endl;
    ArbreNoeudBinaireRecherche<int>* ptrArbre1 = new ArbreNoeudBinaireRecherche<int>();
    cout << "Arbre1 -> un arbre binaire de recherche dégénéré" << endl;
    ptrArbre1->insere(10);
    ptrArbre1->insere(20);
    ptrArbre1->insere(30);
    ptrArbre1->insere(40);
    ptrArbre1->insere(50);
    ptrArbre1->insere(60);
    ptrArbre1->insere(70);
    ptrArbre1->insere(80);
    //10
    //  \
    //  20
    //    \
    //    30
    //      \
    //      40
    //        \
    //        50
    //          \
    //          60
    //            \
    //            70
    //              \
    //              80 
    cout << " Suppression de la feuille 80 : ";
    bool succes = ptrArbre1->supprime(80);
    check(succes);

    cout << " Essai de suppression de la feuille 80 de nouveau : ";
    succes = ptrArbre1->supprime(80);
    check(succes);

    cout << " Suppression du noeud 40 qui a seulement un fils droit : ";
    succes = ptrArbre1->supprime(40);
    check(succes);

    cout << " Arbre1 en parcours préfixé doit être 10 20 30 50 60 70" << endl << "  ";
    ptrArbre1->affichePrefixe();

    cout << " Arbre1 en parcours infixé doit être 10 20 30 50 60 70" << endl << "  ";
    ptrArbre1->afficheInfixe();

    cout << " Arbre1 en parcours postfixé doit être 70 60 50 30 20 10" << endl << "  ";
    ptrArbre1->affichePostfixe();

    cout << " Hauteur de Arbre1 : " << ptrArbre1->getHauteur() << " ; doit être 6." << endl;
    cout << " Nombre de noeuds de Arbre1 : " << ptrArbre1->getNombreDeNoeuds() << " ; doit être 6." << endl;

    cout << " Suppression de la racine 10 (a un sous-arbre droit) : ";
    succes = ptrArbre1->supprime(10);
    check(succes);

    // 20
    //   \
    //   30
    //     \
    //     50
    //       \
    //       60
    //         \
    //         70

    cout << " Arbre1 en parcours préfixé doit être 20 30 50 60 70" << endl << "  ";
    ptrArbre1->affichePrefixe();

    cout << " Arbre1 en parcours infixé doit être 20 30 50 60 70" << endl << "  ";
    ptrArbre1->afficheInfixe();

    cout << " Arbre1 en parcours post doit être 70 60 50 30 20" << endl << "  ";
    ptrArbre1->affichePostfixe();

    cout << " Hauteur de Arbre1 : " << ptrArbre1->getHauteur() << " ; doit être 5." << endl;
    cout << " Nombre de noeuds de Arbre1 : " << ptrArbre1->getNombreDeNoeuds() << " ; doit être 5." << endl;
    //===========================
    ArbreNoeudBinaireRecherche<int>* ptrArbre2 = new ArbreNoeudBinaireRecherche<int>();
    cout << endl << "Arbre2 -> un arbre binaire de recherche équilibré" << endl;
    ptrArbre2->insere(40);
    ptrArbre2->insere(20);
    ptrArbre2->insere(10);
    ptrArbre2->insere(30);
    ptrArbre2->insere(60);
    ptrArbre2->insere(50);
    ptrArbre2->insere(70);
    ptrArbre2->insere(80);

    //        40
    //     /      \
    //    20      60
    //   /  \    /  \
    //  10  30  50  70
    //               \
    //               80

    cout << " Arbre2 en parcours préfixé doit être 40 20 10 30 60 50 70 80" << endl << "  ";
    ptrArbre2->affichePrefixe();

    cout << " Arbre2 parcours infixé doit être 10 20 30 40 50 60 70 80" << endl << "  ";
    ptrArbre2->afficheInfixe();

    cout << " Arbre2 en parcours postfixé doit être 10 30 20 50 80 70 60 40" << endl << "  ";
    ptrArbre2->affichePostfixe();

    cout << " Hauteur de Arbre2 : " << ptrArbre2->getHauteur() << " ; doit être 4." << endl;
    cout << " Nombre de noeuds de Arbre2 : " << ptrArbre2->getNombreDeNoeuds() << " ; doit être 8." << endl;

    cout << " Suppression du noeud 70 qui a seulement un fils droit : ";
    succes = ptrArbre2->supprime(70);
    check(succes);
    //        40
    //     /      \
    //   20       60
    //   /  \    /  \
    // 10  30  50  80

    cout << " Arbre2 en parcours préfixé doit être 40 20 10 30 60 50 80" << endl << "  ";
    ptrArbre2->affichePrefixe();

    cout << " Arbre2 parcours infixé doit être 10 20 30 40 50 60 80" << endl << "  ";
    ptrArbre2->afficheInfixe();

    cout << " Arbre2 en parcours psotfixé doit être 10 30 20 50 80 60 40" << endl << "  ";
    ptrArbre2->affichePostfixe();

    cout << " Hauteur de Arbre2 : " << ptrArbre2->getHauteur() << " ; doit être 3." << endl;
    cout << " Nombre de noeuds de Arbre2 : " << ptrArbre2->getNombreDeNoeuds() << " ; doit être 7." << endl;

    cout << " Suppression du noeud 60 qui a deux sous-arbres (gauche et droit) -> 80 doit remonter à sa place";
    succes = ptrArbre2->supprime(60);
    check(succes);
    //        40
    //     /      \
    //    20      80
    //   /  \    /
    //  10  30  50

    cout << " Arbre2 en parcours préfixé doit être 40 20 10 30 80 50 " << endl << "  ";
    ptrArbre2->affichePrefixe();

    cout << " Arbre2 parcours infixé doit être 10 20 30 40 50 80" << endl << "  ";
    ptrArbre2->afficheInfixe();

    cout << " Arbre2 en parcours postfixé doit être 10 30 20 50 80 40" << endl << "  ";
    ptrArbre2->affichePostfixe();

    cout << " Hauteur de Arbre2 : " << ptrArbre2->getHauteur() << " ; doit être 3." << endl;
    cout << " Nombre de noeuds de Arbre2 : " << ptrArbre2->getNombreDeNoeuds() << " ; doit être 6." << endl;

    cout << " Suppression de la feuille 10: ";
    succes = ptrArbre2->supprime(10);
    check(succes);
    //        40
    //     /      \
    //    20      80
    //      \    /
    //      30  50

    cout << " Arbre2 en parcours préfixé doit être 40 20 30 80 50 " << endl << "  ";
    ptrArbre2->affichePrefixe();

    cout << " Arbre2 parcours infixé doit être 20 30 40 50 80" << endl << "  ";
    ptrArbre2->afficheInfixe();

    cout << " Arbre2 en parcours postfixé doit être 30 20 50 80 40" << endl << "  ";
    ptrArbre2->affichePostfixe();

    cout << " Arbre2 hauteur : " << ptrArbre2->getHauteur() << " ; doit être 3." << endl;
    cout << " Arbre2 nombre de noeuds : " << ptrArbre2->getNombreDeNoeuds() << " ; doit être 5." << endl;

    cout << " Suppression de la racine 40 : ";
    succes = ptrArbre2->supprime(40);
    check(succes);
    //      50
    //     /  \
    //   20   80
    //      \
    //      30

    cout << " Arbre2 en parcours préfixé doit être 50 20 30 80" << endl << "  ";
    ptrArbre2->affichePrefixe();

    cout << " Arbre2 parcours infixé doit être 20 30 50 80" << endl << "  ";
    ptrArbre2->afficheInfixe();

    cout << " Arbre2 en parcours postfixé doit être 30 20 80 50" << endl << "  ";
    ptrArbre2->affichePostfixe();

    cout << " Hauteur Arbre2 : " << ptrArbre2->getHauteur() << " ; doit être 3." << endl;
    cout << " Nombre de noeuds Arbre2 : " << ptrArbre2->getNombreDeNoeuds() << " ; doit être 4." << endl;
    cout << endl << "FIN testeSuppression() " << endl << endl;
}

void testeGetNombreFeuilles() {
    cout << "DÉBUT testeGetNbFeuilles() " << endl << endl;
    ArbreNoeudBinaireRecherche<int>* ptrArbre1 = new ArbreNoeudBinaireRecherche<int>();
    cout << "Arbre1 -> un arbre binaire de recherche équilibré" << endl;
    ptrArbre1->insere(40);
    ptrArbre1->insere(20);
    ptrArbre1->insere(10);
    ptrArbre1->insere(30);
    ptrArbre1->insere(60);
    ptrArbre1->insere(50);
    ptrArbre1->insere(70);
    ptrArbre1->insere(80);

    //        40
    //     /      \
    //    20      60
    //   /  \    /  \
    //  10  30  50  70
    //               \
    //               80

    cout << " Arbre1 en parcours préfixé doit être 40 20 10 30 60 50 70 80" << endl << "  ";
    ptrArbre1->affichePrefixe();

    cout << " Arbre1 parcours infixé doit être 10 20 30 40 50 60 70 80" << endl << "  ";
    ptrArbre1->afficheInfixe();

    cout << " Arbre1 en parcours postfixé doit être 10 30 20 50 80 70 60 40" << endl << "  ";
    ptrArbre1->affichePostfixe();

    cout << " Nombre de feuilles de Arbre1 : " << ptrArbre1->getNombreDeFeuilles() << " ; doit être 4." << endl;
    cout << endl << "FIN testeGetNbFeuilles() " << endl << endl;
}

void testeGetMax() {
    cout << "DÉBUT testeGetMax() " << endl << endl;
    ArbreNoeudBinaireRecherche<int>* ptrArbre1 = new ArbreNoeudBinaireRecherche<int>();
    cout << "Arbre1 -> un arbre binaire de recherche dégénéré à gauche" << endl;
    ptrArbre1->insere(10);
    ptrArbre1->insere(20);
    ptrArbre1->insere(30);
    ptrArbre1->insere(40);
    ptrArbre1->insere(50);
    ptrArbre1->insere(60);
    ptrArbre1->insere(70);
    ptrArbre1->insere(80);
    //10
    //  \
    //  20
    //    \
    //    30
    //      \
    //      40
    //        \
    //        50
    //          \
    //          60
    //            \
    //            70
    //              \
    //              80 
    cout << " Arbre1 en parcours préfixé doit être 10 20 30 40 50 60 70 80" << endl << "  ";
    ptrArbre1->affichePrefixe();

    cout << " Arbre1 en parcours infixé doit être 10 20 30 40 50 60 70 80" << endl << "  ";
    ptrArbre1->afficheInfixe();

    cout << " Arbre1 en parcours postfixé doit être 80 70 60 50 40 30 20 10" << endl << "  ";
    ptrArbre1->affichePostfixe();

    cout << " La valeur la plus grande est : " << ptrArbre1->getMax() << " ; devrait rendre 80" << endl << endl;

    ArbreNoeudBinaireRecherche<int>* ptrArbre2 = new ArbreNoeudBinaireRecherche<int>();
    cout << "Arbre2 -> un arbre binaire de recherche dégénéré à droite" << endl;
    ptrArbre2->insere(80);
    ptrArbre2->insere(70);
    ptrArbre2->insere(60);
    ptrArbre2->insere(50);
    ptrArbre2->insere(30);
    ptrArbre2->insere(20);
    ptrArbre2->insere(10);
    //               80
    //              /
    //             70
    //            / 
    //           60
    //          /
    //         50
    //        /
    //       40
    //      /
    //     30
    //    /
    //   20
    //  /
    // 10
    cout << " Arbre2 en parcours préfixé doit être 80 70 60 50 40 30 20 10" << endl << "  ";
    ptrArbre1->affichePrefixe();

    cout << " Arbre2 en parcours infixé doit être 10 20 30 40 50 60 70 80" << endl << "  ";
    ptrArbre1->afficheInfixe();

    cout << " Arbre2 en parcours postfixé doit être 10 20 30 40 50 60 70 80" << endl << "  ";
    ptrArbre1->affichePostfixe();

    cout << " La valeur la plus grande est : " << ptrArbre2->getMax() << " ; devrait rendre 80" << endl << endl;

    cout << "Arbre3 un arbre vide !" << endl;
    ArbreNoeudBinaireRecherche<int> ptrArbre3;
    cout << " Arbre3 en parcours préfixé doit être \"vide\"" << endl << "  ";
    ptrArbre3.affichePrefixe();

    cout << " Arbre3 en parcours infixé doit être \"vide\"" << endl << "  ";
    ptrArbre3.afficheInfixe();

    cout << " Arbre3 en parcours postfixé doit être \"vide\"" << endl << "  ";
    ptrArbre3.affichePostfixe();
    cout << "La valeur la plus grande d'un arbre vide est : ";
    try {
        cout << ptrArbre3.getMax() << endl;
    } catch (PrecondViolatedExcep e) {
        cout << endl << "  !!! CA C'EST MAL PASSEE, VOICI POURQUOI ---> " << endl;
        cout << e.what() << endl;
        cout << "  !!! ENFIN ON A QUAND MEME RECUPERER LE COUP !" << endl;
    }
    cout << endl << "FIN testeGetMax() " << endl << endl;
}

void testeOperateurAffectationSurcharge() {
    cout << "DÉBUT testeOperateurAffectationSurcharge() " << endl << endl;
    ArbreNoeudBinaireRecherche<int>* ptrArbre2 = new ArbreNoeudBinaireRecherche<int>();
    cout << "Arbre2 avant copie -> un arbre binaire de recherche équilibré" << endl;
    ptrArbre2->insere(50);
    ptrArbre2->insere(20);
    ptrArbre2->insere(80);
    ptrArbre2->insere(30);
    cout << " Arbre2 en parcours préfixé doit être 50 20 30 80" << endl << "  ";
    ptrArbre2->affichePrefixe();

    cout << " Arbre2 parcours infixé doit être 20 30 50 80" << endl << "  ";
    ptrArbre2->afficheInfixe();

    cout << " Arbre2 en parcours postfixé doit être 30 20 80 50" << endl << "  ";
    ptrArbre2->affichePostfixe();

    cout << " Hauteur Arbre2 : " << ptrArbre2->getHauteur() << " ; doit être 3." << endl;
    cout << " Nombre de noeuds Arbre2 : " << ptrArbre2->getNombreDeNoeuds() << " ; doit être 4." << endl;
    cout << endl << "Test de l'opérateur d'affectation surchargé (Arbre3 = Arbre2): " << endl;
    cout << " -> Copie de Arbre2 dans Arbre3, on a : " << endl;
    ArbreNoeudBinaireRecherche<int> tree3 = *ptrArbre2;
    ArbreNoeudBinaireRecherche<int>* ptrArbre3 = &tree3;

    cout << " Arbre2 après copie en parcours préfixé doit être 50 20 30 80" << endl << "  ";
    ptrArbre2->affichePrefixe();

    cout << " Arbre2 après copie en parcours infixé doit être 20 30 50 80" << endl << "  ";
    ptrArbre2->afficheInfixe();

    cout << " Arbre2 après copie en parcours postfixé doit être 30 20 80 50" << endl << "  ";
    ptrArbre2->affichePostfixe();

    cout << " Arbre2 hauteur : " << ptrArbre2->getHauteur() << " ; doit être 3." << endl;
    cout << " Arbre2 nombre de noeuds : " << ptrArbre2->getNombreDeNoeuds() << " ; doit être 4." << endl << endl;

    cout << " Arbre3 en parcours préfxé doit être 50 20 30 80" << endl << "  ";
    ptrArbre3->affichePrefixe();

    cout << " Arbre3 parcours infixé doit être 20 30 50 80" << endl << "  ";
    ptrArbre3->afficheInfixe();

    cout << " Arbre3 en parcours postfixé doit être 30 20 80 50" << endl << "  ";
    ptrArbre3->affichePostfixe();

    cout << " Arbre3 hauteur : " << ptrArbre3->getHauteur() << " ; doit être 3." << endl;
    cout << " Arbre3 nombre de noeuds : " << ptrArbre3->getNombreDeNoeuds() << " ; doit être 4." << endl;

    cout << endl << " Transformation de Arbre2 en supprimant 50" << endl << endl;

    ptrArbre2->supprime(50);

    cout << " Arbre2 en parcours préfixé doit être 80 20 30" << endl << "  ";
    ptrArbre2->affichePrefixe();

    cout << " Arbre2 parcours infixé doit être 20 30 80" << endl << "  ";
    ptrArbre2->afficheInfixe();

    cout << " Arbre2 en parcours postfixé doit être 30 20 80 " << endl << "  ";
    ptrArbre2->affichePostfixe();

    cout << " Hauteur de Arbre2 : " << ptrArbre2->getHauteur() << " ; doit être 2." << endl;
    cout << " Nombre de noeuds Arbre2 : " << ptrArbre2->getNombreDeNoeuds() << " ; doit être 3." << endl;

    cout << endl << "Arbre3 doit être inchangé :" << endl;

    cout << " Arbre3 en parcours préfixé doit être 50 20 30 80" << endl << "  ";
    ptrArbre3->affichePrefixe();

    cout << " Arbre3 parcours infixé doit être 20 30 50 80" << endl << "  ";
    ptrArbre3->afficheInfixe();

    cout << " Arbre3 en parcours postfixé doit être 30 20 80 50" << endl << "  ";
    ptrArbre3->affichePostfixe();

    cout << " Hauteur de Arbre3 : " << ptrArbre3->getHauteur() << " ; doit être 3." << endl;
    cout << " Nombre de noeuds Arbre3 : " << ptrArbre3->getNombreDeNoeuds() << " ; doit être 4." << endl;
    cout << endl << "FIN testeOperateurAffectationSurcharge() " << endl << endl;
}

void testeEstInfoPresente() {
    cout << "DÉBUT testeInfoPresente() " << endl << endl;
    ArbreNoeudBinaireRecherche<int>* ptrArbre1 = new ArbreNoeudBinaireRecherche<int>();
    cout << "Arbre1 -> un arbre binaire de recherche équilibré" << endl;
    ptrArbre1->insere(40);
    ptrArbre1->insere(20);
    ptrArbre1->insere(10);
    ptrArbre1->insere(30);
    ptrArbre1->insere(60);
    ptrArbre1->insere(50);
    ptrArbre1->insere(70);
    ptrArbre1->insere(80);

    //        40
    //     /      \
    //    20      60
    //   /  \    /  \
    //  10  30  50  70
    //               \
    //               80

    cout << " Arbre1 en parcours préfixé doit être 40 20 10 30 60 50 70 80" << endl << "  ";
    ptrArbre1->affichePrefixe();

    cout << " Arbre1 parcours infixé doit être 10 20 30 40 50 60 70 80" << endl << "  ";
    ptrArbre1->afficheInfixe();

    cout << " Arbre1 en parcours postfixé doit être 10 30 20 50 80 70 60 40" << endl << "  ";
    ptrArbre1->affichePostfixe();

    cout << "10 est-il présent ? : " << ptrArbre1->estInfoPresente(10) << " ; devrait être true" << endl;
    cout << "30 est-il présent ? : " << ptrArbre1->estInfoPresente(30) << " ; devrait être true" << endl;
    cout << "60 est-il présent ? " << ptrArbre1->estInfoPresente(60) << " ; devrait être true" << endl;
    cout << "50 est-il présent ? " << ptrArbre1->estInfoPresente(50) << " ; devrait être true" << endl;
    cout << "80 est-il présent ? " << ptrArbre1->estInfoPresente(80) << " ; devrait être true" << endl;
    cout << "23 est-il présent ? " << ptrArbre1->estInfoPresente(23) << " ; devrait être false" << endl;

    cout << endl << "FIN testeInfoPresente() " << endl << endl;
}

void testeGetNombreOccurrences() {
    cout << "DÉBUT testeGetNombreOccurrences() " << endl << endl;
    ArbreNoeudBinaireRecherche<int>* ptrArbre1 = new ArbreNoeudBinaireRecherche<int>();
    cout << "Arbre1 : 10 à gauche" << endl;
    ptrArbre1->insere(17);
    ptrArbre1->insere(10);
    ptrArbre1->insere(3);
    //       17
    //      / 
    //    10
    //   /
    //  3
    cout << " Arbre2 en parcours préfixé doit être 17 10 3" << endl << "  ";
    ptrArbre1->affichePrefixe();

    cout << " Arbre2 parcours infixé doit être 3 10 17" << endl << "  ";
    ptrArbre1->afficheInfixe();

    cout << " Arbre2 en parcours postfixé doit être 3 10 17" << endl << "  ";
    ptrArbre1->affichePostfixe();

    cout << " Le nombre d'occurrences de 10 est " << ptrArbre1->getNombreOccurrences(10) << " ; doit être 1" << endl;
    cout << " Le nombre d'occurrences de 18 est " << ptrArbre1->getNombreOccurrences(18) << " ; doit être 0" << endl << endl;

    ArbreNoeudBinaireRecherche<int>* ptrArbre2 = new ArbreNoeudBinaireRecherche<int>();
    cout << "Arbre2 : 10 à droite" << endl;
    ptrArbre2->insere(7);
    ptrArbre2->insere(10);
    ptrArbre2->insere(3);
    //     7
    //   /   \
    //  3    10
    cout << " Arbre2 en parcours préfixé doit être 7 3 10" << endl << "  ";
    ptrArbre2->affichePrefixe();

    cout << " Arbre2 parcours infixé doit être 3 7 10" << endl << "  ";
    ptrArbre2->afficheInfixe();

    cout << " Arbre2 en parcours postfixé doit être 3 10 3" << endl << "  ";
    ptrArbre2->affichePostfixe();

    cout << " Le nombre d'occurrences de 10 est " << ptrArbre2->getNombreOccurrences(10) << " ; doit être 1" << endl;
    cout << " Le nombre d'occurrences de 2 est " << ptrArbre2->getNombreOccurrences(2) << " ; doit être 0" << endl << endl;


    ArbreNoeudBinaireRecherche<int>* ptrArbre3 = new ArbreNoeudBinaireRecherche<int>();
    cout << "Arbre3 : 10 à gauche en gauche gauche" << endl;
    ptrArbre3->insere(17);
    ptrArbre3->insere(10);
    ptrArbre3->insere(10);
    ptrArbre3->insere(3);
    //          17
    //         /
    //       10
    //      /
    //    10
    //   /
    //  3
    cout << " Arbre3 en parcours préfixé doit être 17 10 10 3" << endl << "  ";
    ptrArbre3->affichePrefixe();

    cout << " Arbre3 parcours infixé doit être 3 10 10 17" << endl << "  ";
    ptrArbre3->afficheInfixe();

    cout << " Arbre3 en parcours postfixé doit être 3 10 10 17" << endl << "  ";
    ptrArbre3->affichePostfixe();

    cout << " Le nombre d'occurrences de 10 est " << ptrArbre3->getNombreOccurrences(10) << " ; doit être 2" << endl;
    cout << " Le nombre d'occurrences de 13 est " << ptrArbre3->getNombreOccurrences(13) << " ; doit être 0" << endl << endl;

    ArbreNoeudBinaireRecherche<int>* ptrArbre4 = new ArbreNoeudBinaireRecherche<int>();
    cout << "Arbre4 : 10 à gauche en gauche droite" << endl;
    ptrArbre4->insere(17);
    ptrArbre4->insere(10);
    ptrArbre4->insere(3);
    ptrArbre4->insere(10);
    //          17
    //         /
    //       10
    //      /
    //     3
    //      \
    //       10
    cout << " Arbre4 en parcours préfixé doit être 17 10 3 10" << endl << "  ";
    ptrArbre4->affichePrefixe();

    cout << " Arbre4 parcours infixé doit être 3 10 10 17" << endl << "  ";
    ptrArbre4->afficheInfixe();

    cout << " Arbre4 en parcours postfixé doit être 10 3 10 17" << endl << "  ";
    ptrArbre4->affichePostfixe();

    cout << " Le nombre d'occurrences de 10 est " << ptrArbre4->getNombreOccurrences(10) << " ; doit être 2" << endl;
    cout << " Le nombre d'occurrences de 7 est " << ptrArbre4->getNombreOccurrences(18) << " ; doit être 0" << endl;

    cout << endl << "FIN testeGetNombreOccurrences() " << endl << endl;
}

void testeAMemeGeometrieQue() {
    bool succes;
    cout << "DÉBUT testeAMemeGeometrieQue() " << endl << endl;
    ArbreNoeudBinaireRecherche<int>* ptrArbre1 = new ArbreNoeudBinaireRecherche<int>();

    cout << "Arbre1 (encore vide) a-t-il la même géomértie que Arbre1 (encore vide) ? : " 
            << ptrArbre1->aMemeGeometrieQue(*ptrArbre1) << " ; doit être true !" << endl << endl;

    ptrArbre1->insere(5);
    ptrArbre1->insere(2);
    ptrArbre1->insere(7);
    ptrArbre1->insere(1);
    ptrArbre1->insere(3);
    ptrArbre1->insere(6);
    ptrArbre1->insere(9);
    ptrArbre1->insere(4);
    ptrArbre1->insere(8);
    cout << " Arbre1 en parcours préfixé doit être 5 2 1 3 4 6 7 6 9 8" << endl << "  ";
    ptrArbre1->affichePrefixe();

    cout << " Arbre1 parcours infixé doit être 1 2 3 4 5 6 7 8 9" << endl << "  ";
    ptrArbre1->afficheInfixe();

    cout << " Arbre1 en parcours postfixé doit être 1 4 3 2 6 8 9 7 5" << endl << "  ";
    ptrArbre1->affichePostfixe();
    cout << endl;

    ArbreNoeudBinaireRecherche<int>* ptrArbre2 = new ArbreNoeudBinaireRecherche<int>();
    ptrArbre2->insere(6);
    ptrArbre2->insere(3);
    ptrArbre2->insere(8);
    ptrArbre2->insere(2);
    ptrArbre2->insere(4);
    ptrArbre2->insere(7);
    ptrArbre2->insere(10);
    ptrArbre2->insere(5);
    ptrArbre2->insere(9);
    cout << " Arbre2 en parcours préfixé doit être 6 3 2 4 7 8 7 10 9" << endl << "  ";
    ptrArbre2->affichePrefixe();

    cout << " Arbre2 parcours infixé doit être 2 3 4 5 6 7 8 9 10" << endl << "  ";
    ptrArbre2->afficheInfixe();

    cout << " Arbre2 en parcours postfixé doit être 2 5 4 3 7 9 10 8 6" << endl << "  ";
    ptrArbre2->affichePostfixe();
    cout << endl;


    cout << "Arbre1 a-t-il la même géomértie que Arbre2 ? : " 
            << ptrArbre1->aMemeGeometrieQue(*ptrArbre2) << " ; doit être true !" << endl << endl;

    ArbreNoeudBinaireRecherche<int>* ptrArbreVide = new ArbreNoeudBinaireRecherche<int>();
    cout << "Arbre1 a-t-il la même géomértie que ArbreVide ? : " 
            << ptrArbre1->aMemeGeometrieQue(*ptrArbreVide) << " ; doit être false !" << endl << endl;

    cout << "ArbreVide a-t-il la même géomértie que que Arbre1 ? : " 
            << ptrArbreVide->aMemeGeometrieQue(*ptrArbre1) << " ; doit être false !" << endl << endl;

    ArbreNoeudBinaireRecherche<int>* ptrArbre3 = new ArbreNoeudBinaireRecherche<int>();
    ptrArbre3->insere(5);
    ptrArbre3->insere(2);
    ptrArbre3->insere(7);
    ptrArbre3->insere(1);
    ptrArbre3->insere(3);
    ptrArbre3->insere(6);
    ptrArbre3->insere(8);
    ptrArbre3->insere(4);
    ptrArbre3->insere(9);
    cout << " Arbre1 en parcours préfixé doit être 5 2 1 3 4 6 7 6 9 8" << endl << "  ";
    ptrArbre1->affichePrefixe();

    cout << " Arbre1 parcours infixé doit être 1 2 3 4 5 6 7 8 9" << endl << "  ";
    ptrArbre1->afficheInfixe();

    cout << " Arbre1 en parcours postfixé doit être 1 4 3 2 6 8 9 7 5" << endl << "  ";
    ptrArbre1->affichePostfixe();
    cout << endl;

    cout << " Arbre3 en parcours préfixé doit être 5 2 1 3 4 7 6 8 9" << endl << "  ";
    ptrArbre3->affichePrefixe();

    cout << " Arbre3 parcours infixé doit être 1 2 3 4 5 6 7 8 9" << endl << "  ";
    ptrArbre3->afficheInfixe();

    cout << " Arbre3 en parcours postfixé doit être 1 4 3 2 6 9 8 7 5" << endl << "  ";
    ptrArbre3->affichePostfixe();
    cout << endl;

    cout << "Arbre1 a-t-il la même géomértie que Arbre3 ? : " 
            << ptrArbre1->aMemeGeometrieQue(*ptrArbre3) << " ; doit être false !" << endl << endl;

    cout << "Arbre3 a-t-il la même géomértie que Arbre1 ? : " 
            << ptrArbre3->aMemeGeometrieQue(*ptrArbre1) << " ; doit être false !" << endl << endl;

    cout << "FIN testeAMemeGeometrieQue()" << endl << endl;
}

int main() {

    //testeInsertAffiche();

    //testeHauteur();

    //testeGetNombreNoeuds();

    //testeGetNombreFeuilles();

    //testeEstInfoPresente();

    //testeGetMax();

    //testeGetNombreOccurrences();

    //testeAMemeGeometrieQue();

    /*
     * teste des opérations fournies
     */
    //testeSuppression();
    //testeOperateurAffectationSurcharge();

    return 0;
} // end main

/**
 * TRACE À OBTENIR !!!!!!!!!!!
 */

/*
DÉBUT testeInsertAffiche() 

Arbre1 -> un arbre binaire de recherche dégénéré
 Arbre1 en parcours préfixé doit être 10 20 30 40 50 60 70 80
  En parcours préfixé, l'ABO contient : 10 20 30 40 50 60 70 80 
 Arbre1 en parcours infixé doit être 10 20 30 40 50 60 70 80
  En parcours infixé, l'ABO contient : 10 20 30 40 50 60 70 80 
 Arbre1 en parcours postfixé doit être 80 70 60 50 40 30 20 10
  En parcours postfixé, l'ABO contient : 80 70 60 50 40 30 20 10 

FIN testeInsertAffiche() 

DÉBUT testeHauteur() 

Arbre1 -> un arbre binaire de recherche dégénéré
 Hauteur de Arbre1 : 8 ; doit être 8.

FIN testeHauteur() 

DÉBUT testeGetNbNoeuds() 

Arbre1 -> un arbre binaire de recherche dégénéré
 Nombre de noeuds de Arbre1 : 8 ; doit être 8.

FIN testeGetNbNoeuds() 

DÉBUT testeGetNbFeuilles() 

Arbre1 -> un arbre binaire de recherche équilibré
 Arbre1 en parcours préfixé doit être 40 20 10 30 60 50 70 80
  En parcours préfixé, l'ABO contient : 40 20 10 30 60 50 70 80 
 Arbre1 parcours infixé doit être 10 20 30 40 50 60 70 80
  En parcours infixé, l'ABO contient : 10 20 30 40 50 60 70 80 
 Arbre1 en parcours postfixé doit être 10 30 20 50 80 70 60 40
  En parcours postfixé, l'ABO contient : 10 30 20 50 80 70 60 40 
 Nombre de feuilles de Arbre1 : 4 ; doit être 4.

FIN testeGetNbFeuilles() 

DÉBUT testeInfoPresente() 

Arbre1 -> un arbre binaire de recherche équilibré
 Arbre1 en parcours préfixé doit être 40 20 10 30 60 50 70 80
  En parcours préfixé, l'ABO contient : 40 20 10 30 60 50 70 80 
 Arbre1 parcours infixé doit être 10 20 30 40 50 60 70 80
  En parcours infixé, l'ABO contient : 10 20 30 40 50 60 70 80 
 Arbre1 en parcours postfixé doit être 10 30 20 50 80 70 60 40
  En parcours postfixé, l'ABO contient : 10 30 20 50 80 70 60 40 
10 est-il présent ? : 1 ; devrait être true
30 est-il présent ? : 1 ; devrait être true
60 est-il présent ? 1 ; devrait être true
50 est-il présent ? 1 ; devrait être true
80 est-il présent ? 1 ; devrait être true
23 est-il présent ? 0 ; devrait être false

FIN testeInfoPresente() 

DÉBUT testeGetMax() 

Arbre1 -> un arbre binaire de recherche dégénéré à gauche
 Arbre1 en parcours préfixé doit être 10 20 30 40 50 60 70 80
  En parcours préfixé, l'ABO contient : 10 20 30 40 50 60 70 80 
 Arbre1 en parcours infixé doit être 10 20 30 40 50 60 70 80
  En parcours infixé, l'ABO contient : 10 20 30 40 50 60 70 80 
 Arbre1 en parcours postfixé doit être 80 70 60 50 40 30 20 10
  En parcours postfixé, l'ABO contient : 80 70 60 50 40 30 20 10 
 La valeur la plus grande est : 10 ; devrait rendre 80

Arbre2 -> un arbre binaire de recherche dégénéré à droite
 Arbre2 en parcours préfixé doit être 80 70 60 50 40 30 20 10
  En parcours préfixé, l'ABO contient : 10 20 30 40 50 60 70 80 
 Arbre2 en parcours infixé doit être 10 20 30 40 50 60 70 80
  En parcours infixé, l'ABO contient : 10 20 30 40 50 60 70 80 
 Arbre2 en parcours postfixé doit être 10 20 30 40 50 60 70 80
  En parcours postfixé, l'ABO contient : 80 70 60 50 40 30 20 10 
 La valeur la plus grande est : 10 ; devrait rendre 80

Arbre3 un arbre vide !
 Arbre3 en parcours préfixé doit être "vide"
  En parcours préfixé, l'ABO contient : 
 Arbre3 en parcours infixé doit être "vide"
  En parcours infixé, l'ABO contient : 
 Arbre3 en parcours postfixé doit être "vide"
  En parcours postfixé, l'ABO contient : 
La valeur la plus grande d'un arbre vide est : 
  !!! CA C'EST MAL PASSEE, VOICI POURQUOI ---> 
Precondition Violated Exception: Pas de maximum sur un arbre vide !
  !!! ENFIN ON A QUAND MEME RECUPERER LE COUP !

FIN testeGetMax() 

DÉBUT testeGetNombreOccurrences() 

Arbre1 : 10 à gauche
 Arbre2 en parcours préfixé doit être 17 10 3
  En parcours préfixé, l'ABO contient : 17 10 3 
 Arbre2 parcours infixé doit être 3 10 17
  En parcours infixé, l'ABO contient : 3 10 17 
 Arbre2 en parcours postfixé doit être 3 10 17
  En parcours postfixé, l'ABO contient : 3 10 17 
 Le nombre d'occurrences de 10 est 1 ; doit être 1
 Le nombre d'occurrences de 18 est 0 ; doit être 0

Arbre2 : 10 à droite
 Arbre2 en parcours préfixé doit être 7 3 10
  En parcours préfixé, l'ABO contient : 7 3 10 
 Arbre2 parcours infixé doit être 3 7 10
  En parcours infixé, l'ABO contient : 3 7 10 
 Arbre2 en parcours postfixé doit être 3 10 3
  En parcours postfixé, l'ABO contient : 3 10 7 
 Le nombre d'occurrences de 10 est 1 ; doit être 1
 Le nombre d'occurrences de 2 est 0 ; doit être 0

Arbre3 : 10 à gauche en gauche gauche
 Arbre3 en parcours préfixé doit être 17 10 10 3
  En parcours préfixé, l'ABO contient : 17 10 10 3 
 Arbre3 parcours infixé doit être 3 10 10 17
  En parcours infixé, l'ABO contient : 3 10 10 17 
 Arbre3 en parcours postfixé doit être 3 10 10 17
  En parcours postfixé, l'ABO contient : 3 10 10 17 
 Le nombre d'occurrences de 10 est 2 ; doit être 2
 Le nombre d'occurrences de 13 est 0 ; doit être 0

Arbre4 : 10 à gauche en gauche droite
 Arbre4 en parcours préfixé doit être 17 10 3 10
  En parcours préfixé, l'ABO contient : 17 10 3 10 
 Arbre4 parcours infixé doit être 3 10 10 17
  En parcours infixé, l'ABO contient : 3 10 10 17 
 Arbre4 en parcours postfixé doit être 10 3 10 17
  En parcours postfixé, l'ABO contient : 10 3 10 17 
 Le nombre d'occurrences de 10 est 2 ; doit être 2
 Le nombre d'occurrences de 7 est 0 ; doit être 0

FIN testeGetNombreOccurrences() 

DÉBUT testeAMemeGeometrieQue() 

Arbre1 (encore vide) a-t-il la même géomértie que Arbre1 (encore vide) ? : 1 ; doit être true !

 Arbre1 en parcours préfixé doit être 5 2 1 3 4 6 7 6 9 8
  En parcours préfixé, l'ABO contient : 5 2 1 3 4 7 6 9 8 
 Arbre1 parcours infixé doit être 1 2 3 4 5 6 7 8 9
  En parcours infixé, l'ABO contient : 1 2 3 4 5 6 7 8 9 
 Arbre1 en parcours postfixé doit être 1 4 3 2 6 8 9 7 5
  En parcours postfixé, l'ABO contient : 1 4 3 2 6 8 9 7 5 

 Arbre2 en parcours préfixé doit être 6 3 2 4 7 8 7 10 9
  En parcours préfixé, l'ABO contient : 6 3 2 4 5 8 7 10 9 
 Arbre2 parcours infixé doit être 2 3 4 5 6 7 8 9 10
  En parcours infixé, l'ABO contient : 2 3 4 5 6 7 8 9 10 
 Arbre2 en parcours postfixé doit être 2 5 4 3 7 9 10 8 6
  En parcours postfixé, l'ABO contient : 2 5 4 3 7 9 10 8 6 

Arbre1 a-t-il la même géomértie que Arbre2 ? : 1 ; doit être true !

Arbre1 a-t-il la même géomértie que ArbreVide ? : 0 ; doit être false !

ArbreVide a-t-il la même géomértie que que Arbre1 ? : 0 ; doit être false !

 Arbre1 en parcours préfixé doit être 5 2 1 3 4 6 7 6 9 8
  En parcours préfixé, l'ABO contient : 5 2 1 3 4 7 6 9 8 
 Arbre1 parcours infixé doit être 1 2 3 4 5 6 7 8 9
  En parcours infixé, l'ABO contient : 1 2 3 4 5 6 7 8 9 
 Arbre1 en parcours postfixé doit être 1 4 3 2 6 8 9 7 5
  En parcours postfixé, l'ABO contient : 1 4 3 2 6 8 9 7 5 

 Arbre3 en parcours préfixé doit être 5 2 1 3 4 7 6 8 9
  En parcours préfixé, l'ABO contient : 5 2 1 3 4 7 6 8 9 
 Arbre3 parcours infixé doit être 1 2 3 4 5 6 7 8 9
  En parcours infixé, l'ABO contient : 1 2 3 4 5 6 7 8 9 
 Arbre3 en parcours postfixé doit être 1 4 3 2 6 9 8 7 5
  En parcours postfixé, l'ABO contient : 1 4 3 2 6 9 8 7 5 

Arbre1 a-t-il la même géomértie que Arbre3 ? : 0 ; doit être false !

Arbre3 a-t-il la même géomértie que Arbre1 ? : 0 ; doit être false !

FIN testeAMemeGeometrieQue()
 */