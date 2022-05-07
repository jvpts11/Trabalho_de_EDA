/**
* @file IJobs.h
* @author Joao_Tavares
* @date 14/03/2022
*
* @brief .h que contém as assinaturas das funções relacionadas aos jobs
*/

#pragma once

#include "IDados.h"

j* t_j_Cria_Job(int jobNumber, o* opHead);
j* t_j_Inserir_Novo_Job(j** head, j* job);
j* t_j_remove_Job(j* h, int jobNumber);
j* t_j_procurar_Job(j* job, int jobNumber);
void t_j_apaga_Jobs(j** h);