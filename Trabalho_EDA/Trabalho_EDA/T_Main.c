/**
* Autor: Jo�o Tavares
* E-mail: a21871@alunos.ipca.pt
* Data:14/03/2022
*
*Descrição: Ficheiro que invoca todos os métodos dos outros
*/

//Bibliotecas nativas de C
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "IDados.h"

//M�todo main, alterado para dar mais legibilidade, contém um menu para teste e utilização do programa
int main()
{
	bool gravouLista;
	short media;
	m_t* l = iniciarListaAPartirDeFicheiros();
	imprimirMaquinas(l);
	media = t_detQTD_Med_de_Tempo(l);
	printf("%d - media",media);
}