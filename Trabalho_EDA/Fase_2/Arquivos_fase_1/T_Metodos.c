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
* @return lista de m�quians gerada a partir de um ficheiro
*/
m* t_m_gerar_maquinas_a_partir_de_ficheiros_de_texto(FILE* fpm, char nome_do_arquivo[20]) {
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

/**
* @brief Fun��o que gera opera��es a partir de ficheiros de texto
*/
o* t_o_gerar_operacoes_a_partir_de_ficheiros_de_texto(FILE* fpo, char nome_do_arquivo[20]) {
	o* next = NULL;
	o* temp = NULL;

	fpo = fopen(nome_do_arquivo, "r");
	int id = 0;

	while (fscanf(fpo, "%d", &id) != EOF) {
		temp = t_o_cria_operacao(id);
		t_o_inserir_nova_Operacao(&next, temp);
	}

	fclose(fpo);

	return temp;
}

/**
* Fun��o que gera jobs a partir de ficheiros de text
* 
* @param fpj - file pointer para jobs
* 
* @param nome_do_arquivo - nome do arquivo a ser aberto
*/
j* t_j_gerar_jobs_a_partir_de_ficheiros_de_texto(FILE* fpj, char nome_do_arquivo[20]) {
	j* next = NULL;
	j* temp = NULL;

	fpj = fopen(nome_do_arquivo, "r");
	int Jid = 0;

	while (fscanf(fpj, "%d\n", &Jid) != EOF) {
		temp = t_j_Cria_Job(Jid);
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