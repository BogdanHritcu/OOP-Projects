#pragma once

#include "../comanda.h"

namespace oop
{
	class ComandaOnline : public Comanda
	{
	private:
		float m_Distance;

	public:
		ComandaOnline();
		~ComandaOnline();

		float getDistance() const override;

		void readFromFile(std::string filePath) override;
		void readFromFile(std::istream& file) override;
		friend std::istream& operator>>(std::istream& in, ComandaOnline& comanda);

		void printToFile(std::string filePath) override;
		void printToFile(std::ostream& file) override;
		friend std::ostream& operator<<(std::ostream& out, ComandaOnline& comanda);
	};
}