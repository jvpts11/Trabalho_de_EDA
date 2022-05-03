#include <stdio.h>
#include <stdlib.h>

#include "IDados.h"
#include "IOperacoes.h"

//Fun��o que cria uma opera��o
o* CriaOperacao(int job, int id)
{
	o* novo = malloc(sizeof(o));
	novo->job = job;
	novo->number = id;
	novo->head = NULL;
	novo->nextt = NULL;
}

//Fun��o que procura uma opera��o
o* ProcuraOperacao(o* h, int id)
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

//Fun��o que cria as opera��es com o n�mero que o utilizador quiser
void NovaOperacao(o** h, int no)
{
	o* otemp;
	for (size_t i = no; i > 0; i--)
	{
		otemp = CriaOperacao(1, i);
		otemp->nextt = *h;
		*h = otemp;
	}
}

//Fun��o que remove a opera��o que o utilizador escolher, recebe um apontador para uma opera��o e seu id
void RemoveOperacao(o** h, int id)
{
	o* aux;
	o* toRemove = ProcuraOperacao(*h, id);
	if (toRemove == *h)
	{
		o* DeptoRemove = ProcuraOperacao(*h, id + 1);
		toRemove->nextt = NULL;
		*h = DeptoRemove;
		aux = *h;
		while (aux != NULL)
		{
			aux->number = aux->number - 1;
			aux = aux->nextt;
		}
	}
	else if (toRemove->nextt == NULL)
	{
		o* AnttoRemove = ProcuraOperacao(*h, id - 1);
		AnttoRemove->nextt = NULL;
	}
	else
	{
		o* AnttoRemove = ProcuraOperacao(*h, id - 1);
		o* DeptoRemove = ProcuraOperacao(*h, id + 1);
		toRemove->nextt = NULL;
		AnttoRemove->nextt = DeptoRemove;
		aux = DeptoRemove;
		while (aux != NULL)
		{
			aux->number = aux->number - 1;
			aux = aux->nextt;
		}
	}
}

//Fun��o que altera uma opera��o
void AlteraOperacao(o** h, int id, int a, short b, int c, short d, int e, short f)
{
	o* alterar = ProcuraOperacao(*h, id);

	m* novo = criarNovoBloco(a, b);

	alterar->head = novo;
	m* novo2 = NULL;
	if (c != 0 && d != 0)
	{
		m* novo2 = criarNovoBloco(c, d);
		novo->next = novo2;
	}
	else if (e != 0 && f != 0)
	{
		novo2->next = criarNovoBloco(e, f);
	}

	*h = alterar;
}