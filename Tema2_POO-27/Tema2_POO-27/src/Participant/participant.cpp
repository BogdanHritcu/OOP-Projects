#include "participant.h"

namespace oop
{
	unsigned long long Participant::s_IDCurent = 0; //initializarea variabilei statice

	Participant::Participant()
	{
		m_ID = s_IDCurent;
		s_IDCurent++;
		m_Incapere = nullptr;
		m_Restaurant = false;
	}

	Participant::Participant(bool restaurant)
	{
		m_ID = s_IDCurent;
		s_IDCurent++;
		m_Incapere = nullptr;
		m_Restaurant = restaurant;
	}

	Participant::Participant(const Participant& participant)
	{
		m_Nume = participant.m_Nume;
		m_Prenume = participant.m_Prenume;
		m_ID = participant.m_ID;
		m_Incapere = participant.m_Incapere;
		m_Restaurant = participant.m_Restaurant;
	}

	Participant& Participant::operator=(const Participant& participant)
	{
		m_Nume = participant.m_Nume;
		m_Prenume = participant.m_Prenume;
		m_ID = participant.m_ID;
		m_Incapere = participant.m_Incapere;
		m_Restaurant = participant.m_Restaurant;

		return *this;
	}

	Participant::~Participant()
	{

	}

	void Participant::setIncapere(const Incapere& incapere)
	{
		m_Incapere = const_cast<Incapere*>(&incapere);
	}

	unsigned long long Participant::getID() const
	{
		return m_ID;
	}

	bool Participant::restaurant() const
	{
		return m_Restaurant;
	}

	Incapere* Participant::getIncapere()
	{
		return m_Incapere;
	}

	void Participant::setNume(const std::string& nume)
	{
		m_Nume = nume;
	}

	void Participant::setPrenume(const std::string& prenume)
	{
		m_Prenume = prenume;
	}

	void Participant::setRestaurant(bool valoare)
	{
		m_Restaurant = valoare;
	}
	
	void Participant::afisare() const
	{
		std::cout << "Nume: " << m_Nume << std::endl;
		std::cout << "Prenume: " << m_Prenume << std::endl;
		std::cout << "Numar camera: ";

		if (m_Incapere)
		{
			std::cout << m_Incapere->getID() << std::endl;
		}
		else
		{
			std::cout << "Nu este cazat" << std::endl;
		}
		
		restaurant() ? std::cout << "M" : std::cout << "Nu m";
		std::cout << "ananca la restaurant." << std::endl;
	}
}