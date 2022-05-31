/**
* @file T_F2_Dados.h
* @author Joao_Tavares
* @brief Header File que contém todas as Assinaturas de funções e estruturas
* @date May 2022
*/

#pragma once


#ifndef DATA
#define DATA

#pragma region Estruturas

struct ListaGenerica {
	void* dados; //Campo que armazena dados genéticos
	struct ListaGenerica *next;
};

typedef struct ListaGenerica g;
#pragma endregion


#endif
