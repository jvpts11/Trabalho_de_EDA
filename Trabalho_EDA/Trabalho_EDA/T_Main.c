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
	//AlteraOperacao(&headop, 2, 4, 5, 8, 9, 0, 0);
}