#include <iostream>

#include "Hotel/hotel.h"
#include "Cerere/cerere.h"

int main()
{
	int i;
	oop::Hotel hotel;
	oop::Grup grup;
	oop::Cerere cerere;

	hotel.citireIncaperi("resource/input_hotel.txt");
	grup.citireParticipanti("resource/input_persoane.txt");
	cerere.setGrup(grup);
	cerere.setTipCerere(oop::TipCerere::rezervare);
	cerere.setTipSala(oop::TipIncapere::sala_individuala);

	hotel.acceptaCerere(cerere);

	hotel.afiseazaStructura();
	std::cout << "######################################################################################################################" << std::endl;
	
	hotel.afisareRezervari(false);
	std::cout << "######################################################################################################################" << std::endl;

	cerere.setTipCerere(oop::TipCerere::anulare);
	hotel.acceptaCerere(cerere); //anularea rezervarilor nu functioneaza
	hotel.afisareRezervari(false);
	std::cout << "######################################################################################################################" << std::endl;

	std::cout << "Incaperi zi1: " << hotel.getNrLocuriLibere(1, oop::TipIncapere::incapere_locuit) << std::endl;
	std::cout << "Camere zi1: " << hotel.getNrLocuriLibere(1, oop::TipIncapere::camera) << std::endl;
	std::cout << "Apartamente zi1: " << hotel.getNrLocuriLibere(1, oop::TipIncapere::apartament) << std::endl;
	std::cout << "Restaurant zi1: " << hotel.getNrLocuriLibere(1, oop::TipIncapere::restaurant) << std::endl;
	std::cout << "Sali scena zi1: " << hotel.getNrLocuriLibere(1, oop::TipIncapere::sala_scena) << std::endl;
	std::cout << "Sali indiv zi1: " << hotel.getNrLocuriLibere(1, oop::TipIncapere::sala_individuala) << std::endl << std::endl;

	std::cout << "Incaperi zi11: " << hotel.getNrLocuriLibere(11, oop::TipIncapere::incapere_locuit) << std::endl;
	std::cout << "Camere zi11: " << hotel.getNrLocuriLibere(11, oop::TipIncapere::camera) << std::endl;
	std::cout << "Apartamente zi11: " << hotel.getNrLocuriLibere(11, oop::TipIncapere::apartament) << std::endl;
	std::cout << "Restaurant zi11: " << hotel.getNrLocuriLibere(11, oop::TipIncapere::restaurant) << std::endl;
	std::cout << "Sali scena zi11: " << hotel.getNrLocuriLibere(11, oop::TipIncapere::sala_scena) << std::endl;
	std::cout << "Sali indiv zi11: " << hotel.getNrLocuriLibere(11, oop::TipIncapere::sala_individuala) << std::endl << std::endl;


	std::cout << "Incaperi zi12: " << hotel.getNrLocuriLibere(12, oop::TipIncapere::incapere_locuit) << std::endl;
	std::cout << "Camere zi12: " << hotel.getNrLocuriLibere(12, oop::TipIncapere::camera) << std::endl;
	std::cout << "Apartamente zi12: " << hotel.getNrLocuriLibere(12, oop::TipIncapere::apartament) << std::endl;
	std::cout << "Restaurant zi12: " << hotel.getNrLocuriLibere(12, oop::TipIncapere::restaurant) << std::endl;
	std::cout << "Sali scena zi12: " << hotel.getNrLocuriLibere(12, oop::TipIncapere::sala_scena) << std::endl;
	std::cout << "Sali indiv zi12: " << hotel.getNrLocuriLibere(12, oop::TipIncapere::sala_individuala) << std::endl << std::endl;

	system("pause");
	
	return 0;
}