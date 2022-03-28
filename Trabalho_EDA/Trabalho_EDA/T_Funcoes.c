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

//Encontra a última lista do job
/*job* FindTail(job* h)
{
	if (h == NULL) return NULL;
	job* aux = h;
	while (aux)
	{
		if (aux->next == NULL)
		{
			return aux;
		}
	}
}*/
//Cria um job novo
void CriaJob(job** h)
{
	int contador = 0;
	job* aux = *h;
	job* tail; //= FindTail(aux);
	while (aux) //while (aux != NULL)
	{
		contador++;
		tail = aux;
		aux = aux->next;
	}
	job nJob;
	nJob.num = contador++;
	nJob.next = NULL;
	aux = *h;
	while (aux->next)
	{
		aux = aux->next;
	}

	tail->next = aux;
}

//Retorna a quantidade máxima de tempo em segundos
short detQTD_Max_de_Tempo(int unidades_de_tempo[]) {

	return 0;
}

//Retorna a quantidade máxima de tempo em segundos
short detQTD_Min_de_Tempo(int unidades_de_tempo[]) {

	return 0;
}

//Retorna a quantidade média de tempo em segundos
short detQTD_Med_de_Tempo(int unidades_de_tempo[]) {
	return 0;
}