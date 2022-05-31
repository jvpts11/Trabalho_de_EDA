/**
* @file T_Maquinas.c
* @author Joao_Tavares
* @date 07/05/2022
*
* @brief Arquivo que guarda fun��es relacionadas �s m�quinas e sua manipula��o
*/

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#include "IDados.h"

#pragma region Criacao_de_maquinas
/**
* @brief Fun��o que cria uma nova m�quina
*
* @param machineId - Id da m�quina a ser criada
*
* @param tempoDeProd - tempo de produ��o da m�quina a ser criada
*
* @return uma m�quina que pode ser ligada com outra em uma lista
*/
m* t_m_criar_Novo_Bloco(int machineId, short tempoDeProd) {
	m* blocoNovo = malloc(sizeof(m));
	blocoNovo->id = machineId;
	blocoNovo->tempoDeProducao = tempoDeProd;
	blocoNovo->next;
	return blocoNovo;
}

/**
* @brief Fun��o que insere uma m�quina em uma lista de m�quinas
*
* @param h - in�cio da lista que vai receber a m�quina
*
* @param maquina - m�quina a ser inserida
*
* @return lista de m�quinas com a m�quina inserida
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
* @brief Fun��o que procura uma m�quina em uma lista de m�quinas
*
* @param maquinas - lista de m�quinas
*
* @param id - id da m�quina a ser encontrada
*
* @return m�quina encontrada na lista
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
* @brief Fun��o que remove uma m�quina em uma lista de m�quinas
*
* @param h - in�cio de uma lista de m�quinas
*
* @param id - id da m�quina a ser removida
*
* @return retorna a lista sem a m�quina que foi indicada para ser removida
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
* @brief m�todo que apaga uma lista de m�quinas
*
* @param h - in�cio da lista de m�quinas a ser removida
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