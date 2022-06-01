/**
* @file T_F2_Planeamento.c
* @author Joao_Tavares
* @brief Source file que contém funções para ficheiros
* @date May 2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "T_F2_Dados.h"
#include "Arquivos_fase_1/IDados.h"

#pragma region planeamento

/**
* @brief Inicia um planeamento de jobs e operações
* 
* @param planeamento[][T] - variável do planeamento que irá receber os jobs e operações
* 
* @param jobId - id do job que entrará no planeamento
* 
* @param opId - id da operação que entrará no planeamento
* 
* @return um booleano para testar se a função funcionou ou não
*/
bool t_F2_iniciar_planeamento(p planeamento[][T], int jobId,int opId) {
	for (int i = 0; i < M;i++) { //notação de matriz ij
		for (int j = 0;j < T;j++) {
			planeamento[i][j].jobId = jobId;
			planeamento[i][j].opId = opId;
		}
	}
}

/**
* @brief função booleana que verifica se há espaço em determinada célula em um planeamento
* 
* @param j - coluna
* 
* @param jEnd - última coluna do planeamento
* 
* @param machineId - id da máquina em questão na célula
*/
bool t_F2_verificar_espaco_no_planeamento(p planeamento[][T],int j,int jEnd, int machineId) { //I,J - notação de matriz
	for (; j < jEnd; j++) {
		if (planeamento[machineId][j].jobId != -1) {
			return true;
		}
	}
	return false;
}

/**
* @brief Função para ocupar um planeamento de jobs e operações
* 
* @param planeamento[][T] - planeamento que será ocupado
* 
* @param nome_do_arquivo - arquivo aonde está o conjunto de jobs que receberá o planeamento
*/
bool t_F2_ocupar_planeamento(p planeamento[][T], char nome_do_arquivo[MAXFILENAME]) {
	FILE* fp;

	int jobId;
	int opId;
	int machineId;
	int unidades_de_tempo;

	int j = 0;
	int jEnd = 0;

	int auxJob = 0;

	e auxiliar;

	fp = fopen(nome_do_arquivo,"r");

	while (fscanf(fp,"%d,%d,%d,%d\n", &auxiliar.jobId, &auxiliar.opId, &auxiliar.machineId, &auxiliar.unidades_de_tempo)) {

		if (auxJob == auxiliar.jobId) {
			j = jEnd;
		}

		else {
			j = 0;
		}

		while (planeamento[auxiliar.machineId][auxiliar.unidades_de_tempo].jobId != -1) {
			j++;
		}

		int aux_jEnd = j + auxiliar.unidades_de_tempo;

	repeat:
		jEnd = j + auxiliar.unidades_de_tempo;
		if (t_F2_verificar_espaco_no_planeamento(planeamento,j,jEnd,auxiliar.machineId) == true) {
			j++; //avança um espaço
			jEnd++; 
			goto repeat; //se repete até que o resultado do if seja falso
		}
		else {
			for (;j<jEnd;j++) {
				planeamento[auxiliar.machineId][j].jobId = auxiliar.jobId;
				planeamento[auxiliar.machineId][j].opId = auxiliar.opId;
			}
		}
		auxJob = auxiliar.jobId;
	}
}

#pragma endregion

#pragma region manipulacao_de_ficheiros

/**
* @brief Função que guarda tudo da lista de jobs, é gravado em um arquivo chamado jobTudo.txt
* 
* @param j* job_a_ser_gravado - job que será gravado em um txt
* 
*/
j* t_F2_guardar_tudo_do_job(j* job_a_ser_gravado) {
	if (job_a_ser_gravado == NULL) return;
	FILE* fp;
	j* aux = job_a_ser_gravado;
	o* auxO1;
	o* auxO2;
	const char filename[MAXFILENAME] = "jobTudo.txt";

	auxO1 = aux->operation;

	
	auxO2 = aux;
	fp = fopen(filename,"a");
	while (auxO2->head != NULL) {
		fprintf(fp,"%d,%d,%d,%d\n",aux->numero,auxO1->number,auxO2->head->id,auxO2->head->tempoDeProducao);
		auxO2 = auxO2->head;
	}
	auxO1 = auxO1->nextt;
	fclose(fp);
}

/**
* @brief Função que grava um plano inteiro de operações e jobs em um arquivo de texto
* 
* @param arquivo - nome do arquivo a ser gravado
*/
bool t_F2_gravar_plano(p planeamento[][T]) {
	FILE* fp;

	int maquina = 0;
	int opId = 0;
	int j = 0; // colunas
	int tempo = 0;
	fp = fopen("plano.csv", "w"); //deve ser gravado em arquivo .csv

	for (maquina = 0; maquina < 1; maquina++) {
		fprintf(fp,"---------- ,");
		for (j = 0; j < T;j++) {
			tempo++;
			fprintf(fp,"T%d",tempo);
		}
		fprintf(fp,"\n");
	}
	for (maquina = 0; maquina < M;maquina++) {
		j = 0;

		fprintf(fp,"Máquina %d: ,",maquina);

		for (j = 0; j < T;j++) {
			if (planeamento[maquina][j].jobId == -1) {
				fprintf(fp,"     ,");
			}
			else {
				fprintf(fp,"J%dO%d,", planeamento[maquina][j].jobId, planeamento[maquina][j].opId);
			}
			fprintf(fp,"\n");
		}
	}

	fclose(fp);
}

#pragma endregion