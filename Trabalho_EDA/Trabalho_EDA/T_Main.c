/**
* Autor: Jo�o Tavares
* E-mail: a21871@alunos.ipca.pt
* Data:14/03/2022
* 
* Colocar outros contribuintes aqui abaixo:
* 
* 
*/

//Bibliotecas nativas de C
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "IDados.h"

//�ltera��o do m�todo Main
#define t_main main

//M�todo main, alterado para dar mais legibilidade
int t_main() 
{
	o* otemp;
	o* headop;
	o o2;
	o o3;
	o* po2 = &o2;
	o* po3 = &o3;
	j* h;
	h = CriaJob(1);
	headop = CriaOperacao(1, 1);
	ListaOpera�aoUltimo(&headop, po2);
	ListaOpera�aoUltimo(&headop, po3);
	otemp = headop;
	printf("%d", h->numero);
	while (otemp)
	{
		printf("%d", otemp->number);
		otemp = otemp->nextt;
	}
	return 0;
}