#include "medie_admitere.h"

MedieAdmitere::MedieAdmitere()
{
	m_Dosar = nullptr;
	m_ProbaConcurs = nullptr;
}

MedieAdmitere::~MedieAdmitere()
{

}

float MedieAdmitere::getNota() const
{
	if (m_Dosar->getFormaInvatamant() == "IF")
	{
		return 0.8f * m_ProbaConcurs->getNota() + 0.2f * m_Dosar->getNota();
	}
	else
	{
		return 0.6f * m_ProbaConcurs->getNota() + 0.4f * m_Dosar->getNota();
	}
}