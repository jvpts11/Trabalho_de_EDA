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
bool t_m_imprimir_maquinas(m* head) {
	
	bool check = false;
	m* temp = head;

	while (temp != NULL) {
		printf("%d-\n", temp->id);
		printf("%d-\n\n", temp->tempoDeProducao);
		temp = temp->next;
		check = true;
	}

	printf("\n");
	return check;
}

#pragma endregion

#pragma region Manipulacao_de_Ficheiros
/**
* @brief Função que gera uma lista de máquinas a partir de um ficheiro
*
* @param nome_do_arquivo - nome do arquivo a ser lido
*
* @param operacao - operacao que receberá as máquinas
* 
* @return operacao com máquians devidamente inseridas
*/
m* t_m_gerar_maquinas_a_partir_de_ficheiros_de_texto(char nome_do_arquivo[20],o* operacao) {
	m* next = NULL;
	m* temp = NULL;

	FILE* fp;

	fp = fopen(nome_do_arquivo, "r");
	int id = 0;
	int operationId = 0;
	short tempoDeProd = 0;

	while (fscanf(fp, "%d,%d,%hi\n",&operationId ,&id, &tempoDeProd) != EOF) { //Lê máquinas até o fim do arquivo
		temp = t_m_criar_Novo_Bloco(id,tempoDeProd);
		t_o_inserir_maquina_na_operacao(operacao,operationId,temp); //insere as máquinas na operação
	}

	fclose(fp);

	return;
}

/**
* @brief Função que gera operações a partir de ficheiros de texto
* 
* @param nome_do_arquivo - nome do arquivo .txt aonde estão as operações
* 
* @return lista de operações
*/
o* t_o_gerar_operacoes_a_partir_de_ficheiros_de_texto(char nome_do_arquivo[20]) {
	o* next = NULL;
	o* temp = NULL;

	FILE* fp;

	fp = fopen(nome_do_arquivo, "r");
	int id = 0;

	while (fscanf(fp, "%d", &id) != EOF) {
		temp = t_o_cria_operacao(id);
		t_o_inserir_nova_Operacao(&next, temp);
	}

	fclose(fp);

	return temp;
}

/**
* Função que gera jobs a partir de ficheiros de text
* 
* @param nome_do_arquivo - nome do arquivo a ser aberto
* 
* @return lista de jobs
*/
j* t_j_gerar_jobs_a_partir_de_ficheiros_de_texto(char nome_do_arquivo[20]) {
	j* next = NULL;
	j* temp = NULL;

	FILE* fp;

	fp = fopen(nome_do_arquivo, "r");
	int id = 0;

	while (fscanf(fp, "%d\n", &id) != EOF) {
		temp = t_j_Cria_Job(id);
		t_j_Inserir_Novo_Job(&next,temp);
	}

	return temp;
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

	dadosGravados = fopen(nome_do_arquivo, "w");
	while (aux != NULL) {
		fprintf(dadosGravados, "%d,%d\n", aux->id, aux->tempoDeProducao);
		aux = aux->next;
	}
	fclose(dadosGravados);

	return true;
}

#pragma endregion
