/**
* Autor: Jo�o Tavares
* E-mail: a21871@alunos.ipca.pt
* Data:14/03/2022
*/

#ifndef N

#define N 7

#pragma region Estruturas
//Struct para definir as m�quinas que constituem os jobs
struct Machines { 

	int id;
	unsigned short tempoDeProducao;
	struct Machines* next;

};

struct Operations {
	int number;
	struct Machines* next;
};

#pragma endregion
#endif // !N