#include "incapere.h"

namespace oop
{
	unsigned long long Incapere::s_IDCurent = 0;

	Incapere::Incapere(int locuri)
	{
		m_ID = s_IDCurent;
		s_IDCurent++;

		m_NumarLocuri = locuri;

		int i;

		for (i = 0; i < 365; i++)
		{
			m_Disponibila[i] = true;
		}
	}

	Incapere::~Incapere()
	{

	}

	int Incapere::getNumarLocuri() const
	{
		return m_NumarLocuri;
	}

	TipIncapere Incapere::getTip() const
	{
		return m_Tip;
	}

	unsigned long long Incapere::getID() const
	{
		return m_ID;
	}

	bool Incapere::disponibila(int zi) const
	{
		return m_Disponibila[zi];
	}

	void Incapere::setDisponibila(int zi, bool valoare)
	{
		m_Disponibila[zi] = valoare;
	}

	void Incapere::afiseaza() const
	{
		std::cout << "Numar: " << m_ID << std::endl;
		std::cout << "Capacitate: " << m_NumarLocuri << std::endl;
	}
}