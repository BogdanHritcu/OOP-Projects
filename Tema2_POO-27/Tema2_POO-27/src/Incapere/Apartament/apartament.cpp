#include "apartament.h"

namespace oop
{
	Apartament::Apartament(int locuri) : Incapere(locuri)
	{
		m_Tip = TipIncapere::apartament;
	}

	Apartament::~Apartament()
	{

	}

	void Apartament::afiseaza() const
	{
		std::cout << "Apartament" << std::endl;
		Incapere::afiseaza();
	}
}