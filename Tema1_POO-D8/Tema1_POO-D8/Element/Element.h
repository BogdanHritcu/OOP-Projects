#pragma once

#include "../Obiect/Obiect.h"

namespace poo
{
	struct Element
	{
	public:
		Obiect* m_Obiect;
		Element* m_Next;

		Element();
		Element(const Element& el);
		~Element();

		Element& operator=(const Element& el);
	};
}