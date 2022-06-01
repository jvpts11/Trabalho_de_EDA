/**
* @file T_Operacoes.c
* @author Joao_Tavares
*/

#include <stdio.h>
#include <stdlib.h>

#include "IDados.h"

#pragma region Manipulacao_de_Operacoes

/**
* @brief Fun��o que cria uma opera��o
* 
* @param id - id da opera��o a ser criada
* 
* @return uma opera��o
*/
o* t_o_cria_operacao(int id)
{
	o* operacao = malloc(sizeof(o));
	operacao->number = id;
	operacao->head = NULL;
	operacao->nextt = NULL;
	return operacao;
}

/**
* @brief Fun��o que procura uma opera��o em uma lista de opera��es
* 
* @param h - lista com a opera��o que dever� ser encontrada
* 
* @param id - id da opera��o a ser procurada
* 
* @return opera��o encontrada
*/
o* t_o_procurar_Operacao(o* h, int id)
{
	if (h == NULL)return NULL;
	o* found = NULL;
	o* aux = NULL;
	aux = h;
	while (aux)
	{
		if (aux->number == id)
		{
			found = aux;
		}
		aux = aux->nextt;
	}
	return found;
}

/**
* @brief M�todo que gera uma lista de opera��es automaticamente, somente usado para testes
* 
* @return true se conseguiu gerar, false se n�o conseguiu
*/
bool t_o_gerar_Operacoes() {
	bool check = false;
	o* headop = NULL;
	o* otemp;

	t_o_inserir_nova_Operacao(&headop, 7);

	o* aux = headop;
	while (aux)
	{
		printf("%d\n", aux->number);
		aux = aux->nextt;
		check = true;
	}
	return check;
}

/**
* @brief Fun��o que insere uma opera��o em uma lista existente
* 
* @param h - lista que receber� a opera��o
* 
* @param op - opera��o que ser� inserida na lista
* 
* @return lista com a opera��o inserida
*/
o* t_o_inserir_nova_Operacao(o** h, o* op)
{
	if (h == NULL || op == NULL) return NULL;
	op->nextt = *h;
	*h = op;
	return op;
}


/**
* @brief Fun��o que remove uma opera��o em uma lista de opera��es
* 
* @param h - Lista existente com a opera��o a ser removida
* 
* @param id - id da opera��o a ser removida
* 
* @return Lista sem a opera��o desejada
*/
o* t_o_remover_operacao(o* h, int id)
{
	if (h == NULL) return NULL;

	o* auxx = h->nextt;
	o* antauxx = h;
	o* depauxx = h->nextt->nextt;

	if (h->number == id) {
		o* aux = h;
		h = h->nextt;
		free(aux);
		return h;
	}
	else
	{
		while (auxx)
		{
			if (auxx->number == id)
			{
				antauxx->nextt = depauxx;
				free(auxx);
				return h;
			}
			else
			{
				antauxx = antauxx->nextt;
				auxx = auxx->nextt;
				depauxx = depauxx->nextt;
			}
		}
	}
}

/**
* @brief Fun��o que insere uma lista de m�quinas em uma opera��o
* 
* @param operacao - lista de opera��es que receber� a lista de m�quinas
* 
* @param operationId - id da opera��o que receber� a opera��o
* 
* @param maquinas - lista de m�quinas que ser� ligada com a opera��o em quest�o
* 
* @return opera��o com a lista de m�quinas inserida
*/
o* t_o_inserir_maquina_na_operacao(o* operacao,int operationId, m* maquinas) {
	o* temp = NULL;
	o* aux = NULL;

	if (operacao || maquinas == NULL) return;

	aux = operacao;

	while (aux != NULL) {
		if (aux->number == operationId) {
			temp = aux;
		}
		aux = aux->nextt;
	}
	temp->head = t_m_inserir_novo_bloco2(temp->head,maquinas);
}

/**
* @brief fun��o booleana que apaga uma lista inteira de opera��es
*/
bool t_o_apaga_operacoes(o** h) {
	
	bool check = false;
	o* aux;
	while (*h) {
		aux = *h;
		*h = (*h)->nextt;
		free(aux);
		check = true;
	}
	return check;
}

/**
* @brief Fun��o que altera uma opera��o, usada somente para testes, n�o deve ser usada
*/
bool AlteraOperacao(o** h, int id, int a, short b, int c, short d, int e, short f)
{
	bool check = false;

	o* alterar = t_o_procurar_Operacao(h, id);

	m* novo = t_m_criar_Novo_Bloco(a, b);

	alterar->head = novo;
	m* novo2 = NULL;
	if (c != 0 && d != 0)
	{
		m* novo2 = t_m_criar_Novo_Bloco(c, d);
		novo->next = novo2;
		check = true;
	}
	else if (e != 0 && f != 0)
	{
		novo2->next = t_m_criar_Novo_Bloco(e, f);
		check = true;
	}

	*h = alterar;
	return check;
}

#pragma endregion