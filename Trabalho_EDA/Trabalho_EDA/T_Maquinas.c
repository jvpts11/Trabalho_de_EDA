#include <stdio.h>
#include <stdlib.h>

#include "IDados.h"
#include "IMaquinas.h"

// Função para criar novo bloco na lista, recebe dois argumentos: o id e o tempo de produção, que é um short.
m* t_m_criar_Novo_Bloco(int machineId, short tempoDeProd) {
	m* blocoNovo = malloc(sizeof(m));
	blocoNovo->id = machineId;
	blocoNovo->tempoDeProducao = tempoDeProd;
	blocoNovo->next;
	return blocoNovo;
}

//Método para criação uma nova head na lista de máquinas
m* t_m_inserir_novo_Bloco(m** h, m* maquina) {
	if (h == NULL || maquina == NULL) return NULL;
	maquina->next = *h;
	*h = maquina;
	return maquina;
}

m* t_m_procurar_Maquina(m* maquinas, int id) {
	m* aux = NULL;
	aux = maquinas;

	while (aux != NULL) {
		if (aux->id == id) {
			aux->id = id;
		}
	}
	return aux;
}

m* t_m_remove_Maquina(m* h, int id) {
	if (h == NULL) return NULL;
	m* aux = NULL;
	aux = h;
	while (aux != NULL) {

	}

}