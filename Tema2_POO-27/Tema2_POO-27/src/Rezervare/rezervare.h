#pragma once

#include "../Grup/grup.h"
#include "../Incapere/incapere.h"

namespace oop
{
	class Rezervare
	{
	private:
		int m_ZiCazare; //ziua in care incepe rezervarea incaperilor
		int m_DurataSedere; //numarul de zile in care este valabila rezervarea
		Grup* m_Grup; //pointer la grupul care a facut rezervarea
		Incapere* m_SalaConf; //sala de conferinta rezervata
		
	public:
		Rezervare();
		Rezervare(int zi_cazare, int durata_sedere);
		~Rezervare();

		int getZiCazare() const;
		int getZiDecazare() const; //cazare + sedere - 1
		int getDurataSedere() const;
		Grup* getGrup() const;
		Incapere* getSalaConf() const;

		void setGrup(const Grup* grup);
		void setZiCazare(int zi);
		void setDurataSedere(int nr_zile);
		void setSalaConf(const Incapere* sala);

		void afiseaza(bool afisare_grup) const;
	};
}