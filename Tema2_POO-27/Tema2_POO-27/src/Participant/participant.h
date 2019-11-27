#pragma once

#include <string>
#include <iostream>

#include "../Incapere/Camera/camera.h"
#include "../Incapere/Apartament/apartament.h"

namespace oop
{
	class Participant
	{
	private:
		static unsigned long long s_IDCurent; //folosit pentru atribuirea de ID-uri unice participantilor

		unsigned long long m_ID; //ID unic pentru fiecare participant
		std::string m_Nume;
		std::string m_Prenume;
		bool m_Restaurant; //micul dejun la restaurant (true) sau nu (false)
		Incapere* m_Incapere; //pointer la incaperea in care este cazat participantul

	public:
		Participant();
		Participant(const Participant& participant);
		Participant& operator=(const Participant& participant);
		Participant(bool restaurant);
		~Participant();

		unsigned long long getID() const;
		bool restaurant() const;
		Incapere* getIncapere();

		void setIncapere(const Incapere& incapere);
		void setNume(const std::string& nume);
		void setPrenume(const std::string& prenume);
		void setRestaurant(bool valoare);

		void afisare() const;
	};
}