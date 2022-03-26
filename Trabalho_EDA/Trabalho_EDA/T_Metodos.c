/**
*Autor:Jo�o Tavares
*E-mail:a21871@alunos.ipca.pt
* Data:16/03/2022
* 
* Descri��o: Ficheiro que cont�m os m�todos e fun��es para manipula��o de ficheiros
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>

#include "IDados.h"

FILE* dadosGravados;
const char d[30] = "Dados_Gravados.txt";
int a, b; //Vari�veis para receberem dados carregados dos ficheiros

// Fun��o para criar novo bloco na lista, recebe dois argumentos: o id e o tempo de produ��o, que � um short.
m_t* criarNovoBloco(int arg1,short arg2) {
	m_t* blocoNovo = malloc(sizeof(m_t));
	blocoNovo->id = arg1;
	blocoNovo->tempoDeProducao = arg2;
	blocoNovo->next;
	return blocoNovo;
}

m_t* criarNovaHead(m_t **h,m_t *bloco_para_ser_inserido) {
	bloco_para_ser_inserido->next = *h;
	*h = bloco_para_ser_inserido;
	return bloco_para_ser_inserido;
}

void imprimirLista(m_t* head) {
	m_t* temp = head;

	while (temp != NULL) {
		printf("%d-\n", temp->id);
		printf("%d-\n\n",temp->tempoDeProducao);
		temp = temp->next;
	}

	printf("\n");
}

void iniciarLista() {
	m_t* next = NULL;
	m_t* temp;

	for (int i = 0; i < 25; i++) {
		temp = criarNovoBloco(i,i);
		criarNovaHead(&next, temp);
	}

	imprimirLista(next);
}

// M�todo para ler o ficheiro e carregar os dados na mem�ria
void lerFicheiro() {
	dadosGravados = fopen(d,"r");
	fscanf(dadosGravados,"%d,%d",&a,&b); //Exemplo de como devem ser carregados os dados na mem�ria
	fclose(dadosGravados);
}

// M�todo para receber os dados das listas e gravar os dados em um ficheiro de texto
void gravarEmFicheiro() {
	dadosGravados = fopen(d,"w");
	fprintf(dadosGravados,"%d,%d");
	fclose(dadosGravados);
}

