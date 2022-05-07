/**
* @file IMaquinas.h
* @author Joao_Tavares
* @date 14/03/2022
*
* @brief .h que contém as assinaturas das funções relacionadas às máquinas
*/

#pragma once

#include "IDados.h"

m* t_m_criar_Novo_Bloco(int arg1, short arg2);
m* t_m_inserir_novo_Bloco(m** h, m* bloco_para_ser_inserido);
m* t_m_remove_Maquina(m* h, int id);
m* t_m_procurar_Maquina(m* maquinas, int id);
void t_m_apagar_Maquinas(m** h);