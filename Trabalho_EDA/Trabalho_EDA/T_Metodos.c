/**
*Autor:João Tavares
*E-mail:a21871@alunos.ipca.pt
* Data:16/03/2022
* 
* Descrição: Ficheiro que contém os métodos e funções para manipulação de ficheiros
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>

#include "IStructs.h"

FILE* dadosGravados;
const char d[30] = "Dados_Gravados.txt";
int a, b; //Variáveis para receberem dados carregados dos ficheiros

typedef struct Machines m_t;

// Função para criar novo bloco na lista, recebe dois argumentos: o id e o tempo de produção, que é um short.
m_t* criarNovoBloco(int arg1,short arg2) {
	m_t* blocoNovo = malloc(sizeof(m_t));
	blocoNovo->id = arg1;
	blocoNovo->tempoDeProducao = arg2;
	blocoNovo->next;
	return blocoNovo;
}

m_t* criarNovaHead(m_t **h) {

}

// Método para ler o ficheiro e carregar os dados na memória
void lerFicheiro() {
	dadosGravados = fopen(d,"r");
	fscanf(dadosGravados,"%d,%d",&a,&b); //Exemplo de como devem ser carregados os dados na memória
	fclose(dadosGravados);
}

// Método para receber os dados das listas e gravar os dados em um ficheiro de texto
void gravarEmFicheiro() {
	dadosGravados = fopen(d,"w");
	fprintf(dadosGravados,"%d,%d");
	fclose(dadosGravados);
}

