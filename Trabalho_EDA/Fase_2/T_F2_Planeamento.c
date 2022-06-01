/**
* @file T_F2_Planeamento.c
* @author Joao_Tavares
* @brief Source file que contém funções para ficheiros
* @date May 2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "T_F2_Dados.h"
#include "Arquivos_fase_1/IDados.h"

bool t_F2_iniciar_planeamento(p planeamento[][T], int jobId,int opId) {
	for (int i = 0; i < M;i++) { //notação de matriz ij
		for (int j = 0;j < T;j++) {
			planeamento[i][j].jobId = jobId;
			planeamento[i][j].opId = opId;
		}
	}
}

/**
* @brief Função que grava um plano inteiro de operações e jobs em um arquivo de texto
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