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
#define MAXFILENAME 40

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

typedef struct Planeamento p;
typedef struct ListaGenerica g;
#pragma endregion


#pragma region MetodosListasGenericas

g* t_F2_g_criar_bloco(g* lista, void* data);

g* t_F2_g_inserir_bloco(g** head, g* lista_a_ser_ligada);

#pragma endregion

#pragma region Planeamento
bool t_F2_iniciar_planeamento(p planeamento[][T], int jobId, int opId);

#pragma endregion

#endif
