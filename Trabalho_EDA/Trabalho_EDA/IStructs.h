/**
* Autor: João Tavares
* E-mail: a21871@alunos.ipca.pt
* Data:14/03/2022
*/

#ifndef N

#define N 40

#pragma region Estruturas
//Struct para definir os jobs
typedef struct Jobs { 

	char id[N];
	int operations[N];
	struct Jobs* next;

}Jobs;

#pragma endregion
#endif // !N