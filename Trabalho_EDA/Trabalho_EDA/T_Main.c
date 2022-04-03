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
	bool gravouLista; //Verificar e realizar a gravação de uma lista
	short media; // Variável para receber a média
	m_t* l = iniciarListaAPartirDeFicheiros(); // Inicialização da lista a partir de um ficheiro de texto
	imprimirMaquinas(l); // Vizualização da lista
	media = t_detQTD_Med_de_Tempo(l); //determinar a quantidade média do tempo
	printf("%d - media",media); // Vizualização da média do tempo
	gravouLista = gravarEmFicheiro(l); // Realizar a gravação em ficheiro
	if (gravouLista == true) {
		printf("Lista gravada com sucesso");
	}
	else {
		printf("Não foi possível gravar a lista");
	}
}