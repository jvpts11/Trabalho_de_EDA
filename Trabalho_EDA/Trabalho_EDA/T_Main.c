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
	job job1;
	job* p1;
	p1 = &job1;

	p1 = CriaJob(1);

	return 0;
}