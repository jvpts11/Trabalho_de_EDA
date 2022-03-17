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

//Interfaces
#include "IStructs.h"

//Funcoes e métodos
#include "T_Manipulacao_de_Ficheiros.c"
#include "T_Funcoes.c"
#include "T_Metodos.c"
#include "T_Debug.c"

#define t_main main

bool programaCorrendo;

bool checarSeEstaCorrendo(int a) {
	if (a == 1) {
		return true;
	}
	else {
		return false;
	}
}

//Método main, alterado para dar mais legibilidade
int t_main() {
	int a = 1;
	do {
		programaCorrendo = checarSeEstaCorrendo(a);
	} while (programaCorrendo == true);

	return 0;
}