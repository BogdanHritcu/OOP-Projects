#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "../Incapere/incapere.h"
#include "../Incapere/Apartament/apartament.h"
#include "../Incapere/Camera/camera.h"
#include "../Incapere/Restaurant/restaurant.h"
#include "../Incapere/SalaConf/SalaIndiv/sala_indiv.h"
#include "../Incapere/SalaConf/SalaScena/sala_scena.h"

#include "../Grup/grup.h"
#include "../Cerere/cerere.h"
#include "../Rezervare/rezervare.h"

namespace oop
{
	struct LocuriLibere
	{
		unsigned short incaperi;
		unsigned short camere;
		unsigned short apartamente;
		unsigned short restaurante;
		unsigned short sali_conf;
		unsigned short sali_scena;
		unsigned short sali_indiv;

		LocuriLibere();
		~LocuriLibere();
	};

	class Hotel
	{
	private:
		LocuriLibere m_LocuriLibere[365];

		Incapere** m_Incaperi; //incaperile din hotel in care se poate locui
		int m_NrIncaperi;
		
		Incapere** m_Sali; //incaperile care sunt sali de conferinta
		int m_NrSali;

		Incapere** m_Restaurante; //incaperile care sunt restaurante
		int m_NrRestaurante;

		Rezervare* m_Rezervari; //vector de rezervari
		int m_NrRezervari;
	
	public:
		Hotel();
		Hotel(const Hotel& hotel);
		Hotel& operator=(const Hotel& hotel);
		~Hotel();

		void citireIncaperi(const std::string& nume_fisier);
		void acceptaCerere(const Cerere& cerere);
		int getNrLocuriLibere(int zi, TipIncapere tip);

		void afisareRezervari(bool afisare_grupuri) const;
		void afiseazaStructura() const;

	private:
		void eliminaIncaperi();
	};
}