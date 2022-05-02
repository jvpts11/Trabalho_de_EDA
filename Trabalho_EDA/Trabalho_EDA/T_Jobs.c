
#include <stdlib.h>
#include <stdio.h>

#include "IDados.h"
#include "IJobs.h"

j* t_j_Cria_Job(int n)
{
	j* novo = malloc(sizeof(j));
	novo->numero = n;
	novo->next = NULL;
	return novo;
}