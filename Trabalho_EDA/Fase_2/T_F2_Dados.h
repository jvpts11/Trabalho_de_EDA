/**
* @file T_F2_Dados.h
* @author Joao_Tavares
* @brief Header File que cont�m todas as Assinaturas de fun��es e estruturas
* @date May 2022
*/

#pragma once


#ifndef DATA


#pragma region Estruturas

typedef struct ListaGenerica {
	void* dados;
	struct ListaGenerica *next;
}g;

#pragma endregion


#pragma region Metodos

g* t_F2_Insere_No_Inicio(g* inicio, void* dados);

#pragma endregion

#endif
