#pragma once

#include <string>

namespace oop
{
	class Ingredient
	{
	private:
		std::string m_Name;
		unsigned int m_Quantity;
		float m_UnitPrice;

	public:
		Ingredient(std::string name = "", unsigned int quantity = 0, float unit_price = 0.0f);
		~Ingredient();

		std::string getName() const;
		unsigned int getQuantity() const;
		float getUnitPrice() const;
		float getPrice() const;

		void setName(std::string name);
		void setQuantity(unsigned int quantity);
		void setUnitPrice(float unit_price);
	};
}