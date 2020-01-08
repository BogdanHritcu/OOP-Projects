#include "pizza.h"

namespace oop
{
	Pizza::Pizza(std::string name, const float labor_cost, const float overhead_percent) : m_LaborCost(labor_cost), m_OverheadPercent(overhead_percent)
	{
		m_Name = name;
	}

	Pizza::~Pizza()
	{

	}

	float Pizza::computePrice()
	{
		std::vector<Ingredient>::iterator it;
		float price = m_LaborCost;

		for (it = m_Ingredients->begin(); it != m_Ingredients->end(); it++)
		{
			price += it->getPrice();
		}

		price += price * m_OverheadPercent;

		return price;
	}

	void Pizza::setIngredients(const std::vector<Ingredient>& ingredients)
	{
		m_Ingredients = const_cast<std::vector<Ingredient>*>(&ingredients);
	}
}