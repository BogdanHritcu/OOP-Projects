#pragma once

#include "../Grup/grup.h"

namespace oop
{
	enum TipCerere { rezervare = 0, anulare };

	class Cerere
	{
	private:
		TipCerere m_Tip; //tipul cererii (rezervare / anulare rezervare)
		Grup* m_Grup; //pointer catre grupul care face rezervarea / anularea rezervarii
		bool m_Proiector;
		TipIncapere m_TipSala;

	public:
		Cerere();
		Cerere(const Cerere& cerere);
		Cerere& operator=(const Cerere& cerere);
		~Cerere();

		TipCerere getTip() const;
		Grup* getGrup() const;
		TipIncapere getTipSala() const; //returneaza tipul de sala de conferinta de care are grupul nevoie
		bool getProiector() const; //returneaza daca grupul are nevoie de sala de conferinta cu proiector

		void setTipCerere(const TipCerere tip_cerere);
		void setGrup(const Grup& grup);
		void setTipSala(TipIncapere tip); //seteaza tipul de sala de conferinta de care are grupul nevoie
		void setProiector(bool valoare); //seteaza daca grupul are nevoie de sala de conferinta cu proiector
	};
}