/**
* Autor: João Tavares
* E-mail: a21871@alunos.ipca.pt
* Data:14/03/2022
*/


#pragma region Estruturas
//Struct para definir as máquinas que constituem os jobs
typedef struct Jobs
{
	int numero;
	struct job* next;
}job;



typedef struct Machines 
{ 
	operation* num;

	int id;
	short tempoDeProducao;
	struct Machines* next;

}m_t;

typedef struct Operations 
{
	int job;
	int number;
	struct Machines* next;
	struct Operations* next;
}operation;


#pragma endregion

#pragma region Metodos

m_t* criarNovoBloco(int arg1, short arg2);
m_t* criarNovaHead(m_t** h, m_t* bloco_para_ser_inserido);
job* CriaJob(int n);


#pragma endregion