/**
* @file T_Metodos.c
* @author Joao_Tavares
* @date 16/03/2022
* 
* @brief Ficheiro que contém métodos e funções diversos (que não necessariamente alteram as listas)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>

#include "IDados.h"

#pragma region vizualizacao_de_listas

/**
* @brief Método que imprime uma lista de máquinas
* 
* @param head - início da lista de máquinas
*/

void t_m_imprimir_maquinas(m* head) {
	m* temp = head;

	while (temp != NULL) {
		printf("%d-\n", temp->id);
		printf("%d-\n\n",temp->tempoDeProducao);
		temp = temp->next;
	}

	printf("\n");
}

void t_j_imprimirjobs(j* head) {
	j* temp = head;
	while (temp != NULL) {
		printf("Job ID - %d",temp->numero);
		temp = temp->next;
	}
	printf("\n");
}


#pragma endregion

#pragma region Manipulacao_de_Ficheiros
/**
* @brief Função que gera uma lista de máquinas a partir de um ficheiro
* 
* @param nome_do_arquivo - nome do arquivo a ser lido
* 
* @return lista de máquians gerada a partir de um ficheiro
*/

m* t_m_gerar_maquinas_a_partir_de_ficheiros_de_texto(FILE*fpm,char nome_do_arquivo[20]) {
	m* next = NULL;
	m* temp = NULL;

	

	fpm = fopen(nome_do_arquivo, "r");
	int id = 0;
	short tempoDeProd = 0;

	while (fscanf(fpm, "%d,%hi\n", &id, &tempoDeProd) != EOF) {
		temp = t_m_criar_Novo_Bloco(id, tempoDeProd);
		t_m_inserir_novo_Bloco(&next, temp);
	}

	fclose(fpm);

	return temp;
}

o* t_o_gerar_operacoes_a_partir_de_ficheiros_de_texto(m*h,j* job, FILE* fpo, char nome_do_arquivo[20]) {
	o* next = NULL;
	o* temp = NULL;

	fpo = fopen(nome_do_arquivo, "r");
	int id = 0;

	while (fscanf(fpo,"%d",&id) != EOF) {
		temp = t_o_cria_operacao(h,job,id);
		t_o_inserir_nova_Operacao(&next,temp);
	}

	fclose(fpo);

	return temp;
}

j* t_j_gerar_jobs_a_partir_de_ficheiros_de_texto(FILE* fpj, char nome_do_arquivo[20]) {
	j* next = NULL;
	j* temp = NULL;

	fpj = fopen(nome_do_arquivo, "r");
	int Jid = 0;
	int Oid = 0;
	int Mid = 0;
	short Mtime = 0;

	while (fscanf(fpj,"%d,%d,%d,%hi\n",&Jid,&Oid,&Mid,&Mtime) != EOF) {

	}
}

/**
* @brief Função que grava todos os dados em um ficheiro de texto
* 
* @param h - início da lista de máquinas a ser gravada
* @param nome_do_arquivo - nome do arquivo aonde vai ser gravado os dados
* 
* @return true se a lista foi gravada com sucesso
*/
bool t_m_gravar_dados_em_ficheiro_de_texto(m* h, char nome_do_arquivo[20]) {
	m* aux = h;

	FILE* dadosGravados;

	dadosGravados = fopen(nome_do_arquivo,"w");
	while (aux !=NULL) {
		fprintf(dadosGravados,"%d,%d\n",aux->id,aux->tempoDeProducao);
		aux = aux->next;
	}
	fclose(dadosGravados);

	return true;
}

#pragma endregion
