/** 
*@file  funcoes.h
*@brief Arquivo de corpo contendo a implentacao das funcoes que realizam
*		a multiplicacao de matrizes de forma recursiva e iterativa, a de impressao e estatisticas.
*@author Luís Eduardo Rique (luiseduardorique@gmail.com)
*@author Rodolpho Erick (rodolphoerick90@gmail.com)
*@since 26/04/2017
*@date  01/05/2017
*/

#ifndef FUNCOES_H
#define FUNCOES_H

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;

/**
* @brief Funcao que escreve a matriz resultante em arquivo
* @param Mres Matriz resultante
* @param n Dimensao das matrizes de entrada
*/
template <typename T>
bool print(T** Mres, int n) {
	string arquivo, aux;
	stringstream ss;

	ss << n;
	ss >> aux;

	arquivo = "../matrizes/C" + aux + "x" + aux + ".txt";

	ofstream outfile(arquivo);

	if (!outfile) {
		cerr << "Arquivo nao gerado." << endl;	
		return false;	
	}

	outfile << n << " " << n << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			outfile << Mres[i][j] << " ";
		}
		outfile << endl;
	}

	outfile.close();

	return true;
}

/**
* @brief Funcao que multiplica duas matrizes quadradas de dimensao n x n de forma iterativa
* @param A Matriz de entrada
* @param B Matriz de entrada
* @param n Dimensao das matrizes de entrada
* @return Matriz produto resultante da multiplicacao
*/
template <typename T>
void multiplicaI(T** A, T** B, T** C, int n) {
	for(int ii=0; ii<n; ii++){
        for(int jj=0; jj<n; jj++){
            int soma = 0;
            for(int kk=0; kk<n; kk++){
                soma += A[ii][kk] * B[kk][jj];
            }
            C[ii][jj] = soma;
        }
    }
}

/**
* @brief Funcao que multiplica duas matrizes quadradas de dimensao n x n de forma recursiva
* @param A Matriz de entrada
* @param B Matriz de entrada
* @param n Dimensao das matrizes de entrada
* @return Matriz produto resultante da multiplicacao
*/
template <typename T>
void multiplicaR(T** A, T** B, T** C, int n) {
	static int i = 0, j = 0, k = 0;

    if(i >= n) {
        return;
    } else if(i < n) {
        if(j < n){
            if(k < n){
                C[i][j] += A[i][k] * B[k][j];
                k++;
                multiplicaR(A, B, C, n);
            }
            k = 0;
            j++;
            multiplicaR(A, B, C, n);
        }
        j = 0;
        i++;
        multiplicaR(A, B, C, n);
    }
}

/**
* @brief Funcao para definir o melhor tempo de cada tipo e armazenar no vetor especifico.
* @param tempo Tempo de execucao do algoritmo, seja ele iterativo ou recursivo.
* @param vetorMelhor Parametro para armazenar em um vetor de melhor tempo iterativo ou recursivo o melhor tempo de execucao.
* @param posicao Indice que indicara onde o tempo sera armazenado.
*/
void melhorTempo(double *tempo, double *vetorMelhor, int posicao);

/**
* @brief Funcao para definir o tempo medio de cada tipo e armazenar no vetor especifico.
* @param tempo Tempo de execucao do algoritmo, seja ele iterativo ou recursivo.
* @param vetorMedio Parametro para armazenar em um vetor de tempo medio iterativo ou recursivo o tempo medio de execucao.
* @param posicao Indice que indicara onde o tempo sera armazenado.
*/
void tempoMedio(double *tempo, double *vetorMedio, int posicao);

/**
* @brief Funcao para definir o pior tempo de cada tipo e armazenar no vetor especifico.
* @param tempo Tempo de execucao do algoritmo, seja ele iterativo ou recursivo.
* @param vetorPior Parametro para armazenar em um vetor de pior tempo iterativo ou recursivo o pior tempo de execucao.
* @param posicao Indice que indicara onde o tempo sera armazenado.
*/
void piorTempo(double *tempo, double *vetorPior, int posicao);

/**
* @brief Funcao para definir o desvio padrao de cada tipo e armazenar no vetor especifico.
* @param tempo Tempo de execucao do algoritmo, seja ele iterativo ou recursivo.
* @param vetorDesvio Parametro para armazenar em um vetor o desvio padrao iterativo ou recursivo.
* @param vetorMedio Parametro para armazenar em um vetor de tempo medio iterativo ou recursivo o tempo medio de execucao.
* @param posicao Indice que indicara onde o tempo sera armazenado.
*/
void desvioPadrao(double *tempo, double *vetorDesvio, double *vetorMedio, int posicao);


#endif