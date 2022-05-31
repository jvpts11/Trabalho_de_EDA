/**
* @file T_F2_Dados.h
* @author Joao_Tavares
* @brief Header File que cont�m todas as Assinaturas de fun��es e estruturas
* @date May 2022
*/

#pragma once


#ifndef DATA
#define DATA

#define J 7
#define O 38
#define MAXFILENAME 40

#pragma region Estruturas

struct ListaGenerica {
	void* dados; //Campo que armazena dados gen�ticos
	struct ListaGenerica *next;
};

struct Planeamento {
	int job;
	int op;
};

typedef struct Planeamento p;
typedef struct ListaGenerica g;
#pragma endregion


#endif
