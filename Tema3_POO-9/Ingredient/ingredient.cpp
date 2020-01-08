#include "ingredient.h"

namespace oop
{
	Ingredient::Ingredient(std::string name, unsigned int quantity, float unit_price)
	{
		m_Name = name;
		m_Quantity = quantity;
		m_UnitPrice = unit_price;
	}

	Ingredient::~Ingredient()
	{

	}

	std::string Ingredient::getName() const
	{
		return m_Name;
	}

	unsigned int Ingredient::getQuantity() const
	{
		return m_Quantity;
	}

	float Ingredient::getUnitPrice() const
	{
		return m_UnitPrice;
	}

	float Ingredient::getPrice() const
	{
		return m_Quantity * m_UnitPrice;
	}

	void Ingredient::setName(std::string name)
	{
		m_Name = name;
	}

	void Ingredient::setQuantity(unsigned int quantity)
	{
		m_Quantity = quantity;
	}

	void Ingredient::setUnitPrice(float unit_price)
	{
		m_UnitPrice = unit_price;
	}
}