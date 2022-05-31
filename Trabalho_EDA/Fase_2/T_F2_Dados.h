/**
* @file T_F2_Dados.h
* @author Joao_Tavares
* @brief Header File que contém todas as Assinaturas de funções e estruturas
* @date May 2022
*/

#pragma once


#ifndef DATA
#define DATA
#define HASHMAX 7 //tamanho máximo da hash table

#pragma region Estruturas

struct ListaGenerica {
	void* dados; //Campo que armazena dados genéticos
	struct ListaGenerica *next;
};

typedef struct ListaGenerica g;
#pragma endregion

#pragma region Hash

typedef struct Hash {

}Hash;



#pragma endregion

#endif
