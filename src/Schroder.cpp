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

double precisao_maquina(){

    double Eps1 = 1;
    double epsilon;

    while(1 + Eps1 > 1){

        epsilon = Eps1;
        Eps1 /= 2;

    }

    return epsilon;

}

double avaliacao_funcao(const double &x){

    return (x+1)*(x-1)*pow(x-3,5);

}

double avaliacao_derivada_funcao(const double &x){

    return (x-1)*pow(x-3,5)+(x+1)*pow(x-3,5)+5*(x-1)*(x+1)*pow(x-3, 4);

}

void print(const double &x, const double &Fx, const double &DFx, 
           const double &deltax, const unsigned &k){

    cout << setprecision(5) << fixed << k << "   " << x; 
        
    cout << scientific << "   " << Fx << "  " << DFx << "    ";
    cout << deltax << "    " << endl;
    cout.unsetf(ios::scientific);
    cout << setprecision(5) << fixed;

}

void print_final(const double &x, const double &Fx, const double &DFx, 
                 const unsigned &k){

    cout << setprecision(5) << fixed << k << "   " << x; 
        
    cout << scientific << "   " << Fx << "  " << DFx << "    " << endl;
    cout.unsetf(ios::scientific);
    cout << setprecision(5) << fixed;

}

void schroder(double &m, double &x, double &Toler, unsigned &IterMax){

    cout << "\n\tCalculo de raiz pelo metodo de Schroder\n" << endl;

    cout << "k     x_k         Fx_k        DFx_k        deltax_k" << endl;

    int Info;

    double epsilon = precisao_maquina();

    unsigned k = 0;

    double Fx;
    double DFx;
    
    double deltax = 1 + Toler;

    while(1){

        Fx = avaliacao_funcao(x);
        DFx = avaliacao_derivada_funcao(x);
        
        deltax = m * Fx / DFx;

        if((fabs(deltax) <= Toler && fabs(Fx) <= Toler) 
            || fabs(DFx) < epsilon 
            || k >= IterMax){

            print_final(x, Fx, DFx, k);

            goto SaiDoLoop;

        }

        print(x, Fx, DFx, deltax, k);

        x -= deltax;

        k++;

    }

    SaiDoLoop:

    if(fabs(deltax) <= Toler && fabs(Fx) <= Toler){

        Info = 0;

    }

    else{

        Info = 1;

    }

    cout << endl;
    
    if(Info == 0 || Info == 2){
        
        cout << "Raiz = " << x << endl;

    }

    cout << "Iter = " << k << endl;
    cout << "Info = " << Info << endl << endl;

}