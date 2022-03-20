/**
*Autor:João Tavares
*E-mail:a21871@alunos.ipca.pt
* Data:16/03/2022
* 
* Descrição: Ficheiro que contém os métodos e funções para manipulação de ficheiros
*/

#include <stdio.h>
#include <stdlib.h>

FILE* dadosGravados;
const char d[30] = "Dados_Gravados.txt";
int a, b; //Variáveis para receberem dados carregados dos ficheiros

void lerFicheiro() {
	dadosGravados = fopen(d,"r");
	fscanf(dadosGravados,"%d,%d",&a,&b); //Exemplo de como devem ser carregados os dados na memória
	fclose(dadosGravados);
}

void gravarEmFicheiro() {

}

void carregarNaMemoria() {
	dadosGravados = fopen(d,"r");
	fclose(dadosGravados);
}