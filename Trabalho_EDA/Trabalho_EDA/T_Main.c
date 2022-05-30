/**
* @file T_Main.c
* @author Joao_Tavares
* @date 14/03/2022
*
* @brief Ficheiro que invoca todos os métodos dos outros
*/

//Bibliotecas nativas de C
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Header Files usados
#include "IDados.h"

/**
* @brief metodo main
*/
int main()
{
	j* headj = t_j_Cria_Job(1);
	j* job2 = t_j_Cria_Job(2);
	j* job3 = t_j_Cria_Job(3);

	job2 = t_j_Inserir_Novo_Job(&headj, job2);
	job3 = t_j_Inserir_Novo_Job(&headj, job3);

	j* aux;
	aux = headj;
	while (aux != NULL)
	{
		printf("%d\n", aux->numero);
		aux = aux->next;
	}
	return 0;
}