/**
* @file T_Metodos.c
* @author Joao_Tavares
* @date 16/03/2022
*
* @brief Ficheiro que cont�m m�todos e fun��es diversos (que n�o necessariamente alteram as listas)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>

#include "IDados.h"

#pragma region vizualizacao_de_listas

/**
* @brief M�todo que imprime uma lista de m�quinas
*
* @param head - in�cio da lista de m�quinas
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
* @brief Fun��o que gera uma lista de m�quinas a partir de um ficheiro
*
* @param nome_do_arquivo - nome do arquivo a ser lido
*
* @param operacao - operacao que receber� as m�quinas
* 
* @return operacao com m�quians devidamente inseridas
*/
m* t_m_gerar_maquinas_a_partir_de_ficheiros_de_texto(char nome_do_arquivo[20],o* operacao) {
	m* next = NULL;
	m* temp = NULL;

	FILE* fp;

	fp = fopen(nome_do_arquivo, "r");
	int id = 0;
	int operationId = 0;
	short tempoDeProd = 0;

	while (fscanf(fp, "%d,%d,%hi\n",&operationId ,&id, &tempoDeProd) != EOF) { //L� m�quinas at� o fim do arquivo
		temp = t_m_criar_Novo_Bloco(id,tempoDeProd);
		t_o_inserir_maquina_na_operacao(operacao,operationId,temp); //insere as m�quinas na opera��o
	}

	fclose(fp);

	return;
}

/**
* @brief Fun��o que gera opera��es a partir de ficheiros de texto
* 
* @param nome_do_arquivo - nome do arquivo .txt aonde est�o as opera��es
* 
* @return lista de opera��es
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
* Fun��o que gera jobs a partir de ficheiros de text
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
* @brief Fun��o que grava todos os dados em um ficheiro de texto
*
* @param h - in�cio da lista de m�quinas a ser gravada
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
