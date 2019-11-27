#include "sala_conf.h"

namespace oop
{
	SalaConf::SalaConf(int locuri) : Incapere(locuri)
	{
		m_Proiector = false;
		m_Tip = TipIncapere::sala_conferinta;
	}

	SalaConf::~SalaConf()
	{

	}

	bool SalaConf::getProiector() const
	{
		return m_Proiector;
	}

	void SalaConf::setProiector(bool valoare)
	{
		m_Proiector = valoare;
	}

	void SalaConf::afiseaza() const
	{
		Incapere::afiseaza();
		std::cout << "Proiector: ";
		if (m_Proiector)
		{
			std::cout << "DA" << std::endl;
		}
		else
		{
			std::cout << "NU" << std::endl;
		}
	}
}