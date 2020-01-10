#include "dosar_if.h"

DosarIF::DosarIF()
{
	m_MedieBac = 1;
}

DosarIF::~DosarIF()
{
	
}

std::string DosarIF::getFormaInvatamant()
{
	return "IF";
}

float DosarIF::getNota() const
{
	return m_MedieBac;
}