/**
* @file T_F2_Dados.h
* @author Joao_Tavares
* @brief Header File que contém todas as Assinaturas de funções e estruturas
* @date May 2022
*/

#pragma once

#include <stdbool.h>

#ifndef DATA

#define DATA

#define M 9
#define T 75
#define MAXFILENAME 40 //Nome máximo para um arquivo

#pragma region Estruturas

/**
* @brief Estrutura para representar um bloco de uma lista genérica
*/
struct ListaGenerica {
	void* dados; //Campo que armazena dados genéticos
	struct ListaGenerica *next;
};

/**
* @brief Estrutura para representar um planeamento de jobs e operações
*/
struct Planeamento {
	int jobId;
	int opId;
};

/**
* @brief Estrutura auxiliar usada na função de t_F2_ocupar_planeamento
*/
struct EstruturaDeDadosAuxiliar {
	int jobId;
	int opId;
	int machineId;
	int unidades_de_tempo;
};

typedef struct EstruturaDeDadosAuxiliar e;
typedef struct Planeamento p;
typedef struct ListaGenerica g;
#pragma endregion

//nota: nenhum desses métodos foi usado no final
#pragma region MetodosListasGenericas

g* t_F2_g_criar_bloco(g* lista, void* data);

g* t_F2_g_inserir_bloco(g** head, g* lista_a_ser_ligada);

#pragma endregion

#pragma region Planeamento
bool t_F2_iniciar_planeamento(p planeamento[][T], int jobId, int opId);

bool t_F2_verificar_espaco_no_planeamento(p planeamento[][T], int j, int jEnd, int machineId);

bool t_F2_ocupar_planeamento(p planeamento[][T], char nome_do_arquivo[MAXFILENAME]);

#pragma endregion

#pragma region manipulacao_de_ficheiros

j* t_F2_guardar_tudo_do_job(j* job_a_ser_gravado);

bool t_F2_gravar_plano(p planeamento[][T]);

#pragma endregion

#endif
