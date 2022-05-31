/**
* @file T_F2_Manipulacao.c
* @author Joao_Tavares
* @brief .C que cont�m fun��es para manipula��o dos jobs e opera��es
* @date May 2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#include "T_F2_Dados.h"
#include "Arquivos_fase_1/IDados.h"

/**
* @brief M�todo que cria um bloco de uma lista gen�rica
* 
* @param lista - vari�vel aonde a lista vai ser armazenada
* 
* @param dados que v�o ser inseridos na lista
*/
g* t_F2_g_criar_bloco(g* lista, void*data) {
	g* novoBloco = malloc(sizeof(data));
	novoBloco->dados = data;
	novoBloco->next;
	return novoBloco;
}

/**
* @brief M�todo que insere um bloco novo em uma lista gen�rica
* 
* @param head - bloco a ser inserido
* 
* @param lista_a_ser_ligada - lista que receber� o bloco
*/
g* t_F2_g_inserir_bloco(g** head,g* lista_a_ser_ligada) {
	if (lista_a_ser_ligada == NULL || head == NULL) return;
	lista_a_ser_ligada->next = *head;
	*head = lista_a_ser_ligada;
	return lista_a_ser_ligada;
}

