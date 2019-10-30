#include "Element.h"

namespace poo
{
	Element::Element()
	{
		m_Obiect = new Obiect; //elementul contine un obiect gol cand este creat
		m_Next = NULL;
	}

	Element::Element(const Element& el)
	{
		if (m_Obiect != NULL)
		{
			*m_Obiect = *el.m_Obiect; //copiaza obiectul din interiorul elementului
		}
		else
		{
			m_Obiect = new Obiect(*el.m_Obiect); //daca obiectul era NULL, atunci creeaza unul nou si copiaza-l in element
		}

		m_Next = el.m_Next; //copiaza pointerul care indica urmatorul element
	}

	Element::~Element()
	{
		if (m_Obiect)
		{
			delete m_Obiect; //sterge obiectul
		}
	}

	Element& Element::operator=(const Element& el)
	{
		if (m_Obiect != NULL)
		{
			*m_Obiect = *el.m_Obiect; //copiaza obiectul din interiorul elementului
		}
		else
		{
			m_Obiect = new Obiect(*el.m_Obiect); //daca obiectul era NULL, atunci creeaza unul nou si copiaza-l in element
		}

		m_Next = el.m_Next; //copiaza pointerul catre elementul urmator

		return *this;
	}
}