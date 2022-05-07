/**
* @file IOperacoes.h
* @author Joao_Tavares
* @date 14/03/2022
* 
* @brief .h que contém as assinaturas das funções relacionadas às operações
*/

#pragma once

#include "IDados.h"

o* CriaOperacao(int job, int id);
o* ProcuraOperacao(o* h, int id);
void NovaOperacao(o** h, int no);
void RemoveOperacao(o** h, int id);
void AlteraOperacao(o** h, int id, int a, short b, int c, short d, int e, short f);