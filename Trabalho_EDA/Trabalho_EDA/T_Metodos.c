/**
*Autor:João Tavares
*E-mail:a21871@alunos.ipca.pt
* Data:16/03/2022
* 
* Descrição: Ficheiro que contém os métodos e funções para manipulação de 
* ficheiros e criação de listas de máquinas
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
// Função para criar novo bloco na lista, recebe dois argumentos: o id e o tempo de produção, que é um short.
m_t* criarNovoBloco(int machineId,short tempoDeProd) {
	m_t* blocoNovo = malloc(sizeof(m_t));
	blocoNovo->id = machineId;
	blocoNovo->tempoDeProducao = tempoDeProd;
	blocoNovo->next;
	return blocoNovo;
}

//Método para criação uma nova head na lista de máquinas
m_t* criarNovaHead(m_t **h,m_t *bloco_para_ser_inserido) {
	if (h == NULL || bloco_para_ser_inserido == NULL) return NULL;
	bloco_para_ser_inserido->next = *h;
	*h = bloco_para_ser_inserido;
	return bloco_para_ser_inserido;
}

//Método para a vizualização de uma lista de máquinas
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
// Método que inicia as listas, ele abre o ficheiro, em seguida recebe um inteiro de uma função, por fim retorna uma lista
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
