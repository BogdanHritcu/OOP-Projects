#include "grup.h"

namespace oop
{
	unsigned long long Grup::s_IDCurent = 0;

	Grup::Grup()
	{
		m_ID = s_IDCurent;
		s_IDCurent++;
		m_NrParticipanti = 0;
		m_DurataSedere = 0;
		m_Participanti = nullptr;
	}

	Grup::Grup(const Grup& grup)
	{
		m_ID = s_IDCurent;
		s_IDCurent++;
		m_DurataSedere = grup.m_DurataSedere;
		m_Participanti = new Participant[grup.m_NrParticipanti];
		m_NrParticipanti = grup.m_NrParticipanti;
		memcpy(m_Participanti, grup.m_Participanti, m_NrParticipanti * sizeof(Participant));
	}

	Grup& Grup::operator=(const Grup& grup)
	{
		m_ID = grup.m_ID;
		delete[] m_Participanti;
		m_DurataSedere = grup.m_DurataSedere;
		m_Participanti = new Participant[grup.m_NrParticipanti];
		m_NrParticipanti = grup.m_NrParticipanti;
		memcpy(m_Participanti, grup.m_Participanti, m_NrParticipanti * sizeof(Participant));
	
		return *this;
	}

	Grup::~Grup()
	{
		delete[] m_Participanti;
	}

	Participant* Grup::getParticipanti() const
	{
		return m_Participanti;
	}

	int Grup::getNrParticipanti() const
	{
		return m_NrParticipanti;
	}

	unsigned long long Grup::getID() const
	{
		return m_ID;
	}

	int Grup::getDurataSedere() const
	{
		return m_DurataSedere;
	}

	void Grup::alocareParticipanti(int numar)
	{
		Participant* temp = m_Participanti;
		m_Participanti = new Participant[numar];

		if (temp != nullptr)
		{
			memcpy(m_Participanti, temp, m_NrParticipanti * sizeof(Participant)); //copiaza vectorul vechi in cel nou 
			delete[] temp; //sterge vectorul vechi
		}
		m_NrParticipanti = numar;
	}

	void Grup::adaugareParticipant(const std::string& nume, const std::string& prenume, bool restaurant)
	{
		alocareParticipanti(m_NrParticipanti + 1);
		m_Participanti[m_NrParticipanti].setNume(nume); //seteaza numele noului participant
		m_Participanti[m_NrParticipanti].setPrenume(prenume); //seteaza prenumele
		m_Participanti[m_NrParticipanti].setRestaurant(restaurant); //seteaza daca mananca la restaurant

		m_NrParticipanti++;
	}

	void Grup::citireParticipanti(const std::string& nume_fisier)
	{
		std::ifstream fisier(nume_fisier);

		if (fisier.is_open())
		{
			std::string nume;
			std::string prenume;
			int restaurant;
			int nr_participanti;
			int durata_sedere;
			int i;

			fisier >> nr_participanti;
			m_NrParticipanti = nr_participanti;

			fisier >> durata_sedere;
			m_DurataSedere = durata_sedere;

			m_Participanti = new Participant[nr_participanti];

			for (i = 0; i < nr_participanti; i++)
			{
				fisier >> nume >> prenume >> restaurant;

				m_Participanti[i].setNume(nume);
				m_Participanti[i].setPrenume(prenume);
				m_Participanti[i].setRestaurant((bool)restaurant);
			}

			fisier.close();
		}
		else
		{
			std::cout << "Nu s-a putut deschide fisierul: " << nume_fisier << std::endl;
		}
	}

	void Grup::afisare() const
	{
		int i;

		std::cout << "PARTICIPANTI:" << std::endl;

		for (i = 0; i < m_NrParticipanti; i++)
		{
			std::cout << "ID:" << m_Participanti[i].getID() << std::endl;
			m_Participanti[i].afisare();
			std::cout << std::endl;
		}
	}

	void Grup::setDurataSedere(int durata)
	{
		m_DurataSedere = durata;
	}
}