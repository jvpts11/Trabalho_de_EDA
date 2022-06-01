/**
* @file T_Operacoes.c
* @author Joao_Tavares
*/

#include <stdio.h>
#include <stdlib.h>

#include "IDados.h"

//Função que cria uma operação
o* t_o_cria_operacao(int id)
{
	o* operacao = malloc(sizeof(o));
	operacao->number = id;
	operacao->head = NULL;
	operacao->nextt = NULL;
	return operacao;
}

//Função que procura uma operação
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

//Função que cria as operações com o número que o utilizador quiser
o* t_o_inserir_nova_Operacao(o** h, o* op)
{
	if (h == NULL || op == NULL) return NULL;
	op->nextt = *h;
	*h = op;
	return op;
}

//Função que remove a operação que o utilizador escolher, recebe um apontador para uma operação e seu id
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

o* t_o_inserir_maquina_na_operacao(o* operacao,int operationId, m* maquinas) {
	o* temp = NULL;
	o* aux = NULL;

	aux = operacao;

	while (aux != NULL) {
		if (aux->number == operationId) {
			temp = aux;
		}
		aux = aux->nextt;
	}
	temp->head = t_m_inserir_novo_bloco2(temp->head,maquinas);
}

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

//Função que altera uma operação
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