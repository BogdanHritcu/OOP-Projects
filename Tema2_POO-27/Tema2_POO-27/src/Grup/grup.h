#pragma once

#include <fstream>

#include "../Participant/participant.h"

#include "../Incapere/SalaConf/SalaScena/sala_scena.h"
#include "../Incapere/SalaConf/SalaIndiv/sala_indiv.h"

namespace oop
{
	class Grup
	{
	private:
		static unsigned long long s_IDCurent; //folosit pentru atribuirea de ID-uri unice grupurilor

		unsigned long long m_ID; //ID unic pentru fiecare grup
		Participant* m_Participanti; //participantii din grup
		int m_NrParticipanti; //numarul de participanti din grup
		int m_DurataSedere;
		
	public:
		Grup();
		Grup(const Grup& grup);
		Grup& operator=(const Grup& grup);
		~Grup();

		Participant* getParticipanti() const;
		int getNrParticipanti() const;
		unsigned long long getID() const;
		int getDurataSedere() const;

		void alocareParticipanti(int numar);
		void adaugareParticipant(const std::string& nume, const std::string& prenume, bool restaurant);
		void setDurataSedere(int durata);
		void citireParticipanti(const std::string& nume_fisier);
		void afisare() const;
	};
}