/**
*Autor:Jo�o Tavares
*E-mail:a21871@alunos.ipca.pt
* Data:16/03/2022
* 
* Descri��o: Ficheiro que cont�m os m�todos e fun��es para manipula��o de ficheiros
*/

#include <stdio.h>
#include <stdlib.h>

FILE* dadosGravados;
const char d[30] = "Dados_Gravados.txt";
int a, b; //Vari�veis para receberem dados carregados dos ficheiros

void lerFicheiro() {
	dadosGravados = fopen(d,"r");
	fscanf(dadosGravados,"%d,%d",&a,&b); //Exemplo de como devem ser carregados os dados na mem�ria
	fclose(dadosGravados);
}

void gravarEmFicheiro() {

}

void carregarNaMemoria() {
	dadosGravados = fopen(d,"r");
	fclose(dadosGravados);
}