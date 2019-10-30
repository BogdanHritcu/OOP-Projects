#pragma once

#include "../Stiva/Stiva.h"

namespace poo
{
	class Nr_Stive
	{
		Stiva* m_StiveVec;
		int m_Size;

	public:
		Nr_Stive();
		Nr_Stive(const Nr_Stive& stive);
		~Nr_Stive();

		void read();
		void showO();

		int getSize();
		Stiva& getStiva(int index);

		Nr_Stive& operator=(const Nr_Stive& stive);

		friend std::istream& operator>>(std::istream& in, Nr_Stive& stive);
		friend std::ostream& operator<<(std::ostream& out, Nr_Stive& stive);
	};

	void read_stack(Stiva& stiva, bool empty = true);
	void show_stack(Stiva& stiva);
	void empty_stack(Stiva& stiva);
	void copy_stack(Stiva& dest, const Stiva& src);
	void invert_stack(Stiva &stiva);
}