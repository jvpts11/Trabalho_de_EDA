/**
* @file T_F2_Manipulacao.c
* @author Joao_Tavares
* @brief .C que contém funções para manipulação dos jobs e operações
* @date May 2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>


#include "T_F2_Dados.h"

g* t_F2_g_criar_bloco(g* lista, void*data) {
	g* novoBloco = malloc(sizeof(data));
	novoBloco->dados = data;
	novoBloco->next;
	return novoBloco;
}

g* t_F2_g_inserir_bloco(g**head,g*lista_a_ser_ligada) {
	if (lista_a_ser_ligada == NULL || head == NULL) return;
	lista_a_ser_ligada->next = *head;
	*head = lista_a_ser_ligada;
	return lista_a_ser_ligada;
}