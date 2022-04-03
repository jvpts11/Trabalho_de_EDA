/**
*Autor:Jo�o Tavares
*E-mail:a21871@alunos.ipca.pt
* Data:16/03/2022
* 
* Descri��o: Ficheiro que cont�m os m�todos e fun��es para manipula��o de 
* ficheiros e cria��o de listas de m�quinas
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
// Fun��o para criar novo bloco na lista, recebe dois argumentos: o id e o tempo de produ��o, que � um short.
m_t* criarNovoBloco(int machineId,short tempoDeProd) {
	m_t* blocoNovo = malloc(sizeof(m_t));
	blocoNovo->id = machineId;
	blocoNovo->tempoDeProducao = tempoDeProd;
	blocoNovo->next;
	return blocoNovo;
}

//M�todo para cria��o uma nova head na lista de m�quinas
m_t* criarNovaHead(m_t **h,m_t *bloco_para_ser_inserido) {
	if (h == NULL || bloco_para_ser_inserido == NULL) return NULL;
	bloco_para_ser_inserido->next = *h;
	*h = bloco_para_ser_inserido;
	return bloco_para_ser_inserido;
}

//M�todo para a vizualiza��o de uma lista de m�quinas
void imprimirMaquinas(m_t* head) {
	m_t* temp = head;

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

	NovaOperacao(&headop, 8);

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
m_t* iniciarListaAPartirDeFicheiros() {
	m_t* next = NULL;
	m_t* temp = NULL;

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
bool gravarEmFicheiro(m_t* h) {
	m_t* aux = h;

	dadosGravados = fopen(e,"w");
	while (aux !=NULL) {
		fprintf(dadosGravados,"%d,%d\n",aux->id,aux->tempoDeProducao);
		aux = aux->next;
	}
	fclose(dadosGravados);

	return true;
}

#pragma endregion
