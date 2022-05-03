
#include <stdlib.h>
#include <stdio.h>

#include "IDados.h"
#include "IJobs.h"

j* t_j_Cria_Job(int jobNumber,o* opHead)
{
	if (opHead == NULL) return NULL;
	j* jobNovo = malloc(sizeof(j));
	jobNovo->numero = jobNumber;
	jobNovo->operation = opHead;
	jobNovo->next;
	return jobNovo;
}

j* t_j_Inserir_Novo_Job(j** head, j* job) {
	if (head == NULL || job == NULL) return NULL;
	job->next = *head;
	*head = job;
	return job;
}