#include "comanda.h"

namespace oop
{
	Comanda::Comanda()
	{

	}

	Comanda::~Comanda()
	{

	}

	const std::vector<std::string>& Comanda::getPizzas() const
	{
		return m_Pizzas;
	}

	void Comanda::addPizza(std::string pizza_name)
	{
		m_Pizzas.push_back(pizza_name);
	}

	float Comanda::getDistance() const
	{
		return 0.0f;
	}

	void Comanda::readFromFile(std::string filePath)
	{
		std::ifstream file(filePath);
		
		if (file.is_open())
		{
			m_Pizzas.clear();

			unsigned int i;
			unsigned int pizza_count;
			std::string pizza_name;

			file >> pizza_count;

			for (i = 0; i < pizza_count; i++)
			{
				file >> pizza_name;
				m_Pizzas.push_back(pizza_name);
			}
		}
		else
		{
			std::cout << "Could not open file: " << filePath << std::endl;
		}

		file.close();
	}

	void Comanda::readFromFile(std::istream& file)
	{
		if (file)
		{
			bool cinput = (&std::cin == &file);

			m_Pizzas.clear();

			unsigned int i;
			unsigned int pizza_count;
			std::string pizza_name;

			if (cinput)
			{
				std::cout << "Numar de pizza:";
			}

			file >> pizza_count;

			for (i = 0; i < pizza_count; i++)
			{
				if (cinput)
				{
					std::cout << "Nume pizza:";
				}

				file >> pizza_name;
				m_Pizzas.push_back(pizza_name);
			}
		}
	}

	std::istream& operator>>(std::istream& in, Comanda& comanda)
	{
		comanda.readFromFile(in);

		return in;
	}

	void Comanda::printToFile(std::string filePath)
	{

		std::ofstream file(filePath);

		if (file.is_open())
		{
			std::vector<std::string>::iterator it;

			for (it = m_Pizzas.begin(); it != m_Pizzas.end(); it++)
			{
				file << *it << std::endl;
			}
		}
		else
		{
			std::cout << "Could not open file: " << filePath << std::endl;
		}
	}

	void Comanda::printToFile(std::ostream& file)
	{
		if (file)
		{
			bool coutput = (&std::cout == &file);
			
			if(!coutput)
			{
				file << m_Pizzas.size() << std::endl;
			}

			std::vector<std::string>::iterator it;

			for (it = m_Pizzas.begin(); it != m_Pizzas.end(); it++)
			{
				file << *it << std::endl;
			}
		}
	}

	std::ostream& operator<<(std::ostream& out, Comanda& comanda)
	{
		comanda.printToFile(out);

		return out;
	}
}