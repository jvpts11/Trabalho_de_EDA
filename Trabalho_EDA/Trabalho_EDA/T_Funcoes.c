/**
* Autor: Jo�o Tavares
* E-mail: a21871@alunos.ipca.pt
* Data:16/03/2022
* 
* Descri��o: Esse arquivo guarda as fun��es para realizar opera��es, listagens dentre outras coisas que
* precisem retornar dados.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "IDados.h"

//Fun��o que cria job
j* CriaJob(int n)
{
	j* novo = malloc(sizeof(j));
	novo->numero = n;
	novo->next = NULL;
	return novo;
}


//Fun��o que cria uma opera��o
o* CriaOperacao(int job, int id)
{
	o* novo = malloc(sizeof(o));
	novo->job = job;
	novo->number = id;
	novo->next = NULL;
	novo->nextt = NULL;
}

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



//Retorna a quantidade m�xima de tempo em segundos
double detQTD_Max_de_Tempo(int unidades_de_tempo[]) {

	return 0;
}

//Retorna a quantidade m�xima de tempo em segundos
double detQTD_Min_de_Tempo(int unidades_de_tempo[]) {

	return 0;
}

//Retorna a quantidade m�dia de tempo em segundos
double detQTD_Med_de_Tempo(int unidades_de_tempo[]) {


	int media = 0;

	for (int i = 0; i < sizeof(unidades_de_tempo); i++) {
		media += unidades_de_tempo[i];
	}

	double mediaFinal = media / sizeof(unidades_de_tempo);

	return mediaFinal;
}