#include <stdio.h>
#include <stdlib.h>

#include "IDados.h"
#include "IMaquinas.h"

// Função para criar novo bloco na lista, recebe dois argumentos: o id e o tempo de produção, que é um short.
m_t* t_m_criarNovoBloco(int machineId, short tempoDeProd) {
	m_t* blocoNovo = malloc(sizeof(m_t));
	blocoNovo->id = machineId;
	blocoNovo->tempoDeProducao = tempoDeProd;
	blocoNovo->next;
	return blocoNovo;
}

//Método para criação uma nova head na lista de máquinas
m_t* t_m_Inserir_Novo_Bloco(m_t** h, m_t* bloco_para_ser_inserido) {
	if (h == NULL || bloco_para_ser_inserido == NULL) return NULL;
	bloco_para_ser_inserido->next = *h;
	*h = bloco_para_ser_inserido;
	return bloco_para_ser_inserido;
}

m_t* t_m_removeMaquina(m_t* h, int id) {

}