#pragma once

#include "../incapere.h"

namespace oop
{
	class Restaurant : public Incapere
	{
	public:
		Restaurant(int locuri);
		~Restaurant();

		void afiseaza() const override;
	};
}