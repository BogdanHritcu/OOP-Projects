#include "sala_scena.h"

namespace oop
{
	SalaScena::SalaScena(int locuri) : SalaConf(locuri)
	{
		m_Tip = TipIncapere::sala_scena;
	}

	SalaScena::~SalaScena()
	{

	}

	void SalaScena::afiseaza() const
	{
		std::cout << "Sala tip scena" << std::endl;
		SalaConf::afiseaza();
	}
}