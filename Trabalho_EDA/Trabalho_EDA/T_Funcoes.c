/**
* Autor: João Tavares
* E-mail: a21871@alunos.ipca.pt
* Data:16/03/2022
* 
* Descrição: Esse arquivo guarda as funções para realizar operações, listagens dentre outras coisas que
* precisem retornar dados.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "IDados.h"

#pragma region Funções_Job_e_Operations


#pragma endregion

#pragma region Funções_de_Tempo
//Retorna a quantidade máxima de tempo em segundos
short t_f_Max_de_Tempo(m_t*h) {
	if (h == NULL) return NULL;
	m_t* aux = h;
	int tempoMax = aux->tempoDeProducao;

	while (aux !=NULL) {
		if (aux->tempoDeProducao > tempoMax) {
			tempoMax = aux->tempoDeProducao;
		}
		aux = aux->next;
	}
	return tempoMax;
}

//Retorna a quantidade mínima de tempo em segundos
short t_f_Min_de_Tempo(m_t* h) {
	if (h == NULL) return NULL;
	m_t* aux = h;
	short tempoMin = aux->tempoDeProducao;

	while (aux != NULL) {
		if (aux->tempoDeProducao < tempoMin) {
			tempoMin = aux->tempoDeProducao;
		}
		aux = aux->next;
	}
	
	return tempoMin;
}

//Retorna a quantidade média de tempo em segundos
short t_f_Med_de_Tempo(m_t*h) {
	if (h == NULL) return NULL;

	m_t* aux = h;

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