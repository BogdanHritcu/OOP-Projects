#include "dosar_id.h"

DosarID::DosarID()
{
	m_NotaMate = 1;
}

DosarID::~DosarID()
{

}

std::string DosarID::getFormaInvatamant()
{
	return "ID";
}

float DosarID::getNota() const
{
	return m_NotaMate;
}