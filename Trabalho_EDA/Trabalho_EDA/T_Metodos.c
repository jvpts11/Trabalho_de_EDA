/**
*Autor:Jo�o Tavares
*E-mail:a21871@alunos.ipca.pt
* Data:16/03/2022
* 
* Descri��o: Ficheiro que cont�m os m�todos e fun��es para manipula��o de ficheiros e cria��o de listas de m�quinas
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>

#include "IDados.h"

FILE* dadosGravados;
const char d[30] = "Dados_Gravados.txt";
int a = 10, b = 20; //Vari�veis para testar leitura e escrita de ficheiros

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
	bloco_para_ser_inserido->next = *h;
	*h = bloco_para_ser_inserido;
	return bloco_para_ser_inserido;
}

//M�todo para a vizualiza��o de uma lista de m�quinas
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
// M�todo que inicia as listas, ele abre o ficheiro, em seguida recebe um inteiro de uma fun��o, por fim retorna uma lista
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
