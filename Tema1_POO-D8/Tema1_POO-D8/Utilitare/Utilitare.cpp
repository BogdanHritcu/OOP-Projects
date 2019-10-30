#include "Utilitare.h"

namespace poo
{
	Nr_Stive::Nr_Stive()
	{
		m_StiveVec = NULL; //vectorul de stive este NULL la inceput
		m_Size = 0; //dimensiunea este 0
	}
	
	Nr_Stive::Nr_Stive(const Nr_Stive& stive)
	{
		m_StiveVec = new Stiva[stive.m_Size]; //aloca memorie suficienta cat sa se poata copia vectorul de stive
		m_Size = stive.m_Size; //modifica dimensiunea vectorului

		int i;

		for (i = 0; i < stive.m_Size; i++)
		{
			m_StiveVec[i] = stive.m_StiveVec[i]; //copiaza toate stivele in noul vector
		}
	}

	Nr_Stive::~Nr_Stive()
	{
		delete[] m_StiveVec; //sterge vectorul de stive
	}

	void Nr_Stive::read()
	{
		delete[] m_StiveVec; //sterge vectorul curent de stive

		int size;

		//citeste dimenisunea vectorului de stive dorit
		do
		{
			std::cout << "Numarul de stive citite:";
			std::cin >> size;

			if (size <= 0)
			{
				std::cout << "Numarul de stive citite trebuie sa fie mai mare decat 0!" << std::endl;
			}

		} while (size <= 0);

		m_StiveVec = new Stiva[size]; //aloca un nou vector de stive cu dimensiunea dorita
		m_Size = size; //modifica dimensiunea vectorului

		int i;

		for (i = 0; i < size; i++)
		{
			std::cin >> m_StiveVec[i]; //citeste fiecare stiva
		}
	}

	void Nr_Stive::showO()
	{
		int i;

		for (i = 0; i < m_Size; i++) //afiseaza fiecare stiva din vector
		{
			std::cout << "Stiva" << i << ":" << std::endl;
			std::cout << m_StiveVec[i] << std::endl;
		}
	}

	int Nr_Stive::getSize()
	{
		return m_Size;
	}

	Stiva& Nr_Stive::getStiva(int index)
	{
		if (index >= 0 && index < m_Size)
		{
			return m_StiveVec[index];
		}

		//UB pentru folosirea pe un vector gol
	}

	Nr_Stive& Nr_Stive::operator=(const Nr_Stive& stive)
	{
		delete[] m_StiveVec; //sterge vecttorul de stive curent

		m_StiveVec = new Stiva[stive.m_Size]; //aloca memorie suficienta pentru noul vector de stive
		m_Size = stive.m_Size; //modifica dimensiunea vectorului de stive stive
	
		int i;

		for (i = 0; i < stive.m_Size; i++)
		{
			m_StiveVec[i] = stive.m_StiveVec[i]; //copiaza fiecare stiva in noul vector
		}

		return *this;
	}

	std::istream& operator>>(std::istream& in, Nr_Stive& stive)
	{

		delete[] stive.m_StiveVec; //sterge vectorul curent de stive
		
		int size;

		//citeste dimenisunea vectorului de stive dorit
		do
		{
			std::cout << "Numarul de stive citite:";
			in >> size;

			if (size <= 0)
			{
				std::cout << "Numarul de stive citite trebuie sa fie mai mare decat 0!" << std::endl;
			}

		} while (size <= 0);

		stive.m_StiveVec = new Stiva[size]; //aloca un nou vector de stive cu dimensiunea dorita
		stive.m_Size = size; //modifica dimensiunea vectorului

		int i;

		for (i = 0; i < size; i++)
		{
			in >> stive.m_StiveVec[i]; //citeste fiecare stiva
		}

		return in;
	}
	
	std::ostream& operator<<(std::ostream& out, Nr_Stive& stive)
	{
		int i;

		for (i = 0; i < stive.m_Size; i++) //afiseaza fiecare stiva din vector
		{
			out << "Stiva" << i << ":" << std::endl;
			out << stive.m_StiveVec[i] << std::endl;
		}

		return out;
	}

	void read_stack(Stiva& stiva, bool empty)
	{
		stiva.read(empty);
	}

	void show_stack(Stiva& stiva)
	{
		stiva.show();
	}

	void empty_stack(Stiva& stiva)
	{
		stiva.empty();
	}

	void copy_stack(Stiva& dest, const Stiva& src)
	{
		dest = src;
	}

	void invert_stack(Stiva &stiva)
	{
		stiva.invert();
	}
}