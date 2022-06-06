/**
* @file T_F2_Main.c
* @author Joao_Tavares
* @brief Chama todas as fun��es
* @date May 2022
*/

#include <stdio.h>
#include <stdlib.h>

#include "T_F2_Dados.h"
#include "Arquivos_fase_1/IDados.h"

void main() 
{

	//M�todos para criar um Job
#pragma region Lista_de_Jobs
	//In�cio da lista de jobs
	j* HeadJob = NULL;

	//Montagem da lista de jobs a partir dos dados do ficheiro
	HeadJob = t_j_gerar_jobs_a_partir_de_ficheiros_de_texto("Arquivos_de_Texto//Jobs//Jobs.txt");

#pragma endregion


	//M�todos para a cria��o de Opera��es
#pragma region Lista_de_Opera��es

	//Montagem das listas de opera��es dos jobs a partir dos dados de um ficheiro

	o* HeadOper1 = NULL;
	HeadOper1 = t_o_gerar_operacoes_a_partir_de_ficheiros_de_texto("Arquivos_de_Texto//Operacoes//OperacoesJobUm.txt");

	o* HeadOper2 = NULL;
	HeadOper2 = t_o_gerar_operacoes_a_partir_de_ficheiros_de_texto("Arquivos_de_Texto//Operacoes//OperacoesJobDois.txt");

	o* HeadOper3 = NULL;
	HeadOper3 = t_o_gerar_operacoes_a_partir_de_ficheiros_de_texto("Arquivos_de_Texto//Operacoes//OperacoesJobTres.txt");

	o* HeadOper4 = NULL;
	HeadOper4 = t_o_gerar_operacoes_a_partir_de_ficheiros_de_texto("Arquivos_de_Texto//Operacoes//OperacoesJobQuatro.txt");

	o* HeadOper5 = NULL;
	HeadOper5 = t_o_gerar_operacoes_a_partir_de_ficheiros_de_texto("Arquivos_de_Texto//Operacoes//OperacoesJobCinco.txt");

	o* HeadOper6 = NULL;
	HeadOper6 = t_o_gerar_operacoes_a_partir_de_ficheiros_de_texto("Arquivos_de_Texto//Operacoes//OperacoesJobSeis.txt");

	o* HeadOper7 = NULL;
	HeadOper7 = t_o_gerar_operacoes_a_partir_de_ficheiros_de_texto("Arquivos_de_Texto//Operacoes//OperacoesJobSete.txt");

	o* HeadOper8 = NULL;
	HeadOper8 = t_o_gerar_operacoes_a_partir_de_ficheiros_de_texto("Arquivos_de_Texto//Operacoes//OperacoesJobOito.txt");

#pragma endregion

	
	//M�todos para inserir os dados das m�quinas de um ficheiro nas opera��es
#pragma region MaquinasdeOpera�oes

    //Maquinas Job 1

	t_m_gerar_maquinas_a_partir_de_ficheiros_de_texto("Arquivos_de_Texto//Maquinas//MaquinasJobUm.txt", HeadOper1);

	//Maquinas Job 2

	t_m_gerar_maquinas_a_partir_de_ficheiros_de_texto("Arquivos_de_Texto//Maquinas//MaquinasJobDois.txt", HeadOper2);

	//Maquinas Job 3

	t_m_gerar_maquinas_a_partir_de_ficheiros_de_texto("Arquivos_de_Texto//Maquinas//MaquinasJobTres.txt", HeadOper3);

	//Maquinas Job 4

	t_m_gerar_maquinas_a_partir_de_ficheiros_de_texto("Arquivos_de_Texto//Maquinas//MaquinasJobQuatro.txt", HeadOper4);

	//Maquinas Job 5

	t_m_gerar_maquinas_a_partir_de_ficheiros_de_texto("Arquivos_de_Texto//Maquinas//MaquinasJobCinco.txt", HeadOper5);

	//Maquinas Job 6

	t_m_gerar_maquinas_a_partir_de_ficheiros_de_texto("Arquivos_de_Texto//Maquinas//MaquinasJobSeis.txt", HeadOper6);

	//Maquinas Job 7

	t_m_gerar_maquinas_a_partir_de_ficheiros_de_texto("Arquivos_de_Texto//Maquinas//MaquinasJobSete.txt", HeadOper7);

	//Maquinas Job 8

	t_m_gerar_maquinas_a_partir_de_ficheiros_de_texto("Arquivos_de_Texto//Maquinas//MaquinasJobOito.txt", HeadOper8);

#pragma endregion


	//Inserir as listas de Opera��es nos jobs
#pragma region Inserir_Opera��es_nos_Jobs

	t_o_inserir_operacao_no_job(HeadJob, HeadOper1);
	t_o_inserir_operacao_no_job(HeadJob, HeadOper2);
	t_o_inserir_operacao_no_job(HeadJob, HeadOper3);
	t_o_inserir_operacao_no_job(HeadJob, HeadOper4);
	t_o_inserir_operacao_no_job(HeadJob, HeadOper5);
	t_o_inserir_operacao_no_job(HeadJob, HeadOper6);
	t_o_inserir_operacao_no_job(HeadJob, HeadOper7);
	t_o_inserir_operacao_no_job(HeadJob, HeadOper8);

	//Guardar em ficheiro a informa��o completa da lista de Jobs

	t_F2_guardar_tudo_do_job(HeadJob);

#pragma endregion


	
#pragma region Parte_do_planeamento

	p planeamento[M][T];

	t_F2_iniciar_planeamento(planeamento, -1, -1);

	t_F2_ocupar_planeamento(planeamento, "jobTudo.txt");

	t_F2_gravar_plano(planeamento);

	#pragma endregion
}