/**
* @file T_F2_Dados.h
* @author Joao_Tavares
* @brief Header File que cont�m todas as Assinaturas de fun��es e estruturas
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
* @brief Estrutura para representar um bloco de uma lista gen�rica
*/
struct ListaGenerica {
	void* dados; //Campo que armazena dados gen�ticos
	struct ListaGenerica *next;
};

/**
* @brief Estrutura para representar um planeamento de jobs e opera��es
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
