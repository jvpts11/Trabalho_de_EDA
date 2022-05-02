#include <stdio.h>
#include <stdlib.h>

#include "IDados.h"
#include "IMaquinas.h"

// Fun��o para criar novo bloco na lista, recebe dois argumentos: o id e o tempo de produ��o, que � um short.
m_t* t_m_criarNovoBloco(int machineId, short tempoDeProd) {
	m_t* blocoNovo = malloc(sizeof(m_t));
	blocoNovo->id = machineId;
	blocoNovo->tempoDeProducao = tempoDeProd;
	blocoNovo->next;
	return blocoNovo;
}

//M�todo para cria��o uma nova head na lista de m�quinas
m_t* t_m_Inserir_Novo_Bloco(m_t** h, m_t* bloco_para_ser_inserido) {
	if (h == NULL || bloco_para_ser_inserido == NULL) return NULL;
	bloco_para_ser_inserido->next = *h;
	*h = bloco_para_ser_inserido;
	return bloco_para_ser_inserido;
}

m_t* t_m_removeMaquina(m_t* h, int id) {

}