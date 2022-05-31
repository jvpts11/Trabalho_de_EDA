/**
* @file T_F2_Dados.h
* @author Joao_Tavares
* @brief Header File que cont�m todas as Assinaturas de fun��es e estruturas
* @date May 2022
*/

#pragma once

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
	int job;
	int op;
};

typedef struct Planeamento p;
typedef struct ListaGenerica g;
#pragma endregion


#pragma region MetodosListasGenericas

g* t_F2_g_criar_bloco(g* lista, void* data);

g* t_F2_g_inserir_bloco(g** head, g* lista_a_ser_ligada);

#pragma endregion

#endif
