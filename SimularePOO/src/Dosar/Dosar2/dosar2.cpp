#include "dosar2.h"

Dosar2::Dosar2(std::string forma_invatamant)
{
	m_NotaFacultate = 1;
	m_FormaInvatamant = forma_invatamant;
}

Dosar2::~Dosar2()
{

}

std::string Dosar2::getFormaInvatamant()
{
	return (m_FormaInvatamant + "2");
}

float Dosar2::getNota() const
{
	return m_NotaFacultate;
}