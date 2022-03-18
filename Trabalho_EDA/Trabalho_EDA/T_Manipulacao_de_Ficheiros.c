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

void lerFicheiro() {

}

void gravarEmFicheiro() {

}

void carregarNaMemoria() {
	dadosGravados = fopen(d,"r");
	fclose(dadosGravados);
}