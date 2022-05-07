/**
* @file T_Funcoes.c
* @author Joao_Tavares
* @date 16/03/2022
* 
* @brief Esse arquivo guarda as funções de tempo
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "IDados.h"

#pragma region Funções_de_Tempo
/**
* @brief Função que calcula quantidade máxima de tempo em um job
* 
* @param h - apontador do inicio de uma lista
* 
* @return tempo máximo encontrado
*/
short t_f_Max_de_Tempo(m*h) {
	if (h == NULL) return NULL;
	m* aux = h;
	int tempoMax = aux->tempoDeProducao;

	while (aux !=NULL) {
		if (aux->tempoDeProducao > tempoMax) {
			tempoMax = aux->tempoDeProducao;
		}
		aux = aux->next;
	}
	return tempoMax;
}

/**
* @brief Função que calcula quantidade mínima de tempo em um job
*
* @param h - apontador do inicio de uma lista
* 
* @return tempo mínimo encontrado
*/
short t_f_Min_de_Tempo(m* h) {
	if (h == NULL) return NULL;
	m* aux = h;
	short tempoMin = aux->tempoDeProducao;

	while (aux != NULL) {
		if (aux->tempoDeProducao < tempoMin) {
			tempoMin = aux->tempoDeProducao;
		}
		aux = aux->next;
	}
	
	return tempoMin;
}

/**
* @brief Função que calcula quantidade média de tempo em um job
*
* @param h - apontador do inicio de uma lista
* 
* @return média aritmética do tempo
*/
short t_f_Med_de_Tempo(m*h) {
	if (h == NULL) return NULL;

	m* aux = h;

	short media = 0;
	short nmaquinas = 0;
	
	while (aux!=NULL) {
		nmaquinas = nmaquinas + 1;
		media += aux->tempoDeProducao;
		aux = aux->next;
	}
	short mediaFinal = media / nmaquinas;

	return mediaFinal;
}

#pragma endregion