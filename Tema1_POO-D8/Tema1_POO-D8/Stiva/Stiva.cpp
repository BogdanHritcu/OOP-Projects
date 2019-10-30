#include "Stiva.h"

namespace poo
{
	Stiva::Stiva()
	{
		m_Top = NULL; //stiva este vida
	}

	Stiva::Stiva(const Stiva& stiva)
	{
		Element *curr_s = stiva.m_Top; //pointer de parcurgere la varful stivei sursa
		Element *curr_d; //pointer de parcurgere la varful stivei destinatie

		while (curr_s != NULL) //cat timp nu am ajuns la baza stivei sursa
		{
			push(Obiect()); //adauga obiecte goale in stiva destinatie
			curr_s = curr_s->m_Next; //treci la urmatorul element din stiva
		}

		curr_s = stiva.m_Top; //revine la varful stivei sursa
		curr_d = m_Top; //revine la varful stivei destinatie

		while (curr_s != NULL) //cat timp nu am ajuns la baza stivei sursa
		{
			*curr_d->m_Obiect = *curr_s->m_Obiect; //copiaza obiectul curent din sursa in obiectul gol din destinatie
			curr_s = curr_s->m_Next; //treci la urmatorul element din stiva sursa
			curr_d = curr_d->m_Next; //treci la urmatorul element din stiva destinatie
		}
	}

	Stiva::~Stiva()
	{
		empty(); //elibereaza memoria ocupata de stiva (sterge toate elementele)
	}

	bool Stiva::isEmpty()
	{
		return m_Top == NULL; //daca varful este NULL, atunci stiva e vida
	}

	void Stiva::push(const Obiect& ob)
	{
		Element* elem = new Element; //element nou
		*elem->m_Obiect = ob; //copiaza obiectul in element
		elem->m_Next = m_Top; //pune noul element peste varful stivei
		m_Top = elem; //elemntul creat este noul varf
	}

	void Stiva::pop()
	{
		if (!isEmpty())
		{
			Element* temp = m_Top; //retine varful
			m_Top = m_Top->m_Next; //schimba varful in urmatorul element
			delete temp; //sterge vechiul varf
		}
	}

	Obiect Stiva::pop_ob()
	{
		Obiect ob; //obiect temporar pentru returnarea valorii eliminate din stiva

		if (!isEmpty())
		{
			ob = *m_Top->m_Obiect; //copiaza obiectul care se scoate din stiva

			Element* temp = m_Top; //retine varful
			m_Top = m_Top->m_Next; //schimba varful in urmatorul element
			delete temp; //sterge vechiul varf
		}

		return ob; //returneaza obiectul eliminat din stiva sau un obiect gol daca stiva este vida
	}

	Obiect& Stiva::top()
	{
		if (m_Top)
		{
			return *m_Top->m_Obiect; //returneaza o referinta la obiectul din varful stivei
		}

		//undefined behavior daca stiva este vida
	}

	void Stiva::read(bool empty)
	{
		if (empty)
		{
			this->empty(); //goleste stiva daca empty == true
		}

		int size;

		do
		{
			std::cout << "Numarul de elemente citite:";
			std::cin >> size;

			if (size <= 0)
			{
				std::cout << "Numarul de elemente citite trebuie sa fie mai mare decat 0!" << std::endl;
			}

		} while (size <= 0);

		int i;
		Obiect ob;

		for (i = 0; i < size; i++)
		{
			std::cout << "Element" << i << ":" << std::endl;
			std::cin >> ob;

			push(ob); //adauga obiectul in stiva
		}
	}

	void Stiva::show()
	{
		int i = 0;
		Element* curr = m_Top; //pune pointerul de parcurgere la varful stivei

		while (curr != NULL) //parcurge stiva pana ajungi la baza ei
		{
			std::cout << "Element" << i << ":" << std::endl;
			std::cout << *curr->m_Obiect << std::endl; //afiseaza elementul
			curr = curr->m_Next; //treci la urmatorul element
			i++;
		}
	}
	
	void Stiva::copy(const Stiva& stiva)
	{
		empty(); //goleste stiva destinatie

		Element *curr_s = stiva.m_Top; //pointer de parcurgere la varful stivei sursa
		Element *curr_d; //pointer de parcurgere la varful stivei destinatie

		while (curr_s != NULL) //cat timp nu am ajuns la baza stivei sursa
		{
			push(Obiect()); //adauga obiecte goale in stiva destinatie
			curr_s = curr_s->m_Next; //treci la urmatorul element din stiva
		}

		curr_s = stiva.m_Top; //revine la varful stivei sursa
		curr_d = m_Top; //revine la varful stivei destinatie

		while (curr_s != NULL) //cat timp nu am ajuns la baza stivei sursa
		{
			*curr_d->m_Obiect = *curr_s->m_Obiect; //copiaza obiectul curent din sursa in obiectul gol din destinatie
			curr_s = curr_s->m_Next; //treci la urmatorul element din stiva sursa
			curr_d = curr_d->m_Next; //treci la urmatorul element din stiva destinatie
		}
	}

	void Stiva::empty()
	{
		Element* curr = m_Top; //pointer de parcurgere la varful stivei
		Element* temp; //pointer pentru stocarea temporara a unui element

		while (curr != NULL) //cat timp nu am ajuns la baza stivei
		{
			temp = curr; //retine adresa elementului curent in variabila temporara
			curr = curr->m_Next; //treci la urmatorul element

			delete temp; //elibereaza memoria folosind pointerul temporar
		}

		m_Top = NULL; //stiva este goala, deci varful este NULL
	}

	void Stiva::invert()
	{
		Stiva stiva; //stiva auxiliara
		Element* curr = m_Top; //pointer pentru parcurgerea stivei

		while (curr != NULL) //cat timp nu am ajuns la baza stivei
		{
			curr = curr->m_Next; //treci la urmatorul element
			stiva.push(pop_ob()); //adauga in stiva auxiliara elementele din stiva curenta, in ordinea inversa a eliminarii

			//mai intai se trece la urmatorul element pentru ca prin metoda pop_ob se sterge elemetul current
			//lasand pointerul in UB
		}

		*this = stiva;
	}

	Stiva& Stiva::operator=(const Stiva& stiva)
	{
		copy(stiva);

		return *this;
	}

	std::istream& operator>>(std::istream& in, Stiva& stiva)
	{
		int size;

		do
		{
			std::cout << "Numarul de elemente citite:";
			in >> size;

			if (size <= 0)
			{
				std::cout << "Numarul de elemente citite trebuie sa fie mai mare decat 0!" << std::endl;
			}

		} while (size <= 0);

		int i;
		Obiect ob;

		for (i = 0; i < size; i++)
		{
			std::cout << "Element" << i << ":" << std::endl;
			in >> ob;
			
			stiva.push(ob); //adauga obiectul in stiva
		}

		return in;
	}

	std::ostream& operator<<(std::ostream& out, Stiva& stiva)
	{
		int i = 0;
		Element* curr = stiva.m_Top;

		while (curr != NULL)
		{
			std::cout << "Element" << i << ":" << std::endl;
			out << *curr->m_Obiect << std::endl;
			curr = curr->m_Next;
			i++;
		}

		return out;
	}
}