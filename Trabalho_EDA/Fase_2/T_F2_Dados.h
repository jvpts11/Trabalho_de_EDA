/**
* @file T_F2_Dados.h
* @author Joao_Tavares
* @brief Header File que cont�m todas as Assinaturas de fun��es e estruturas
* @date May 2022
*/

#pragma once


#ifndef DATA
#define DATA

#pragma region Estruturas

struct ListaGenerica {
	void* dados; //Campo que armazena dados gen�ticos
	struct ListaGenerica *next;
};

typedef struct ListaGenerica g;
#pragma endregion


#endif
