/**
* @file T_F2_Manipulacao.c
* @author Joao_Tavares
* @brief Source file que cont�m fun��es para ficheiros
* @date May 2022
*/

#include <stdio.h>
#include <stdlib.h>

#include "T_F2_Dados.h"
#include "Arquivos_fase_1/IDados.h"


/**
* @brief Fun��o que abre um plano de opera��es e jobs
* 
* @param arquivo - nome do arquivo a ser aberto
*/
void t_F2_abrir_plano(char arquivo[MAXFILENAME]) {
	FILE* fp;
}

/**
* @brief Fun��o que grava um plano inteiro de opera��es e jobs em um arquivo de texto
* 
* @param arquivo - nome do arquivo a ser gravado
*/
bool t_F2_gravar_plano(char arquivo[MAXFILENAME]) {
	FILE* fp;

	int job = 0;
	int op = 0;
	int col = 0;
	fp = fopen(arquivo,"w"); //deve ser gravado em arquivo .csv

	for (job = 0; job < M; job++) {
		col = 0;
		fprintf(fp,"");
	}

	fclose(fp);
}