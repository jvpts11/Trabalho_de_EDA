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
	j* job1 = t_j_Cria_Job(1);
	j* job2 = t_j_Cria_Job(2);
	j* job3 = t_j_Cria_Job(3);
	j** headj = job1;

	job2 = t_j_Inserir_Novo_Job(&headj, job2);
	job3 = t_j_Inserir_Novo_Job(&headj, job3);

	o* op1_1 = t_o_cria_operacao(1);
	o* op1_2 = t_o_cria_operacao(2);
	o* op1_3 = t_o_cria_operacao(3);
	o** headop1 = op1_1;

	op1_2 = t_o_inserir_nova_Operacao(&headop1, op1_2);
	op1_3 = t_o_inserir_nova_Operacao(&headop1, op1_3);

	o* op2_1 = t_o_cria_operacao(1);
	o* op2_2 = t_o_cria_operacao(2);
	o** headop2 = op2_1;

	op2_2 = t_o_inserir_nova_Operacao(&headop2, op2_1);

	o* op3_1 = t_o_cria_operacao(1);
	o* op3_2 = t_o_cria_operacao(2);
	o* op3_3 = t_o_cria_operacao(3);
	o* op3_4 = t_o_cria_operacao(4);
	o* op3_5 = t_o_cria_operacao(5);
	o** headop3 = op3_1;

	op3_2 = t_o_inserir_nova_Operacao(&headop3, op3_2);
	op3_3 = t_o_inserir_nova_Operacao(&headop3, op3_3);
	op3_4 = t_o_inserir_nova_Operacao(&headop3, op3_4);
	op3_5 = t_o_inserir_nova_Operacao(&headop3, op3_5);

	job1->operation = op1_1;
	job2->operation = op2_1;
	job3->operation = op3_1;

	
	j* aux;
	aux = headj;
	o* auxx;
	auxx = t_o_procurar_Operacao(headop1, 1);
	while (aux != NULL)
	{
		if (aux->numero == 1)
		{
			printf("%d\n", auxx->number);
			auxx = auxx->nextt;
		}
	}
	return 0;
	
}