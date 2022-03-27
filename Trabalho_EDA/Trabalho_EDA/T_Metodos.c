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

m_t* criarNovaHead(m_t **h,m_t *bloco_para_ser_inserido) {
	bloco_para_ser_inserido->next = *h;
	*h = bloco_para_ser_inserido;
	return bloco_para_ser_inserido;
}

#pragma endregion

#pragma region Listas_a_Partir_de_Ficheiros

void imprimirListaAPartirDeFicheiros(m_t* head) {
	m_t* temp = head;

	while (temp != NULL) {
		printf("%d-\n", temp->id);
		printf("%d-\n\n",temp->tempoDeProducao);
		temp = temp->next;
	}

	printf("\n");
}

// M�todo que inicia as listas, ele recebe
void iniciarListaAPartirDeFicheiros() {
	m_t* next = NULL;
	m_t* temp;

	int numeroDeMaquinas = lerNumeroDeMaquinas();

	for (int i = 0; i < numeroDeMaquinas; i++) {
		temp = criarNovoBloco(i,i);
		criarNovaHead(&next, temp);
	}

	imprimirListaAPartirDeFicheiros(next);
}



//Fun��o que retorna o n�mero de m�quinas em um arquivo com base no m�mero de linhas no arquivo
int lerNumeroDeMaquinas() {
	int numeroDeMaquinas = 0;
	if (dadosGravados == NULL) return NULL;
	dadosGravados = fopen(d,"r");
	while (!feof(dadosGravados)) {
		numeroDeMaquinas++;
		if (dadosGravados == EOF) {
			break;
		}
	}
	fclose(dadosGravados);
	return numeroDeMaquinas;
}

#pragma endregion

#pragma region Leitura_E_Escrita_De_Ficheiros
// M�todo para ler o ficheiro e carregar os dados na mem�ria
bool lerFicheiro(m_t*h) {
	m_t* aux = h;
	if (dadosGravados == NULL) return false;
	
	int nMaquinas = lerNumeroDeMaquinas();
	dadosGravados = fopen(d,"r");

	while (aux != NULL) {
		fscanf(dadosGravados, "%d,%d\n", aux->id, aux->tempoDeProducao);
		h = h->next;
	}
	fclose(dadosGravados);

	return true;
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
