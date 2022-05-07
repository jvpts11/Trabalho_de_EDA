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
#include "IMaquinas.h"
#include "IOperacoes.h"

FILE* dadosGravados; //Apontador do ficheiro

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


#pragma endregion

#pragma region Manipulacao_de_Ficheiros
/**
* @brief Função que gera uma lista de máquinas a partir de um ficheiro
* 
* @param nome_do_arquivo - nome do arquivo a ser lido
* 
* @return lista de máquians gerada a partir de um ficheiro
*/
m* t_m_gerar_listas_a_partir_de_ficheiros_de_texto(char nome_do_arquivo[20]) {
	m* next = NULL;
	m* temp = NULL;

	dadosGravados = fopen(nome_do_arquivo, "r");
	int id = 0;
	short tempoDeProd = 0;

	while (fscanf(dadosGravados, "%d,%hi\n", &id, &tempoDeProd) != EOF) {
		temp = t_m_criar_Novo_Bloco(id, tempoDeProd);
		t_m_inserir_novo_Bloco(&next, temp);
	}

	fclose(dadosGravados);

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

	dadosGravados = fopen(nome_do_arquivo,"w");
	while (aux !=NULL) {
		fprintf(dadosGravados,"%d,%d\n",aux->id,aux->tempoDeProducao);
		aux = aux->next;
	}
	fclose(dadosGravados);

	return true;
}

#pragma endregion
