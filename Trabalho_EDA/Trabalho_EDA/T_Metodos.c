/**
*Autor:João Tavares
*E-mail:a21871@alunos.ipca.pt
* Data:16/03/2022
* 
* Descrição: Ficheiro que contém os métodos e funções para manipulação de ficheiros e criação de listas de máquinas
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>

#include "IDados.h"

FILE* dadosGravados;
const char d[30] = "Dados_Gravados.txt";
int a = 10, b = 20; //Variáveis para testar leitura e escrita de ficheiros

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
	bloco_para_ser_inserido->next = *h;
	*h = bloco_para_ser_inserido;
	return bloco_para_ser_inserido;
}

//Método para a vizualização de uma lista de máquinas
void imprimirLista(m_t* head) {
	m_t* temp = head;

	while (temp != NULL) {
		printf("%d-\n", temp->id);
		printf("%d-\n\n",temp->tempoDeProducao);
		temp = temp->next;
	}

	printf("\n");
}

#pragma endregion

#pragma region Manipulacao_de_Ficheiros
// Método que inicia as listas, ele abre o ficheiro, em seguida recebe um inteiro de uma função, por fim retorna uma lista
m_t* iniciarListaAPartirDeFicheiros() {
	m_t* next = NULL;
	m_t* temp = NULL;

	dadosGravados = fopen(d, "r");
	int id = 0;
	short tempoDeProd = 0;

	int numeroDeMaquinas = lerNumeroDeMaquinas();

	for (int i = 0; i < numeroDeMaquinas; i++) {
		fscanf(dadosGravados, "%d,%d", &id,&tempoDeProd);
		temp = criarNovoBloco(i,i);
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

	if (h == NULL) return false;

	dadosGravados = fopen(d,"w");
	while (aux !=NULL) {
		fprintf(dadosGravados,"%d,%d",aux->id,aux->tempoDeProducao);
		h = h->next;
	}
	fclose(dadosGravados);

	return true;
}

#pragma endregion
