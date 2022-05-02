#pragma once

#include "IDados.h"

o* CriaOperacao(int job, int id);
o* ProcuraOperacao(o* h, int id);
void NovaOperacao(o** h, int no);
void RemoveOperacao(o** h, int id);
void AlteraOperacao(o** h, int id, int a, short b, int c, short d, int e, short f);