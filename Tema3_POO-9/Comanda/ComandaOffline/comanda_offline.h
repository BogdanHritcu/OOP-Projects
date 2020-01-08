#pragma once

#include "../comanda.h"

namespace oop
{
	class ComandaOffline : public Comanda
	{

	public:
		ComandaOffline();
		~ComandaOffline();

		friend std::istream& operator>>(std::istream& in, ComandaOffline& comanda);
		friend std::ostream& operator<<(std::ostream& out, ComandaOffline& comanda);
	};
}