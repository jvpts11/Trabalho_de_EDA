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
#ifndef IDADOS
#define IDADOS


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
	int opId;
	short tempoDeProducao;
	struct Machines* next;
};

typedef struct Machines m;

/**
* @brief estrutura para representação de uma operação
*/
struct Operations
{
	int number;
	struct Machines* head;
	struct Operations* nextt;
};

typedef struct Operations o;

#pragma endregion

#pragma region Metodos

bool t_m_imprimir_maquinas(m* head);
m* t_m_gerar_maquinas_a_partir_de_ficheiros_de_texto(char nome_do_arquivo[20], o* operacao);
o* t_o_gerar_operacoes_a_partir_de_ficheiros_de_texto(char nome_do_arquivo[20]);
j* t_j_gerar_jobs_a_partir_de_ficheiros_de_texto(char nome_do_arquivo[20]);
bool t_m_gravar_dados_em_ficheiro_de_texto(m* h, char nome_do_arquivo[20]);

#pragma endregion

#pragma region Maquinas

m* t_m_criar_Novo_Bloco(int machineId,short tempoDeProd);
m* t_m_inserir_novo_Bloco(m** h, m* maquina);
m* t_m_inserir_novo_bloco2(m* h, m* maquina);
m* t_m_procurar_Maquina(m* maquinas, int id);
m* t_m_remove_Maquina(m* h, int id);
bool t_m_apagar_Maquinas(m** h);

#pragma endregion

#pragma region Jobs

j* t_j_Cria_Job(int jobNumber);
j* t_j_Inserir_Novo_Job(j** head, j* job);
j* t_j_remove_Job(j* h, int jobNumber);
j* t_j_procurar_Job(j* job, int jobNumber);
j* t_o_inserir_operacao_no_job(j* lista_de_jobs, o* lista_de_operacoes);
bool t_j_apaga_Jobs(j** h);

#pragma endregion

#pragma region Operacoes

o* t_o_cria_operacao(int id);
o* t_o_procurar_Operacao(o* h, int id);
bool t_o_apaga_operacoes(o** h);
bool t_o_gerar_Operacoes();
o* t_o_inserir_nova_Operacao(o** h, o* op);
o* t_o_remover_operacao(o* h, int id);
o* t_o_inserir_maquina_na_operacao(o* operacao, int operationId, m* maquinas);
bool AlteraOperacao(o** h, int id, int a, short b, int c, short d, int e, short f);

#pragma endregion

#pragma region Funcoes

short t_f_Max_de_Tempo(m* h);
short t_f_Min_de_Tempo(m* h);
short t_f_Med_de_Tempo(m* h);

#pragma endregion

#endif // !1