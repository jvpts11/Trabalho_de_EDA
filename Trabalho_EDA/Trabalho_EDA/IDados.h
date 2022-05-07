/**
* @file IDados.h
* @author Joao_Tavares
* @date 14/03/2022
* 
* @brief .h que contém as estruturas que definem os blocos das listas
*/

#pragma once
#include <stdbool.h>

#define L 40

#pragma region Estruturas
/**
* @brief estrutura para representação de um job
*/
struct Jobs
{
	int numero;
	struct Jobs* next;
	struct Jobs* operation;
};

typedef struct Jobs j;

/**
* @brief estrutura para representação de uma máquina
*/
struct Machines
{
	int id;
	short tempoDeProducao;
	struct Machines* next;
};

typedef struct Machines m;

/**
* @brief estrutura para representação de uma operação
*/
struct Operations
{
	int job;
	int number;
	struct Machines* head;
	struct Operations* nextt;
};

typedef struct Operations o;

typedef struct Dados {
	void* data;
	struct Dados* next;
}Dados;


#pragma endregion

#pragma region Metodos

void t_m_imprimir_maquinas(m* head);
m* t_m_gerar_listas_a_partir_de_ficheiros_de_texto(char nome_do_arquivo[20]);
bool t_m_gravar_dados_em_ficheiro_de_texto(m* h, char nome_do_arquivo[20]);

#pragma endregion