/**
*Autor:Jo�o Tavares
*E-mail:a21871@alunos.ipca.pt
* Data:16/03/2022
* 
* Descri��o: Ficheiro que cont�m m�todos e fun��es diversos (que n�o necessariamente alteram as listas)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>

#include "IDados.h"

FILE* dadosGravados; //Apontador do ficheiro
const char d[30] = "Dados_Gravados.txt"; //Arquivo de texto de origem para carregamento da lista
const char e[30] = "Dados_Gravados2.txt"; //Arquivo de texto de chegada para grava��o da lista

#pragma region Manipulacao_de_Listas

//M�todo para a vizualiza��o de uma lista de m�quinas
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
// M�todo que inicia as listas, ele abre o ficheiro, em seguida recebe um inteiro de uma fun��o, por fim retorna uma lista
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

//Fun��o que retorna o n�mero de m�quinas em um arquivo com base no m�mero de linhas no arquivo
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

// M�todo para receber os dados das listas e gravar os dados em um ficheiro de texto
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
