#include "restaurant.h"

namespace oop
{
	Restaurant::Restaurant(int locuri) : Incapere(locuri)
	{
		m_Tip = TipIncapere::restaurant;
	}

	Restaurant::~Restaurant()
	{

	}

	void Restaurant::afiseaza() const
	{
		std::cout << "Restaurant" << std::endl;
		Incapere::afiseaza();
	}
}