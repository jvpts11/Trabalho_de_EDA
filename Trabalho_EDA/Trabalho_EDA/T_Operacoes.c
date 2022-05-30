/**
* @file T_Operacoes.c
* @author Joao_Tavares
*/

#include <stdio.h>
#include <stdlib.h>

#include "IDados.h"

//Fun��o que cria uma opera��o
o* t_o_cria_operacao(int id)
{
	o* operacao = malloc(sizeof(o));
	operacao->number = id;
	operacao->head = NULL;
	operacao->nextt;
	return operacao;
}

//Fun��o que procura uma opera��o
o* t_o_procurar_Operacao(o* h, int id)
{
	if (h == NULL)return NULL;
	o* found = NULL;
	o* aux = h;
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

void t_o_gerar_Operacoes() {
	o* headop = NULL;
	o* otemp;

	t_o_inserir_nova_Operacao(&headop, 7);

	o* aux = headop;
	while (aux)
	{
		printf("%d\n", aux->number);
		aux = aux->nextt;
	}
}

//Fun��o que cria as opera��es com o n�mero que o utilizador quiser
o* t_o_inserir_nova_Operacao(o** h, o* op)
{
	if (h == NULL || op == NULL) return NULL;
	op->nextt = *h;
	*h = op;
	return op;
}

//Fun��o que remove a opera��o que o utilizador escolher, recebe um apontador para uma opera��o e seu id
o* t_o_remover_operacao(o* h, int id)
{
	if (h == NULL) return NULL;

	if (h->number == id) {
		o* aux = h;
		h = h->nextt;
		free(aux);
	}

	return h;
}

void t_o_apaga_operacoes(o** h) {
	o* aux;
	while (*h) {
		aux = *h;
		*h = (*h)->nextt;
		free(aux);
	}
}

//Fun��o que altera uma opera��o
void AlteraOperacao(o** h, int id, int a, short b, int c, short d, int e, short f)
{
	o* alterar = t_o_procurar_Operacao( h, id);

	m* novo = t_m_criar_Novo_Bloco(a, b);

	alterar->head = novo;
	m* novo2 = NULL;
	if (c != 0 && d != 0)
	{
		m* novo2 = t_m_criar_Novo_Bloco(c, d);
		novo->next = novo2;
	}
	else if (e != 0 && f != 0)
	{
		novo2->next = t_m_criar_Novo_Bloco(e, f);
	}

	*h = alterar;
}