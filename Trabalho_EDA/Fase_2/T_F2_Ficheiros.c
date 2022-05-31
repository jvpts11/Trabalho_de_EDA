/**
* @file T_F2_Manipulacao.c
* @author Joao_Tavares
* @brief Source file que contém funções para ficheiros
* @date May 2022
*/

#include <stdio.h>
#include <stdlib.h>

#include "T_F2_Dados.h"
#include "Arquivos_fase_1/IDados.h"

void t_F2_abrir_plano(char arquivo[MAXFILENAME]) {
	FILE* fp;
}

bool t_F2_gravar_plano(char arquivo[MAXFILENAME]) {
	FILE* fp;

	int job = 0;
	int op = 0;
	int col = 0;
	fp = fopen(arquivo,"w"); //deve ser gravado em arquivo .csv

	for (job = 0; job < J; job++) {
		col = 0;
		fprintf(fp,"");
	}

	fclose(fp);
}