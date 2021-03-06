/**
* @file T_Jobs.c
* @author Joao_Tavares
* @date 07/05/2022
*
* @brief Arquivo que guarda funcoes relacionadas aos jobs e sua manipulacao
*/


#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

#include "IDados.h"


/**
* @brief Fun??o que cria um job
*
* @param jobNumber - n?mero do job
*
* @param opHead - lista de opera??es
*
* @return um job que pode ser ligado com uma lista de opera??es e outro job
*/
j* t_j_Cria_Job(int jobNumber)
{
	j* jobNovo = malloc(sizeof(j));
	jobNovo->numero = jobNumber;
	jobNovo->operation = NULL;
	jobNovo->next = NULL;
	return jobNovo;
}

/**
* @brief Fun??o que insere um job em uma lista de jobs
*
* @param head - apontador de apontador de uma lista de jobs
*
* @param job - job a ser inserido
*
* @return lista com o job inserido
*/
j* t_j_Inserir_Novo_Job(j** head, j* job)
{
	if (head == NULL || job == NULL) return NULL;
	job->next = *head;
	*head = job;
	return job;
}

/**
* @brief Fun??o que remove um job especifico
*
* @param h - In?cio de uma lista de jobs
*
* @param jobNumber - n?mero do job a ser removido
*
* @return lista de jobs sem o job removido
*/
j* t_j_remove_Job(j* h, int jobNumber) {
	if (h == NULL) return NULL;

	if (h->numero == jobNumber) {
		j* aux = h;
		h = h->next;
		free(aux);
	}
	return h;
}

/**
* @brief Fun??o que procura um job em uma lista de jobs
*
* @param job - lista de jobs
*
* @param jobNumber - job a ser procurado
*
* @return job encontrado
*/
j* t_j_procurar_Job(j* job, int jobNumber) {
	if (job == NULL) return NULL;
	j* aux = NULL;
	aux = job;

	while (aux != NULL) {
		if (aux->numero == jobNumber) {
			aux->numero = jobNumber;
		}
	}
	return aux;
}

/**
* @brief m?todo que apaga uma lista de jobs da mem?ria
*
* @param h - lista a ser apagada
*
*/
void t_j_apaga_Jobs(j** h) {
	j* aux;
	while (*h) {
		aux = *h;
		*h = (*h)->next;
		free(aux);
	}
}