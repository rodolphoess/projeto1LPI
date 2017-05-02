/** 
*@file  funcoes.cpp
*@brief Arquivo de corpo contendo a implentacao das funcoes que realizam
*		a multiplicacao de matrizes de forma recursiva e iterativa, a de impressao e estatisticas.
*@author Luís Eduardo Rique (luiseduardorique@gmail.com)
*@author Rodolpho Erick (rodolphoerick90@gmail.com)
*@since 26/04/2017
*@date  01/05/2017
*/

#include "../include/funcoes.h"

/**
* @brief Funcao para definir o melhor tempo de cada tipo e armazenar no vetor especifico.
* @param tempo Tempo de execucao do algoritmo, seja ele iterativo ou recursivo.
* @param vetorMelhor Parametro para armazenar em um vetor de melhor tempo iterativo ou recursivo o melhor tempo de execucao.
* @param posicao Indice que indicara onde o tempo sera armazenado.
*/
void melhorTempo(double *tempo, double *vetorMelhor, int posicao) {
	int numExecucoes = 20;
	double melhorTempo = tempo[0];

	for (int i = 0; i < numExecucoes; i++) {
		if (melhorTempo > tempo[i]) {
			melhorTempo = tempo[i];
		}
	}

	vetorMelhor[posicao] = melhorTempo;
}

/**
* @brief Funcao para definir o tempo medio de cada tipo e armazenar no vetor especifico.
* @param tempo Tempo de execucao do algoritmo, seja ele iterativo ou recursivo.
* @param vetorMedio Parametro para armazenar em um vetor de tempo medio iterativo ou recursivo o tempo medio de execucao.
* @param posicao Indice que indicara onde o tempo sera armazenado.
*/
void tempoMedio(double *tempo, double *vetorMedio, int posicao) {
	int numExecucoes = 20;
	double somaTempos = 0.0;

	for (int i = 0; i < numExecucoes; i++) {
		somaTempos += tempo[i];
	}

	vetorMedio[posicao] = somaTempos / numExecucoes;

}

/**
* @brief Funcao para definir o pior tempo de cada tipo e armazenar no vetor especifico.
* @param tempo Tempo de execucao do algoritmo, seja ele iterativo ou recursivo.
* @param vetorPior Parametro para armazenar em um vetor de pior tempo iterativo ou recursivo o pior tempo de execucao.
* @param posicao Indice que indicara onde o tempo sera armazenado.
*/
void piorTempo(double *tempo, double *vetorPior, int posicao) {
	int numExecucoes = 20;
	double piorTempo = tempo[0];

	for (int i = 0; i < numExecucoes; i++) {
		if (piorTempo < tempo[i]) {
			piorTempo = tempo[i];
		}
	}

	vetorPior[posicao] = piorTempo;
}

/**
* @brief Funcao para definir o desvio padrao de cada tipo e armazenar no vetor especifico.
* @param tempo Tempo de execucao do algoritmo, seja ele iterativo ou recursivo.
* @param vetorDesvio Parametro para armazenar em um vetor o desvio padrao iterativo ou recursivo.
* @param vetorMedio Parametro para armazenar em um vetor de tempo medio iterativo ou recursivo o tempo medio de execucao.
* @param posicao Indice que indicara onde o tempo sera armazenado.
*/
void desvioPadrao(double *tempo, double *vetorDesvio, double *vetorMedio, int posicao) {
	int numExecucoes = 20;
	double desvioTempos = 0.0;

	for (int i = 0; i < numExecucoes; i++) {
		desvioTempos += pow ((tempo[i]) - vetorMedio[posicao], 2);
	}

	vetorDesvio[posicao] = sqrt((1.0 / numExecucoes) * desvioTempos); 

}

