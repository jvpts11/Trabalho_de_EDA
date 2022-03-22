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

#include "IStructs.h"

FILE* dadosGravados;
const char d[30] = "Dados_Gravados.txt";
int a, b; //Vari�veis para receberem dados carregados dos ficheiros

typedef struct Maquinas m_t;

m_t* criarNovoBloco(int a) {

}

void lerFicheiro() {
	dadosGravados = fopen(d,"r");
	fscanf(dadosGravados,"%d,%d",&a,&b); //Exemplo de como devem ser carregados os dados na mem�ria
	fclose(dadosGravados);
}

void gravarEmFicheiro() {
	dadosGravados = fopen(d,"w");
	fprintf(dadosGravados,"%d,%d");
	fclose(dadosGravados);
}

void carregarNaMemoria() {
	dadosGravados = fopen(d,"r");
	fclose(dadosGravados);
}