#pragma once

#include <iostream>

namespace oop
{
	enum TipIncapere { incapere_locuit = 0, camera, apartament, restaurant, sala_conferinta, sala_scena, sala_individuala, invalid };

	class Incapere
	{
	protected:
		static unsigned long long s_IDCurent; //folosit pentru atribuirea de ID-uri unice incaperilor

		unsigned long long m_ID; //ID unic pentru fiecare incapere

		bool m_Disponibila[365];
		TipIncapere m_Tip; //tipul incaperii
		
		int m_NumarLocuri;

	public:
		Incapere(int locuri);
		Incapere(const Incapere& incapere);
		Incapere& operator=(const Incapere& incapere);
		~Incapere();

		int getNumarLocuri() const;
		TipIncapere getTip() const;
		unsigned long long getID() const;
		bool disponibila(int zi) const;
		
		void setDisponibila(int zi, bool valoare);

		virtual void afiseaza() const;
	};
}