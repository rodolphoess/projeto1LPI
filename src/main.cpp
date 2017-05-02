/** 
*@file matrizes.cpp
*@brief Programa que compara os algoritmos de multiplicacao de matrizes recursivo e iterativo
*@author Luís Eduardo Rique (luiseduardorique@gmail.com)
*@author Rodolpho Erick (rodolphoerick90@gmail.com)
*@since 26/04/2017
*@date  01/05/2017
*/

#include <iostream>
#include <fstream>
#include <sstream>

#include "../include/leitura.h"

using namespace std;

/**
*@brief Funcao principal
*/
int main(int argc, char* argv[]){

    /** @brief Leitura do nome do arquivo e checagem se ele existe ou nao. */
    string *nomeMatrizesA = new string[argc - 1];
    string *nomeMatrizesB = new string[argc - 1];   
    for (int i = 1; i <= argc - 1; i++) {
        stringstream ss;
        string argumento;       

        ss << argv[i];
        ss >> argumento;        

        nomeMatrizesA[i - 1] = "A" + argumento + "x" + argumento + ".txt";                 
        nomeMatrizesB[i - 1] = "B" + argumento + "x" + argumento + ".txt";                

        ss.clear(); 

        ifstream entradaA("../matrizes/" + nomeMatrizesA[i - 1]);
        ifstream entradaB("../matrizes/" + nomeMatrizesB[i - 1]);
    
        if (!entradaA) {
            cerr << "O arquivo da matriz A de dimensao " << argumento << "x" << argumento << " nao foi encontrado." << endl;
            return 0;
        }
        if (!entradaB) {
            cerr << "O arquivo da matriz B de dimensao " << argumento << "x" << argumento << " nao foi encontrado." << endl;
            return 0;
        }

        entradaA.close();
        entradaB.close();
    }   

    leitura(nomeMatrizesA, nomeMatrizesB, argc - 1);

    delete [] nomeMatrizesA;
    delete [] nomeMatrizesB;

    return 0;
}