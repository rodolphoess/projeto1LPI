/** 
*@file  leitura.h
*@brief Funçao para leitura das matrizes dos arquivos A e B.
*@author Luís Eduardo Rique (luiseduardorique@gmail.com)
*@author Rodolpho Erick (rodolphoerick90@gmail.com)
*@since 26/04/2017
*@date  01/05/2017
*/

#ifndef LEITURA_H
#define LEITURA_H

#include <chrono>
#include <string>
#include <fstream>

using namespace std;

/**
* @brief Funcao para leitura das matrizes contida nos arquivos
* @param nomeArquivosA 	nome dos arquivos que contem as matrizes A.
* @param nomeArquivosB 	nome dos arquivos que contem as matrizes B.
* @param numMatrizes 	numero de matrizes de cada tipo.
*/
void leitura(string *nomeArquivosA, string *nomeArquivosB, int numMatrizes);

#endif