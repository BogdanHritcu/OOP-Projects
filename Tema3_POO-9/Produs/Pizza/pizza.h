#pragma once

#include "../../Ingredient/ingredient.h"
#include "../produs.h"
#include <vector>

namespace oop
{
	class Pizza : public Produs
	{
	private:
		const float m_LaborCost;
		const float m_OverheadPercent;
		std::vector<Ingredient>* m_Ingredients;

	public:
		Pizza(std::string name = "", float labor_cost = 0.0f, const float overhead_percent = 0.0f);
		~Pizza();

		float computePrice() override;
		void setIngredients(const std::vector<Ingredient>& ingredients) override;
	};
}