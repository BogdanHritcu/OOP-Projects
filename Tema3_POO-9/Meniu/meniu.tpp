#include "meniu.h"

namespace oop
{
	template<class T>
	Meniu<T>::Meniu()
	{
		m_SoldCount = 0;
		m_SoldProducts = nullptr;
	}

	template<class T>
	Meniu<T>::Meniu(const Meniu<T>& meniu)
	{
		m_SoldProducts = new Produs*[meniu.m_SoldCount];
		m_SoldCount = meniu.m_SoldCount;

		unsigned int i;

		for (i = 0; i < m_SoldCount; i++)
		{
			m_SoldProducts[i] = nullptr;

			Pizza* temp = dynamic_cast<Pizza*>(meniu.m_SoldProducts[i]);

			if (temp != nullptr)
			{
				m_SoldProducts[i] = new Pizza(*temp);
			}
		}
	}

	template<class T>
	Meniu<T>& Meniu<T>::operator=(const Meniu<T>& meniu)
	{
		clearSales();

		m_SoldProducts = new Produs*[meniu.m_SoldCount];
		m_SoldCount = meniu.m_SoldCount;

		unsigned int i;

		for (i = 0; i < m_SoldCount; i++)
		{
			m_SoldProducts[i] = nullptr;

			Pizza* temp = dynamic_cast<Pizza*>(meniu.m_SoldProducts[i]);

			if (temp != nullptr)
			{
				m_SoldProducts[i] = new Pizza(*temp);
			}
		}

		return *this;
	}

	template<class T>
	Meniu<T>::~Meniu()
	{
		clearSales();
	}

	template<class T>
	void Meniu<T>::addPizzaType(const std::string& name, const std::vector<Ingredient>& ingredients)
	{
		m_PizzaTypes[name] = ingredients;
	}

	template<class T>
	void Meniu<T>::removePizzaType(const std::string& name)
	{
		m_PizzaTypes.erase(name);
	}

	template<class T>
	void Meniu<T>::clearSales()
	{
		unsigned int i;

		for (i = 0; i < m_SoldCount; i++)
		{
			delete m_SoldProducts[i];
		}

		delete[] m_SoldProducts;

		m_SoldCount = 0;
	}

	template<class T>
	float Meniu<T>::evaluateSales() const
	{
		unsigned int i;
		float total = 0.0f;

		for (i = 0; i < m_SoldCount; i++)
		{
			total += m_SoldProducts[i]->computePrice();
		}

		return total;
	}

	template<class T>
	void Meniu<T>::operator+=(Comanda& order)
	{
		Produs** temp = m_SoldProducts;
		m_SoldProducts = new Produs*[m_SoldCount + order.getPizzas().size()];
		memcpy(m_SoldProducts, temp, m_SoldCount * sizeof(Produs*));
		delete temp;

		std::vector<std::string>::const_iterator it;
		float labor_cost = 12;
		float overhead_percent = order.getDistance() / 10 * 0.05f; //5% pentru fiecare 10km

		for (it = order.getPizzas().begin(); it != order.getPizzas().end(); it++)
		{
			if (m_PizzaTypes.find(*it) != m_PizzaTypes.end())
			{
				if (m_PizzaSold.find(*it) != m_PizzaSold.end())
				{
					m_PizzaSold[*it]++;
				}
				else
				{
					m_PizzaSold[*it] = 0;
				}

				m_SoldProducts[m_SoldCount] = new Pizza(*it, labor_cost, overhead_percent);
				m_SoldProducts[m_SoldCount]->setIngredients(m_PizzaTypes[*it]);
				m_SoldCount++;
			}
		}
	}

	template<class T>
	void Meniu<T>::addPizzaTypesFromFile(std::string filePath)
	{
		std::string pizza_name;
		unsigned int ingredient_count;
		unsigned int i;
		std::string ingredient_name;
		unsigned int quantity;
		float unit_price;
		std::vector<Ingredient> ingredients;

		std::ifstream file(filePath);

		if (file.is_open())
		{
			while (file >> pizza_name >> ingredient_count)
			{
				ingredients.clear();

				for(i = 0; i < ingredient_count; i++)
				{
					file >> ingredient_name >> quantity >> unit_price;
					ingredients.push_back(Ingredient(ingredient_name, quantity, unit_price));
				}

				m_PizzaTypes[pizza_name] = ingredients;
			}
		}
		else
		{
			std::cout << "Could not open file: " << filePath << std::endl;
		}

		file.close();
	}

	template<class T>
	void Meniu<T>::printPizzaTypesToFile(std::string filePath)
	{
		std::ofstream file(filePath);

		if (file.is_open())
		{
			std::unordered_map<std::string, std::vector<Ingredient>>::iterator it;
			std::vector<Ingredient>::iterator jt;

			for (it = m_PizzaTypes.begin(); it != m_PizzaTypes.end(); it++)
			{
				file << it->first << " " << it->second.size() << std::endl;

				for (jt = it->second.begin(); jt != it->second.end(); jt++)
				{
					file << jt->getName() << " " << jt->getQuantity() << " " << jt->getUnitPrice() << std::endl;
				}

				file << std::endl;
			}
		}
		else
		{
			std::cout << "Could not open file: " << filePath << std::endl;
		}

		file.close();
	}
	
	template<class T>
	void Meniu<T>::printPizzaTypes()
	{
		std::unordered_map<std::string, std::vector<Ingredient>>::iterator it;
		std::vector<Ingredient>::iterator jt;

		for (it = m_PizzaTypes.begin(); it != m_PizzaTypes.end(); it++)
		{
			std::cout << it->first << " " << it->second.size() << std::endl;

			for (jt = it->second.begin(); jt != it->second.end(); jt++)
			{
				std::cout << jt->getName() << " " << jt->getQuantity() << " " << jt->getUnitPrice() << std::endl;
			}

			std::cout << std::endl;
		}
	}

	template<class T>
	void Meniu<T>::printSalesToFile(std::string filePath)
	{
		std::ofstream file(filePath);

		if (file.is_open())
		{
			unsigned int i;

			for (i = 0; i < m_SoldCount; i++)
			{
				file << "#" << i << ": " << m_SoldProducts[i]->getName() << std::endl;
				file << "Price: " << m_SoldProducts[i]->computePrice() << std::endl;
			}

			file << "Total: " << evaluateSales() << std::endl;
		}
		else
		{
			std::cout << "Could not open file: " << filePath << std::endl;
		}

		file.close();
	}

	template<class T>
	void Meniu<T>::printSales()
	{
		unsigned int i;

		for (i = 0; i < m_SoldCount; i++)
		{
			std::cout << "#" << i << ": " << m_SoldProducts[i]->getName() << std::endl;
			std::cout << "Price: " << m_SoldProducts[i]->computePrice() << std::endl;
		}

		std::cout << "Total: " << evaluateSales() << std::endl;
	}

	template<class T>
	unsigned int Meniu<T>::getSoldCount(const std::string name)
	{
		if (m_PizzaSold.find(name) != m_PizzaSold.end())
		{
			return m_PizzaSold[name];
		}
		return 0;
	}

	template<class T>
	void Meniu<T>::printMenuType()
	{
		std::cout << typeid(T).name() << std::endl;
	}

	//ComandaOnline specialization

	Meniu<ComandaOnline>::Meniu()
	{
		m_SoldCount = 0;
		m_SoldProducts = nullptr;

		m_SoldVegetarianCount = 0;
		m_SoldVegetarianPizza = nullptr;
	}

	Meniu<ComandaOnline>::Meniu(const Meniu<ComandaOnline>& meniu)
	{
		m_SoldProducts = new Produs*[meniu.m_SoldCount];
		m_SoldCount = meniu.m_SoldCount;

		unsigned int i;

		for (i = 0; i < m_SoldCount; i++)
		{
			m_SoldProducts[i] = nullptr;

			Pizza* temp = dynamic_cast<Pizza*>(meniu.m_SoldProducts[i]);

			if (temp != nullptr)
			{
				m_SoldProducts[i] = new Pizza(*temp);
			}
		}

		m_SoldVegetarianPizza = new Produs*[meniu.m_SoldVegetarianCount];
		m_SoldVegetarianCount = meniu.m_SoldVegetarianCount;

		for (i = 0; i < m_SoldVegetarianCount; i++)
		{
			m_SoldVegetarianPizza[i] = nullptr;

			Pizza* temp = dynamic_cast<Pizza*>(meniu.m_SoldVegetarianPizza[i]);

			if (temp != nullptr)
			{
				m_SoldVegetarianPizza[i] = new Pizza(*temp);
			}
		}
	}

	Meniu<ComandaOnline>& Meniu<ComandaOnline>::operator=(const Meniu<ComandaOnline>& meniu)
	{
		clearSales();

		m_SoldProducts = new Produs*[meniu.m_SoldCount];
		m_SoldCount = meniu.m_SoldCount;

		unsigned int i;

		for (i = 0; i < m_SoldCount; i++)
		{
			m_SoldProducts[i] = nullptr;

			Pizza* temp = dynamic_cast<Pizza*>(meniu.m_SoldProducts[i]);

			if (temp != nullptr)
			{
				m_SoldProducts[i] = new Pizza(*temp);
			}
		}

		m_SoldVegetarianPizza = new Produs*[meniu.m_SoldVegetarianCount];
		m_SoldVegetarianCount = meniu.m_SoldVegetarianCount;

		for (i = 0; i < m_SoldVegetarianCount; i++)
		{
			m_SoldVegetarianPizza[i] = nullptr;

			Pizza* temp = dynamic_cast<Pizza*>(meniu.m_SoldVegetarianPizza[i]);

			if (temp != nullptr)
			{
				m_SoldVegetarianPizza[i] = new Pizza(*temp);
			}
		}

		return *this;
	}

	Meniu<ComandaOnline>::~Meniu()
	{
		clearSales();
	}

	void Meniu<ComandaOnline>::addPizzaType(const std::string& name, const std::vector<Ingredient>& ingredients)
	{
		m_PizzaTypes[name] = ingredients;
	}

	void Meniu<ComandaOnline>::removePizzaType(const std::string& name)
	{
		m_PizzaTypes.erase(name);
	}

	void Meniu<ComandaOnline>::clearSales()
	{
		unsigned int i;

		for (i = 0; i < m_SoldCount; i++)
		{
			delete m_SoldProducts[i];
		}

		delete[] m_SoldProducts;

		m_SoldCount = 0;

		m_SoldProducts = nullptr;

		clearVegetarianSales();
	}

	void Meniu<ComandaOnline>::clearVegetarianSales()
	{
		unsigned int i;

		for (i = 0; i < m_SoldVegetarianCount; i++)
		{
			delete m_SoldVegetarianPizza[i];
		}

		delete[] m_SoldVegetarianPizza;

		m_SoldVegetarianCount = 0;

		m_SoldVegetarianPizza = nullptr;
	}

	float Meniu<ComandaOnline>::evaluateSales() const
	{
		unsigned int i;
		float total = 0.0f;

		for (i = 0; i < m_SoldCount; i++)
		{
			total += m_SoldProducts[i]->computePrice();
		}

		for (i = 0; i < m_SoldVegetarianCount; i++)
		{
			total += m_SoldVegetarianPizza[i]->computePrice();
		}

		return total;
	}

	float Meniu<ComandaOnline>::evaluateVegetarianSales() const
	{
		unsigned int i;
		float total = 0.0f;

		for (i = 0; i < m_SoldVegetarianCount; i++)
		{
			total += m_SoldVegetarianPizza[i]->computePrice();
		}

		return total;
	}

	void Meniu<ComandaOnline>::operator+=(ComandaOnline& order)
	{
		Produs** temp = m_SoldProducts;
		m_SoldProducts = new Produs*[m_SoldCount + order.getPizzas().size()];
		memcpy(m_SoldProducts, temp, m_SoldCount * sizeof(Produs*));
		delete temp;

		temp = m_SoldVegetarianPizza;
		m_SoldVegetarianPizza = new Produs*[m_SoldVegetarianCount + order.getPizzas().size()];
		memcpy(m_SoldVegetarianPizza, temp, m_SoldVegetarianCount * sizeof(Produs*));
		delete temp;

		std::vector<std::string>::const_iterator it;
		float labor_cost = 12;
		float overhead_percent = order.getDistance() / 10 * 0.05f; //5% pentru fiecare 10km

		for (it = order.getPizzas().begin(); it != order.getPizzas().end(); it++)
		{
			if (m_PizzaTypes.find(*it) != m_PizzaTypes.end())
			{
				if (m_PizzaSold.find(*it) != m_PizzaSold.end())
				{
					m_PizzaSold[*it]++;
				}
				else
				{
					m_PizzaSold[*it] = 0;
				}

				if (*it == "vegetariana")
				{
					m_SoldVegetarianPizza[m_SoldVegetarianCount] = new Pizza(*it, labor_cost, overhead_percent);
					m_SoldVegetarianPizza[m_SoldVegetarianCount]->setIngredients(m_PizzaTypes[*it]);
					m_SoldVegetarianCount++;
				}
				else
				{
					m_SoldProducts[m_SoldCount] = new Pizza(*it, labor_cost, overhead_percent);
					m_SoldProducts[m_SoldCount]->setIngredients(m_PizzaTypes[*it]);
					m_SoldCount++;
				}
			}
		}
	}

	void Meniu<ComandaOnline>::addPizzaTypesFromFile(std::string filePath)
	{
		std::string pizza_name;
		unsigned int ingredient_count;
		unsigned int i;
		std::string ingredient_name;
		unsigned int quantity;
		float unit_price;
		std::vector<Ingredient> ingredients;

		std::ifstream file(filePath);

		if (file.is_open())
		{
			while (file >> pizza_name >> ingredient_count)
			{
				ingredients.clear();

				for (i = 0; i < ingredient_count; i++)
				{
					file >> ingredient_name >> quantity >> unit_price;
					ingredients.push_back(Ingredient(ingredient_name, quantity, unit_price));
				}

				m_PizzaTypes[pizza_name] = ingredients;
			}
		}
		else
		{
			std::cout << "Could not open file: " << filePath << std::endl;
		}

		file.close();
	}

	void Meniu<ComandaOnline>::printPizzaTypesToFile(std::string filePath)
	{
		std::ofstream file(filePath);

		if (file.is_open())
		{
			std::unordered_map<std::string, std::vector<Ingredient>>::iterator it;
			std::vector<Ingredient>::iterator jt;

			for (it = m_PizzaTypes.begin(); it != m_PizzaTypes.end(); it++)
			{
				file << it->first << " " << it->second.size() << std::endl;

				for (jt = it->second.begin(); jt != it->second.end(); jt++)
				{
					file << jt->getName() << " " << jt->getQuantity() << " " << jt->getUnitPrice() << std::endl;
				}

				file << std::endl;
			}
		}
		else
		{
			std::cout << "Could not open file: " << filePath << std::endl;
		}

		file.close();
	}

	void Meniu<ComandaOnline>::printPizzaTypes()
	{
		std::unordered_map<std::string, std::vector<Ingredient>>::iterator it;
		std::vector<Ingredient>::iterator jt;

		for (it = m_PizzaTypes.begin(); it != m_PizzaTypes.end(); it++)
		{
			std::cout << it->first << " " << it->second.size() << std::endl;

			for (jt = it->second.begin(); jt != it->second.end(); jt++)
			{
				std::cout << jt->getName() << " " << jt->getQuantity() << " " << jt->getUnitPrice() << std::endl;
			}

			std::cout << std::endl;
		}
	}

	void Meniu<ComandaOnline>::printSalesToFile(std::string filePath)
	{
		std::ofstream file(filePath);

		if (file.is_open())
		{
			unsigned int i;

			file << "NON-VEGETARIAN PIZZA" << std::endl;

			for (i = 0; i < m_SoldCount; i++)
			{
				file << "#" << i << ": " << m_SoldProducts[i]->getName() << std::endl;
				file << "Price: " << m_SoldProducts[i]->computePrice() << std::endl;
			}

			file << "Total: " << evaluateSales() - evaluateVegetarianSales() << std::endl;

			file.close();

			std::string raw_name = filePath.substr(0, filePath.find_last_of("."));
			std::string extension = filePath.substr(filePath.find_last_of("."), filePath.length());
			file.open(raw_name + "_veg" + extension);

			if (file.is_open())
			{
				file << "VEGETARIAN PIZZA" << std::endl;

				for (i = 0; i < m_SoldVegetarianCount; i++)
				{
					file << "#" << i << ": " << m_SoldVegetarianPizza[i]->getName() << std::endl;
					file << "Price: " << m_SoldVegetarianPizza[i]->computePrice() << std::endl;
				}

				file << "Total: " << evaluateVegetarianSales() << std::endl;
			}
			else
			{
				std::cout << "Could not create file: " << raw_name + "_veg" + extension << std::endl;
			}
		}
		else
		{
			std::cout << "Could not open file: " << filePath << std::endl;
		}

		file.close();
	}

	void Meniu<ComandaOnline>::printSales()
	{
		unsigned int i;

		std::cout << "NON-VEGETARIAN PIZZA" << std::endl;

		for (i = 0; i < m_SoldCount; i++)
		{
			std::cout << "#" << i << ": " << m_SoldProducts[i]->getName() << std::endl;
			std::cout << "Price: " << m_SoldProducts[i]->computePrice() << std::endl;
		}
		std::cout << "Total: " << evaluateSales() - evaluateVegetarianSales() << std::endl;

		std::cout << "VEGETARIAN PIZZA" << std::endl;

		for (i = 0; i < m_SoldVegetarianCount; i++)
		{
			std::cout << "#" << i << ": " << m_SoldVegetarianPizza[i]->getName() << std::endl;
			std::cout << "Price: " << m_SoldVegetarianPizza[i]->computePrice() << std::endl;
		}

		std::cout << "Total: " << evaluateVegetarianSales() << std::endl;
	}

	unsigned int Meniu<ComandaOnline>::getSoldCount(const std::string name)
	{
		if (m_PizzaSold.find(name) != m_PizzaSold.end())
		{
			return m_PizzaSold[name];
		}
		return 0;
	}

	void Meniu<ComandaOnline>::printMenuType()
	{
		std::cout << typeid(ComandaOnline).name() << std::endl;
	}
}