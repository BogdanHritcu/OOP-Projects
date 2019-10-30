#pragma once

#include "../Element/Element.h"

namespace poo
{
	class Stiva
	{
	private:
		Element* m_Top;

	public:
		Stiva();
		Stiva(const Stiva& stiva);
		~Stiva();

		bool isEmpty();
		void push(const Obiect& ob);
		void pop();
		Obiect pop_ob();
		Obiect& top();

		void read(bool empty = true);
		void show();

		void copy(const Stiva& stiva);
		void empty();
		void invert();

		Stiva& operator=(const Stiva& stiva);

		friend std::istream& operator>>(std::istream& in, Stiva& stiva);
		friend std::ostream& operator<<(std::ostream& out, Stiva& stiva);
	};
}