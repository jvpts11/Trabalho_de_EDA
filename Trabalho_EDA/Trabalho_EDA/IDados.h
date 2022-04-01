/**
* Autor: Jo�o Tavares
* E-mail: a21871@alunos.ipca.pt
* Data:14/03/2022
* 
* Descrição: Interface que contém algumas definições de dados
*/


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

m_t* criarNovoBloco(int arg1, short arg2);
m_t* criarNovaHead(m_t** h, m_t* bloco_para_ser_inserido);
j* CriaJob(int n);
o* CriaOperacao(int job, int id);
void NovaOperacao(o** h, int no);
void RemoveOperacao(o** h, int id);
void AlteraOperacao(o** h, int id, int a, short b, int c, short d, int e, short f);
void imprimirMaquinas(m_t* head);
m_t* iniciarListaAPartirDeFicheiros();
int lerNumeroDeMaquinas();
bool gravarEmFicheiro(m_t* h);
short t_detQTD_Min_de_Tempo(m_t* h);
short t_detQTD_Max_de_Tempo(m_t* h);
short t_detQTD_Med_de_Tempo(m_t* h);

#pragma endregion