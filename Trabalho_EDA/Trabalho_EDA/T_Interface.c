/**
* Autor: Jo�o Tavares
* E-mail: a21871@alunos.ipca.pt
* Data:14/03/2022
* 
* Descri��o: Todos os menus de vizualiza��o est�o contidos aqui
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <memory.h>

bool leuOFicheiro;

void menu1() {
	int selecao;

	printf("Selecione uma a��o:\n");

	printf("1 - Carregar Maquinas de um ficheiro\n2 - Listar jobs na mem�ria\n3 - Gravar dados\n4 - Gerar um job inserindo maquinas\n5 - Sair");
	scanf("%d",&selecao);

	switch (selecao) {
	case1:
		selecao = 0;
		system("clear");
		break;
	case2:
		selecao = 0;
		system("clear");
		break;
	case 3:
		selecao = 0;
		system("clear");
		break;
	case 4:
		selecao = 0;
		system("clear");
		break;
	case 5:
		selecao = 0;
		break;
	default:
		menu1();
		free(selecao);
		break;
	}
}