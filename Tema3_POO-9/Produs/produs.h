#pragma once

#include <vector>

#include "../Ingredient/ingredient.h"

namespace oop
{
	class Produs
	{
	protected:
		std::string m_Name;

	public:
		Produs();
		~Produs();

		virtual float computePrice() = 0;
		virtual void setIngredients(const std::vector<Ingredient>& ingredients) = 0;
		std::string getName() const;
	};
}