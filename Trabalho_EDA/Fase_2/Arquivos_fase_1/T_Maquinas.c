/**
* @file T_Maquinas.c
* @author Joao_Tavares
* @date 07/05/2022
*
* @brief Arquivo que guarda funções relacionadas às máquinas e sua manipulação
*/

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#include "IDados.h"

#pragma region Criacao_de_maquinas
/**
* @brief Função que cria uma nova máquina
*
* @param machineId - Id da máquina a ser criada
*
* @param tempoDeProd - tempo de produção da máquina a ser criada
*
* @return uma máquina que pode ser ligada com outra em uma lista
*/
m* t_m_criar_Novo_Bloco(int machineId, short tempoDeProd) {
	m* blocoNovo = malloc(sizeof(m));
	blocoNovo->id = machineId;
	blocoNovo->tempoDeProducao = tempoDeProd;
	blocoNovo->next;
	return blocoNovo;
}

/**
* @brief Função que insere uma máquina em uma lista de máquinas
*
* @param h - início da lista que vai receber a máquina
*
* @param maquina - máquina a ser inserida
*
* @return lista de máquinas com a máquina inserida
*/
m* t_m_inserir_novo_Bloco(m** h, m* maquina) {
	if (h == NULL || maquina == NULL) return NULL;
	maquina->next = *h;
	*h = maquina;
	return maquina;
}

#pragma endregion

#pragma region manipulacao_e_remocao_de_maquinas
/**
* @brief Função que procura uma máquina em uma lista de máquinas
*
* @param maquinas - lista de máquinas
*
* @param id - id da máquina a ser encontrada
*
* @return máquina encontrada na lista
*/
m* t_m_procurar_Maquina(m* maquinas, int id) {
	if (maquinas == NULL) return NULL;
	m* aux = NULL;
	aux = maquinas;

	while (aux != NULL) {
		if (aux->id == id) {
			aux->id = id;
		}
	}
	return aux;
}

/**
* @brief Função que remove uma máquina em uma lista de máquinas
*
* @param h - início de uma lista de máquinas
*
* @param id - id da máquina a ser removida
*
* @return retorna a lista sem a máquina que foi indicada para ser removida
*/
m* t_m_remove_Maquina(m* h, int id) {
	if (h == NULL) return NULL;

	if (h->id == id) {
		m* aux = h;
		h = h->next;
		free(aux);
	}

	return h;
}

/**
* @brief método que apaga uma lista de máquinas
*
* @param h - início da lista de máquinas a ser removida
*/
bool t_m_apagar_Maquinas(m** h) {

	bool check = false;
	m* aux;
	while (*h) {
		aux = *h;
		*h = (*h)->next;
		free(aux);
		check = true;
	}
	return check;
}

#pragma endregion