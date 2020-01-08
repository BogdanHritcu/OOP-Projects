#include "comanda_offline.h"

namespace oop
{
	ComandaOffline::ComandaOffline()
	{

	}

	ComandaOffline::~ComandaOffline()
	{
		
	}

	std::istream& operator>>(std::istream& in, ComandaOffline& comanda)
	{
		comanda.readFromFile(in);

		return in;
	}

	std::ostream& operator<<(std::ostream& out, ComandaOffline& comanda)
	{
		comanda.printToFile(out);

		return out;
	}
}