/**
* Autor: João Tavares
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

//Ãlteração do método Main
#define t_main main

//Método main, alterado para dar mais legibilidade
int t_main() 
{
	o* headop = NULL;
	o* otemp;
	j* h;
	h = CriaJob(1);
	NovaOperacao(&headop, 8);
	RemoveOperacao(&headop, 5);

	o* aux = headop;
	while (aux)
	{
		printf("%d\n", aux->number);
		aux = aux->nextt;
	}
	return 0;
}