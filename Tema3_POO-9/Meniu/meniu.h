#pragma once

#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <fstream>

#include "../Ingredient/ingredient.h"
#include "../Produs/produs.h"
#include "../Produs/Pizza/pizza.h"
#include "../Comanda/ComandaOnline/comanda_online.h"
#include "../Comanda/ComandaOffline/comanda_offline.h"

namespace oop
{
	template<class T = ComandaOffline>
	class Meniu
	{
	private:
		std::unordered_map<std::string, std::vector<Ingredient>> m_PizzaTypes;
		std::unordered_map<std::string, unsigned int> m_PizzaSold;

		unsigned int m_SoldCount;
	    Produs** m_SoldProducts;

	public:
		Meniu();
		Meniu(const Meniu<T>& meniu);
		Meniu<T>& operator=(const Meniu<T>& meniu);
		~Meniu();

		void removePizzaType(const std::string& name);

		void clearSales();
		float evaluateSales() const;
		void operator+=(Comanda& order);

		void addPizzaTypesFromFile(std::string filePath);
		void addPizzaType(const std::string& name, const std::vector<Ingredient>& ingredients);

		void printPizzaTypesToFile(std::string filePath);
		void printPizzaTypes();
		
		void printSalesToFile(std::string filePath);
		void printSales();

		unsigned int getSoldCount(const std::string name);
		
		//
		void printMenuType();

	};

	template<>
	class Meniu<ComandaOnline>
	{
	private:
		std::unordered_map<std::string, std::vector<Ingredient>> m_PizzaTypes;
		std::unordered_map<std::string, unsigned int> m_PizzaSold;

		unsigned int m_SoldCount;
		Produs** m_SoldProducts;

		unsigned int m_SoldVegetarianCount;
		Produs** m_SoldVegetarianPizza;

	public:
		Meniu();
		Meniu(const Meniu<ComandaOnline>& meniu);
		Meniu<ComandaOnline>& operator=(const Meniu<ComandaOnline>& meniu);
		~Meniu();

		void clearSales();
		void clearVegetarianSales();
		float evaluateSales() const;
		float evaluateVegetarianSales() const;

		void removePizzaType(const std::string& name);

		void operator+=(ComandaOnline& order);

		void addPizzaTypesFromFile(std::string filePath);
		void addPizzaType(const std::string& name, const std::vector<Ingredient>& ingredients);

		void printPizzaTypesToFile(std::string filePath);
		void printPizzaTypes();

		void printSalesToFile(std::string filePath);
		void printSales();

		unsigned int getSoldCount(const std::string name);

		//
		void printMenuType();
	};
}

#include "../Meniu/meniu.tpp"