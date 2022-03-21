/**
* Autor: João Tavares
* E-mail: a21871@alunos.ipca.pt
* Data:14/03/2022
*/

#ifndef N

#define N 7

#pragma region Estruturas
//Struct para definir as máquinas que constituem os jobs
typedef struct Machines { 

	int id;
	int operation_number;
	double time_of_production;
	struct Machines* next;

}Machines;

#pragma endregion
#endif // !N