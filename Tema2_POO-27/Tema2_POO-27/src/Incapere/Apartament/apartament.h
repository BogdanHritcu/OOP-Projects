#pragma once

#include "../incapere.h"

namespace oop
{
	class Apartament : public Incapere
	{
	public:
		Apartament(int locuri);
		~Apartament();

		void afiseaza() const override;
	};
}