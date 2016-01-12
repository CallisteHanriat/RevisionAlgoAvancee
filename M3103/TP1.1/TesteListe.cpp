/************************
 *    ETUDIANT
 ************************/


#include <iostream>
#include <string>
#include "ListeChainee.h"

using namespace std;

void testeAffiche() {
    cout << "DEBUT testeAffiche()" << endl << endl;
    //--> Construire une liste d'entiers avec des insereTete()
    ListeChainee<int> uneListe;
    uneListe.insereTete(6);
    uneListe.insereTete(5);
    uneListe.insereTete(4);
    uneListe.insereTete(3);
    uneListe.insereTete(2);
    uneListe.insereTete(1);

    //--> Faire l'affichage récursif de la liste de gauche à droite
    uneListe.afficheGD();
    cout << endl;

    //--> Faire l'affichage récursif de la liste de droite à gauche
    uneListe.afficheDG();
    cout << endl;

    //--> Faire l'affichage itératif de la liste de gauche à droite
    uneListe.afficheGDIter();
    cout << endl;

    cout << "FIN testeAffiche()" << endl << endl;
}

void testAfficheIter() {
    cout << "DEBUT testAfficheIter()" << endl << endl;
    //--> Construire une liste d'entiers avec des insereTete()
    ListeChainee<int> uneListe;
    uneListe.insereTete(6);
    uneListe.insereTete(5);
    uneListe.insereTete(4);
    uneListe.insereTete(3);
    uneListe.insereTete(2);
    uneListe.insereTete(1);

    //--> Faire l'affichage itératif de la liste de gauche à droite
    uneListe.afficheGDIter();
    cout << endl;

    //--> Faire l'affichage itératif de la liste de droite à gauche
    uneListe.afficheDGIter();
    cout << endl;

    cout << "FIN testAfficheIter()" << endl << endl;
} // end testAfficheIter()

void testeInsereAtPositRecAvecProc() {
    cout << "DEBUT testeInsereAtPositRecAvecProc()" << endl << endl;

    ListeChainee<string> uneListe;
    cout << "uneListe vient d'être construite elle doit être vide !" << endl;
    cout << "estVide() retourne " << uneListe.estVide() << " ; devrait retouner 1 (true)" << endl;
    cout << endl << "Insertion de zéro, un, deux, trois, quatre, cinq aux positions repectives 1, 2, 3, 4, 5" << endl;
    string items[] = {"zéro", "un", "deux", "trois", "quatre", "cinq"};
    for (int i = 0; i < 6; i++) {
        cout << "Ajout de : " << items[i] << endl;
        bool success = uneListe.insereAtPositRecAvecProc(i + 1, items[i]);
        if (!success) {
            cout << "Ajout de : " << items[i] << " à la liste impossible." << endl;
        }
    }
    uneListe.afficheGD();

    cout << "estVide() retourne " << uneListe.estVide() << " ; devrait retouner 0 (false)" << endl;
    cout << "getLongueur() retourne " << uneListe.getLongueur() << " ; devrait retouner 5" << endl;
    cout << "insertion à la position 3 de \"entreUnEtDeux\"" << endl;
    uneListe.insereAtPositRecAvecProc(3, "entreUnEtDeux");
    cout << "insertion à la position 1 de \"avantZéro\"" << endl;
    uneListe.insereAtPositRecAvecProc(1, "avantZéro");
    cout << "insertion à la position 9 de \"aprèsCinq\"" << endl;
    uneListe.insereAtPositRecAvecProc(9, "aprèsCinq");
    cout << "insertion à la position 11 de \"tropLoin\"" << endl;
    uneListe.insereAtPositRecAvecProc(11, "tropLoin");
    uneListe.afficheGD();

    cout << endl << "FIN testeInsereAtPositRecAvecProc()" << endl << endl;
}

void testeSupprimeAtPositRecAvecProc() {
    cout << "DEBUT testeSupprimeAtPositRecAvecProc()" << endl << endl;

    ListeChainee<string> uneListe;
    cout << "Insertion de zéro, un, deux, trois, quatre, cinq aux positions repectives 1, 2, 3, 4, 5" << endl;
    string items[] = {"zéro", "un", "deux", "trois", "quatre", "cinq"};
    for (int i = 0; i < 6; i++) {
        cout << "Ajout de : " << items[i] << endl;
        bool success = uneListe.insereAtPositRecAvecProc(i + 1, items[i]);
        if (!success) {
            cout << "Ajout de : " << items[i] << " à la liste impossible." << endl;
        }
    }
    cout << "La liste originale contient : " << endl;
    uneListe.afficheGD();

    cout << "suppression à la position 1 de \"zéro\"" << endl;
    uneListe.supprimeAtPositRecAvecProc(1);
    uneListe.afficheGD();
    cout << "suppression à la position 2 de \"deux\"" << endl;
    uneListe.supprimeAtPositRecAvecProc(2);
    uneListe.afficheGD();
    cout << "suppression à la position 4 de \"cinq\"" << endl;
    uneListe.supprimeAtPositRecAvecProc(4);
    uneListe.afficheGD();
    cout << "suppression à la position 11 (trop loin !)" << endl;
    uneListe.supprimeAtPositRecAvecProc(11);
    uneListe.afficheGD();

    cout << endl << "FIN testeSupprimeAtPositRecAvecProc()" << endl << endl;
}

void testeEstInfoPresentRec() {
    cout << "DEBUT testeEstInfoPresentRec()" << endl << endl;

    ListeChainee<int> uneListe;
    uneListe.insereTete(6);
    uneListe.insereTete(5);
    uneListe.insereTete(4);
    uneListe.insereTete(3);
    uneListe.insereTete(2);
    uneListe.insereTete(1);

    //--> Faire l'affichage itératif de la liste de gauche à droite
    uneListe.afficheGDIter();
    cout << endl;

    int val = 4;
    cout << val << " est " << ((uneListe.estInfoPresentRec(val)) ? "présent" : "absent") << endl;
    val = 10;
    cout << val << " est " << ((uneListe.estInfoPresentRec(val)) ? "présent" : "absent") << endl;

    cout << endl << "FIN testeEstInfoPresentRec()" << endl << endl;    
}

void testeInsereAtPositIter() {
    cout << "DEBUT testeInsertAtPositIter()" << endl << endl;

    ListeChainee<string> uneListe;
    cout << "uneListe vient d'être construite elle doit être vide !" << endl;
    cout << "estVide() retourne " << uneListe.estVide() << " ; devrait retouner 1 (true)" << endl;
    cout << endl << "Insertion de zéro, un, deux, trois, quatre, cinq aux positions repectives 1, 2, 3, 4, 5" << endl;
    string items[] = {"zéro", "un", "deux", "trois", "quatre", "cinq"};
    for (int i = 0; i < 6; i++) {
        cout << "Ajout de : " << items[i] << endl;
        bool success = uneListe.insereAtPositIter(i + 1, items[i]);
        if (!success) {
            cout << "Ajout de : " << items[i] << " à la liste impossible." << endl;
        }
    }
    uneListe.afficheGD();

    cout << "estVide() retourne " << uneListe.estVide() << " ; devrait retourner 0 (false)" << endl;
    cout << "getLongueur() retourne " << uneListe.getLongueur() << " ; devrait retourner 6" << endl;
    cout << "insertion à la position 3 de \"entreUnEtDeux\"" << endl;
    uneListe.insereAtPositIter(3, "entreUnEtDeux");
    cout << "insertion à la position 1 de \"avantZéro\"" << endl;
    uneListe.insereAtPositIter(1, "avantZéro");
    cout << "insertion à la position 9 de \"aprèsCinq\"" << endl;
    uneListe.insereAtPositIter(9, "aprèsCinq");
    uneListe.afficheGD();

    cout << endl << "FIN testeInsertAtPositIter()" << endl << endl;
}

void testeSupprimeAtPositIter() {
    cout << "DEBUT testeSupprimeAtPositIter()" << endl << endl;

    ListeChainee<string> uneListe;
    cout << "Insertion de zéro, un, deux, trois, quatre, cinq aux positions repectives 1, 2, 3, 4, 5" << endl;
    string items[] = {"zéro", "un", "deux", "trois", "quatre", "cinq"};
    for (int i = 0; i < 6; i++) {
        cout << "Ajout de : " << items[i] << endl;
        bool success = uneListe.insereAtPositRecAvecProc(i + 1, items[i]);
        if (!success) {
            cout << "Ajout de : " << items[i] << " à la liste impossible." << endl;
        }
    }
    cout << "La liste originale contient : " << endl;
    uneListe.afficheGD();

    cout << "suppression à la position 1 de \"zéro\"" << endl;
    uneListe.supprimeAtPositIter(1);
    uneListe.afficheGD();
    cout << "suppression à la position 2 de \"deux\"" << endl;
    uneListe.supprimeAtPositIter(2);
    uneListe.afficheGD();
    cout << "suppression à la position 4 de \"cinq\"" << endl;
    uneListe.supprimeAtPositIter(4);
    uneListe.afficheGD();
    cout << "suppression à la position 11 (trop loin !)" << endl;
    uneListe.supprimeAtPositIter(11);
    uneListe.afficheGD();

    cout << endl << "FIN testeSupprimeAtPositIter()" << endl << endl;
}

void testeAfficheIter() {
    cout << "DEBUT testeAfficheIter()" << endl << endl;
    //--> Construire une liste d'entiers avec des insereTete()
    ListeChainee<int> uneListe;
    uneListe.insereTete(6);
    uneListe.insereTete(5);
    uneListe.insereTete(4);
    uneListe.insereTete(3);
    uneListe.insereTete(2);
    uneListe.insereTete(1);

    //--> Faire l'affichage récursif de la liste de gauche à droite
    uneListe.afficheDGIter();
    cout << endl;
    cout << "FIN testeAfficheIter()" << endl << endl;
    
    cout << "La liste est " << ((uneListe.estTrie()) ? "triée" : "pas triée") << endl;
    uneListe.insereTete(10);
    
    cout << "La liste est " << ((uneListe.estTrie()) ? "triée" : "pas triée") << endl;
}

int main() {
    /*
     * Décommenter une par une chaque procédure quand vous êtes prêt à
     * l'exécuter
     */
    /*
     * UNE TRACE DU RESULTAT A OBTENIR EST PROPOSEE EN FIN DE FICHIER
     */


    testeAffiche();
    testeInsereAtPositRecAvecProc();
    testeSupprimeAtPositRecAvecProc();
    testeEstInfoPresentRec();   // A ECRIRE !!!!
    testeInsereAtPositIter();
    testeSupprimeAtPositIter();
    testeAfficheIter();
    return 0;
}

/*
DEBUT testeAffiche()

En parcours récursif de gauche à droite, la liste contient -> 1 2 3 4 5 6 

En parcours récursif de droite à gauche, la liste contient -> 6 5 4 3 2 1 

En parcours itératif de gauche à droite, la liste contient -> 1 2 3 4 5 6 

FIN testeAffiche()

DEBUT testeInsereAtPositRecAvecProc()

uneListe vient d'être construite elle doit être vide !
estVide() retourne 1 ; devrait retouner 1 (true)

Insertion de zéro, un, deux, trois, quatre, cinq aux positions repectives 1, 2, 3, 4, 5
Ajout de : zéro
Ajout de : un
Ajout de : deux
Ajout de : trois
Ajout de : quatre
Ajout de : cinq
En parcours récursif de gauche à droite, la liste contient -> zéro un deux trois quatre cinq 
estVide() retourne 0 ; devrait retouner 0 (false)
getLongueur() retourne 6 ; devrait retouner 6
insertion à la position 3 de "entreUnEtDeux"
insertion à la position 1 de "avantZéro"
insertion à la position 9 de "aprèsCinq"
insertion à la position 11 de "tropLoin"
En parcours récursif de gauche à droite, la liste contient -> avantZéro zéro un entreUnEtDeux deux trois quatre cinq aprèsCinq 

FIN testeInsereAtPositRecAvecProc()

DEBUT testeSupprimeAtPositRecAvecProc()

Insertion de zéro, un, deux, trois, quatre, cinq aux positions repectives 1, 2, 3, 4, 5
Ajout de : zéro
Ajout de : un
Ajout de : deux
Ajout de : trois
Ajout de : quatre
Ajout de : cinq
La liste originale contient : 
En parcours récursif de gauche à droite, la liste contient -> zéro un deux trois quatre cinq 
suppression à la position 1 de "zéro"
En parcours récursif de gauche à droite, la liste contient -> un deux trois quatre cinq 
suppression à la position 2 de "deux"
En parcours récursif de gauche à droite, la liste contient -> un trois quatre cinq 
suppression à la position 4 de "cinq"
En parcours récursif de gauche à droite, la liste contient -> un trois quatre 
suppression à la position 11 (trop loin !)
En parcours récursif de gauche à droite, la liste contient -> un trois quatre 

FIN testeSupprimeAtPositRecAvecProc()

DEBUT testeInsertAtPositIter()

uneListe vient d'être construite elle doit être vide !
estVide() retourne 1 ; devrait retouner 1 (true)

Insertion de zéro, un, deux, trois, quatre, cinq aux positions repectives 1, 2, 3, 4, 5
Ajout de : zéro
Ajout de : un
Ajout de : deux
Ajout de : trois
Ajout de : quatre
Ajout de : cinq
En parcours récursif de gauche à droite, la liste contient -> zéro un deux trois quatre cinq 
estVide() retourne 0 ; devrait retouner 0 (false)
getLongueur() retourne 6 ; devrait retouner 5
insertion à la position 3 de "entreUnEtDeux"
insertion à la position 1 de "avantZéro"
insertion à la position 9 de "aprèsCinq"
En parcours récursif de gauche à droite, la liste contient -> avantZéro zéro un entreUnEtDeux deux trois quatre cinq aprèsCinq 

FIN testeInsertAtPositIter()

DEBUT testeSupprimeAtPositIter()

Insertion de zéro, un, deux, trois, quatre, cinq aux positions repectives 1, 2, 3, 4, 5
Ajout de : zéro
Ajout de : un
Ajout de : deux
Ajout de : trois
Ajout de : quatre
Ajout de : cinq
La liste originale contient : 
En parcours récursif de gauche à droite, la liste contient -> zéro un deux trois quatre cinq 
suppression à la position 1 de "zéro"
En parcours récursif de gauche à droite, la liste contient -> un deux trois quatre cinq 
suppression à la position 2 de "deux"
En parcours récursif de gauche à droite, la liste contient -> un trois quatre cinq 
suppression à la position 4 de "cinq"
En parcours récursif de gauche à droite, la liste contient -> un trois quatre 
suppression à la position 11 (trop loin !)
En parcours récursif de gauche à droite, la liste contient -> un trois quatre 

FIN testeSupprimeAtPositIter()

DEBUT testeAfficheIter()

En parcours itératif de gauche à droite, la liste contient -> 1 2 3 4 5 6 

En parcours itératif de droite à gauche, la liste contient -> 6 5 4 3 2 1 

FIN testeAfficheIter()

 */
