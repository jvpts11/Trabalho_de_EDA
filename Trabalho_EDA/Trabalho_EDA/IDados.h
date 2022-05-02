/**
* Autor: Jo�o Tavares
* E-mail: a21871@alunos.ipca.pt
* Data:14/03/2022
* 
* Descrição: Interface que contém as estruturas que definem os blocos das listas
*/

#pragma once

#ifndef N 10



#pragma region Estruturas
//Struct para geração de uma lista de jobs
struct Jobs
{
	int numero;
	struct Jobs* next;
};

typedef struct Jobs j;

//Struct para geração de uma lista de Máquinas
struct Machines
{
	int id;
	short tempoDeProducao;
	struct Machines* next;
};

typedef struct Machines m_t;

//Struct para geração de uma lista de operações
struct Operations
{
	int job;
	int number;
	struct Machines* next;
	struct Operations* nextt;
};

typedef struct Operations o;


#pragma endregion

#pragma region Metodos

void imprimirMaquinas(m_t* head);
int lerNumeroDeMaquinas();
bool gravarEmFicheiro(m_t* h);

#pragma endregion

#endif