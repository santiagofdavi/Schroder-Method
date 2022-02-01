/* SCHRODER METHOD IN C++  

Created using the F.F.CAMPOS' Algotithm in "Algoritmos Numéricos", LTC 3rd

Author: Davi Ferreira Santiago
    School of Engineering, Universidade Federal de Minas Gerais
Date: February 1st, 2022 */

#include <iostream>
#include <cmath>
#include <iomanip>

#include "Schroder.hpp"

using namespace std;

int main(){

    double m, x, Toler;
    unsigned IterMax;

    cin >> m >> x >> Toler >> IterMax;

    schroder(m, x, Toler, IterMax);

    return 0;

}