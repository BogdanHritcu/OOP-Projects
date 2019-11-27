#include "sala_indiv.h"

namespace oop
{
	SalaIndiv::SalaIndiv(int locuri, int mese, int locuri_masa) : SalaConf(locuri)
	{
		m_Tip = TipIncapere::sala_individuala;
		m_NrMese = mese;
		m_LocuriMasa = locuri_masa;
	}

	SalaIndiv::~SalaIndiv()
	{
		
	}

	int SalaIndiv::getNrMese() const
	{
		return m_NrMese;
	}

	int SalaIndiv::getLocuriMasa() const
	{
		return m_LocuriMasa;
	}

	void SalaIndiv::afiseaza() const
	{
		std::cout << "Sala cu mese individuale" << std::endl;
		SalaConf::afiseaza();
	}
}