/**
*Autor:João Tavares
*E-mail:a21871@alunos.ipca.pt
* Data:16/03/2022
* 
* Descrição: Ficheiro que contém métodos e funções diversos (que não necessariamente alteram as listas)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>

#include "IDados.h"

FILE* dadosGravados; //Apontador do ficheiro
const char d[30] = "Dados_Gravados.txt"; //Arquivo de texto de origem para carregamento da lista
const char e[30] = "Dados_Gravados2.txt"; //Arquivo de texto de chegada para gravação da lista

#pragma region Manipulacao_de_Listas

//Método para a vizualização de uma lista de máquinas
void imprimirMaquinas(m* head) {
	m* temp = head;

	while (temp != NULL) {
		printf("%d-\n", temp->id);
		printf("%d-\n\n",temp->tempoDeProducao);
		temp = temp->next;
	}

	printf("\n");
}

void gerarOperacoes() {
	o* headop = NULL;
	o* otemp;

	NovaOperacao(&headop, 7);

	o* aux = headop;
	while (aux)
	{
		printf("%d\n", aux->number);
		aux = aux->nextt;
	}
}

#pragma endregion

#pragma region Manipulacao_de_Ficheiros
// Método que inicia as listas, ele abre o ficheiro, em seguida recebe um inteiro de uma função, por fim retorna uma lista
m* iniciarListaAPartirDeFicheiros() {
	m* next = NULL;
	m* temp = NULL;

	dadosGravados = fopen("Dados_Gravados.txt", "r");
	int id = 0;
	short tempoDeProd = 0;

	while (fscanf(dadosGravados, "%d,%hi\n", &id, &tempoDeProd) != EOF) {
		temp = criarNovoBloco(id, tempoDeProd);
		criarNovaHead(&next, temp);
	}

	fclose(dadosGravados);

	return temp;
}

//Função que retorna o número de máquinas em um arquivo com base no múmero de linhas no arquivo
int lerNumeroDeMaquinas() {
	int numeroDeMaquinas = 0;
	int ch = 0;

	dadosGravados = fopen(d, "r");

	do {
		ch = fgetc(dadosGravados);
		if (ch == '\n')
			numeroDeMaquinas++;
	} while (ch != EOF);

	fclose(dadosGravados);

	return numeroDeMaquinas;
}

// Método para receber os dados das listas e gravar os dados em um ficheiro de texto
bool gravarEmFicheiro(m* h) {
	m* aux = h;

	dadosGravados = fopen(e,"w");
	while (aux !=NULL) {
		fprintf(dadosGravados,"%d,%d\n",aux->id,aux->tempoDeProducao);
		aux = aux->next;
	}
	fclose(dadosGravados);

	return true;
}

#pragma endregion
