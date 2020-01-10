#pragma once

#include <vector>

#include "../Dosar/dosar.h"

class ProgramInvatamant
{
protected:
	unsigned int m_LocuriLibere;
	//std::vector<Dosar*> m_Dosare;
	
public:
	ProgramInvatamant(unsigned int locuri_libere);

	//std::vector<Dosar*>& getDosare();
	unsigned int getNumarLocuri();
	//virtual void addDosar(Dosar*& dosar) = 0;
};