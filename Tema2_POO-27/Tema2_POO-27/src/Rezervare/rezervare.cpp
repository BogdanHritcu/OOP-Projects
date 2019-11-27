#include "rezervare.h"

namespace oop
{
	Rezervare::Rezervare()
	{
		m_ZiCazare = -1;
		m_DurataSedere = -1;
		m_Grup = nullptr;
		m_SalaConf = nullptr;
	}

	Rezervare::Rezervare(int zi_cazare, int durata_sedere)
	{
		m_ZiCazare = zi_cazare;
		m_DurataSedere = durata_sedere;

		m_Grup = nullptr;
		m_SalaConf = nullptr;
	}

	Rezervare::~Rezervare()
	{
		//decazeaza toti participantii din grupul rezervarii
		//elibereaza toate camerele
	}

	int Rezervare::getZiCazare() const
	{
		return m_ZiCazare;
	}

	int Rezervare::getZiDecazare() const
	{
		return m_ZiCazare + m_DurataSedere - 1;
	}

	int Rezervare::getDurataSedere() const
	{
		return m_DurataSedere;
	}

	Grup* Rezervare::getGrup() const
	{
		return m_Grup;
	}

	Incapere* Rezervare::getSalaConf() const
	{
		return m_SalaConf;
	}

	void Rezervare::setGrup(const Grup* grup)
	{
		m_Grup = const_cast<Grup*>(grup);
	}

	void Rezervare::setZiCazare(int zi)
	{
		m_ZiCazare = zi;
	}

	void Rezervare::setDurataSedere(int nr_zile)
	{
		m_DurataSedere = nr_zile;
	}

	void Rezervare::setSalaConf(const Incapere* sala)
	{
		m_SalaConf = const_cast<Incapere*>(sala);
	}

	void Rezervare::afiseaza(bool afisare_grup) const
	{
		int i;
		int nr_participanti = m_Grup->getNrParticipanti();

		std::cout << "REZERVARE GRUP " << m_Grup->getID() << ":" << std::endl;
		std::cout << "Zi cazare: " << m_ZiCazare << std::endl;
		std::cout << "Zi decazare: " << m_ZiCazare + m_DurataSedere - 1 << std::endl;
		std::cout << "Sala de conferinta: ";
		if (m_SalaConf)
		{
			std::cout << m_SalaConf->getID() << std::endl;
		}
		else
		{
			std::cout << "Nu a fost rezervata." << std::endl;
		}

		if (afisare_grup)
		{
			m_Grup->afisare();
		}
	}
}