/**
* Autor: Jo�o Tavares
* E-mail: a21871@alunos.ipca.pt
* Data:16/03/2022
* 
* Descri��o: Pequeno arquivo para debug, nao deve ser implementado no fim do projeto
*/

#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

//M�todo apenas para debugging e acesso a outros m�todos
void t_debug_print() {
	printf("printf aqui fodase kkkk");
}

int t_debug_dividir(int a, int b) {
	int c;

	if (b > 0) {
		c = a / b;
		return c;
	}
	else {
		return("Retornei string kkkk");
	}
}