/**
* @file T_F2_Main.c
* @author Joao_Tavares
* @brief Chama todas as funções
* @date May 2022
*/

#include <stdio.h>
#include <stdlib.h>

#include "T_F2_Dados.h"
#include "Arquivos_fase_1/IDados.h"

void main() 
{
	j* hj = t_j_Cria_Job(1);
	j* job2 = t_j_Cria_Job(2);
	j* job3 = t_j_Cria_Job(3);
	j* job4 = t_j_Cria_Job(4);

	//job1 = t_j_Inserir_Novo_Job(hj, job1);
	job2 = t_j_Inserir_Novo_Job(&hj, job2);
	job3 = t_j_Inserir_Novo_Job(&hj, job3);
	job4 = t_j_Inserir_Novo_Job(&hj, job4);

	//hj = t_j_remove_Job(hj, 2);

	//j* aux = t_j_procurar_Job(hj, 2);
	//printf("%d", aux->numero);

	o* ope1 = t_o_cria_operacao(1);
	o* ope2 = t_o_cria_operacao(2);
	o* ope3 = t_o_cria_operacao(3);
	o** ho_1 = ope1;

	ope2 = t_o_inserir_nova_Operacao(&ho_1, ope2);
	ope3 = t_o_inserir_nova_Operacao(&ho_1, ope3);
	

	o* auxx;
	auxx = ho_1;
	//auxx = t_o_procurar_Operacao(ho_1, 1);

	auxx = t_o_remover_operacao(ho_1, 3);

	/*
	aux = hj;

	while (aux != NULL)
	{
		printf("%d\n", aux->numero);
		aux = aux->next;
	}
	*/

	while (auxx != NULL)
	{
		printf("%d\n", auxx->number);
		auxx = auxx->nextt;
	}
}