#include "program_invatamant.h"

ProgramInvatamant::ProgramInvatamant(unsigned int locuri_libere)
{
	m_LocuriLibere = locuri_libere;
}
/*
std::vector<Dosar*>& ProgramInvatamant::getDosare()
{
	return m_Dosare;
}
*/
unsigned int ProgramInvatamant::getNumarLocuri()
{
	return m_LocuriLibere;
}