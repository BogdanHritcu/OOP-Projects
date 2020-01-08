#include <iostream>

#include "Meniu/meniu.h"

int main()
{
	oop::Meniu<> meniu_offline;
	oop::Meniu<oop::ComandaOnline> meniu_online;

	oop::ComandaOffline com_off;
	oop::ComandaOnline com_on;

	meniu_offline.addPizzaTypesFromFile("resource/pizza_types.txt");
	meniu_online.addPizzaTypesFromFile("resource/pizza_types.txt");

	com_off.readFromFile("resource/comanda_offline1.txt");
	com_on.readFromFile("resource/comanda_online1.txt");
	
	meniu_online += com_on;

	meniu_offline += com_off;
	meniu_offline += com_on;

	meniu_offline.printPizzaTypesToFile("pizza_types_off.txt");
	meniu_online.printPizzaTypesToFile("pizza_types_on.txt");
	
	meniu_offline.printSalesToFile("sales_off.txt");
	meniu_online.printSalesToFile("sales_on.txt");

	system("pause");
	return 0;
}