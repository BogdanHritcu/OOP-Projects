#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <vector>

namespace oop
{
	class Comanda
	{
	protected:
		std::vector<std::string> m_Pizzas;

	public:
		Comanda();
		~Comanda();

		const std::vector<std::string>& getPizzas() const;
		void addPizza(std::string pizza_name);
		virtual float getDistance() const;

		virtual void readFromFile(std::string filePath);
		virtual void readFromFile(std::istream& file);
		friend std::istream& operator>>(std::istream& in, Comanda& comanda);

		virtual void printToFile(std::string filePath);
		virtual void printToFile(std::ostream& file);
		friend std::ostream& operator<<(std::ostream& out, Comanda& comanda);
	};
}