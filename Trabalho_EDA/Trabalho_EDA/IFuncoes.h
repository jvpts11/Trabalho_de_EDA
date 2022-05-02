#pragma once

#include "IDados.h"

#ifndef N

j* CriaJob(int n);
o* CriaOperacao(int job, int id);
o* ProcuraOperacao(o* h, int id);
void NovaOperacao(o** h, int no);
void RemoveOperacao(o** h, int id);
void AlteraOperacao(o** h, int id, int a, short b, int c, short d, int e, short f);
short t_detQTD_Max_de_Tempo(m_t* h);
short t_detQTD_Min_de_Tempo(m_t* h);
short t_detQTD_Med_de_Tempo(m_t* h);
	

#endif