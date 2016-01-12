/* 
 * File:   main.cpp
 * Author: brouxco
 *
 * Created on 2 novembre 2015, 15:09
 */

#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int factorielleIter(int n) {
    int res = 1;
    int i = 1;
    while (i <= n) {
        res *= i;
        i++;
    }
    return res;
}

int factorielleRec(int n) {
    if (n == 0){
        return 1;
    } else {
        return factorielleRec(n - 1) * n;
    }
}

bool estPair(int n) {
    if (n == 0) {
        return true;
    } else if (n == 1) {
        return false;
    } else {
        return estPair(n - 2);
    }
}

bool estPairQcq(int n) {
    if (n < 0) {
        return estPair(-n);
    } else {
        return estPair(n);
    }
}

bool estImpairCroisee(int n);

bool estPairCroisee(int n) {
    if (n == 0) {
        return true;
    } else if (n == 1) {
        return false;
    } else {
        return !estImpairCroisee(n - 2);
    }
}

bool estImpairCroisee(int n) {
    if (n == 0) {
        return false;
    } else if (n == 1) {
        return true;
    } else {
        return !estPairCroisee(n - 2);
    }
}

bool estImpairQcqCroisee(int n);

bool estPairQcqCroisee(int n) {
    if (n < 0) {
        return !estImpairCroisee(-n);
    } else {
        return !estImpairCroisee(n);
    }
}

bool estImpairQcqCroisee(int n) {
    if (n < 0) {
        return !estPairCroisee(-n);
    } else {
        return !estPairCroisee(n);
    }
}

int F91(int n) {
    if (n > 100) {
        return n - 10;
    } else {
        return F91(F91(n + 11));
    }
}

template<class T>
int dichoIter(const vector<T> & v, T val) {
    int sup = v.size() - 1;
    
    if (v[sup] < val) {
        return -(sup + 1);
    } else {
        int m;
        int inf = 0;
        while (inf <= sup) {
            m = (inf + sup) / 2;
            if (v[m] < val) {
                inf = m + 1;
            } else {
                sup = m - 1;
            }
        }
        if (v[inf] == val) {
            return inf + 1;
        } else {
            return -(inf + 1);
        }
    }
}

template<class T>
int dichoRecWorker(const vector<T> & v, int inf, int sup, T val);

template<class T>
int dichoRec(const vector<T> & v, T val) {
    if (v[v.size() - 1] < val) {
        return -v.size();
    } else {
        return dichoRecWorker(v, 0, v.size() - 1, val);
    }
}

template<class T>
int dichoRecWorker(const vector<T> & v, int inf, int sup, T val) {
    if (inf > sup) {
        if (v[inf] == val) {
            return inf + 1;
        } else {
            return -(inf + 1);
        }
    } else {
        int m = (inf + sup) / 2;
        if (v[m] < val) {
            return dichoRecWorker(v, m+1, sup, val);
        } else {
            return dichoRecWorker(v, inf, m-1, val);
        }
    }
}

void hanoi(int nbDisques, char depart, char intermediaire, char arrivee){
    if (nbDisques == 1){
        cout << "Déplacement du disque 1 du piquet " << depart << " vers le piquet " << arrivee << endl;
    } else {
        hanoi(nbDisques - 1, depart, arrivee, intermediaire);
        cout << "Déplacement du disque " << nbDisques << " du piquet " << depart << " vers le piquet " << arrivee << endl;
        hanoi(nbDisques - 1, intermediaire, depart, arrivee);
    }
}

template<class T>
T maxVectWorker(const vector<T> & v, int inf, int sup);

template<class T>
T maxVect(const vector<T> & v){
    return maxVectWorker(v, 0, v.size() - 1);
}

template<class T>
T maxVectWorker(const vector<T> & v, int inf, int sup){
    if (inf > sup) {
        return 0;
    } else if (inf == sup) {
        return v[inf];
    } else {
        int m = (inf + sup) / 2;
        return max(maxVectWorker(v, inf, m), maxVectWorker(v, m+1, sup));
    }
}

double puissance(float x, int n) {
    if (n == 0){
        return 1;
    } else {
        return x * puissance(x, n - 1);
    }
}

double puissanceNbMult(float x, int n, int& nbmult) {
    nbmult++;
    if (n == 0){
        return 1;
    } else {
        return x * puissanceNbMult(x, n - 1, nbmult);
    }
}

double puissanceDRNbMult(float x, int n, int& nbmult){
    nbmult++;
    if (n == 0){
        return 1;
    } else if (n == 1){
        return x;
    } else if (n > 1 && (n % 2 == 0)){
        return puissanceDRNbMult(x, n/2, nbmult) * puissanceDRNbMult(x, n/2, nbmult);
    } else {
        return x * puissanceDRNbMult(x, n/2, nbmult) * puissanceDRNbMult(x, n/2, nbmult);
    }
}

template<class T> 
void minMaxIter(vector<T> v, T& mini, T& maxi, int& nbComp) {
    for (auto el : v){
        maxi = max(el, maxi);
        mini = min(el, mini);
        nbComp += 2;
    }
}

/*
 * 
 */
int main(int argc, char** argv) {
    cout << "factorielleIter" << endl << endl;
    cout << "0! = " << factorielleIter(0) << endl;
    cout << "5! = " << factorielleIter(5) << endl;
    
    cout << endl << "factorielleRec" << endl << endl;
    cout << "0! = " << factorielleRec(0) << endl;
    cout << "5! = " << factorielleRec(5) << endl;
    
    cout << endl << "estPair" << endl << endl;
    cout << "0 est " << (estPair(0) ? "pair" : "impair") << endl;
    cout << "1 est " << (estPair(1) ? "pair" : "impair") << endl;
    cout << "5 est " << (estPair(5) ? "pair" : "impair") << endl;
    cout << "6 est " << (estPair(6) ? "pair" : "impair") << endl;
    
    cout << endl << "estPairQcq" << endl << endl;
    cout << "0 est " << (estPairQcq(0) ? "pair" : "impair") << endl;
    cout << "1 est " << (estPairQcq(1) ? "pair" : "impair") << endl;
    cout << "-5 est " << (estPairQcq(-5) ? "pair" : "impair") << endl;
    cout << "-6 est " << (estPairQcq(-6) ? "pair" : "impair") << endl;
    
    cout << endl << "estPairCroisee" << endl << endl;
    cout << "0 est " << (estPairCroisee(0) ? "pair" : "impair") << endl;
    cout << "1 est " << (estPairCroisee(1) ? "pair" : "impair") << endl;
    cout << "5 est " << (estPairCroisee(5) ? "pair" : "impair") << endl;
    cout << "6 est " << (estPairCroisee(6) ? "pair" : "impair") << endl;
    
    cout << endl << "estImpairCroisee" << endl << endl;
    cout << "0 est " << (estImpairCroisee(0) ? "impair" : "pair") << endl;
    cout << "1 est " << (estImpairCroisee(1) ? "impair" : "pair") << endl;
    cout << "5 est " << (estImpairCroisee(5) ? "impair" : "pair") << endl;
    cout << "6 est " << (estImpairCroisee(6) ? "impair" : "pair") << endl;
    
    cout << endl << "estPairQcqCroisee" << endl << endl;
    cout << "0 est " << (estPairQcqCroisee(0) ? "pair" : "impair") << endl;
    cout << "1 est " << (estPairQcqCroisee(1) ? "pair" : "impair") << endl;
    cout << "-5 est " << (estPairQcqCroisee(-5) ? "pair" : "impair") << endl;
    cout << "-6 est " << (estPairQcqCroisee(-6) ? "pair" : "impair") << endl;
    
    cout << endl << "estImpairQcqCroisee" << endl << endl;
    cout << "0 est " << (estImpairQcqCroisee(0) ? "impair" : "pair") << endl;
    cout << "1 est " << (estImpairQcqCroisee(1) ? "impair" : "pair") << endl;
    cout << "-5 est " << (estImpairQcqCroisee(-5) ? "impair" : "pair") << endl;
    cout << "-6 est " << (estImpairQcqCroisee(-6) ? "impair" : "pair") << endl;
    
    cout << endl << "F91" << endl << endl;
    cout << "F91(20) = " << F91(20) << endl;
    cout << "F91(3) = " << F91(3) << endl;
    cout << "F91(1000) = " << F91(1000) << endl;
    cout << "F91(2000) = " << F91(2000) << endl;
    
    cout << endl << "dichoIter" << endl << endl;
    vector<int> vec = {2, 6, 9, 41, 57, 78};
    cout << "dichoIter(50) = " << dichoIter(vec, 50) << endl;
    cout << "dichoIter(57) = " << dichoIter(vec, 57) << endl;
    
    cout << endl << "dichoRec" << endl << endl;
    vec = {2, 6, 9, 41, 57, 78};
    cout << "dichoRec(50) = " << dichoRec(vec, 50) << endl;
    cout << "dichoIter(57) = " << dichoIter(vec, 57) << endl;
    
    cout << endl << "hanoi" << endl << endl;
    hanoi(3, 'D', 'I', 'A');
    
    cout << endl << "max" << endl << endl;
    vec = {2, 6, 9, 41, 57, 78};
    cout << "max(vec) = " << maxVect(vec) << endl;
    
    cout << endl << "puissance" << endl << endl;
    cout << "5 puissance 3 = " << puissance(5, 3) << endl;
    cout << "5 puissance 32 = " << puissance(5, 32) << endl;
    
    cout << endl << "puissance nbCoups" << endl << endl;
    int nbCoups = 0;
    cout << "5 puissance 3 = " << puissanceNbMult(5, 3, nbCoups);
    cout << " - calculé en " << nbCoups << " coups." << endl;
    nbCoups = 0;
    cout << "5 puissance 16 = " << puissanceNbMult(5, 16, nbCoups);
    cout << " - calculé en " << nbCoups << " coups." << endl;
    nbCoups = 0;
    cout << "5 puissance 3 = " << puissanceDRNbMult(5, 3, nbCoups);
    cout << " - calculé en " << nbCoups << " coups." << endl;
    nbCoups = 0;
    cout << "5 puissance 16 = " << puissanceDRNbMult(5, 16, nbCoups);
    cout << " - calculé en " << nbCoups << " coups." << endl;
    
    cout << endl << "min max nbCoups" << endl << endl;
    int min = 0,
        max = 0;
    nbCoups = 0;
    vec = {0, 2, 6, 9, 41, 57, 78, 82};
    minMaxIter(vec, min, max, nbCoups);
    cout << "min = " << min << " max = " << max << " - calculé en " << nbCoups << " coups." << endl;
    
    return EXIT_SUCCESS;
}