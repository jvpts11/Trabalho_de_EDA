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
//Função que cria job
j* CriaJob(int n)
{
	j* novo = malloc(sizeof(j));
	novo->numero = n;
	novo->next = NULL;
	return novo;
}

//Função que cria uma operação
o* CriaOperacao(int job, int id)
{
	o* novo = malloc(sizeof(o));
	novo->job = job;
	novo->number = id;
	novo->next = NULL;
	novo->nextt = NULL;
}

//Função que procura uma operação
o* ProcuraOperacao(o* h, int id)
{
	if (h == NULL)return NULL;
	o* found = NULL;
	o* aux = h;
	while (aux)
	{
		if (aux->number == id)
		{
			found = aux;
		}
		aux = aux->nextt;
	}
	return found;
}

//Função que cria as operações com o número que o utilizador quiser
void NovaOperacao(o** h, int no)
{
	o* otemp;
	for (size_t i = no; i > 0; i--)
	{
		otemp = CriaOperacao(1, i);
		otemp->nextt = *h;
		*h = otemp;
	}
}

//Função que remove a operação que o utilizador escolher, recebe um apontador para uma operação e seu id
void RemoveOperacao(o** h, int id)
{
	o* aux;
	o* toRemove = ProcuraOperacao(*h, id);
	if (toRemove == *h)
	{
		o* DeptoRemove = ProcuraOperacao(*h, id + 1);
		toRemove->nextt = NULL;
		*h = DeptoRemove;
		aux = *h;
		while (aux != NULL)
		{
			aux->number = aux->number - 1;
			aux = aux->nextt;
		}
	}
	else if (toRemove->nextt == NULL)
	{
		o* AnttoRemove = ProcuraOperacao(*h, id - 1);
		AnttoRemove->nextt = NULL;
	}
	else
	{
		o* AnttoRemove = ProcuraOperacao(*h, id - 1);
		o* DeptoRemove = ProcuraOperacao(*h, id + 1);
		toRemove->nextt = NULL;
		AnttoRemove->nextt = DeptoRemove;
		aux = DeptoRemove;
		while (aux != NULL)
		{
			aux->number = aux->number - 1;
			aux = aux->nextt;
		}
	}
}

//Função que altera uma operação
void AlteraOperacao(o** h, int id, int a, short b, int c, short d, int e, short f)
{
	o* alterar = ProcuraOperacao(*h, id);

	m_t* novo = criarNovoBloco(a, b);
	
	alterar->next = novo;
	m_t* novo2 = NULL;
	if (c != 0 && d != 0)
	{
		m_t* novo2 = criarNovoBloco(c, d);
		novo->next = novo2;
	}
	else if (e != 0 && f != 0)
	{
		novo2->next = criarNovoBloco(e, f);
	}

	*h = alterar;
}

#pragma endregion

#pragma region Funções_de_Tempo
//Retorna a quantidade máxima de tempo em segundos
short t_detQTD_Max_de_Tempo(m_t*h) {
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
short t_detQTD_Min_de_Tempo(m_t* h) {
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
short t_detQTD_Med_de_Tempo(m_t*h) {
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