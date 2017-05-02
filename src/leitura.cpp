/** 
*@file  leitura.cpp
*@brief Funçao para leitura das matrizes dos arquivos A e B.
*@author Luís Eduardo Rique (luiseduardorique@gmail.com)
*@author Rodolpho Erick (rodolphoerick90@gmail.com)
*@since 26/04/2017
*@date  01/05/2017
*/

#include "../include/leitura.h"
#include "../include/funcoes.h"

/**
* @brief Funcao para leitura das matrizes contida nos arquivos
* @param nomeArquivosA 	nome dos arquivos que contem as matrizes A.
* @param nomeArquivosB 	nome dos arquivos que contem as matrizes B.
* @param numMatrizes 	numero de matrizes de cada tipo.
*/
void leitura(string *nomeArquivosA, string *nomeArquivosB, int numMatrizes) {	
	double *melhorI = new double[numMatrizes];
	double *medioI = new double[numMatrizes];
	double *piorI = new double[numMatrizes];
	double *desvioI = new double[numMatrizes];

	double *melhorR = new double[numMatrizes];
	double *medioR = new double[numMatrizes];
	double *piorR = new double[numMatrizes];
	double *desvioR = new double[numMatrizes];

	int vetorEstatistica = 0;

	for (int i = 0; i < numMatrizes; i++) {		
		ifstream entradaA(nomeArquivosA[i]);		
		
		int dimensao, lixo, primeiroValorA, primeiroValorB;
		
		entradaA >> dimensao;	/**< Pegando o tamanho da matriz quadrada A. */		
		entradaA >> lixo;		/**< Pegando a segunda informacao quanto ao tamanho mas ignorando-a. */
		
		entradaA >> primeiroValorA;	/**< Obtendo o primeiro valor da matriz para posterior checagem se e int ou double. */
		int numTesteA = (int) primeiroValorA;
		int **matrizA = new int*[dimensao];

		if (numTesteA == primeiroValorA) {	/**< Realizando a checagem se trata-se de uma matriz int ou double. */
			for (int i = 0; i < dimensao; i++) {
				matrizA[i] = new int[dimensao];
			}
		} else {
			double **matrizA = (double**) matrizA;
			for (int i = 0; i < dimensao; i++) {
				matrizA[i] = new double[dimensao];
			}
		}

		entradaA.clear();
		entradaA.seekg(entradaA.beg);

		entradaA >> lixo;	
		entradaA >> lixo;

		for (int i = 0; i < dimensao; i++) {	/**< Inicializando a matriz A. */
			for (int j = 0; j < dimensao; j++) {
				entradaA >> matrizA[i][j];
			}
		}

		entradaA.close();


		ifstream entradaB(nomeArquivosB[i]);
		entradaB >> dimensao;	/**< Pegando o tamanho da matriz quadrada B. */	
		entradaB >> lixo;		/**< Pegando a segunda informacao quanto ao tamanho mas ignorando-a. */

		entradaB >> primeiroValorB;		/**< Obtendo o primeiro valor da matriz para posterior checagem se e int ou double. */
		int numTesteB = (int) primeiroValorB;

		int **matrizB = new int*[dimensao];
		int **matrizC = new int*[dimensao];

		if (numTesteB == primeiroValorB) {		/**< Realizando a checagem se trata-se de uma matriz int ou double. */
			for (int i = 0; i < dimensao; i++) {
				matrizB[i] = new int[dimensao];
			}
		} else {
			double **matrizB = (double**) matrizB;
			double **matrizC = (double**) matrizC;
			for (int i = 0; i < dimensao; i++) {
				matrizB[i] = new double[dimensao];
				matrizC[i] = new double[dimensao];
			}
		}

		entradaB.clear();
		entradaB.seekg(entradaB.beg);

		entradaB >> lixo;
		entradaB >> lixo;

		for (int i = 0; i < dimensao; i++) {	/**< Inicializando a matriz B. */
			for (int j = 0; j < dimensao; j++) {
				entradaB >> matrizB[i][j];
			}
		}

		entradaB.close();	


		double tempoI[20];
		for (int i = 0; i < 20; i++) {
			auto t1 = std::chrono::steady_clock::now();
			multiplicaI(matrizA, matrizB, matrizC, dimensao);
			auto t2 = std::chrono::steady_clock::now();
			auto deltaTI = t2 - t1;
			tempoI[i] = std::chrono::duration <double, std::milli> (deltaTI).count();
		}

		bool resultadoArquivo = print(matrizC, dimensao);

		if (resultadoArquivo) {
			cout << "Arquivo C" << dimensao << "x" << dimensao << ".txt gerado com sucesso." << endl;
		} else {
			cerr << "Arquivo C" << dimensao << "x" << dimensao << ".txt nao foi gerado." << endl;			
		}

		double tempoR[20];
		for (int i = 0; i < 20; i++) {
			auto t3 = std::chrono::steady_clock::now();
			multiplicaR(matrizA, matrizB, matrizC, dimensao);
			auto t4 = std::chrono::steady_clock::now();
			auto deltaTR = t4 - t3;
			tempoR[i] = std::chrono::duration <double, std::milli> (deltaTR).count();
		}

		melhorTempo(tempoI, melhorI, vetorEstatistica);
		piorTempo(tempoI, piorI, vetorEstatistica);
		tempoMedio(tempoI, medioI, vetorEstatistica);		
		desvioPadrao(tempoI, desvioI, medioI, vetorEstatistica);

		melhorTempo(tempoR, melhorR, vetorEstatistica);
		piorTempo(tempoR, piorR, vetorEstatistica);
		tempoMedio(tempoR, medioR, vetorEstatistica);		
		desvioPadrao(tempoR, desvioR, medioR, vetorEstatistica);

		++vetorEstatistica;
	}

	delete [] melhorI;
	delete [] medioI;
	delete [] piorI;
	delete [] desvioI;	

	delete [] melhorR;
	delete [] medioR;
	delete [] piorR;
	delete [] desvioR;
	
}
