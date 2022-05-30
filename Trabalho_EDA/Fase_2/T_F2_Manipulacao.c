/**
* @file T_F2_Manipulacao.c
* @author Joao_Tavares
* @brief .C que contém funções para manipulação dos jobs e operações
*/

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>


#include "T_F2_Dados.h"

g* t_F2_Insere_No_Inicio(g* inicio, void *dados) {

	if (dados == NULL) return inicio;
	g* aux;

	if (inicio == NULL) {
		aux = (g*)malloc(sizeof(g));
		aux->dados = dados;
		aux->next = NULL;
		inicio = aux;
		return inicio;
	}

	inicio->next = t_F2_Insere_No_Inicio(inicio->next,dados);

	return inicio;
}

g* t_F2_abrir_arquivo(char nome_do_arquivo[30]) {

	g* aux;
	FILE* fp;

	fp = fopen(nome_do_arquivo,"r");

	while (fscanf(fp,"") != EOF) {

	}


}

void t_F2_gravar_arquivo(g* lista, char nome_do_arquivo[30] ) {
	if (lista == NULL)return;

	FILE* fp;
	
	fp = fopen(nome_do_arquivo,"w");

	while (lista != NULL) {

	}
	
}